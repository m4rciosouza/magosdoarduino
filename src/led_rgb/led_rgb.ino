/**
 * Código do curso Magos do Arduino para utilizar um LED RGB.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_VERMELHO 3
#define PINO_VERDE 5
#define PINO_AZUL 6

void setup() {
  pinMode(PINO_VERMELHO, OUTPUT);
  pinMode(PINO_VERDE, OUTPUT);
  pinMode(PINO_AZUL, OUTPUT);
}

void loop() {
  digitalWrite(PINO_VERMELHO, HIGH);
  delay(1000);
  digitalWrite(PINO_VERMELHO, LOW);
  digitalWrite(PINO_VERDE, HIGH);
  delay(1000);
  digitalWrite(PINO_VERDE, LOW);
  digitalWrite(PINO_AZUL, HIGH);
  delay(1000);
  digitalWrite(PINO_AZUL, LOW);
}
