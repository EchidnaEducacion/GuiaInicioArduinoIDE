// Respiración: el azul del LED RGB se enciende y se apaga poco a poco

const int rgbRojo = 9;   // LED RGB: color rojo en el pin 9
const int rgbVerde = 5;  // LED RGB: color verde en el pin 5
const int rgbAzul = 6;   // LED RGB: color azul en el pin 6

const int paso = 5;     // el azul sube y baja de 5 en 5
const int espera = 30;  // tiempo entre un brillo y el siguiente, en milisegundos

void setup() {
  pinMode(rgbRojo, OUTPUT);  // los tres colores del LED RGB son salidas
  pinMode(rgbVerde, OUTPUT);
  pinMode(rgbAzul, OUTPUT);
  Serial.begin(9600);        // para ver en el Monitor serie la mezcla de cada color
}

void loop() {
  // el azul se enciende poco a poco
  for (int azul = 0; azul <= 255; azul = azul + paso) {
    analogWrite(rgbAzul, azul);
    delay(espera);
  }

  // el azul se apaga poco a poco
  for (int azul = 255; azul >= 0; azul = azul - paso) {
    analogWrite(rgbAzul, azul);
    delay(espera);
  }
}
