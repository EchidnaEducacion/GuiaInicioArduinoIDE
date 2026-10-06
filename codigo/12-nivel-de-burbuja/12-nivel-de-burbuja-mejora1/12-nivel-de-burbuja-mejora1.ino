// Lee el acelerómetro: dibuja los ejes X e Y en el Serial Plotter

#include <Adafruit_LIS3DH.h>  // librería del acelerómetro

Adafruit_LIS3DH acelerometro;  // el acelerómetro de la placa

void setup() {
  Serial.begin(9600);        // abre la comunicación a 9600 baudios
  acelerometro.begin(0x18);  // pone en marcha el acelerómetro
}

void loop() {
  acelerometro.read();  // lee el acelerómetro

  Serial.print("X:");                // nombre del eje X
  Serial.print(acelerometro.x_g);    // valor del eje X
  Serial.print(" Y:");               // nombre del eje Y
  Serial.println(acelerometro.y_g);  // valor del eje Y y salto de línea

  delay(100);  // diez medidas por segundo
}
