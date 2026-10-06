// Linterna automática: el LED RGB se enciende en blanco cuando hay poca luz

const int sensorLuz = A3;  // sensor de luz (LDR) conectado al pin A3
const int rgbRojo = 9;     // LED RGB: color rojo en el pin 9
const int rgbVerde = 5;    // LED RGB: color verde en el pin 5
const int rgbAzul = 6;     // LED RGB: color azul en el pin 6

const int umbral = 200;  // por debajo de este valor consideramos que es de noche

int valorLuz = 0;  // guarda la luz que mide el sensor (de 0 a 1023)

void setup() {
  pinMode(rgbRojo, OUTPUT);  // los tres colores del LED RGB son salidas
  pinMode(rgbVerde, OUTPUT);
  pinMode(rgbAzul, OUTPUT);
}

void loop() {
  valorLuz = analogRead(sensorLuz);

  if (valorLuz < umbral) {
    // poca luz: los tres colores encendidos dan luz blanca
    digitalWrite(rgbRojo, HIGH);
    digitalWrite(rgbVerde, HIGH);
    digitalWrite(rgbAzul, HIGH);
  } else {
    // mucha luz: LED RGB apagado
    digitalWrite(rgbRojo, LOW);
    digitalWrite(rgbVerde, LOW);
    digitalWrite(rgbAzul, LOW);
  }
}
