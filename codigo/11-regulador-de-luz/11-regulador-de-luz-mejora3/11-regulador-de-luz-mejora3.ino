// Theremín: el eje X del joystick elige la nota del zumbador

const int joystickX = A0;  // eje X del joystick en el pin A0
const int zumbador = 10;   // zumbador conectado al pin 10

const int centroMin = 492;  // zona del centro: de 492...
const int centroMax = 532;  // ...a 532

const int notaGrave = 200;   // frecuencia a la izquierda, en Hz
const int notaAguda = 1000;  // frecuencia a la derecha, en Hz

int valorX = 0;      // guarda la posición del joystick en el eje X
int frecuencia = 0;  // guarda la nota que suena, en Hz

void setup() {
  pinMode(zumbador, OUTPUT);
}

void loop() {
  valorX = analogRead(joystickX);

  if (valorX < centroMin || valorX > centroMax) {
    // fuera del centro: suena una nota según la posición
    frecuencia = map(valorX, 0, 1023, notaGrave, notaAguda);
    tone(zumbador, frecuencia);
  } else {
    noTone(zumbador);  // en el centro: silencio
  }
}
