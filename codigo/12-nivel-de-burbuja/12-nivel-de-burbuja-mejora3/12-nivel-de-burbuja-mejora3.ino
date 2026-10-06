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
