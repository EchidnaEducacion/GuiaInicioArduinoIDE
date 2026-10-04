# 2.3 Interruptor de luz

![Imagen cabecera Interruptor de luz](../assets/images/Pulsadores.png "Imagen cabecera Interruptor de luz"){ .img-cabecera }

## 1. Qué vamos a hacer

Vamos a programar un sistema de encendido y apagado manual con dos botones:

* Al presionar el **pulsador derecho (SR)**, el **LED rojo** se encenderá.
* Al presionar el **pulsador izquierdo (SL)**, el **LED rojo** se apagará.

### 1.1 Qué vamos a aprender

* A leer **entradas digitales** (saber si un botón está presionado o no).
* A diferenciar claramente entre una **Entrada (Input)** y una **Salida (Output)** en robótica:
    * **Entrada (SR y SL):** Detecta la orden del usuario.
    * **Salida (LED rojo):** Produce la respuesta (luz).
* A tomar decisiones en el programa mediante la estructura condicional **`if ... else`** (si ... si no): si se cumple la condición se ejecuta una parte del programa y, si no, la otra.
* A utilizar **condicionales anidados** (un `if` dentro de otro).
* A guardar valores que cambian en **variables**.
* A controlar el estado de un actuador (LED) mediante eventos físicos (pulsaciones).

### 1.2 Qué vamos a usar

* **Pulsador SR (Switch Right / Derecho, pin 2):** Para encender el LED.
* **Pulsador SL (Switch Left / Izquierdo, pin 3):** Para apagar el LED.
* **LED rojo (pin 13):** Componente que cambia de estado según el botón pulsado.

![Pulsadores en EchidnaBlack2](../assets/images/Lupa_Pulsadores.png "Pulsadores en EchidnaBlack2"){ .img-lupa }

Los pines de los pulsadores son **entradas**, así que en `setup()` los configuramos con `pinMode(pin, INPUT)`. Para leer el estado de un pulsador usamos la función `digitalRead(pin)`:

* **pin**: el número del pin del pulsador (SR, el `2`; SL, el `3`).
* Devuelve `HIGH` si el pulsador está **pulsado** y `LOW` si **no** lo está.

## 2. Programamos

El programa comprueba si el pulsador derecho está presionado; en ese caso, enciende el LED rojo. Si no lo está y presionamos el pulsador izquierdo, el LED se apaga.

Escribe el siguiente código en Arduino IDE y cárgalo en la placa:

```arduino linenums="1"
// Interruptor de luz: SR enciende el LED rojo y SL lo apaga

const int pulsadorSR = 2;  // pulsador derecho conectado al pin 2
const int pulsadorSL = 3;  // pulsador izquierdo conectado al pin 3
const int ledRojo = 13;    // LED rojo conectado al pin 13

int estadoSR = LOW;  // guarda si SR está pulsado (HIGH) o no (LOW)
int estadoSL = LOW;  // guarda si SL está pulsado (HIGH) o no (LOW)

void setup() {
  pinMode(pulsadorSR, INPUT);  // los pulsadores son entradas
  pinMode(pulsadorSL, INPUT);
  pinMode(ledRojo, OUTPUT);    // el LED es una salida
}

void loop() {
  // lee el estado de los dos pulsadores
  estadoSR = digitalRead(pulsadorSR);
  estadoSL = digitalRead(pulsadorSL);

  if (estadoSR == HIGH) {
    digitalWrite(ledRojo, HIGH);  // SR pulsado: enciende el LED
  } else {
    if (estadoSL == HIGH) {
      digitalWrite(ledRojo, LOW);  // SL pulsado: apaga el LED
    }
  }
}
```

**Cómo funciona**:

**Las constantes** (líneas 3 a 5): guardan los pines de los dos pulsadores y del LED rojo.

**Las variables** (líneas 7 y 8): `estadoSR` y `estadoSL` guardan lo que leemos en cada pulsador. A diferencia de las constantes, su valor **cambia** mientras el programa funciona: `HIGH` si el pulsador está pulsado y `LOW` si no lo está.

**La función `setup()`** (líneas 10 a 14): configura los pines de los pulsadores como **entradas** (`INPUT`), porque la placa lee por ellos, y el del LED como **salida** (`OUTPUT`).

**La función `loop()`** (líneas 16 a 28): primero lee los dos pulsadores con `digitalRead` y guarda el resultado en las variables. Después decide qué hacer con `if ... else`. Entre los paréntesis del `if` va la **condición**: `estadoSR == HIGH` se cumple si SR está pulsado (con `==` comparamos si dos valores son iguales). El programa revisa continuamente:

```
SI el pulsador derecho (SR) está presionado:
    --> Enciende el LED rojo inmediatamente.

SI NO (es decir, si SR no está presionado el programa comprueba la segunda condición):
    SI el pulsador izquierdo (SL) está presionado:
        --> Apaga el LED rojo.
```

Si no pulsamos ninguno, el programa no cambia el LED, que se queda como estaba.

## 3. Mejóralo

Prueba a realizar algunas de las siguientes modificaciones al proyecto:

1. **Luz cruzada (biestable):** Añade el **LED verde** al programa para que funcionen de forma alterna:
    * Al pulsar **SR**: LED rojo encendido y LED verde apagado.
    * Al pulsar **SL**: LED rojo apagado y LED verde encendido.

    **Pista:** declara una constante para el LED verde (pin `11`), configúralo como salida y, dentro de cada `if`, cambia los dos LED.

    **Ayuda:** además de la constante y el `pinMode` del LED verde, cambia la función `loop()`:

    ```arduino
    void loop() {
      estadoSR = digitalRead(pulsadorSR);
      estadoSL = digitalRead(pulsadorSL);

      if (estadoSR == HIGH) {
        digitalWrite(ledRojo, HIGH);  // SR: rojo encendido
        digitalWrite(ledVerde, LOW);  //     verde apagado
      } else {
        if (estadoSL == HIGH) {
          digitalWrite(ledRojo, LOW);    // SL: rojo apagado
          digitalWrite(ledVerde, HIGH);  //     verde encendido
        }
      }
    }
    ```

2. **Los dos a la vez:** Haz que, si pulsas **SR y SL a la vez**, se encienda el **LED naranja**, y que se apague en cuanto sueltes alguno de los dos.

    **Pista:** para que se cumplan dos condiciones a la vez se usa `&&` («y»): `if (estadoSR == HIGH && estadoSL == HIGH)`. Usa un `else` para apagar el LED naranja cuando no se cumpla.

    **Ayuda:** declara la constante del LED naranja (pin `12`), configúralo como salida y añade al final de la función `loop()`:

    ```arduino
      // los dos pulsadores a la vez: LED naranja
      if (estadoSR == HIGH && estadoSL == HIGH) {
        digitalWrite(ledNaranja, HIGH);
      } else {
        digitalWrite(ledNaranja, LOW);
      }
    ```

3. **Pulsador con memoria (conmutador):** Programa un solo pulsador (por ejemplo, **SL**) para que funcione como el interruptor de la luz de tu habitación: la primera vez que lo pulsas enciende el LED, y al volverlo a pulsar lo apaga.

    **Pista:** necesitas una variable que recuerde si el LED está encendido o apagado, y esperar a que sueltes el pulsador antes de seguir con `while`, que repite lo que tiene dentro mientras se cumpla la condición.

    **Ayuda:** esta mejora es más compleja, así que te dejamos una posible solución:

    ```arduino linenums="1"
    // Pulsador con memoria: SL enciende y apaga el LED rojo

    const int pulsadorSL = 3;  // pulsador izquierdo conectado al pin 3
    const int ledRojo = 13;    // LED rojo conectado al pin 13

    int estadoLED = LOW;  // recuerda si el LED está apagado o encendido

    void setup() {
      pinMode(pulsadorSL, INPUT);
      pinMode(ledRojo, OUTPUT);
    }

    void loop() {
      if (digitalRead(pulsadorSL) == HIGH) {
        // cambia el LED al estado contrario
        if (estadoLED == LOW) {
          estadoLED = HIGH;
        } else {
          estadoLED = LOW;
        }
        digitalWrite(ledRojo, estadoLED);

        // espera a que sueltes el pulsador
        while (digitalRead(pulsadorSL) == HIGH) {
        }
        delay(50);  // evita los rebotes del pulsador al soltarlo
      }
    }
    ```

    La clave es la variable **`estadoLED`**, que recuerda si el LED está apagado (`LOW`) o encendido (`HIGH`). Cada vez que pulsamos **SL**, el programa cambia el LED al estado contrario y actualiza la variable. El bucle **`while`** hace que el programa espere a que soltemos el pulsador; sin él, mientras lo mantenemos pulsado el LED se encendería y apagaría muchas veces seguidas. El `delay(50)` final evita los **rebotes**: al soltar el pulsador, sus contactos pueden abrirse y cerrarse varias veces en pocos milisegundos.
