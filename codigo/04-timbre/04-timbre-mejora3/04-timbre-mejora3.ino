// Timbre de dos tonos: SL suena grave y SR, agudo

const int pulsadorSR = 2;  // pulsador derecho conectado al pin 2
const int pulsadorSL = 3;  // pulsador izquierdo conectado al pin 3
const int zumbador = 10;   // zumbador conectado al pin 10

const int tonoGrave = 440;  // frecuencia del tono de SL, en Hz
const int tonoAgudo = 880;  // frecuencia del tono de SR, en Hz

int estadoSR = LOW;  // guarda si SR está pulsado (HIGH) o no (LOW)
int estadoSL = LOW;  // guarda si SL está pulsado (HIGH) o no (LOW)

void setup() {
  pinMode(pulsadorSR, INPUT);
  pinMode(pulsadorSL, INPUT);
  pinMode(zumbador, OUTPUT);
}

void loop() {
  estadoSR = digitalRead(pulsadorSR);
  estadoSL = digitalRead(pulsadorSL);

  if (estadoSL == HIGH) {
    tone(zumbador, tonoGrave);  // SL pulsado: tono grave
  } else {
    if (estadoSR == HIGH) {
      tone(zumbador, tonoAgudo);  // SR pulsado: tono agudo
    } else {
      noTone(zumbador);  // ninguno pulsado: silencio
    }
  }
}
