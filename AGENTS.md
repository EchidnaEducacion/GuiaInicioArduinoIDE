# AGENTS.md

Instrucciones para agentes de IA (Claude Code y similares) que trabajen en este repositorio.

## Qué es este proyecto

**Proyectos de inicio con Arduino**: proyectos sencillos para programar la
placa **EchidnaBlack2** con **Arduino IDE** (código C/C++), publicados con
[Zensical](https://zensical.org/) como sitio estático
(<https://echidnaeducacion.github.io/GuiaInicioArduino/>) y como PDF. Es el
equivalente de «Proyectos de inicio con EchidnaML»
(<https://github.com/EchidnaEducacion/GuiaInicioEchidnaML>), que programa la
placa con bloques, y sigue la misma estrategia (configuración, scripts y
estilos) que el manual de Echidna
(<https://github.com/EchidnaEducacion/manual>); si cambias algo de la
maquetación, comprueba si conviene hacer lo mismo allí.

No es un proyecto de software: es contenido editorial dirigido a docentes y
alumnado que empiezan con la placa.

## Convenciones editoriales

- **Idioma**: español, registro cercano (tuteo al alumnado), términos clave
  en **negrita**.
- **Estructura fija de cada proyecto**: `# N.M Título`, imagen de cabecera
  `{ .img-cabecera }`, `## 1. Qué vamos a hacer`,
  `### 1.1 Qué vamos a aprender`, `### 1.2 Qué vamos a usar`,
  `## 2. Programamos` y `## 3. Mejóralo`. Mantén este patrón al añadir un
  proyecto.
- **Qué vamos a usar (1.2)**: lista de componentes con su pin y, al final,
  **una única función o instrucción de Arduino**, la que introduce el
  proyecto (con su nombre entre comillas invertidas y sus parámetros
  explicados). Las que ya se presentaron en proyectos anteriores no se
  vuelven a explicar.
- **Programamos (2)**: el programa completo en un bloque ```` ```cpp ```` y
  después **Cómo funciona**, explicado por partes (variables y constantes,
  `setup()`, `loop()`...).
- **Mejóralo (3)**: tres propuestas numeradas, de menos a más difícil. Cada
  una termina con **Pista:** (información sobre cómo hacerlo: una función,
  un valor, una idea) y **Ayuda:** (el código de la solución, en bloque
  ```` ```cpp ```` sangrado 4 espacios dentro de la lista).
- **Introducción**: cómo instalar y abrir Arduino IDE, su entorno, la
  elección de placa y puerto, la estructura `setup()`/`loop()`, cómo cargar
  un programa y la tabla de pines de la placa se explican **solo** en
  `docs/01-introduccion.md`. Los proyectos remiten allí.
- **Estructura por secciones**: `1. Introducción` (`docs/01-introduccion.md`),
  `2. Proyectos con Arduino` (`docs/02-arduino/`) y `3. Licencia`
  (`docs/03-licencia.md`). La sección de proyectos tiene un `index.md`
  (presentación y lista de proyectos) y los proyectos se numeran por
  sección (2.1, 2.2…). El número va en el `nav` y también en el `# Título`
  de la página (`# 2.1 Hola Mundo`, `# 2. Proyectos con Arduino`), para que
  el índice del PDF salga numerado; si reordenas, renumera ambos.
- **Navegación**: `nav` en `zensical.toml` es la fuente de verdad del orden.
  Si añades, eliminas o reordenas un proyecto, actualiza a la vez `nav`, la
  lista de `docs/02-arduino/index.md`, la de `docs/index.md` y la del
  `README.md`. Los ficheros de proyecto se nombran `NN-nombre.md` dentro de
  la carpeta de su sección.
- **Sin emojis**: WeasyPrint no los coloca bien en el PDF (aparecen como un
  punto suelto en el margen superior). No los reintroduzcas.
- **Markdown estricto (Python-Markdown)**: las listas necesitan una línea en
  blanco antes y las listas anidadas 4 espacios de sangría; con 2 o 3
  espacios, o sin línea en blanco, GitHub las muestra bien pero la web y el
  PDF no. Lo mismo para los bloques de código dentro de una lista: 4
  espacios.
- **Imágenes**: viven en `docs/assets/images/` (sin subcarpetas), siempre en
  local (no enlaces a GitHub), referenciadas con ruta relativa y el `title`
  repitiendo el `alt`:
  `![Descripción](../assets/images/Nombre.png "Descripción")` desde las
  carpetas de sección (`assets/images/...` sin `../` solo en las páginas de
  `docs/`). Ancho explícito opcional con `{ width="N" }` (en el PDF no tiene
  efecto porque `print.css` fija `width: auto`, y limita la altura a
  95 mm). Clases disponibles (ver `extra.css`/`print.css`):
    - `.img-cabecera`: imagen de cabecera de cada proyecto (18rem en la
      web, 80 mm en el PDF).
    - `.img-lupa`: detalles con lupa (`Lupa_*.png`), mismo tamaño reducido
      (26rem en la web, 100 mm en el PDF).
    - `.img-row` e `.img-text-row`: imágenes en fila, o imagen y texto.
    - `.solo-web`: se ve en la web y se oculta en el PDF (GIF y vídeos).
- Los marcadores provisionales en mayúsculas (`IMAGEN ...`, `VIDEO ...`,
  `IMAGEN PORTADA`...) son contenido pendiente del autor: no los elimines
  ni los inventes.

## Reglas del código

- Bloques con ```` ```cpp ````; el programa de `## 2. Programamos` va
  completo, listo para copiar y cargar.
- Comentarios en español, breves, que expliquen la intención.
- Nombres de variables claros en español y en camelCase (`ledRojo`,
  `valorLuz`, `umbral`).
- Pines siempre como constantes al principio del programa:
  `const int ledRojo = ...;`. Nunca números de pin sueltos en el código.
- Sin librerías salvo que hagan falta (por ejemplo, para el acelerómetro
  I2C); si se usan, se explica cómo instalarlas.
- Los pines, la placa, el procesador y el bootloader salen de la tabla de
  la introducción, que da el autor: no los inventes.
- Cada programa (y cada **Ayuda**) debe compilar:
  `arduino-cli compile --fqbn arduino:avr:nano <carpeta>` (el `.ino` debe
  llamarse como su carpeta).

## Estructura del repositorio

- `zensical.toml`: configuración del sitio y navegación (`nav`).
- `docs/`: contenido Markdown (`index.md` es la página de inicio web y no
  entra en el PDF).
- `docs/assets/images/`, `docs/assets/fonts/` (Exo y Open Sans para el PDF),
  `docs/assets/stylesheets/extra.css` (identidad visual de la web).
- `scripts/guia_nav.py`: recorrido común del `nav` (usa `tomllib`: Python
  3.11 o superior).
- `scripts/build_pdf.py` + `scripts/print.css`: generan
  `site/proyectos-inicio-arduino.pdf` uniendo todas las páginas ya
  construidas en un único documento (portada maquetada en HTML, índice con
  página real de secciones y proyectos, un salto de página por sección y por
  proyecto). Requiere `zensical build --clean` previo.
- `.github/workflows/docs.yml`: publicación en GitHub Pages (web + PDF) al
  hacer push a `main`. `.gitlab-ci.yml`: GitLab Pages (sin PDF).

## Cómo comprobar los cambios

```bash
python3 -m venv .venv
source .venv/bin/activate
python -m pip install -r requirements.txt
zensical build --clean
python scripts/build_pdf.py
```

Revisa la web (`zensical serve`) y el PDF: imágenes visibles, listas y
bloques de código bien formados y posición correcta en la navegación.

## Licencia

Contenido bajo
[Creative Commons Reconocimiento-CompartirIgual 4.0](https://creativecommons.org/licenses/by-sa/4.0/).
Cualquier contenido nuevo debe ser compatible con esta licencia.
