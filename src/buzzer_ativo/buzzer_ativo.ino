/**
 * Código do curso Magos do Arduino para utilizar um buzzer ativo.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

// define o pino onde será conectado o buzzer
#define BUZZER_PIN 8

void setup() {
  pinMode(BUZZER_PIN, OUTPUT); // inicializa o pino do buzzer como output/saída
}

void loop() {
  digitalWrite(BUZZER_PIN, HIGH); // toca som
  delay(500); // aguarda meio segundo
  digitalWrite(BUZZER_PIN, LOW); // para o som
  delay(500); // aguarda meio segundo
}