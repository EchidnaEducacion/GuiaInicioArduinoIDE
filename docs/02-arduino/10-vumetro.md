# 2.10 Vúmetro

![Imagen cabecera Vúmetro](../assets/images/Vumetro.png "Imagen cabecera Vúmetro"){ .img-cabecera }

## 1. Qué vamos a hacer

Vamos a construir un **vúmetro** o **semáforo de ruido**, que muestra con los LED de la placa cuánto ruido hay a nuestro alrededor. Con silencio se encenderá solo el **LED verde**; si el ruido aumenta, se encenderá también el **naranja**; y si hay mucho ruido, se encenderán los **tres LED**.

### 1.1 Qué vamos a aprender

* A utilizar el **micrófono** para medir la **intensidad del sonido**.
* A cambiar la **referencia** de las entradas analógicas para medir señales pequeñas con más precisión.
* A usar `if`, `else if` y `else` para distinguir **tres niveles**.
* A trabajar con **umbrales numéricos** para definir estados (silencio, ruido moderado y mucho ruido).
* A entender por qué algunas señales, como el sonido, **cambian constantemente**.

### 1.2 Qué vamos a usar

#### Componentes

* **Micrófono (pin A7):** Convierte las vibraciones del sonido en una señal eléctrica. Da valores bajos con silencio y valores más altos cuanto más intenso es el sonido.
* **LED verde (pin 11), naranja (pin 12) y rojo (pin 13):** Nos indicarán el nivel de ruido.

![Micrófono en EchidnaBlack2](../assets/images/Lupa_Microfono.png "Micrófono en EchidnaBlack2"){ .img-lupa }

#### Programación

El micrófono está en un pin **analógico** (ver la tabla de pines de la [Introducción](../01-introduccion.md)), así que lo leemos con `analogRead`. El problema es que su señal es muy **pequeña**: con la configuración normal, `analogRead` reparte los valores de `0` a `1023` entre 0 y 5 V, y el micrófono apenas llega a dar unos pocos valores. Para solucionarlo usamos la función `analogReference(tipo)`:

* **tipo**: la tensión de **referencia**, es decir, la tensión que corresponde al valor máximo, `1023`. Con `INTERNAL` usamos una referencia interna de **1,1 V** en lugar de 5 V.

Así, los valores de `0` a `1023` se reparten entre 0 y 1,1 V, y la misma señal del micrófono nos da valores casi cinco veces más grandes. La referencia se cambia una sola vez, en `setup()`, y afecta a todas las lecturas con `analogRead`.

## 2. Programamos

Revisamos continuamente el valor del micrófono y, según el nivel de ruido, encendemos o apagamos cada uno de los tres LED.

Escribe el siguiente código en Arduino IDE y cárgalo en la placa:

```arduino linenums="1"
// Vúmetro: los LED verde, naranja y rojo indican el nivel de ruido

const int microfono = A7;   // micrófono conectado al pin A7
const int ledVerde = 11;    // LED verde conectado al pin 11
const int ledNaranja = 12;  // LED naranja conectado al pin 12
const int ledRojo = 13;     // LED rojo conectado al pin 13

const int umbralSilencio = 2;  // por debajo de este valor hay silencio
const int umbralRuido = 20;    // por debajo de este valor el ruido es moderado

int valorSonido = 0;  // guarda el valor que lee el micrófono

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledNaranja, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  analogReference(INTERNAL);  // referencia de 1,1 V: el micrófono da valores más altos
}

void loop() {
  // lee el micrófono
  valorSonido = analogRead(microfono);

  if (valorSonido < umbralSilencio) {
    // silencio: solo el LED verde
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledNaranja, LOW);
    digitalWrite(ledRojo, LOW);
  } else if (valorSonido < umbralRuido) {
    // ruido moderado: verde y naranja
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledNaranja, HIGH);
    digitalWrite(ledRojo, LOW);
  } else {
    // mucho ruido: los tres LED
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledNaranja, HIGH);
    digitalWrite(ledRojo, HIGH);
  }
}
```

**Cómo funciona**:

**Las constantes** (líneas 3 a 9): guardan los pines del micrófono y de los tres LED, y los dos **umbrales** que separan los niveles de ruido.

**La variable** (línea 11): `valorSonido` guarda el valor que lee el micrófono en cada momento.

**La función `setup()`** (líneas 13 a 18): configura los tres LED como **salidas** y cambia la referencia de las entradas analógicas a 1,1 V con `analogReference(INTERNAL)`.

**La función `loop()`** (líneas 20 a 40): lee el micrófono con `analogRead` y compara el valor con los umbrales usando `if`, `else if` y `else`: el programa comprueba las condiciones en orden y ejecuta solo la primera que se cumple. El programa revisa continuamente:

```
SI el micrófono registra valores menores de 2 (silencio):
    --> Se enciende el LED verde y se apagan el naranja y el rojo.

SI NO, SI registra valores menores de 20 (entre 2 y 20, ruido moderado):
    --> Se encienden los LED verde y naranja y se apaga el rojo.

SI NO (20 o más, mucho ruido):
    --> Se encienden los tres LED.
```

Es probable que veas que los LED **parpadean** aunque el ruido sea constante. Esto ocurre porque la señal del sonido cambia muy deprisa: el micrófono capta las vibraciones de la onda sonora y cada lectura da un valor distinto. En la primera propuesta de Mejóralo aprenderás a solucionarlo.

## 3. Mejóralo

Prueba a realizar algunas de las siguientes modificaciones al proyecto:

1. **Calibra tu aula:** Observa qué valores mide el micrófono con silencio, hablando en voz baja y dando una palmada, y ajusta los umbrales (`2` y `20`) para que el vúmetro funcione bien en tu clase.

    **Pista:** envía el valor del micrófono al ordenador con `Serial.begin(9600)` en `setup()` y `Serial.println(valorSonido)` en `loop()`, como en el proyecto [El echidna dice la temperatura](08-echidna-dice-temperatura.md). Además del **Monitor serie**, prueba el **Serial Plotter** (menú **Herramientas > Serial Plotter**), que dibuja los valores como una gráfica y deja ver muy bien cómo cambia el sonido.

    **Ayuda:** añade al final de `setup()`:

    ```arduino
      Serial.begin(9600);  // abre la comunicación con el ordenador
    ```

    y en `loop()`, justo después de leer el micrófono:

    ```arduino
      Serial.println(valorSonido);  // envía el valor al Monitor serie
    ```

    Cuando sepas los valores, cambia los números de las constantes `umbralSilencio` y `umbralRuido`.

2. **Una lectura más estable:** Para que los LED no parpadeen, en lugar de usar cada lectura del micrófono, calcula la **media** de varias (por ejemplo, de `32`) y usa esa media en los condicionales.

    **Pista:** necesitas una variable que vaya sumando las lecturas (`suma`). Pon la suma a `0`, haz las lecturas con un bucle `for`, como en el proyecto [Mezclamos colores](09-mezclamos-colores.md), y al terminar divide la suma entre el número de lecturas.

    **Ayuda:** declara la constante `muestras` y la variable `suma`:

    ```arduino
    const int muestras = 32;  // número de lecturas para calcular la media

    int suma = 0;  // va sumando las lecturas para calcular la media
    ```

    y, en `loop()`, cambia la lectura del micrófono por:

    ```arduino
      // suma varias lecturas del micrófono y calcula la media
      suma = 0;
      for (int i = 0; i < muestras; i++) {
        suma = suma + analogRead(microfono);
      }
      valorSonido = suma / muestras;
    ```

    Es importante poner `suma = 0` al principio de cada vuelta: si no, la suma iría acumulando las lecturas de las vueltas anteriores y la media saldría cada vez más grande. La variable `i` solo sirve para contar las lecturas: el bucle se repite mientras `i` sea menor que `muestras`, y `i++` es una forma corta de escribir `i = i + 1`.

3. **Encendido por palmada:** Programa un interruptor que funcione con palmadas: con una palmada, el **LED rojo** se enciende, y con otra palmada, se apaga.

    **Pista:** una palmada da un valor muy alto en el micrófono, así que basta con un solo umbral. Necesitas una variable que recuerde si el LED está encendido o apagado, como en el pulsador con memoria del proyecto [Interruptor de luz](03-interruptor-de-luz.md). Después de cada palmada, espera un poco con `delay` para que el final del sonido no cuente como otra palmada.

    **Ayuda:** esta mejora es más compleja, así que te dejamos una posible solución:

    ```arduino linenums="1"
    // Encendido por palmada: cada palmada enciende o apaga el LED rojo

    const int microfono = A7;  // micrófono conectado al pin A7
    const int ledRojo = 13;    // LED rojo conectado al pin 13

    const int umbralPalmada = 20;  // por encima de este valor hay una palmada

    int estadoLED = LOW;  // recuerda si el LED está apagado o encendido

    void setup() {
      pinMode(ledRojo, OUTPUT);
      analogReference(INTERNAL);  // referencia de 1,1 V
    }

    void loop() {
      if (analogRead(microfono) > umbralPalmada) {
        // palmada: cambia el LED al estado contrario
        if (estadoLED == LOW) {
          estadoLED = HIGH;
        } else {
          estadoLED = LOW;
        }
        digitalWrite(ledRojo, estadoLED);

        delay(300);  // espera a que termine el sonido de la palmada
      }
    }
    ```

    Cada vez que el micrófono supera `umbralPalmada`, el programa cambia el LED al estado contrario y actualiza la variable **`estadoLED`**. El `delay(300)` hace que el programa no vuelva a escuchar hasta que termine el sonido de la palmada; si no, una sola palmada podría encender y apagar el LED varias veces seguidas. Si el LED cambia al hablar, sube el umbral; si no reacciona a las palmadas, bájalo.
