// Elige el color: H blanco, L apagado, R rojo, G verde y B azul

const int rgbRojo = 9;   // LED RGB: color rojo en el pin 9
const int rgbVerde = 5;  // LED RGB: color verde en el pin 5
const int rgbAzul = 6;   // LED RGB: color azul en el pin 6

char letra = ' ';  // guarda la letra que llega del ordenador

void setup() {
  pinMode(rgbRojo, OUTPUT);  // los tres colores del LED RGB son salidas
  pinMode(rgbVerde, OUTPUT);
  pinMode(rgbAzul, OUTPUT);
  Serial.begin(9600);        // abre la comunicación a 9600 baudios
}

void loop() {
  // ¿ha llegado alguna letra desde el ordenador?
  if (Serial.available() > 0) {
    letra = Serial.read();  // lee la letra

    if (letra == 'H') {
      // H (de HIGH): enciende los tres colores, luz blanca
      digitalWrite(rgbRojo, HIGH);
      digitalWrite(rgbVerde, HIGH);
      digitalWrite(rgbAzul, HIGH);
      Serial.println("LED encendido");
    }

    if (letra == 'L') {
      // L (de LOW): apaga los tres colores
      digitalWrite(rgbRojo, LOW);
      digitalWrite(rgbVerde, LOW);
      digitalWrite(rgbAzul, LOW);
      Serial.println("LED apagado");
    }

    if (letra == 'R') {
      // R (de Red): solo el rojo
      digitalWrite(rgbRojo, HIGH);
      digitalWrite(rgbVerde, LOW);
      digitalWrite(rgbAzul, LOW);
      Serial.println("LED rojo");
    }

    if (letra == 'G') {
      // G (de Green): solo el verde
      digitalWrite(rgbRojo, LOW);
      digitalWrite(rgbVerde, HIGH);
      digitalWrite(rgbAzul, LOW);
      Serial.println("LED verde");
    }

    if (letra == 'B') {
      // B (de Blue): solo el azul
      digitalWrite(rgbRojo, LOW);
      digitalWrite(rgbVerde, LOW);
      digitalWrite(rgbAzul, HIGH);
      Serial.println("LED azul");
    }
  }
}
