// Latido: el LED verde se enciende deprisa y se apaga despacio

const int ledVerde = 11;  // LED verde conectado al pin 11

const int esperaSubida = 2;  // subida rápida: 2 milisegundos por paso
const int esperaBajada = 8;  // bajada lenta: 8 milisegundos por paso

void setup() {
  pinMode(ledVerde, OUTPUT);  // el LED es una salida
}

void loop() {
  // el latido: sube deprisa...
  for (int brillo = 0; brillo <= 255; brillo = brillo + 1) {
    analogWrite(ledVerde, brillo);
    delay(esperaSubida);
  }

  // ...y baja despacio
  for (int brillo = 255; brillo >= 0; brillo = brillo - 1) {
    analogWrite(ledVerde, brillo);
    delay(esperaBajada);
  }

  delay(500);  // pausa entre latidos
}
