/**
 * Código do curso Magos do Arduino para utilizar um fotoresistor que quando 
 * acionado iniciará a transição de cores de um LED RGB.
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

  digitalWrite(PINO_VERMELHO, LOW);
  digitalWrite(PINO_VERDE, LOW);
  digitalWrite(PINO_AZUL, LOW);
}

void loop() {
  int valor = analogRead(A0);
    
  if (valor > 650) {
    analogWrite(PINO_VERMELHO, 0);
    analogWrite(PINO_VERDE, 0);
    analogWrite(PINO_AZUL, 0);
  } else {
    mudarCor(PINO_VERMELHO, PINO_VERDE);
    mudarCor(PINO_VERDE, PINO_AZUL);
    mudarCor(PINO_AZUL, PINO_VERMELHO);
  }

  delay(250);
}

void mudarCor(int cor1, int cor2) {
  for (int i=0; i<255; i++) {
    analogWrite(cor1, i);
    analogWrite(cor2, 255 - i);
    delay(5);
  }
}
