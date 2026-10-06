// Regulador de luz: el LED verde brilla más cuanto más movemos el joystick

const int joystickX = A0;  // eje X del joystick en el pin A0
const int ledVerde = 11;   // LED verde conectado al pin 11

const int centroMin = 492;  // por debajo, el joystick está hacia la izquierda
const int centroMax = 532;  // por encima, hacia la derecha

int valorX = 0;  // guarda la posición del joystick en el eje X (de 0 a 1023)
int brillo = 0;  // guarda el brillo del LED (de 0 a 255)

void setup() {
  pinMode(ledVerde, OUTPUT);  // el LED es una salida
}

void loop() {
  // lee la posición del joystick
  valorX = analogRead(joystickX);

  if (valorX > centroMax) {
    // hacia la derecha: de 532 a 1023 pasa a 0 a 255
    brillo = map(valorX, centroMax, 1023, 0, 255);
  } else if (valorX < centroMin) {
    // hacia la izquierda: de 492 a 0 pasa a 0 a 255
    brillo = map(valorX, centroMin, 0, 0, 255);
  } else {
    brillo = 0;  // en el centro: apagado
  }

  analogWrite(ledVerde, brillo);  // enciende el LED con ese brillo
}
