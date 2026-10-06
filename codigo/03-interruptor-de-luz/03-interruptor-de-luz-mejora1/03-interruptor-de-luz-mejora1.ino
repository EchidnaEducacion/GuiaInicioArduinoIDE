// Luz cruzada: SR enciende el LED rojo y SL, el LED verde

const int pulsadorSR = 2;  // pulsador derecho conectado al pin 2
const int pulsadorSL = 3;  // pulsador izquierdo conectado al pin 3
const int ledVerde = 11;   // LED verde conectado al pin 11
const int ledRojo = 13;    // LED rojo conectado al pin 13

int estadoSR = LOW;  // guarda si SR está pulsado (HIGH) o no (LOW)
int estadoSL = LOW;  // guarda si SL está pulsado (HIGH) o no (LOW)

void setup() {
  pinMode(pulsadorSR, INPUT);  // los pulsadores son entradas
  pinMode(pulsadorSL, INPUT);
  pinMode(ledVerde, OUTPUT);   // los LED son salidas
  pinMode(ledRojo, OUTPUT);
}

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
