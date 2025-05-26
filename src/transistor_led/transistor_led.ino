/**
 * Código do curso Magos do Arduino para utilizar um transistor com o Arduino.
 * 
 * Através do transistor um LED pisca a cada meio segundo. 
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
  delay(500);
  digitalWrite(PINO_TRANSISTOR, LOW);
  delay(500);
}
