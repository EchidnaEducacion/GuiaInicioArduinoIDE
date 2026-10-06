// Encendido por palmada: cada palmada enciende o apaga el LED rojo

const int microfono = A7;  // micrófono conectado al pin A7
const int ledRojo = 13;    // LED rojo conectado al pin 13

const int umbralPalmada = 20;  // por encima de este valor hay una palmada

int estadoLED = LOW;  // recuerda si el LED está apagado o encendido

void setup() {
  pinMode(ledRojo, OUTPUT);
  analogReference(INTERNAL);  // referencia de 1,1 V
}

void loop() {
  if (analogRead(microfono) > umbralPalmada) {
    // palmada: cambia el LED al estado contrario
    if (estadoLED == LOW) {
      estadoLED = HIGH;
    } else {
      estadoLED = LOW;
    }
    digitalWrite(ledRojo, estadoLED);

    delay(300);  // espera a que termine el sonido de la palmada
  }
}
