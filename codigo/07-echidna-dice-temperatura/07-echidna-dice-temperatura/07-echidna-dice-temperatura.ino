// Echidna dice la temperatura: muestra la temperatura en el Monitor serie

const int sensorTemperatura = A6;  // sensor de temperatura conectado al pin A6

int lectura = 0;          // guarda el valor que lee el sensor (de 0 a 1023)
float temperatura = 0.0;  // guarda la temperatura en grados Celsius, con decimales

void setup() {
  Serial.begin(9600);  // abre la comunicación con el ordenador a 9600 baudios
}

void loop() {
  // lee el sensor y convierte el valor a grados Celsius
  lectura = analogRead(sensorTemperatura);
  temperatura = (lectura * 0.4658) - 50.0;  // conversión ajustada a EchidnaBlack2

  // escribe la frase en el Monitor serie
  Serial.print("Hola, ahora hace una temperatura de ");
  Serial.print(temperatura);
  Serial.println(" ºC");

  delay(1000);  // espera 1 segundo hasta la siguiente medida
}
