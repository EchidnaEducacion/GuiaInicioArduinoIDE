// Semáforo con semáforo de peatones en el LED RGB

const int ledVerde = 11;    // LED verde conectado al pin 11
const int ledNaranja = 12;  // LED naranja conectado al pin 12
const int ledRojo = 13;     // LED rojo conectado al pin 13
const int peatonRojo = 9;   // rojo del LED RGB conectado al pin 9
const int peatonVerde = 5;  // verde del LED RGB conectado al pin 5

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledNaranja, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(peatonRojo, OUTPUT);
  pinMode(peatonVerde, OUTPUT);
}

void loop() {
  // coches en verde: peatones en rojo
  digitalWrite(peatonRojo, HIGH);
  digitalWrite(ledVerde, HIGH);
  delay(5000);
  digitalWrite(ledVerde, LOW);

  // coches en naranja: peatones siguen en rojo
  digitalWrite(ledNaranja, HIGH);
  delay(2000);
  digitalWrite(ledNaranja, LOW);

  // coches en rojo: peatones en verde
  digitalWrite(peatonRojo, LOW);
  digitalWrite(peatonVerde, HIGH);
  digitalWrite(ledRojo, HIGH);
  delay(5000);
  digitalWrite(ledRojo, LOW);
  digitalWrite(peatonVerde, LOW);
}
