// Frío o calor: el LED rojo avisa cuando la temperatura supera el umbral

const int sensorTemperatura = A6;  // sensor de temperatura conectado al pin A6
const int ledRojo = 13;            // LED rojo conectado al pin 13
const int ledVerde = 11;           // LED verde conectado al pin 11

const float umbral = 28.0;  // por encima de esta temperatura hace calor

int lectura = 0;          // guarda el valor que lee el sensor (de 0 a 1023)
float temperatura = 0.0;  // guarda la temperatura en grados Celsius, con decimales

void setup() {
  Serial.begin(9600);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  lectura = analogRead(sensorTemperatura);
  temperatura = (lectura * 0.4658) - 50.0;

  Serial.print("Hola, ahora hace una temperatura de ");
  Serial.print(temperatura);
  Serial.println(" ºC");

  if (temperatura > umbral) {
    digitalWrite(ledRojo, HIGH);  // calor: LED rojo
    digitalWrite(ledVerde, LOW);
  } else {
    digitalWrite(ledRojo, LOW);   // sin calor: LED verde
    digitalWrite(ledVerde, HIGH);
  }

  delay(1000);  // espera 1 segundo hasta la siguiente medida
}
