// Grados Fahrenheit: SR dice la temperatura en ºC y SL, en ºF

const int pulsadorSR = 2;          // pulsador derecho conectado al pin 2
const int pulsadorSL = 3;          // pulsador izquierdo conectado al pin 3
const int sensorTemperatura = A6;  // sensor de temperatura conectado al pin A6

int lectura = 0;          // guarda el valor que lee el sensor (de 0 a 1023)
float temperatura = 0.0;  // guarda la temperatura en grados Celsius, con decimales
float fahrenheit = 0.0;   // guarda la temperatura en grados Fahrenheit

void setup() {
  pinMode(pulsadorSR, INPUT);  // los pulsadores son entradas
  pinMode(pulsadorSL, INPUT);
  Serial.begin(9600);          // abre la comunicación con el ordenador a 9600 baudios
}

void loop() {
  // mide la temperatura en las dos escalas
  lectura = analogRead(sensorTemperatura);
  temperatura = (lectura * 0.4658) - 50.0;
  fahrenheit = temperatura * 1.8 + 32;

  if (digitalRead(pulsadorSR) == HIGH) {
    // SR pulsado: temperatura en grados Celsius
    Serial.print("Hola, ahora hace una temperatura de ");
    Serial.print(temperatura);
    Serial.println(" ºC");
    delay(1000);
  }

  if (digitalRead(pulsadorSL) == HIGH) {
    // SL pulsado: temperatura en grados Fahrenheit
    Serial.print("Hola, ahora hace una temperatura de ");
    Serial.print(fahrenheit);
    Serial.println(" ºF");
    delay(1000);
  }
}
