// Parpadeo alterno: el LED rojo y el verde se encienden por turnos

const int ledRojo = 13;   // LED rojo conectado al pin 13
const int ledVerde = 11;  // LED verde conectado al pin 11

void setup() {
  pinMode(ledRojo, OUTPUT);   // el pin del LED rojo es una salida
  pinMode(ledVerde, OUTPUT);  // el pin del LED verde es una salida
}

void loop() {
  digitalWrite(ledRojo, HIGH);  // enciende el rojo
  digitalWrite(ledVerde, LOW);  // apaga el verde
  delay(1000);                  // espera 1 segundo
  digitalWrite(ledRojo, LOW);   // apaga el rojo
  digitalWrite(ledVerde, HIGH); // enciende el verde
  delay(1000);                  // espera 1 segundo
}
