/**
 * Código do curso Magos do Arduino para utilizar um push button em nodo Pull Up.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

// define o pino onde será conectado o push button
#define BTN_PIN 2

void setup() {
  pinMode(BTN_PIN, INPUT_PULLUP); // inicializa o pino do push button como pull up
  pinMode(LED_BUILTIN, OUTPUT); // inicializa o led da placa Arduino como saída
}

void loop() {
  int valorBtn = digitalRead(BTN_PIN); // faz a leitura do estado corrente do push button

  if (valorBtn == HIGH) { // caso não pressionado 
    digitalWrite(LED_BUILTIN, LOW); // led apagado
  } else { // caso push button pressionado
    digitalWrite(LED_BUILTIN, HIGH); // acende o led
  }
}