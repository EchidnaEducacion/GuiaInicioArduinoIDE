# 2.1 Hola Mundo

![Imagen cabecera Hola Mundo](../assets/images/Hola_Mundo.png "Imagen cabecera Hola Mundo"){ .img-cabecera }

## 1. Qué vamos a hacer

En este primer proyecto haremos que el **LED rojo** de la placa EchidnaBlack2 se encienda y se apague de forma continua (parpadeo).

![LED rojo parpadeando en EchidnaBlack2](../assets/images/Hola_Mundo_funcionamiento.gif "LED rojo parpadeando en EchidnaBlack2")

### 1.1 Qué vamos a aprender

* A crear nuestro primer programa en Arduino IDE.
* A utilizar la función `loop()`, que se repite para siempre, para realizar una **programación cíclica** (tareas que se repiten sin fin).
* A controlar el estado (encendido/apagado) de un componente de la placa.

### 1.2 Qué vamos a usar

#### Componentes

* **LED rojo (pin 13):** Se enciende y se apaga para crear el parpadeo.

![LED en EchidnaBlack2](../assets/images/Lupa_Ledes.png "LED en EchidnaBlack2"){ .img-lupa }

#### Programación

Para encender y apagar los LED usamos la función `digitalWrite(pin, valor)`:

* **pin**: el número del pin al que está conectado el LED (el rojo, el `13`).
* **valor**: `HIGH` para **encender** el LED (el pin da 5 V) o `LOW` para **apagarlo** (el pin da 0 V).

## 2. Programamos

Este programa utiliza un bucle continuo para ejecutar la siguiente secuencia lógica, creando un parpadeo constante en el LED rojo.

Escribe el siguiente código en Arduino IDE y cárgalo en la placa:

```arduino linenums="1"
// Hola Mundo: enciende y apaga el LED rojo cada segundo

const int ledRojo = 13;  // LED rojo conectado al pin 13

// setup() se ejecuta una sola vez, al encender la placa
void setup() {
  pinMode(ledRojo, OUTPUT);  // el pin del LED es una salida
}

// loop() se repite una y otra vez, para siempre
void loop() {
  digitalWrite(ledRojo, HIGH);  // enciende el LED
  delay(1000);                  // espera 1 segundo (1000 ms)
  digitalWrite(ledRojo, LOW);   // apaga el LED
  delay(1000);                  // espera 1 segundo
}
```

**Cómo funciona**:

Las líneas que empiezan por `//` son **comentarios**: explican el programa a las personas que lo leen y la placa no las ejecuta.

**La constante `ledRojo`** (línea 3): guarda el número del pin del LED rojo. Así, en el resto del programa escribimos `ledRojo` en lugar de `13`, el código se entiende mejor y, si cambiara el pin, solo tendríamos que cambiarlo en un sitio.

**La función `setup()`** (líneas 6 a 8): se ejecuta **una sola vez**, al encender la placa o al cargar el programa. Con `pinMode(ledRojo, OUTPUT)` indicamos que el pin del LED es una **salida**: la placa va a enviar señales por él.

**La función `loop()`** (líneas 11 a 16): crea un ciclo infinito que ejecuta los pasos en orden, de arriba a abajo:

1. **`digitalWrite(ledRojo, HIGH)`**: Envía la señal para encender el LED.
2. **`delay(1000)`**: Mantiene el LED encendido durante un segundo. El tiempo de `delay` se indica en **milisegundos** (1000 ms = 1 s).
3. **`digitalWrite(ledRojo, LOW)`**: Envía la señal para apagar el LED.
4. **`delay(1000)`**: Mantiene el LED apagado durante un segundo antes de volver al paso 1.

## 3. Mejóralo

Una vez que consigas hacer parpadear el LED, prueba a realizar estas modificaciones por tu cuenta:

1. **Ritmo rápido:** Cambia el tiempo de espera a `0.2` segundos. ¿Qué le ocurre al parpadeo? ¿Qué ocurre si sigues bajando el tiempo de espera?

    **Pista:** recuerda que `delay` cuenta en milisegundos: 0,2 segundos son `200`.

    **Ayuda:** solo cambia la función `loop()`:

    ```arduino
    void loop() {
      digitalWrite(ledRojo, HIGH);  // enciende el LED
      delay(200);                   // espera 0,2 segundos
      digitalWrite(ledRojo, LOW);   // apaga el LED
      delay(200);                   // espera 0,2 segundos
    }
    ```

2. **Sombra de señal:** Intenta que el LED esté encendido mucho tiempo (`2` segundos) y apagado muy poco tiempo (`0.1` segundos).

    **Pista:** cada `delay` controla una fase: el primero, cuánto tiempo está encendido el LED, y el segundo, cuánto tiempo está apagado.

    **Ayuda:** solo cambia la función `loop()`:

    ```arduino
    void loop() {
      digitalWrite(ledRojo, HIGH);  // enciende el LED
      delay(2000);                  // encendido 2 segundos
      digitalWrite(ledRojo, LOW);   // apaga el LED
      delay(100);                   // apagado 0,1 segundos
    }
    ```

3. **Parpadeo alterno:** Haz que el LED rojo y el LED verde se enciendan por turnos: cuando uno está encendido, el otro está apagado.

    **Pista:** declara otra constante para el LED verde (pin `11`) y no olvides indicar en `setup()` que su pin también es una salida.

    **Ayuda:**

    ```arduino linenums="1"
    // Parpadeo alterno: el LED rojo y el verde se encienden por turnos

    const int ledRojo = 13;   // LED rojo conectado al pin 13
    const int ledVerde = 11;  // LED verde conectado al pin 11

    void setup() {
      pinMode(ledRojo, OUTPUT);   // el pin del LED rojo es una salida
      pinMode(ledVerde, OUTPUT);  // el pin del LED verde es una salida
    }

    void loop() {
      digitalWrite(ledRojo, HIGH);  // enciende el rojo
      digitalWrite(ledVerde, LOW);  // apaga el verde
      delay(1000);                  // espera 1 segundo
      digitalWrite(ledRojo, LOW);   // apaga el rojo
      digitalWrite(ledVerde, HIGH); // enciende el verde
      delay(1000);                  // espera 1 segundo
    }
    ```
