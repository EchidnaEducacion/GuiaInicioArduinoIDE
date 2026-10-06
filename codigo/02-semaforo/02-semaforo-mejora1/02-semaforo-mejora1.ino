// Naranja intermitente: el LED naranja parpadea 3 veces antes del rojo

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

  // fase naranja: 3 parpadeos rápidos
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledNaranja, HIGH);
    delay(300);
    digitalWrite(ledNaranja, LOW);
    delay(300);
  }

  // fase roja: 5 segundos
  digitalWrite(ledRojo, HIGH);
  delay(5000);
  digitalWrite(ledRojo, LOW);
}
