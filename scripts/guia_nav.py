"""Utilidades compartidas para recorrer el `nav` de zensical.toml.

Usado por build_pdf.py para mantener el mismo orden y la misma jerarquía
(profundidad de capítulo/subsección/página) en cualquier herramienta que
procese la guía completa.
"""

import re
import tomllib
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CONFIG_PATH = ROOT / "zensical.toml"
SITE_DIR = ROOT / "site"
DOCS_DIR = ROOT / "docs"


def load_nav():
    config = tomllib.loads(CONFIG_PATH.read_text(encoding="utf-8"))
    project = config["project"]
    return project["nav"], project["site_name"], project.get("site_author", "")


def walk_nav(nav, depth=0):
    """Aplana el nav en tuplas (profundidad, ruta .md)."""
    for entry in nav:
        for _title, value in entry.items():
            if isinstance(value, str):
                yield depth, value
            else:
                yield from walk_section(value, depth)


def walk_section(items, depth):
    for i, item in enumerate(items):
        if isinstance(item, str):
            is_index = Path(item).name == "index.md"
            yield (depth if i == 0 and is_index else depth + 1), item
        else:
            for _title, value in item.items():
                if isinstance(value, str):
                    yield depth + 1, value
                else:
                    yield from walk_section(value, depth + 1)


def ordered_pages(nav, include_home=False):
    """Lista [(depth, md_path), ...] en orden de lectura de la guía."""
    pages = list(walk_nav(nav))
    if not include_home:
        pages = [(d, p) for d, p in pages if p != "index.md"]
    return pages


def md_to_html(md_path: str) -> Path:
    relative = Path(md_path)
    if relative.name == "index.md":
        return SITE_DIR / relative.parent / "index.html"
    return SITE_DIR / relative.parent / relative.stem / "index.html"


def site_url_of(md_path: str) -> str:
    """Ruta 'limpia' equivalente a la que usa Zensical para enlazar entre páginas."""
    relative = Path(md_path)
    directory = relative.parent if relative.name == "index.md" else relative.parent / relative.stem
    posix = directory.as_posix()
    return "" if posix == "." else posix + "/"


def slugify_page(md_path: str) -> str:
    return "pg-" + re.sub(r"[^a-z0-9]+", "-", md_path.lower()).strip("-")
