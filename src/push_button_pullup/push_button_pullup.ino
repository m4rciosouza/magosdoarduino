/**
 * Código do curso Magos do Arduino para utilizar um push button em nodo Pull Up.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define BTN_PIN 2

void setup() {
  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int valorBtn = digitalRead(BTN_PIN);

  if (valorBtn == HIGH) {
    digitalWrite(LED_BUILTIN, LOW);
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
  }
}