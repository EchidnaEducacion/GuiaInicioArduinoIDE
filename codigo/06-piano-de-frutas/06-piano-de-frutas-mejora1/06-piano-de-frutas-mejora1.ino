// Luz y sonido: el LED verde se enciende mientras suena la nota Do

const int entradaMkMk = A0;  // entrada MkMk conectada al pin A0
const int zumbador = 10;     // zumbador conectado al pin 10
const int ledVerde = 11;     // LED verde conectado al pin 11

const int umbral = 350;    // por encima de este valor hay contacto
const int notaDo = 262;    // frecuencia de la nota Do central, en Hz
const int duracion = 250;  // duración de la nota, en milisegundos

int valorMkMk = 0;  // guarda el valor que lee la entrada (de 0 a 1023)

void setup() {
  pinMode(zumbador, OUTPUT);  // el zumbador es una salida
  pinMode(ledVerde, OUTPUT);  // el LED es una salida
}

void loop() {
  // lee la entrada MkMk
  valorMkMk = analogRead(entradaMkMk);

  if (valorMkMk > umbral) {
    digitalWrite(ledVerde, HIGH);      // enciende el LED
    tone(zumbador, notaDo, duracion);  // suena la nota Do
    delay(duracion);                   // espera a que termine la nota
    digitalWrite(ledVerde, LOW);       // apaga el LED
  }
}
