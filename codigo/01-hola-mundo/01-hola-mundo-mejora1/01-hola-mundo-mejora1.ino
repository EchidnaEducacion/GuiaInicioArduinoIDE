// Ritmo rápido: el LED rojo parpadea cada 0,2 segundos

const int ledRojo = 13;  // LED rojo conectado al pin 13

// setup() se ejecuta una sola vez, al encender la placa
void setup() {
  pinMode(ledRojo, OUTPUT);  // el pin del LED es una salida
}

// loop() se repite una y otra vez, para siempre
void loop() {
  digitalWrite(ledRojo, HIGH);  // enciende el LED
  delay(200);                   // espera 0,2 segundos
  digitalWrite(ledRojo, LOW);   // apaga el LED
  delay(200);                   // espera 0,2 segundos
}
