// Respiración lenta: el LED RGB se enciende y se apaga muy despacio

const int rgbRojo = 9;   // LED RGB: color rojo en el pin 9
const int rgbVerde = 5;  // LED RGB: color verde en el pin 5
const int rgbAzul = 6;   // LED RGB: color azul en el pin 6

const int espera = 30;  // tiempo entre un brillo y el siguiente, en milisegundos

void setup() {
  pinMode(rgbRojo, OUTPUT);  // los tres colores del LED RGB son salidas
  pinMode(rgbVerde, OUTPUT);
  pinMode(rgbAzul, OUTPUT);
}

void loop() {
  // encendido gradual: el brillo sube de 0 a 255
  for (int brillo = 0; brillo <= 255; brillo = brillo + 1) {
    analogWrite(rgbRojo, brillo);
    analogWrite(rgbVerde, brillo);
    analogWrite(rgbAzul, brillo);
    delay(espera);
  }

  // apagado gradual: el brillo baja de 255 a 0
  for (int brillo = 255; brillo >= 0; brillo = brillo - 1) {
    analogWrite(rgbRojo, brillo);
    analogWrite(rgbVerde, brillo);
    analogWrite(rgbAzul, brillo);
    delay(espera);
  }

  delay(1000);  // espera 1 segundo con el LED apagado
}
