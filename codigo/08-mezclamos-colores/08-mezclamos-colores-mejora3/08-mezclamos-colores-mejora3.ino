// Termómetro de colores: el LED RGB cambia de color según la temperatura

const int sensorTemperatura = A6;  // sensor de temperatura conectado al pin A6
const int rgbRojo = 9;             // LED RGB: color rojo en el pin 9
const int rgbVerde = 5;            // LED RGB: color verde en el pin 5
const int rgbAzul = 6;             // LED RGB: color azul en el pin 6

const float umbralFrio = 20.0;   // por debajo de esta temperatura hace frío
const float umbralCalor = 28.0;  // por encima de esta temperatura hace calor

int lectura = 0;          // guarda el valor que lee el sensor (de 0 a 1023)
float temperatura = 0.0;  // guarda la temperatura en grados Celsius, con decimales

void setup() {
  pinMode(rgbRojo, OUTPUT);
  pinMode(rgbVerde, OUTPUT);
  pinMode(rgbAzul, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lectura = analogRead(sensorTemperatura);
  temperatura = (lectura * 0.4658) - 50.0;

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" ºC");

  if (temperatura < umbralFrio) {
    // frío: azul
    analogWrite(rgbRojo, 0);
    analogWrite(rgbVerde, 0);
    analogWrite(rgbAzul, 255);
  } else if (temperatura > umbralCalor) {
    // calor: rojo
    analogWrite(rgbRojo, 255);
    analogWrite(rgbVerde, 0);
    analogWrite(rgbAzul, 0);
  } else {
    // temperatura agradable: verde
    analogWrite(rgbRojo, 0);
    analogWrite(rgbVerde, 255);
    analogWrite(rgbAzul, 0);
  }

  delay(1000);  // espera 1 segundo hasta la siguiente medida
}
