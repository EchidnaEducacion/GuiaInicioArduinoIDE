// De rojo a azul: el LED RGB pasa poco a poco del rojo al azul y vuelve

const int rgbRojo = 9;   // LED RGB: color rojo en el pin 9
const int rgbVerde = 5;  // LED RGB: color verde en el pin 5
const int rgbAzul = 6;   // LED RGB: color azul en el pin 6

const int paso = 5;     // los colores cambian de 5 en 5
const int espera = 30;  // tiempo entre un color y el siguiente, en milisegundos

void setup() {
  pinMode(rgbRojo, OUTPUT);  // los tres colores del LED RGB son salidas
  pinMode(rgbVerde, OUTPUT);
  pinMode(rgbAzul, OUTPUT);
  Serial.begin(9600);        // para ver en el Monitor serie la mezcla de cada color
}

void loop() {
  // del rojo al azul: el azul sube mientras el rojo baja
  for (int valor = 0; valor <= 255; valor = valor + paso) {
    analogWrite(rgbRojo, 255 - valor);
    analogWrite(rgbAzul, valor);
    delay(espera);
  }

  // del azul al rojo: el azul baja mientras el rojo sube
  for (int valor = 255; valor >= 0; valor = valor - paso) {
    analogWrite(rgbRojo, 255 - valor);
    analogWrite(rgbAzul, valor);
    delay(espera);
  }
}
