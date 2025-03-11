/**
 * Código do curso Magos do Arduino para piscar um LED.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PIN_LED 2 // adicione o pino onde o led está conectado

void setup() {
  // define o pino do led como output/saída
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  digitalWrite(PIN_LED, HIGH);  // liga o led
  delay(500);                   // aguarda meio segundo
  digitalWrite(PIN_LED, LOW);   // desliga o led
  delay(500);                   // aguarda meio segundo
}
