// Los dos a la vez: con SR y SL pulsados a la vez se enciende el LED naranja

const int pulsadorSR = 2;   // pulsador derecho conectado al pin 2
const int pulsadorSL = 3;   // pulsador izquierdo conectado al pin 3
const int ledNaranja = 12;  // LED naranja conectado al pin 12
const int ledRojo = 13;     // LED rojo conectado al pin 13

int estadoSR = LOW;  // guarda si SR está pulsado (HIGH) o no (LOW)
int estadoSL = LOW;  // guarda si SL está pulsado (HIGH) o no (LOW)

void setup() {
  pinMode(pulsadorSR, INPUT);   // los pulsadores son entradas
  pinMode(pulsadorSL, INPUT);
  pinMode(ledNaranja, OUTPUT);  // los LED son salidas
  pinMode(ledRojo, OUTPUT);
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

  // los dos pulsadores a la vez: LED naranja
  if (estadoSR == HIGH && estadoSL == HIGH) {
    digitalWrite(ledNaranja, HIGH);
  } else {
    digitalWrite(ledNaranja, LOW);
  }
}
