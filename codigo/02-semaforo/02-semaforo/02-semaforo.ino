// Semáforo: verde 5 s, naranja 2 s y rojo 5 s

const int ledVerde = 11;    // LED verde conectado al pin 11
const int ledNaranja = 12;  // LED naranja conectado al pin 12
const int ledRojo = 13;     // LED rojo conectado al pin 13

void setup() {
  // los pines de los tres LED son salidas
  pinMode(ledVerde, OUTPUT);
  pinMode(ledNaranja, OUTPUT);
  pinMode(ledRojo, OUTPUT);
}

void loop() {
  // fase verde: 5 segundos
  digitalWrite(ledVerde, HIGH);
  delay(5000);
  digitalWrite(ledVerde, LOW);

  // fase naranja: 2 segundos
  digitalWrite(ledNaranja, HIGH);
  delay(2000);
  digitalWrite(ledNaranja, LOW);

  // fase roja: 5 segundos
  digitalWrite(ledRojo, HIGH);
  delay(5000);
  digitalWrite(ledRojo, LOW);
}
