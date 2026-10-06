// Medidor de luz: cuanta más luz, más LED encendidos

const int sensorLuz = A3;   // sensor de luz (LDR) conectado al pin A3
const int ledVerde = 11;    // LED verde conectado al pin 11
const int ledNaranja = 12;  // LED naranja conectado al pin 12
const int ledRojo = 13;     // LED rojo conectado al pin 13

int valorLuz = 0;  // guarda la luz que mide el sensor (de 0 a 1023)

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledNaranja, OUTPUT);
  pinMode(ledRojo, OUTPUT);
}

void loop() {
  valorLuz = analogRead(sensorLuz);

  if (valorLuz < 200) {
    // muy poca luz: ningún LED
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledNaranja, LOW);
    digitalWrite(ledRojo, LOW);
  } else if (valorLuz < 500) {
    // algo de luz: LED verde
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledNaranja, LOW);
    digitalWrite(ledRojo, LOW);
  } else if (valorLuz < 800) {
    // bastante luz: verde y naranja
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledNaranja, HIGH);
    digitalWrite(ledRojo, LOW);
  } else {
    // mucha luz: los tres LED
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledNaranja, HIGH);
    digitalWrite(ledRojo, HIGH);
  }
}
