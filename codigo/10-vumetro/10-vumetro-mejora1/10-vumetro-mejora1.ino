// Calibra tu aula: envía al ordenador los valores del micrófono

const int microfono = A7;   // micrófono conectado al pin A7
const int ledVerde = 11;    // LED verde conectado al pin 11
const int ledNaranja = 12;  // LED naranja conectado al pin 12
const int ledRojo = 13;     // LED rojo conectado al pin 13

const int umbralSilencio = 2;  // por debajo de este valor hay silencio
const int umbralRuido = 20;    // por debajo de este valor el ruido es moderado

int valorSonido = 0;  // guarda el valor que lee el micrófono

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledNaranja, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  analogReference(INTERNAL);  // referencia de 1,1 V: el micrófono da valores más altos
  Serial.begin(9600);  // abre la comunicación con el ordenador
}

void loop() {
  // lee el micrófono
  valorSonido = analogRead(microfono);
  Serial.println(valorSonido);  // envía el valor al Monitor serie

  if (valorSonido < umbralSilencio) {
    // silencio: solo el LED verde
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledNaranja, LOW);
    digitalWrite(ledRojo, LOW);
  } else if (valorSonido < umbralRuido) {
    // ruido moderado: verde y naranja
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledNaranja, HIGH);
    digitalWrite(ledRojo, LOW);
  } else {
    // mucho ruido: los tres LED
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledNaranja, HIGH);
    digitalWrite(ledRojo, HIGH);
  }
}
