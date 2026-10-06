// Color a la carta: 254r109g4b pone el LED RGB naranja Echidna

const int rgbRojo = 9;   // LED RGB: color rojo en el pin 9
const int rgbVerde = 5;  // LED RGB: color verde en el pin 5
const int rgbAzul = 6;   // LED RGB: color azul en el pin 6

char letra = ' ';  // guarda cada carácter que llega del ordenador
int numero = 0;    // va juntando las cifras del número
int rojo = 0;      // intensidad del rojo (de 0 a 255)
int verde = 0;     // intensidad del verde (de 0 a 255)
int azul = 0;      // intensidad del azul (de 0 a 255)

void setup() {
  pinMode(rgbRojo, OUTPUT);
  pinMode(rgbVerde, OUTPUT);
  pinMode(rgbAzul, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    letra = Serial.read();

    if (letra >= '0' && letra <= '9') {
      // una cifra: la añade al final del número
      numero = numero * 10 + (letra - '0');
      if (numero > 255) {
        numero = 255;  // como máximo, 255
      }
    } else if (letra == 'r') {
      rojo = numero;  // el número es la intensidad del rojo
      Serial.print("Rojo: ");
      Serial.println(rojo);
      numero = 0;
    } else if (letra == 'g') {
      verde = numero;  // el número es la intensidad del verde
      Serial.print("Verde: ");
      Serial.println(verde);
      numero = 0;
    } else if (letra == 'b') {
      azul = numero;  // el número es la intensidad del azul
      Serial.print("Azul: ");
      Serial.println(azul);
      numero = 0;
    }
  }

  // mezcla los tres colores
  analogWrite(rgbRojo, rojo);
  analogWrite(rgbVerde, verde);
  analogWrite(rgbAzul, azul);
}
