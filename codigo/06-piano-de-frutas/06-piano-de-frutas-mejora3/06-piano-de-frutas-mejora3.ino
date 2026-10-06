// Teclado de colores: cada tecla MkMk toca una nota y enciende un color

const int teclaDo = A0;   // tecla Do en la entrada MkMk A0
const int teclaRe = A1;   // tecla Re en la entrada MkMk A1
const int teclaMi = A2;   // tecla Mi en la entrada MkMk A2
const int teclaFa = A3;   // tecla Fa en la entrada MkMk A3
const int zumbador = 10;  // zumbador conectado al pin 10
const int rgbRojo = 9;    // LED RGB: color rojo en el pin 9
const int rgbVerde = 5;   // LED RGB: color verde en el pin 5
const int rgbAzul = 6;    // LED RGB: color azul en el pin 6

const int umbral = 350;    // por encima de este valor hay contacto
const int notaDo = 262;    // frecuencias de las notas, en Hz
const int notaRe = 294;
const int notaMi = 330;
const int notaFa = 349;
const int duracion = 250;  // duración de cada nota, en milisegundos

void setup() {
  pinMode(zumbador, OUTPUT);
  pinMode(rgbRojo, OUTPUT);
  pinMode(rgbVerde, OUTPUT);
  pinMode(rgbAzul, OUTPUT);
}

void loop() {
  if (analogRead(teclaDo) > umbral) {
    digitalWrite(rgbRojo, HIGH);  // Do: rojo
    tone(zumbador, notaDo, duracion);
    delay(duracion);
  }
  if (analogRead(teclaRe) > umbral) {
    digitalWrite(rgbVerde, HIGH);  // Re: verde
    tone(zumbador, notaRe, duracion);
    delay(duracion);
  }
  if (analogRead(teclaMi) > umbral) {
    digitalWrite(rgbAzul, HIGH);  // Mi: azul
    tone(zumbador, notaMi, duracion);
    delay(duracion);
  }
  if (analogRead(teclaFa) > umbral) {
    digitalWrite(rgbRojo, HIGH);  // Fa: blanco (los tres colores)
    digitalWrite(rgbVerde, HIGH);
    digitalWrite(rgbAzul, HIGH);
    tone(zumbador, notaFa, duracion);
    delay(duracion);
  }

  // apaga el LED RGB hasta la siguiente nota
  digitalWrite(rgbRojo, LOW);
  digitalWrite(rgbVerde, LOW);
  digitalWrite(rgbAzul, LOW);
}
