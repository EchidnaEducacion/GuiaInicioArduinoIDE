// Calibra tu aula: muestra en el Monitor serie la luz que mide el sensor

const int sensorLuz = A3;  // sensor de luz (LDR) conectado al pin A3
const int ledVerde = 11;   // LED verde conectado al pin 11

const int umbral = 200;  // por debajo de este valor consideramos que es de noche

int valorLuz = 0;  // guarda la luz que mide el sensor (de 0 a 1023)

void setup() {
  pinMode(ledVerde, OUTPUT);
  Serial.begin(9600);  // abre la comunicación con el ordenador
}

void loop() {
  valorLuz = analogRead(sensorLuz);
  Serial.println(valorLuz);  // muestra el valor en el Monitor serie

  if (valorLuz < umbral) {
    digitalWrite(ledVerde, HIGH);
  } else {
    digitalWrite(ledVerde, LOW);
  }

  delay(200);  // espera un poco para poder leer los valores
}
