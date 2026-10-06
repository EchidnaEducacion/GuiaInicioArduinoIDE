// Timbre: el zumbador suena mientras pulsamos SL

const int pulsadorSL = 3;  // pulsador izquierdo conectado al pin 3
const int zumbador = 10;   // zumbador conectado al pin 10

int estadoSL = LOW;  // guarda si SL está pulsado (HIGH) o no (LOW)

void setup() {
  pinMode(pulsadorSL, INPUT);  // el pulsador es una entrada
  pinMode(zumbador, OUTPUT);   // el zumbador es una salida
}

void loop() {
  // lee el estado del pulsador
  estadoSL = digitalRead(pulsadorSL);

  if (estadoSL == HIGH) {
    analogWrite(zumbador, 125);  // SL pulsado: el zumbador suena
  } else {
    analogWrite(zumbador, 0);    // SL sin pulsar: el zumbador se calla
  }
}
