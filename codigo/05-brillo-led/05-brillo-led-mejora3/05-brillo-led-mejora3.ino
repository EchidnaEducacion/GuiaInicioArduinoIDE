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
