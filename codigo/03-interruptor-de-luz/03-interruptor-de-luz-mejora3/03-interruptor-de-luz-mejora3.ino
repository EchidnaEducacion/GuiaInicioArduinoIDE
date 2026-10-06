// Pulsador con memoria: SL enciende y apaga el LED rojo

const int pulsadorSL = 3;  // pulsador izquierdo conectado al pin 3
const int ledRojo = 13;    // LED rojo conectado al pin 13

int estadoLED = LOW;  // recuerda si el LED está apagado o encendido

void setup() {
  pinMode(pulsadorSL, INPUT);
  pinMode(ledRojo, OUTPUT);
}

void loop() {
  if (digitalRead(pulsadorSL) == HIGH) {
    // cambia el LED al estado contrario
    if (estadoLED == LOW) {
      estadoLED = HIGH;
    } else {
      estadoLED = LOW;
    }
    digitalWrite(ledRojo, estadoLED);

    // espera a que sueltes el pulsador
    while (digitalRead(pulsadorSL) == HIGH) {
    }
    delay(50);  // evita los rebotes del pulsador al soltarlo
  }
}
