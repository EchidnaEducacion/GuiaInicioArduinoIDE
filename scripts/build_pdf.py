#!/usr/bin/env python3
"""Genera site/proyectos-inicio-arduino.pdf a partir del sitio ya construido por Zensical.

En vez de imprimir cada página por separado (lo que fuerza un salto de
página entre cada fichero .md y deja huecos en blanco), este script une el
contenido de todas las páginas —en el orden y la jerarquía del `nav` de
zensical.toml— en un único documento HTML y lo imprime una sola vez con
WeasyPrint. Los saltos de página solo se fuerzan entre capítulos y
subsecciones (profundidad 0 y 1 del nav); el resto del contenido fluye de
forma continua, como en un libro.

La profundidad de cada página determina cuánto se desplazan sus
encabezados: el index.md de una sección hereda la profundidad de la propia
sección (su <h1> hace de título de capítulo/subsección) y el resto de
páginas quedan un nivel más abajo. Así el índice y los marcadores del PDF
reflejan la estructura real del recurso.
"""

from pathlib import Path
from urllib.parse import urljoin

from lxml import html as lxml_html
from weasyprint import CSS, HTML
from weasyprint.text.fonts import FontConfiguration

from guia_nav import (
    SITE_DIR,
    load_nav,
    md_to_html,
    ordered_pages,
    site_url_of,
    slugify_page,
)

PRINT_CSS_PATH = Path(__file__).resolve().parent / "print.css"
OUTPUT_PATH = SITE_DIR / "proyectos-inicio-arduino.pdf"

MAX_TOC_DEPTH = 1


def shift_headings(article, shift):
    if shift <= 0:
        return
    for level in range(6, 0, -1):
        new_level = min(level + shift, 6)
        if new_level == level:
            continue
        for heading in article.xpath(f".//h{level}"):
            heading.tag = f"h{new_level}"


def find_article(tree, html_path):
    candidates = tree.xpath(
        "//article[contains(concat(' ', normalize-space(@class), ' '), ' md-content__inner ')]"
    )
    if not candidates:
        raise SystemExit(f"No se encontró el contenido principal en {html_path}")
    return candidates[0]


def render_page(depth, md_path, url_to_id):
    html_path = md_to_html(md_path)
    if not html_path.exists():
        raise SystemExit(f"No se encontró la página construida para '{md_path}': {html_path}")

    tree = lxml_html.fromstring(html_path.read_text(encoding="utf-8"))
    article = find_article(tree, html_path)

    page_id = slugify_page(md_path)
    page_dir_uri = (SITE_DIR / site_url_of(md_path)).resolve().as_uri() + "/"

    for el in article.xpath(".//*[@src]"):
        el.set("src", urljoin(page_dir_uri, el.get("src")))

    for img in article.xpath(".//img[@width]"):
        # WeasyPrint, a diferencia de un navegador, ignora el atributo HTML
        # `width` de <img> y usa el tamaño nativo de la imagen. Lo pasamos a
        # estilo en línea para que el PDF mida lo mismo que la web.
        img.set("style", f"width: {img.get('width')}px; height: auto;")

    for block in article.xpath(
        ".//div[contains(concat(' ', @class, ' '), ' highlight ')] | .//table"
    ):
        # El párrafo que presenta un bloque de código o una tabla debe quedar
        # en la misma página que el código o la tabla. WeasyPrint no admite :has() ni selectores
        # hacia atrás, así que marcamos aquí el párrafo (ver .keep-with-next
        # en print.css).
        previous = block.getprevious()
        if previous is not None and previous.tag == "p":
            previous.set("class", f"{previous.get('class', '')} keep-with-next".strip())

    for el in article.xpath(".//*[@id]"):
        el.set("id", f"{page_id}--{el.get('id')}")

    for a in article.xpath(".//a[@href]"):
        href = a.get("href")
        if href.startswith("#"):
            a.set("href", f"#{page_id}--{href[1:]}")
            continue
        if href.startswith(("http://", "https://", "mailto:", "tel:")):
            continue
        path_part, _, frag = href.partition("#")
        target = urljoin(f"/{site_url_of(md_path)}", path_part).lstrip("/")
        if target in url_to_id:
            anchor = url_to_id[target]
            if frag:
                anchor += f"--{frag}"
            a.set("href", f"#{anchor}")

    shift_headings(article, depth)

    article.tag = "section"
    article.set("id", page_id)
    article.set("class", f"pdf-page depth-{depth}")

    toc_entry = None
    if depth <= MAX_TOC_DEPTH:
        heading_level = 1 + depth
        heading = article.find(f".//h{heading_level}")
        if heading is not None:
            toc_entry = (depth, heading.text_content().strip(), page_id)

    return lxml_html.tostring(article, encoding="unicode"), toc_entry


def render_cover(site_title, site_author):
    logo = (SITE_DIR / "assets/images/Logo_Echidna_I.png").resolve().as_uri()
    # A diferencia del manual, este recurso no tiene una ilustración de portada
    # propia: la portada se maqueta con HTML + print.css (logo, título,
    # imagen y autoría). La imagen está pendiente: hasta tenerla se muestra el
    # marcador IMAGEN PORTADA. El <h1> fija además el string-set de doc-title
    # que aparece en la cabecera del resto de páginas.
    return f"""
<section id="cover">
  <img class="cover-logo" src="{logo}" alt="Echidna Educación">
  <div class="cover-title">
    <h1>{site_title}</h1>
    <p class="cover-subtitle">Primeros pasos con la placa EchidnaBlack2 y Arduino IDE</p>
  </div>
  <p class="cover-image-pendiente">IMAGEN PORTADA</p>
  <p class="cover-author">{site_author}</p>
</section>
"""


def render_toc(entries):
    items = "".join(
        f'<li class="toc-depth-{depth}"><a href="#{anchor}">{title}</a></li>'
        for depth, title, anchor in entries
    )
    return f"""
<section id="toc">
  <h1>Índice</h1>
  <ul class="toc-list">{items}</ul>
</section>
"""


def main():
    if not SITE_DIR.exists():
        raise SystemExit(f"No existe {SITE_DIR}. Ejecuta antes 'zensical build --clean'.")

    nav, site_title, site_author = load_nav()

    pages = ordered_pages(nav)
    url_to_id = {site_url_of(path): slugify_page(path) for _, path in pages}

    body_parts = []
    toc_entries = []
    for depth, md_path in pages:
        fragment, toc_entry = render_page(depth, md_path, url_to_id)
        body_parts.append(fragment)
        if toc_entry:
            toc_entries.append(toc_entry)

    document_html = (
        "<!doctype html><html lang=\"es\"><head><meta charset=\"utf-8\">"
        f"<title>{site_title}</title></head><body>"
        f"{render_cover(site_title, site_author)}{render_toc(toc_entries)}{''.join(body_parts)}"
        "</body></html>"
    )

    base_url = SITE_DIR.as_uri() + "/"
    # font_config debe pasarse tanto al parsear el CSS (donde se registran
    # las reglas @font-face) como a write_pdf (donde se usan al maquetar);
    # si solo se pasa a uno de los dos, WeasyPrint ignora @font-face en
    # silencio y cae a su fuente por defecto (DejaVu Sans).
    font_config = FontConfiguration()
    print_css = CSS(filename=str(PRINT_CSS_PATH), font_config=font_config)
    HTML(string=document_html, base_url=base_url).write_pdf(
        OUTPUT_PATH, stylesheets=[print_css], font_config=font_config
    )
    print(f"PDF generado en {OUTPUT_PATH} ({len(pages)} páginas de contenido)")


if __name__ == "__main__":
    main()
