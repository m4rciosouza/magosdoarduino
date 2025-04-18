/**
 * Código do curso Magos do Arduino para criar uma biblioteca para controlar um 
 * display de sete segmentos com Arduino.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#include "SeteSegmentos.h"

#define PINO_A 1
#define PINO_B 2
#define PINO_C 3
#define PINO_D 4
#define PINO_E 5
#define PINO_F 6
#define PINO_G 7

SeteSegmentos seteSegmentos(PINO_A, PINO_B, PINO_C, PINO_D, PINO_E, PINO_F, PINO_G);

void setup() {
  // inicializa os pinos do diplay de setesegmentos
  seteSegmentos.inicializar();

  // faz uma contagem regressiva de 9 a 0 e depois limpa o display
  seteSegmentos.exibirNum9();
  delay(500);
  seteSegmentos.exibirNum8();
  delay(500);
  seteSegmentos.exibirNum7();
  delay(500);
  seteSegmentos.exibirNum6();
  delay(500);
  seteSegmentos.exibirNum5();
  delay(500);
  seteSegmentos.exibirNum4();
  delay(500);
  seteSegmentos.exibirNum3();
  delay(500);
  seteSegmentos.exibirNum2();
  delay(500);
  seteSegmentos.exibirNum1();
  delay(500);
  seteSegmentos.exibirNum0();
  delay(500);
  seteSegmentos.limpar();
  delay(2000);
}

byte numero = 0;
void loop() {
  seteSegmentos.exibir(numero++);

  if (numero == 10) {
    numero = 0;
  }
  
  delay(1000);
}
