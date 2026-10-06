// LED testigo: el LED verde indica que el timbre suena y el rojo, que está en silencio

const int pulsadorSL = 3;  // pulsador izquierdo conectado al pin 3
const int zumbador = 10;   // zumbador conectado al pin 10
const int ledVerde = 11;   // LED verde conectado al pin 11
const int ledRojo = 13;    // LED rojo conectado al pin 13

int estadoSL = LOW;  // guarda si SL está pulsado (HIGH) o no (LOW)

void setup() {
  pinMode(pulsadorSL, INPUT);  // el pulsador es una entrada
  pinMode(zumbador, OUTPUT);   // el zumbador es una salida
  pinMode(ledVerde, OUTPUT);   // los LED son salidas
  pinMode(ledRojo, OUTPUT);
}

void loop() {
  estadoSL = digitalRead(pulsadorSL);

  if (estadoSL == HIGH) {
    analogWrite(zumbador, 125);    // suena
    digitalWrite(ledVerde, HIGH);  // verde encendido
    digitalWrite(ledRojo, LOW);    // rojo apagado
  } else {
    analogWrite(zumbador, 0);      // silencio
    digitalWrite(ledVerde, LOW);   // verde apagado
    digitalWrite(ledRojo, HIGH);   // rojo encendido
  }
}
