// Dos colores: el rojo y después el azul se encienden y se apagan poco a poco

const int rgbRojo = 9;   // LED RGB: color rojo en el pin 9
const int rgbVerde = 5;  // LED RGB: color verde en el pin 5
const int rgbAzul = 6;   // LED RGB: color azul en el pin 6

const int espera = 10;  // tiempo entre un brillo y el siguiente, en milisegundos

void setup() {
  pinMode(rgbRojo, OUTPUT);  // los tres colores del LED RGB son salidas
  pinMode(rgbVerde, OUTPUT);
  pinMode(rgbAzul, OUTPUT);
}

void loop() {
  // el rojo se enciende y se apaga poco a poco
  for (int brillo = 0; brillo <= 255; brillo = brillo + 1) {
    analogWrite(rgbRojo, brillo);
    delay(espera);
  }
  for (int brillo = 255; brillo >= 0; brillo = brillo - 1) {
    analogWrite(rgbRojo, brillo);
    delay(espera);
  }

  // el azul se enciende y se apaga poco a poco
  for (int brillo = 0; brillo <= 255; brillo = brillo + 1) {
    analogWrite(rgbAzul, brillo);
    delay(espera);
  }
  for (int brillo = 255; brillo >= 0; brillo = brillo - 1) {
    analogWrite(rgbAzul, brillo);
    delay(espera);
  }
}
