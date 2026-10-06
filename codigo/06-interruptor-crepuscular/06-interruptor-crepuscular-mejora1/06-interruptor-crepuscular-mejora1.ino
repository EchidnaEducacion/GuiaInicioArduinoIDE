// Lee el sensor de luz: muestra su valor en el Monitor serie

const int sensorLuz = A3;  // sensor de luz (LDR) conectado al pin A3

int valorLuz = 0;  // guarda la luz que mide el sensor (de 0 a 1023)

void setup() {
  Serial.begin(9600);  // abre la comunicación a 9600 baudios
}

void loop() {
  valorLuz = analogRead(sensorLuz);  // lee el sensor

  Serial.print("Valor del sensor de luz: ");  // texto
  Serial.println(valorLuz);                   // valor y salto de línea

  delay(1000);  // espera 1 segundo para poder leer los valores
}
