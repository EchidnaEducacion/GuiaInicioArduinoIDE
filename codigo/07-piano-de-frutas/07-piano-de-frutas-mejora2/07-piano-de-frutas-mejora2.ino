// Escala musical: cuatro teclas MkMk tocan Do, Re, Mi y Fa

const int teclaDo = A0;   // tecla Do en la entrada MkMk A0
const int teclaRe = A1;   // tecla Re en la entrada MkMk A1
const int teclaMi = A2;   // tecla Mi en la entrada MkMk A2
const int teclaFa = A3;   // tecla Fa en la entrada MkMk A3
const int zumbador = 10;  // zumbador conectado al pin 10

const int umbral = 350;    // por encima de este valor hay contacto
const int notaDo = 262;    // frecuencias de las notas, en Hz
const int notaRe = 294;
const int notaMi = 330;
const int notaFa = 349;
const int duracion = 250;  // duración de cada nota, en milisegundos

void setup() {
  pinMode(zumbador, OUTPUT);  // el zumbador es una salida
}

void loop() {
  if (analogRead(teclaDo) > umbral) {
    tone(zumbador, notaDo, duracion);  // tecla Do
    delay(duracion);
  }
  if (analogRead(teclaRe) > umbral) {
    tone(zumbador, notaRe, duracion);  // tecla Re
    delay(duracion);
  }
  if (analogRead(teclaMi) > umbral) {
    tone(zumbador, notaMi, duracion);  // tecla Mi
    delay(duracion);
  }
  if (analogRead(teclaFa) > umbral) {
    tone(zumbador, notaFa, duracion);  // tecla Fa
    delay(duracion);
  }
}
