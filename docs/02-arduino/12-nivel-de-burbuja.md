# 2.12 Nivel de burbuja

IMAGEN CABECERA ACELERÓMETRO

## 1. Qué vamos a hacer

Vamos a convertir la placa en un **nivel de burbuja**, como el que usan los albañiles para comprobar si algo está recto. El **acelerómetro** medirá cuánto inclinamos la placa y la luz se moverá por la columna de LED (verde, naranja, rojo y el azul del LED RGB): con la placa horizontal, todos apagados; al inclinarla un poco, se enciende uno de los LED del centro, y al inclinarla mucho, uno de los extremos.

### 1.1 Qué vamos a aprender

* Qué mide un **acelerómetro**: la **gravedad** en cada uno de sus ejes, que cambia al inclinar la placa.
* A instalar y usar una **librería**, un conjunto de instrucciones ya programadas para manejar un componente.
* A repasar el condicional **`if ... else if ... else`** para elegir entre varios casos.

### 1.2 Qué vamos a usar

#### Componentes

* **Acelerómetro (I2C, pines A4 y A5):** Mide la aceleración en tres ejes (X, Y y Z). Con la placa quieta, lo único que mide es la **gravedad**, así que nos dice hacia dónde está inclinada. Se comunica con el microcontrolador por **I2C**, una conexión de dos cables (SDA en A4 y SCL en A5).
* **LED verde (pin 11), naranja (pin 12) y rojo (pin 13)** y el **azul del LED RGB (pin 6):** Forman la columna por la que se mueve la luz.

![Acelerómetro en EchidnaBlack2](../assets/images/Lupa_acelerometro.png "Acelerómetro en EchidnaBlack2"){ .img-lupa }

#### Programación

El acelerómetro no se lee con `analogRead`: envía sus medidas por I2C y entenderlas a mano sería complicado. Para eso usamos una **librería**, que ya trae programadas las instrucciones para manejarlo. Antes de usarla hay que instalarla en Arduino IDE, una sola vez:

1. Abre el menú **Herramientas > Gestionar bibliotecas**.
2. Busca **Adafruit LIS3DH** (LIS3DH es el modelo del acelerómetro de la placa).
3. Pulsa **Instalar** y, cuando pregunte si quieres instalar también las librerías que necesita, elige **Instalar todo**.

Después, en el programa usamos la librería así:

* **`#include <Adafruit_LIS3DH.h>`**: al principio del programa, añade la librería.
* **`Adafruit_LIS3DH acelerometro;`**: crea el **acelerómetro** en el programa, con el nombre que elijamos (aquí, `acelerometro`).
* **`acelerometro.begin(0x18)`**: en `setup()`, pone en marcha el acelerómetro. `0x18` es su **dirección** en la conexión I2C.
* **`acelerometro.read()`**: en `loop()`, lee el acelerómetro.
* **`acelerometro.y_g`**: después de leer, nos da la aceleración del **eje Y** en **g** (la gravedad de la Tierra): unos `0` con la placa horizontal, que crece hacia `1` al inclinarla hacia un lado y baja hacia `-1` al inclinarla hacia el otro. Igual, `acelerometro.x_g` y `acelerometro.z_g` dan los ejes X y Z.

Como la medida tiene decimales, la guardamos en una variable de tipo `float`.

## 2. Programamos

El programa lee continuamente la inclinación del eje Y y, con varios `else if`, enciende el LED que le corresponde: verde o naranja hacia un lado, ninguno en horizontal, y rojo o azul hacia el otro.

Escribe el siguiente código en Arduino IDE y cárgalo en la placa:

```arduino linenums="1"
// Nivel de burbuja: la luz se mueve por los LED al inclinar la placa

#include <Adafruit_LIS3DH.h>  // librería del acelerómetro

const int rgbAzul = 6;      // LED RGB: color azul en el pin 6
const int ledVerde = 11;    // LED verde conectado al pin 11
const int ledNaranja = 12;  // LED naranja conectado al pin 12
const int ledRojo = 13;     // LED rojo conectado al pin 13

const float inclinacionPoca = 0.2;   // algo inclinada (en g)
const float inclinacionMucha = 0.6;  // muy inclinada (en g)

Adafruit_LIS3DH acelerometro;  // el acelerómetro de la placa

float inclinacion = 0.0;  // guarda la aceleración del eje Y, en g

void setup() {
  pinMode(rgbAzul, OUTPUT);  // los LED son salidas
  pinMode(ledVerde, OUTPUT);
  pinMode(ledNaranja, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  acelerometro.begin(0x18);  // pone en marcha el acelerómetro
}

void loop() {
  // lee el acelerómetro y guarda la inclinación del eje Y
  acelerometro.read();
  inclinacion = acelerometro.y_g;

  if (inclinacion < -inclinacionMucha) {
    // muy inclinada hacia un lado: LED verde
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledNaranja, LOW);
    digitalWrite(ledRojo, LOW);
    digitalWrite(rgbAzul, LOW);
  } else if (inclinacion < -inclinacionPoca) {
    // algo inclinada hacia ese lado: LED naranja
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledNaranja, HIGH);
    digitalWrite(ledRojo, LOW);
    digitalWrite(rgbAzul, LOW);
  } else if (inclinacion < inclinacionPoca) {
    // horizontal: todos apagados
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledNaranja, LOW);
    digitalWrite(ledRojo, LOW);
    digitalWrite(rgbAzul, LOW);
  } else if (inclinacion < inclinacionMucha) {
    // algo inclinada hacia el otro lado: LED rojo
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledNaranja, LOW);
    digitalWrite(ledRojo, HIGH);
    digitalWrite(rgbAzul, LOW);
  } else {
    // muy inclinada hacia el otro lado: azul del LED RGB
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledNaranja, LOW);
    digitalWrite(ledRojo, LOW);
    digitalWrite(rgbAzul, HIGH);
  }
}
```

**Cómo funciona**:

**La librería** (línea 3): `#include` añade al programa la librería del acelerómetro que hemos instalado.

**Las constantes** (líneas 5 a 11): guardan los pines de los cuatro LED y los dos umbrales de inclinación, `0.2` g (algo inclinada) y `0.6` g (muy inclinada). Son de tipo `float` porque tienen decimales.

**El acelerómetro y la variable** (líneas 13 y 15): `Adafruit_LIS3DH acelerometro;` crea el acelerómetro en el programa, y `inclinacion` guardará la medida del eje Y.

**La función `setup()`** (líneas 17 a 23): configura los pines de los LED como salidas y pone en marcha el acelerómetro con `acelerometro.begin(0x18)`.

**La función `loop()`** (líneas 25 a 61): lee el acelerómetro con `acelerometro.read()` y guarda en `inclinacion` el valor del eje Y. Después, como en el [Vúmetro](10-vumetro.md), una cadena de `if ... else if ... else` comprueba los casos en orden, de la inclinación más negativa a la más positiva, y ejecuta solo el primero que se cumple. Fíjate en que `-inclinacionMucha` es el umbral con el signo cambiado, `-0.6`:

```
SI la inclinación es menor que -0.6:
    --> Enciende el LED verde.
SI NO, SI es menor que -0.2:
    --> Enciende el LED naranja.
SI NO, SI es menor que 0.2 (está casi horizontal):
    --> Apaga todos los LED.
SI NO, SI es menor que 0.6:
    --> Enciende el LED rojo.
SI NO (es 0.6 o más):
    --> Enciende el azul del LED RGB.
```

Como el verde, el naranja, el rojo y el LED RGB están uno encima de otro en la placa, al inclinarla la luz se desplaza por la columna, como la burbuja de un nivel.

## 3. Mejóralo

Prueba a realizar algunas de las siguientes modificaciones al proyecto:

1. **Lee el acelerómetro:** Mira cómo cambian los valores de los ejes X e Y cuando inclinas la placa hacia delante, hacia atrás y hacia los lados.

    **Pista:** envía los dos valores al ordenador y ábrelos con el **Serial Plotter**, como en la primera mejora del [Regulador de luz con joystick](11-regulador-de-luz.md): escribe `X:` antes del valor del eje X e `Y:` antes del valor del eje Y. Los ejes del acelerómetro se leen con `acelerometro.x_g` y `acelerometro.y_g`.

    **Ayuda:** este programa solo lee el acelerómetro y envía los ejes X e Y al ordenador:

    ```arduino linenums="1"
    // Lee el acelerómetro: dibuja los ejes X e Y en el Serial Plotter

    #include <Adafruit_LIS3DH.h>  // librería del acelerómetro

    Adafruit_LIS3DH acelerometro;  // el acelerómetro de la placa

    void setup() {
      Serial.begin(9600);        // abre la comunicación a 9600 baudios
      acelerometro.begin(0x18);  // pone en marcha el acelerómetro
    }

    void loop() {
      acelerometro.read();  // lee el acelerómetro

      Serial.print("X:");                // nombre del eje X
      Serial.print(acelerometro.x_g);    // valor del eje X
      Serial.print(" Y:");               // nombre del eje Y
      Serial.println(acelerometro.y_g);  // valor del eje Y y salto de línea

      delay(100);  // diez medidas por segundo
    }
    ```

2. **Alarma de caída:** Haz que el **zumbador** pite cuando la placa esté muy inclinada, hacia cualquiera de los dos lados.

    **Pista:** el zumbador está en el pin `10` y suena con `analogWrite(zumbador, 125)`. Para comprobar si se cumple **una u otra** condición usa `||` («o»), como en el theremín del [Regulador de luz con joystick](11-regulador-de-luz.md): `if (inclinacion > inclinacionMucha || inclinacion < -inclinacionMucha)`.

    **Ayuda:** declara la constante del zumbador (pin `10`), configúralo como salida en `setup()` y añade al final de la función `loop()`:

    ```arduino
      // muy inclinada hacia cualquier lado: suena la alarma
      if (inclinacion > inclinacionMucha || inclinacion < -inclinacionMucha) {
        analogWrite(zumbador, 125);
      } else {
        analogWrite(zumbador, 0);
      }
    ```

3. **La luz que rueda:** Haz que la luz **ruede** por los cuatro LED hacia el lado al que inclinas la placa: mientras está inclinada, pasa de un LED al siguiente y, al llegar al último, vuelve a empezar por el otro extremo. Con la placa horizontal, la luz se queda quieta.

    **Pista:** usa una variable `posicion` que diga qué LED está encendido (`1` el verde, `2` el naranja, `3` el rojo y `4` el azul). En cada vuelta de `loop()`, súmale `1` si la placa está inclinada hacia un lado y réstale `1` si lo está hacia el otro. Si pasa de `4`, vuelve a `1`, y si baja de `1`, pasa a `4`. Después, enciende solo el LED de esa posición y espera un poco con `delay` para que se vea el movimiento.

    **Ayuda:** esta mejora es más compleja, así que te dejamos una posible solución:

    ```arduino linenums="1"
    // La luz que rueda: la luz se desplaza por los LED hacia el lado inclinado

    #include <Adafruit_LIS3DH.h>  // librería del acelerómetro

    const int rgbAzul = 6;      // LED RGB: color azul en el pin 6
    const int ledVerde = 11;    // LED verde conectado al pin 11
    const int ledNaranja = 12;  // LED naranja conectado al pin 12
    const int ledRojo = 13;     // LED rojo conectado al pin 13

    const float inclinacionPoca = 0.2;  // inclinada (en g)
    const int espera = 200;             // tiempo entre un paso y el siguiente, en ms

    Adafruit_LIS3DH acelerometro;  // el acelerómetro de la placa

    float inclinacion = 0.0;  // guarda la aceleración del eje Y, en g
    int posicion = 1;         // LED encendido: 1 verde, 2 naranja, 3 rojo, 4 azul

    void setup() {
      pinMode(rgbAzul, OUTPUT);
      pinMode(ledVerde, OUTPUT);
      pinMode(ledNaranja, OUTPUT);
      pinMode(ledRojo, OUTPUT);
      acelerometro.begin(0x18);
    }

    void loop() {
      acelerometro.read();
      inclinacion = acelerometro.y_g;

      // la luz avanza hacia el lado inclinado
      if (inclinacion < -inclinacionPoca) {
        posicion = posicion - 1;
      } else if (inclinacion > inclinacionPoca) {
        posicion = posicion + 1;
      }

      // al pasar de un extremo, vuelve por el otro
      if (posicion > 4) {
        posicion = 1;
      }
      if (posicion < 1) {
        posicion = 4;
      }

      // enciende solo el LED de la posición actual
      if (posicion == 1) {
        digitalWrite(ledVerde, HIGH);
      } else {
        digitalWrite(ledVerde, LOW);
      }
      if (posicion == 2) {
        digitalWrite(ledNaranja, HIGH);
      } else {
        digitalWrite(ledNaranja, LOW);
      }
      if (posicion == 3) {
        digitalWrite(ledRojo, HIGH);
      } else {
        digitalWrite(ledRojo, LOW);
      }
      if (posicion == 4) {
        digitalWrite(rgbAzul, HIGH);
      } else {
        digitalWrite(rgbAzul, LOW);
      }

      delay(espera);
    }
    ```

    El operador `==` («igual a») compara dos valores. No hay que confundirlo con `=`, que **guarda** un valor en una variable.
