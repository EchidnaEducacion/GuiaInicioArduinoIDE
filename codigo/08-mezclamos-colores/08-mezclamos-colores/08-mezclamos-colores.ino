// Mezclamos colores: recorre los colores del LED RGB con tres bucles for anidados

const int rgbRojo = 9;   // LED RGB: color rojo en el pin 9
const int rgbVerde = 5;  // LED RGB: color verde en el pin 5
const int rgbAzul = 6;   // LED RGB: color azul en el pin 6

const int paso = 51;     // cuánto sube cada color en cada vuelta (0, 51, 102, 153, 204, 255)
const int espera = 100;  // tiempo que se ve cada color, en milisegundos

void setup() {
  pinMode(rgbRojo, OUTPUT);  // los tres colores del LED RGB son salidas
  pinMode(rgbVerde, OUTPUT);
  pinMode(rgbAzul, OUTPUT);
  Serial.begin(9600);        // para ver en el Monitor serie la mezcla de cada color
}

void loop() {
  for (int rojo = 0; rojo <= 255; rojo = rojo + paso) {
    for (int verde = 0; verde <= 255; verde = verde + paso) {
      for (int azul = 0; azul <= 255; azul = azul + paso) {
        // mezcla los tres colores
        analogWrite(rgbRojo, rojo);
        analogWrite(rgbVerde, verde);
        analogWrite(rgbAzul, azul);

        // muestra la mezcla en el Monitor serie
        Serial.print(rojo);
        Serial.print("  ");
        Serial.print(verde);
        Serial.print("  ");
        Serial.println(azul);

        delay(espera);
      }
    }
  }
}
