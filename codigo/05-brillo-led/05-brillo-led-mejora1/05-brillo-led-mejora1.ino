// Respiración lenta: el LED verde se enciende y se apaga muy despacio

const int ledVerde = 11;  // LED verde conectado al pin 11

const int espera = 30;  // tiempo entre un brillo y el siguiente, en milisegundos

void setup() {
  pinMode(ledVerde, OUTPUT);  // el LED es una salida
}

void loop() {
  // encendido gradual: el brillo sube de 0 a 255
  for (int brillo = 0; brillo <= 255; brillo = brillo + 1) {
    analogWrite(ledVerde, brillo);
    delay(espera);
  }

  // apagado gradual: el brillo baja de 255 a 0
  for (int brillo = 255; brillo >= 0; brillo = brillo - 1) {
    analogWrite(ledVerde, brillo);
    delay(espera);
  }

  delay(1000);  // espera 1 segundo con el LED apagado
}
