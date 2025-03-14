/**
 * Código do curso Magos do Arduino para utilizar um buzzer ativo.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define BUZZER_PIN 8

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(500);
  digitalWrite(BUZZER_PIN, LOW);
  delay(500);
}