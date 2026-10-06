// Interruptor crepuscular: el LED verde se enciende cuando hay poca luz

const int sensorLuz = A3;  // sensor de luz (LDR) conectado al pin A3
const int ledVerde = 11;   // LED verde conectado al pin 11

const int umbral = 200;  // por debajo de este valor consideramos que es de noche

int valorLuz = 0;  // guarda la luz que mide el sensor (de 0 a 1023)

void setup() {
  pinMode(ledVerde, OUTPUT);  // el LED es una salida
}

void loop() {
  // lee la cantidad de luz
  valorLuz = analogRead(sensorLuz);

  if (valorLuz < umbral) {
    digitalWrite(ledVerde, HIGH);  // poca luz (de noche): enciende el LED
  } else {
    digitalWrite(ledVerde, LOW);   // mucha luz (de día): apaga el LED
  }
}
