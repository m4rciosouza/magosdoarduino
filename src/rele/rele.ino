/**
 * Código do curso Magos do Arduino para utilizar um relê no Arduino.
 * 
 * Utilize um relé com o Arduino para ligar e desligar uma lâmpada 
 * conectada a uma fonte externa.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_RELE 8
#define PINO_BOTAO 2

void setup() {
  // inicializam os pinos do relê e botão
  pinMode(PINO_RELE, OUTPUT);
  pinMode(PINO_BOTAO, INPUT_PULLUP);
}

int estadoBotao = -1;

void loop() {
  // faz a leitura do botão
  int valorBotao = digitalRead(PINO_BOTAO);

  // caso botão pressionado, 0/LOW porque é pull-up
  if (valorBotao == LOW) {
    estadoBotao *= -1; // inverte o valor
  }

  // espera para debounce do botão
  delay(300);

  // ativa/desativa o relê
  if (estadoBotao == -1) {
    digitalWrite(PINO_RELE, LOW);
  } else {
    digitalWrite(PINO_RELE, HIGH);
  }
}
