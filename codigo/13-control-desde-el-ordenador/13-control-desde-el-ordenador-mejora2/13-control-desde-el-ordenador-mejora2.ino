// Brillo desde el teclado: un número terminado en > da el brillo

const int rgbRojo = 9;   // LED RGB: color rojo en el pin 9
const int rgbVerde = 5;  // LED RGB: color verde en el pin 5
const int rgbAzul = 6;   // LED RGB: color azul en el pin 6

char letra = ' ';  // guarda cada carácter que llega del ordenador
int numero = 0;    // va juntando las cifras del número
int brillo = 0;    // guarda el brillo del LED (de 0 a 255)

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
    } else if (letra == '>') {
      // fin del número: lo usa como brillo
      brillo = numero;
      Serial.print("Brillo: ");
      Serial.println(brillo);
      numero = 0;  // listo para el siguiente número
    }
  }

  // enciende el LED en blanco con el brillo actual
  analogWrite(rgbRojo, brillo);
  analogWrite(rgbVerde, brillo);
  analogWrite(rgbAzul, brillo);
}
