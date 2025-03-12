#define BTN_PIN 2
#define LED_PIN 13

void setup() {
  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int valorBtn = digitalRead(BTN_PIN);

  if (valorBtn == HIGH) {
    digitalWrite(LED_PIN, LOW);
  } else {
    digitalWrite(LED_PIN, HIGH);
  }

  delay(100);
}