/**
 * Código do curso Magos do Arduino para utilizar LED RGB gerando uma 
 * transição de cores como efeito.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_VERMELHO 3
#define PINO_VERDE 5
#define PINO_AZUL 6

void setup() {
  pinMode(PINO_VERMELHO, OUTPUT);
  pinMode(PINO_VERDE, OUTPUT);
  pinMode(PINO_AZUL, OUTPUT);

  digitalWrite(PINO_VERMELHO, HIGH);
  digitalWrite(PINO_VERDE, HIGH);
  digitalWrite(PINO_AZUL, HIGH);
}

void loop() {
  mudarCor(PINO_VERMELHO, PINO_VERDE);
  mudarCor(PINO_VERDE, PINO_AZUL);
  mudarCor(PINO_AZUL, PINO_VERMELHO);
}

void mudarCor(int cor1, int cor2) {
  for (int i=0; i<255; i++) {
    analogWrite(cor1, i);
    analogWrite(cor2, 255 - i);
    delay(5);
  }
}
