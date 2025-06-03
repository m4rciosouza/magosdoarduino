/**
 * Código do curso Magos do Arduino para utilizar um transistor para 
 * controlar um motor dc com o Arduino.
 * 
 * Controle de um motor dc de ~5v utilizando um transistor 2N2222.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_TRANSISTOR 2

void setup() {
  pinMode(PINO_TRANSISTOR, OUTPUT);
}

void loop() {
  digitalWrite(PINO_TRANSISTOR, HIGH);
  delay(3000);
  digitalWrite(PINO_TRANSISTOR, LOW);
  delay(3000);
}
