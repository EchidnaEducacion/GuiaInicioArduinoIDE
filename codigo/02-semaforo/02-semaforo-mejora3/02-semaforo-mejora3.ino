// Semáforo sonoro: pitidos lentos en verde y silencio en rojo

const int ledVerde = 11;    // LED verde conectado al pin 11
const int ledNaranja = 12;  // LED naranja conectado al pin 12
const int ledRojo = 13;     // LED rojo conectado al pin 13
const int zumbador = 10;    // zumbador conectado al pin 10

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledNaranja, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(zumbador, OUTPUT);
}

void loop() {
  // fase verde: 5 pitidos lentos (5 segundos)
  digitalWrite(ledVerde, HIGH);
  for (int i = 0; i < 5; i++) {
    analogWrite(zumbador, 125);  // suena
    delay(500);
    analogWrite(zumbador, 0);    // calla
    delay(500);
  }
  digitalWrite(ledVerde, LOW);

  // fase naranja: 2 segundos
  digitalWrite(ledNaranja, HIGH);
  delay(2000);
  digitalWrite(ledNaranja, LOW);

  // fase roja: 5 segundos en silencio
  digitalWrite(ledRojo, HIGH);
  delay(5000);
  digitalWrite(ledRojo, LOW);
}
