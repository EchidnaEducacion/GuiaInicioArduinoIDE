// Lee el joystick: dibuja los ejes X e Y en el Serial Plotter

const int joystickX = A0;  // eje X del joystick en el pin A0
const int joystickY = A1;  // eje Y del joystick en el pin A1

int valorX = 0;  // guarda la posición del eje X
int valorY = 0;  // guarda la posición del eje Y

void setup() {
  Serial.begin(9600);  // abre la comunicación a 9600 baudios
}

void loop() {
  valorX = analogRead(joystickX);
  valorY = analogRead(joystickY);

  Serial.print("X:");      // nombre del eje X
  Serial.print(valorX);    // valor del eje X
  Serial.print(" Y:");     // nombre del eje Y
  Serial.println(valorY);  // valor del eje Y y salto de línea

  delay(100);  // diez medidas por segundo
}
