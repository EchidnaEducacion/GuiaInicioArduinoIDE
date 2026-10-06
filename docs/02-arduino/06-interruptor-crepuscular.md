# 2.6 Interruptor crepuscular

![Imagen cabecera Interruptor crepuscular](../assets/images/Interruptor_crepuscular.png "Imagen cabecera Interruptor crepuscular"){ .img-cabecera }

## 1. Qué vamos a hacer

Vamos a programar un sistema automático similar al de las farolas de la calle: el **LED verde** se encenderá automáticamente cuando la luz ambiental baje (de noche) y se apagará cuando haya suficiente luz (de día).

### 1.1 Qué vamos a aprender

* A programar un **sistema automático** que reaccione al entorno.
* A utilizar el **sensor de luz (LDR)** para medir la iluminación ambiental.
* A leer **entradas analógicas**, que dan valores intermedios y no solo `HIGH` o `LOW`.
* A usar un **operador de comparación** (`<`) para que el condicional `if ... else` decida a partir de la lectura de un sensor.
* A trabajar con **umbrales numéricos** para definir estados (día/noche).

### 1.2 Qué vamos a usar

#### Componentes

* **Sensor de luz (LDR, pin A3):** Mide la cantidad de luz que recibe. Cuanto más oscuro esté el entorno, menor será el valor que leemos.
* **LED verde (pin 11):** Funcionará como nuestra luz automática.

![Sensor de luz (LDR) en EchidnaBlack2](../assets/images/Lupa_LDR.png "Sensor de luz (LDR) en EchidnaBlack2"){ .img-lupa }

#### Programación

El sensor de luz está en un pin de tipo **Analógico** (ver la tabla de pines de la [Introducción](../01-introduccion.md)). Para leerlo usamos la función `analogRead(pin)`:

* **pin**: el pin analógico del sensor, el `A3`.
* Devuelve un número entre **`0`** (no hay luz) y **`1023`** (mucha luz).

Los pines analógicos son **entradas** por defecto, así que no hace falta configurarlos con `pinMode`.

## 2. Programamos

El programa revisa continuamente el valor del sensor de luz: si es menor que un cierto **umbral**, enciende el LED; en caso contrario, lo apaga.

Escribe el siguiente código en Arduino IDE y cárgalo en la placa:

```arduino linenums="1"
// Interruptor crepuscular: el LED verde se enciende cuando hay poca luz

const int sensorLuz = A3;  // sensor de luz (LDR) conectado al pin A3
const int ledVerde = 11;   // LED verde conectado al pin 11

const int umbral = 200;  // por debajo de este valor consideramos que es de noche

int valorLuz = 0;  // guarda la luz que mide el sensor (de 0 a 1023)

void setup() {
  pinMode(ledVerde, OUTPUT);  // el LED es una salida
}

void loop() {
  // lee la cantidad de luz
  valorLuz = analogRead(sensorLuz);

  if (valorLuz < umbral) {
    digitalWrite(ledVerde, HIGH);  // poca luz (de noche): enciende el LED
  } else {
    digitalWrite(ledVerde, LOW);   // mucha luz (de día): apaga el LED
  }
}
```

**Cómo funciona**:

**Las constantes** (líneas 3 a 6): guardan los pines del sensor de luz y del LED verde, y el **umbral**, el valor que separa el día de la noche. Al tenerlo en una constante, si queremos ajustarlo solo hay que cambiar un número.

**La variable** (línea 8): `valorLuz` guarda la luz que mide el sensor, un número entre `0` y `1023`.

**La función `setup()`** (líneas 10 a 12): configura el pin del LED como **salida** (`OUTPUT`). El sensor no necesita `pinMode`, porque está en un pin analógico.

**La función `loop()`** (líneas 14 a 23): lee el sensor con `analogRead` y guarda el resultado en `valorLuz`. Después, con `if ... else`, lo compara con el umbral. El operador `<` («menor que») comprueba si `valorLuz` es más pequeño que `umbral`. El programa revisa continuamente:

```
SI el sensor de luz registra valores menores de 200:
    --> Se enciende el LED verde.

SI NO (si registra valores mayores o iguales a 200):
    --> Se apaga el LED verde.
```

El valor 200 actúa como el umbral que define cuándo debe encenderse o apagarse la luz.

## 3. Mejóralo

Prueba a realizar algunas de las siguientes modificaciones al proyecto:

1. **Calibra tu aula:** Averigua qué valor lee el sensor de luz en tu mesa y ajusta el umbral para que la luz se encienda solo cuando tapes el sensor con la mano.

    **Pista:** para ver el valor del sensor en el ordenador, abre la comunicación en `setup()` con `Serial.begin(9600)` y envía el valor en `loop()` con `Serial.println(valorLuz)`. Después de cargar el programa, abre el **Monitor serie** (menú **Herramientas > Monitor Serie**) con la velocidad en **9600 baudios**. Prueba con la mano encima y sin ella, y elige un umbral entre los dos valores.

    **Ayuda:** cambia las funciones `setup()` y `loop()`:

    ```arduino
    void setup() {
      pinMode(ledVerde, OUTPUT);
      Serial.begin(9600);  // abre la comunicación con el ordenador
    }

    void loop() {
      valorLuz = analogRead(sensorLuz);
      Serial.println(valorLuz);  // muestra el valor en el Monitor serie

      if (valorLuz < umbral) {
        digitalWrite(ledVerde, HIGH);
      } else {
        digitalWrite(ledVerde, LOW);
      }

      delay(200);  // espera un poco para poder leer los valores
    }
    ```

    Cuando sepas el valor, cambia el número de la constante `umbral`.

2. **Luz blanca:** Sustituye el LED verde por el **LED RGB** para que ilumine más: cuando haya oscuridad, se encenderá en color **blanco**, y cuando haya mucha luz, se apagará.

    **Pista:** el LED RGB tiene tres colores, cada uno en su pin: rojo en el `9`, verde en el `5` y azul en el `6`. Si encendemos los tres a la vez con `digitalWrite`, se mezclan y vemos luz **blanca**.

    **Ayuda:** esta mejora cambia varias partes del programa, así que te dejamos una posible solución:

    ```arduino linenums="1"
    // Linterna automática: el LED RGB se enciende en blanco cuando hay poca luz

    const int sensorLuz = A3;  // sensor de luz (LDR) conectado al pin A3
    const int rgbRojo = 9;     // LED RGB: color rojo en el pin 9
    const int rgbVerde = 5;    // LED RGB: color verde en el pin 5
    const int rgbAzul = 6;     // LED RGB: color azul en el pin 6

    const int umbral = 200;  // por debajo de este valor consideramos que es de noche

    int valorLuz = 0;  // guarda la luz que mide el sensor (de 0 a 1023)

    void setup() {
      pinMode(rgbRojo, OUTPUT);  // los tres colores del LED RGB son salidas
      pinMode(rgbVerde, OUTPUT);
      pinMode(rgbAzul, OUTPUT);
    }

    void loop() {
      valorLuz = analogRead(sensorLuz);

      if (valorLuz < umbral) {
        // poca luz: los tres colores encendidos dan luz blanca
        digitalWrite(rgbRojo, HIGH);
        digitalWrite(rgbVerde, HIGH);
        digitalWrite(rgbAzul, HIGH);
      } else {
        // mucha luz: LED RGB apagado
        digitalWrite(rgbRojo, LOW);
        digitalWrite(rgbVerde, LOW);
        digitalWrite(rgbAzul, LOW);
      }
    }
    ```

3. **Medidor de luz:** Convierte la placa en un medidor de luz: cuanta más luz haya, más LED se encenderán. Con muy poca luz, ninguno; con algo de luz, el **verde**; con bastante, el **verde** y el **naranja**; y con mucha luz, los tres (**verde**, **naranja** y **rojo**).

    **Pista:** necesitas varios umbrales (por ejemplo, `200`, `500` y `800`). Para comprobar varias condiciones una detrás de otra, usa `else if` («si no, si»): el programa comprueba cada condición en orden y ejecuta solo la primera que se cumple.

    **Ayuda:** esta mejora es más compleja, así que te dejamos una posible solución:

    ```arduino linenums="1"
    // Medidor de luz: cuanta más luz, más LED encendidos

    const int sensorLuz = A3;   // sensor de luz (LDR) conectado al pin A3
    const int ledVerde = 11;    // LED verde conectado al pin 11
    const int ledNaranja = 12;  // LED naranja conectado al pin 12
    const int ledRojo = 13;     // LED rojo conectado al pin 13

    int valorLuz = 0;  // guarda la luz que mide el sensor (de 0 a 1023)

    void setup() {
      pinMode(ledVerde, OUTPUT);
      pinMode(ledNaranja, OUTPUT);
      pinMode(ledRojo, OUTPUT);
    }

    void loop() {
      valorLuz = analogRead(sensorLuz);

      if (valorLuz < 200) {
        // muy poca luz: ningún LED
        digitalWrite(ledVerde, LOW);
        digitalWrite(ledNaranja, LOW);
        digitalWrite(ledRojo, LOW);
      } else if (valorLuz < 500) {
        // algo de luz: LED verde
        digitalWrite(ledVerde, HIGH);
        digitalWrite(ledNaranja, LOW);
        digitalWrite(ledRojo, LOW);
      } else if (valorLuz < 800) {
        // bastante luz: verde y naranja
        digitalWrite(ledVerde, HIGH);
        digitalWrite(ledNaranja, HIGH);
        digitalWrite(ledRojo, LOW);
      } else {
        // mucha luz: los tres LED
        digitalWrite(ledVerde, HIGH);
        digitalWrite(ledNaranja, HIGH);
        digitalWrite(ledRojo, HIGH);
      }
    }
    ```

    Con **`else if`** el programa va comprobando los umbrales de menor a mayor. Por ejemplo, si el sensor lee `650`, no se cumple `valorLuz < 200` ni `valorLuz < 500`, pero sí `valorLuz < 800`, así que se encienden el verde y el naranja y el programa ya no comprueba nada más. Si no se cumple ninguna condición, se ejecuta el último `else`: hay mucha luz y se encienden los tres LED.
