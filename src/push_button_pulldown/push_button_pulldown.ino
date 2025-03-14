/**
 * Código do curso Magos do Arduino para utilizar um push button em nodo Pull Down.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define BTN_PIN 2

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BTN_PIN, INPUT);
}

void loop() {
  int valorBtn = digitalRead(BTN_PIN);

  if (valorBtn == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}