// Como la tecla t: la placa dice la temperatura al pulsar SR

const int pulsadorSR = 2;          // pulsador derecho conectado al pin 2
const int sensorTemperatura = A6;  // sensor de temperatura conectado al pin A6

int lectura = 0;          // guarda el valor que lee el sensor (de 0 a 1023)
float temperatura = 0.0;  // guarda la temperatura en grados Celsius, con decimales

void setup() {
  pinMode(pulsadorSR, INPUT);  // el pulsador es una entrada
  Serial.begin(9600);          // abre la comunicación con el ordenador a 9600 baudios
}

void loop() {
  if (digitalRead(pulsadorSR) == HIGH) {
    // SR pulsado: mide y dice la temperatura
    lectura = analogRead(sensorTemperatura);
    temperatura = (lectura * 0.4658) - 50.0;

    Serial.print("Hola, ahora hace una temperatura de ");
    Serial.print(temperatura);
    Serial.println(" ºC");

    delay(1000);  // espera 1 segundo para no repetir la frase
  }
}
