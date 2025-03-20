/**
 * Código do curso Magos do Arduino para utilizar um push button em nodo Pull Down.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

// define o pino onde será conectado o push button
#define BTN_PIN 2

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // inicializa o led como output/saída
  pinMode(BTN_PIN, INPUT); // inicializa o pino do push button da placa Arduino como input/entrada
}

void loop() {
  int valorBtn = digitalRead(BTN_PIN); // faz a leitura do estado corrente do push button

  if (valorBtn == HIGH) { // caso push button pressionado
    digitalWrite(LED_BUILTIN, HIGH); // acende o led
  } else { // caso não pressionado
    digitalWrite(LED_BUILTIN, LOW); // led apagado
  }
}