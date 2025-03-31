/**
 * Código do curso Magos do Arduino para criar um transmissor de dados seriais.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define BTN_PIN 8

void setup() {
  pinMode(BTN_PIN, INPUT_PULLUP);

  // inicializa conexão serial, para Arduino UNO R3 use Serial
  // consulte https://docs.arduino.cc/language-reference/en/functions/communication/serial para maiores detalhes
  Serial1.begin(9600);
}

void loop() {
  int valorBtn = digitalRead(BTN_PIN);
  delay(300); // debouncing

  // caso botão pressionado informa o receptor
  if (valorBtn == LOW) {
    // para Arduino UNO R3 use Serial
    Serial1.write('1');
  }
}
