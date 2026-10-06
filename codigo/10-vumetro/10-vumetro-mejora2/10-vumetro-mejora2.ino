// Una lectura más estable: el vúmetro usa la media de 32 lecturas del micrófono

const int microfono = A7;   // micrófono conectado al pin A7
const int ledVerde = 11;    // LED verde conectado al pin 11
const int ledNaranja = 12;  // LED naranja conectado al pin 12
const int ledRojo = 13;     // LED rojo conectado al pin 13

const int umbralSilencio = 2;  // por debajo de este valor hay silencio
const int umbralRuido = 20;    // por debajo de este valor el ruido es moderado
const int muestras = 32;       // número de lecturas para calcular la media

int valorSonido = 0;  // guarda el valor que lee el micrófono
int suma = 0;         // va sumando las lecturas para calcular la media

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledNaranja, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  analogReference(INTERNAL);  // referencia de 1,1 V: el micrófono da valores más altos
}

void loop() {
  // suma varias lecturas del micrófono y calcula la media
  suma = 0;
  for (int i = 0; i < muestras; i++) {
    suma = suma + analogRead(microfono);
  }
  valorSonido = suma / muestras;

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
