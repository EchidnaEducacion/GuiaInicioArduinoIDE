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
