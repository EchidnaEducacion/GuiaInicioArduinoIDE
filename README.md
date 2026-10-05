# Proyectos de inicio con Arduino — proyecto Zensical

Proyectos sencillos para iniciarse en la programación de la placa
EchidnaBlack2 con Arduino IDE (C/C++). Se publican como sitio web estático
con [Zensical](https://zensical.org/) en
<https://echidnaeducacion.github.io/GuiaInicioArduinoIDE/> y como PDF maquetado
con [WeasyPrint](https://weasyprint.org/), con la misma estrategia que el
[manual de EchidnaBlack y EchidnaML](https://github.com/EchidnaEducacion/manual)
y que [Proyectos de inicio con EchidnaML](https://github.com/EchidnaEducacion/GuiaInicioEchidnaML).

## Estructura

### 1. Introducción

[Introducción](docs/01-introduccion.md): EchidnaBlack2, instalación de
Arduino IDE, conexión de la placa, estructura de un programa y pines.

### 2. Proyectos con Arduino

[Presentación de la sección](docs/02-arduino/index.md).

1. [Hola Mundo](docs/02-arduino/01-hola-mundo.md)
2. [Semáforo](docs/02-arduino/02-semaforo.md)
3. [Interruptor de luz](docs/02-arduino/03-interruptor-de-luz.md)
4. [Timbre](docs/02-arduino/04-timbre.md)
5. [Interruptor crepuscular](docs/02-arduino/05-interruptor-crepuscular.md)
6. [Piano de frutas](docs/02-arduino/06-piano-de-frutas.md)
7. [El echidna dice la temperatura](docs/02-arduino/07-echidna-dice-temperatura.md)
8. [Mezclamos colores](docs/02-arduino/08-mezclamos-colores.md)

### 3. Licencia

[Licencia](docs/03-licencia.md).

Todos los proyectos siguen la misma estructura: `1. Qué vamos a hacer` (con
`1.1 Qué vamos a aprender` y `1.2 Qué vamos a usar`),
`2. Programamos` y `3. Mejóralo`.

## Requisitos

- Python 3.11 o superior
- `pip`

## Vista previa local

```bash
python3 -m venv .venv
source .venv/bin/activate
python -m pip install -r requirements.txt
zensical serve
```

Si tu sistema no tiene Python 3.11 o superior (por ejemplo, Ubuntu 22.04),
puedes crear el entorno con [uv](https://docs.astral.sh/uv/), que descarga
el Python necesario sin tocar el del sistema:

```bash
uv venv --python 3.12 .venv
uv pip install --python .venv -r requirements.txt
source .venv/bin/activate
zensical serve
```

En Windows, active el entorno con `.venv\Scripts\activate`.
La terminal mostrará la dirección local de la vista previa.

## Generar el sitio estático

```bash
zensical build --clean
```

El sitio resultante se guarda en `site/`. Puede publicarse con cualquier
servidor web estático.

## Generar el PDF

```bash
python scripts/build_pdf.py
```

Requiere haber ejecutado antes `zensical build --clean`. El script une el
contenido de todas las páginas (en el orden del `nav` de `zensical.toml`) en
un único documento y lo maqueta con WeasyPrint usando `scripts/print.css`:
portada, índice con numeración de página real y un salto de página al
empezar cada proyecto. Genera `site/proyectos-inicio-arduino.pdf`.

En Debian/Ubuntu, WeasyPrint necesita estas bibliotecas del sistema y, si
`pip` no encuentra una rueda precompilada de `lxml` para tu Python, hacen
falta además las cabeceras de desarrollo de `libxml2`/`libxslt`:

```bash
sudo apt install libpango-1.0-0 libpangoft2-1.0-0 libharfbuzz-subset0 libxml2-dev libxslt1-dev
```

El flujo de GitHub Actions instala estas dependencias y genera el PDF en
cada publicación, por lo que queda disponible en
`<sitio>/proyectos-inicio-arduino.pdf` (enlazado desde la página de inicio).

## Comprobar los programas

Cada programa debe compilar para Arduino Nano (ATmega328P, Old Bootloader) con
[arduino-cli](https://arduino.github.io/arduino-cli/):

```bash
arduino-cli core install arduino:avr
arduino-cli compile --fqbn arduino:avr:nano:cpu=atmega328old <carpeta-del-programa>
```

## Licencia

Contenido bajo licencia
[Creative Commons Reconocimiento-CompartirIgual 4.0](https://creativecommons.org/licenses/by-sa/4.0/).
