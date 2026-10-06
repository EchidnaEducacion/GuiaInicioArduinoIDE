# 2.5 Brillo LED

IMAGEN CABECERA BRILLO LED

## 1. Qué vamos a hacer

Vamos a hacer que el **LED RGB** de la placa se encienda **poco a poco** en color blanco, hasta brillar al máximo, y que después se apague también poco a poco, como la luz de un cine al empezar y terminar la película.

### 1.1 Qué vamos a aprender

* A utilizar el **LED RGB** y a encender sus tres colores a la vez para conseguir luz **blanca**.
* A regular el **brillo** de un LED con valores de `0` a `255` mediante **PWM** con `analogWrite`.
* A repetir instrucciones un número de veces con el bucle **`for`**, contando hacia arriba y hacia abajo.

### 1.2 Qué vamos a usar

#### Componentes

* **LED RGB (pines 9, 5 y 6):** Componente que tiene dentro tres LED: uno **rojo** (R, *Red*, pin 9), uno **verde** (G, *Green*, pin 5) y uno **azul** (B, *Blue*, pin 6). Si los encendemos los tres con el mismo brillo, sus luces se mezclan y vemos luz **blanca**.

![LED RGB en EchidnaBlack2](../assets/images/Lupa_LEDRGB.png "LED RGB en EchidnaBlack2"){ .img-lupa }

#### Programación

En el proyecto [Timbre](04-timbre.md) usamos `analogWrite` para hacer sonar el zumbador. Los pines del LED RGB también son de tipo **Digital/Analógico** (ver la tabla de pines de la [Introducción](../01-introduccion.md)), así que con `analogWrite` podemos darle a cada color un **brillo** entre `0` (apagado) y `255` (brillo máximo); con `128`, por ejemplo, luce a media potencia. La señal **PWM** enciende y apaga el LED tan deprisa que no vemos el parpadeo: cuanto más tiempo está encendido en cada parpadeo, más brillante lo vemos.

Para que el brillo cambie poco a poco tendríamos que escribir 256 `analogWrite` seguidos, uno por cada valor. En lugar de eso, usamos el bucle `for`, que repite las instrucciones que tiene entre llaves `{ }`:

```arduino
for (int brillo = 0; brillo <= 255; brillo = brillo + 1) {
  // instrucciones que se repiten
}
```

Entre los paréntesis tiene tres partes, separadas por punto y coma:

* **Inicio** (`int brillo = 0`): crea la variable que cuenta las vueltas y le da su primer valor.
* **Condición** (`brillo <= 255`): el bucle se repite mientras se cumpla. El operador `<=` significa «menor o igual que».
* **Incremento** (`brillo = brillo + 1`): cómo cambia la variable al final de cada vuelta; aquí, suma `1`.

## 2. Programamos

El programa tiene dos bucles `for`, uno detrás de otro: el primero sube el brillo del LED RGB de `0` a `255` y el segundo lo baja de `255` a `0`. Al terminar, el LED se queda apagado un segundo y todo vuelve a empezar.

Escribe el siguiente código en Arduino IDE y cárgalo en la placa:

```arduino linenums="1"
// Brillo LED: el LED RGB se enciende y se apaga poco a poco en color blanco

const int rgbRojo = 9;   // LED RGB: color rojo en el pin 9
const int rgbVerde = 5;  // LED RGB: color verde en el pin 5
const int rgbAzul = 6;   // LED RGB: color azul en el pin 6

const int espera = 10;  // tiempo entre un brillo y el siguiente, en milisegundos

void setup() {
  pinMode(rgbRojo, OUTPUT);  // los tres colores del LED RGB son salidas
  pinMode(rgbVerde, OUTPUT);
  pinMode(rgbAzul, OUTPUT);
}

void loop() {
  // encendido gradual: el brillo sube de 0 a 255
  for (int brillo = 0; brillo <= 255; brillo = brillo + 1) {
    analogWrite(rgbRojo, brillo);
    analogWrite(rgbVerde, brillo);
    analogWrite(rgbAzul, brillo);
    delay(espera);
  }

  // apagado gradual: el brillo baja de 255 a 0
  for (int brillo = 255; brillo >= 0; brillo = brillo - 1) {
    analogWrite(rgbRojo, brillo);
    analogWrite(rgbVerde, brillo);
    analogWrite(rgbAzul, brillo);
    delay(espera);
  }

  delay(1000);  // espera 1 segundo con el LED apagado
}
```

**Cómo funciona**:

**Las constantes** (líneas 3 a 7): guardan los pines de los tres colores del LED RGB y la **espera**, el tiempo que pasa entre un brillo y el siguiente.

**La función `setup()`** (líneas 9 a 13): configura los tres pines del LED RGB como **salidas**.

**La función `loop()`** (líneas 15 a 33): tiene dos bucles `for` seguidos.

* **El primer bucle** (líneas 17 a 22) crea la variable `brillo` con el valor `0` y, en cada vuelta, enciende los tres colores con ese brillo, espera 10 milisegundos y suma `1`. Se repite mientras `brillo` sea menor o igual que `255`, así que da 256 vueltas y el LED pasa de apagado a brillo máximo en unos 2,5 segundos.
* **El segundo bucle** (líneas 25 a 30) hace lo contrario: empieza en `255` y, en cada vuelta, **resta** `1` (`brillo = brillo - 1`). Se repite mientras `brillo` sea mayor o igual que `0` (el operador `>=` significa «mayor o igual que»), así que el LED se va apagando poco a poco.

Al final, `delay(1000)` deja el LED apagado un segundo antes de que `loop()` vuelva a empezar:

```
PARA cada brillo de 0 a 255:
    --> Enciende el LED RGB en blanco con ese brillo.
    --> Espera 10 milisegundos.

PARA cada brillo de 255 a 0:
    --> Enciende el LED RGB en blanco con ese brillo.
    --> Espera 10 milisegundos.

Espera 1 segundo con el LED apagado.
```

La variable `brillo` se crea dentro de cada `for` y solo existe mientras dura ese bucle, por eso podemos usar el mismo nombre en los dos.

## 3. Mejóralo

Prueba a realizar algunas de las siguientes modificaciones al proyecto:

1. **Respiración lenta:** Haz que el LED se encienda y se apague mucho más despacio, como si respirara tranquilamente. ¿Y si lo quieres muy rápido?

    **Pista:** la constante `espera` marca cuánto dura cada uno de los 256 pasos. Con `30` milisegundos, cada subida dura unos 7,7 segundos; con `2`, apenas medio segundo.

    **Ayuda:** cambia solo la constante:

    ```arduino
    const int espera = 30;  // tiempo entre un brillo y el siguiente, en milisegundos
    ```

2. **Dos colores:** En lugar de blanco, haz que primero se encienda y se apague poco a poco el **rojo**, y después el **azul**.

    **Pista:** necesitas cuatro bucles `for` seguidos: subir y bajar el rojo, y subir y bajar el azul. Dentro de cada bucle, usa `analogWrite` solo con el color que corresponde.

    **Ayuda:** cambia la función `loop()`:

    ```arduino
    void loop() {
      // el rojo se enciende y se apaga poco a poco
      for (int brillo = 0; brillo <= 255; brillo = brillo + 1) {
        analogWrite(rgbRojo, brillo);
        delay(espera);
      }
      for (int brillo = 255; brillo >= 0; brillo = brillo - 1) {
        analogWrite(rgbRojo, brillo);
        delay(espera);
      }

      // el azul se enciende y se apaga poco a poco
      for (int brillo = 0; brillo <= 255; brillo = brillo + 1) {
        analogWrite(rgbAzul, brillo);
        delay(espera);
      }
      for (int brillo = 255; brillo >= 0; brillo = brillo - 1) {
        analogWrite(rgbAzul, brillo);
        delay(espera);
      }
    }
    ```

3. **Regulador de brillo:** Usa los pulsadores como el regulador de luz de una lámpara: mientras mantienes pulsado **SR**, el LED blanco brilla cada vez más, y mientras mantienes pulsado **SL**, brilla cada vez menos.

    **Pista:** ahora no hace falta un `for`: declara una variable global `brillo` y, en cada vuelta de `loop()`, súmale `1` si SR está pulsado y réstale `1` si lo está SL. Para que no se salga de los valores de `analogWrite`, súmale solo si es menor que `255` y réstale solo si es mayor que `0`, con un `if` dentro de otro, como en el [Interruptor de luz](03-interruptor-de-luz.md).

    **Ayuda:** esta mejora es más compleja, así que te dejamos una posible solución:

    ```arduino linenums="1"
    // Regulador de brillo: SR sube el brillo del LED RGB y SL lo baja

    const int pulsadorSR = 2;  // pulsador derecho conectado al pin 2
    const int pulsadorSL = 3;  // pulsador izquierdo conectado al pin 3
    const int rgbRojo = 9;     // LED RGB: color rojo en el pin 9
    const int rgbVerde = 5;    // LED RGB: color verde en el pin 5
    const int rgbAzul = 6;     // LED RGB: color azul en el pin 6

    const int espera = 10;  // velocidad a la que cambia el brillo, en milisegundos

    int estadoSR = LOW;  // guarda si SR está pulsado (HIGH) o no (LOW)
    int estadoSL = LOW;  // guarda si SL está pulsado (HIGH) o no (LOW)
    int brillo = 0;      // guarda el brillo del LED (de 0 a 255)

    void setup() {
      pinMode(pulsadorSR, INPUT);
      pinMode(pulsadorSL, INPUT);
      pinMode(rgbRojo, OUTPUT);
      pinMode(rgbVerde, OUTPUT);
      pinMode(rgbAzul, OUTPUT);
    }

    void loop() {
      estadoSR = digitalRead(pulsadorSR);
      estadoSL = digitalRead(pulsadorSL);

      // SR pulsado: sube el brillo sin pasar de 255
      if (estadoSR == HIGH) {
        if (brillo < 255) {
          brillo = brillo + 1;
        }
      }

      // SL pulsado: baja el brillo sin bajar de 0
      if (estadoSL == HIGH) {
        if (brillo > 0) {
          brillo = brillo - 1;
        }
      }

      // enciende el LED en blanco con el brillo actual
      analogWrite(rgbRojo, brillo);
      analogWrite(rgbVerde, brillo);
      analogWrite(rgbAzul, brillo);

      delay(espera);
    }
    ```

    La variable `brillo` es **global** (se declara fuera de las funciones) para que **recuerde** su valor de una vuelta de `loop()` a la siguiente. Si sueltas los dos pulsadores, no cambia y el LED se queda con el último brillo.
