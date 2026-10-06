// Mando de colores: el eje X controla el rojo y el eje Y, el azul

const int joystickX = A0;  // eje X del joystick en el pin A0
const int joystickY = A1;  // eje Y del joystick en el pin A1
const int rgbRojo = 9;     // LED RGB: color rojo en el pin 9
const int rgbAzul = 6;     // LED RGB: color azul en el pin 6

int valorX = 0;  // guarda la posición del eje X
int valorY = 0;  // guarda la posición del eje Y
int rojo = 0;    // intensidad del rojo (de 0 a 255)
int azul = 0;    // intensidad del azul (de 0 a 255)

void setup() {
  pinMode(rgbRojo, OUTPUT);
  pinMode(rgbAzul, OUTPUT);
}

void loop() {
  valorX = analogRead(joystickX);
  valorY = analogRead(joystickY);

  // cada eje, de 0 a 1023, pasa a una intensidad de 0 a 255
  rojo = map(valorX, 0, 1023, 0, 255);
  azul = map(valorY, 0, 1023, 0, 255);

  analogWrite(rgbRojo, rojo);
  analogWrite(rgbAzul, azul);
}
