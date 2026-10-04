# 1. Introducción

**EchidnaBlack2** es una **placa** con diversos componentes integrados (LED, pulsadores, zumbador, sensores...) pensada para aprender los fundamentos de la **programación** y la **robótica**. Su objetivo es fomentar el **pensamiento computacional** en Primaria, Secundaria, Bachillerato y F.P., y estimular la creatividad con proyectos prácticos que conectan el mundo digital y el analógico.

![EchidnaBlack2](assets/images/EchidnaBlack_2_perspectiva.jpg "EchidnaBlack2"){ width="330" }

Su microcontrolador es un **ATmega328P**, el mismo que el de **Arduino Nano**, así que podemos programarla con **Arduino IDE** escribiendo código en **C/C++**.

Te proponemos una serie de **proyectos sencillos** para dar tus primeros pasos. Cada proyecto presenta un componente de la placa y la instrucción de Arduino que lo controla.

Si quieres ampliar información, consulta el [Manual de EchidnaML y EchidnaBlack](https://echidnaeducacion.github.io/manual/) y la web del proyecto: [www.echidna.es](https://echidna.es/).

## Instalar Arduino IDE

INSTALACIÓN DE ARDUINO IDE

## Conectar la placa

PLACA, PROCESADOR, BOOTLOADER Y PUERTO EN ARDUINO IDE

## Estructura de un programa

ESTRUCTURA SETUP/LOOP

## Cargar un programa en la placa

CARGAR UN PROGRAMA

## Pines de la EchidnaBlack2

Cada componente de la placa está conectado a un **pin** del microcontrolador. En los programas usaremos estos números para indicar con qué componente queremos trabajar:

| Componente | Pin |
|---|---|
| LED rojo | D13 |
| LED naranja | D12 |
| LED verde | D11 |
| LED RGB: rojo / verde / azul | D9 / D5 / D6 (PWM) |
| Zumbador | D10 |
| Pulsador SR (derecho) | D2 |
| Pulsador SL (izquierdo) | D3 |
| Joystick: eje X / eje Y | A0 / A1 |
| Sensor de luz (LDR) | A3 |
| Sensor de temperatura | A6 |
| Micrófono | A7 |
| Acelerómetro | I2C: A4 (SDA) / A5 (SCL) |

En el código, los pines digitales se escriben solo con su número (`13`) y los analógicos con la letra A (`A3`).
