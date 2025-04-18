/**
 * Código do curso Magos do Arduino para criar uma biblioteca para controlar um 
 * display de sete segmentos com Arduino.
 * 
 * Este código implementa o header da classe SeteSegmentos, 
 * que é responsável por controlar um display de sete segmentos.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#include "Arduino.h"
#include "SeteSegmentos.h"

SeteSegmentos::SeteSegmentos(int pinoA, int pinoB, int pinoC, int pinoD, int pinoE, int pinoF, int pinoG) {
  _pinoA = pinoA;
  _pinoB = pinoB;
  _pinoC = pinoC;
  _pinoD = pinoD;
  _pinoE = pinoE;
  _pinoF = pinoF;
  _pinoG = pinoG;
}

void SeteSegmentos::inicializar() {
  pinMode(_pinoA, OUTPUT);
  pinMode(_pinoB, OUTPUT);
  pinMode(_pinoC, OUTPUT);
  pinMode(_pinoD, OUTPUT);
  pinMode(_pinoE, OUTPUT);
  pinMode(_pinoF, OUTPUT);
  pinMode(_pinoG, OUTPUT);
}

void SeteSegmentos::exibir(int numero) {
  digitalWrite(_pinoA, _digitos[numero][0]);
  digitalWrite(_pinoB, _digitos[numero][1]);
  digitalWrite(_pinoC, _digitos[numero][2]);
  digitalWrite(_pinoD, _digitos[numero][3]);
  digitalWrite(_pinoE, _digitos[numero][4]);
  digitalWrite(_pinoF, _digitos[numero][5]);
  digitalWrite(_pinoG, _digitos[numero][6]);
}

void SeteSegmentos::limpar() {
  digitalWrite(_pinoA, LOW);
  digitalWrite(_pinoB, LOW);
  digitalWrite(_pinoC, LOW);
  digitalWrite(_pinoD, LOW);
  digitalWrite(_pinoE, LOW);
  digitalWrite(_pinoF, LOW);
  digitalWrite(_pinoG, LOW);
}

void SeteSegmentos::exibirNum0() {
  exibir(0);
}

void SeteSegmentos::exibirNum1() {
  exibir(1);
}

void SeteSegmentos::exibirNum2() {
  exibir(2);
}

void SeteSegmentos::exibirNum3() {
  exibir(3);
}

void SeteSegmentos::exibirNum4() {
  exibir(4);
}

void SeteSegmentos::exibirNum5() {
  exibir(5);
}

void SeteSegmentos::exibirNum6() {
  exibir(6);
}

void SeteSegmentos::exibirNum7() {
  exibir(7);
}

void SeteSegmentos::exibirNum8() {
  exibir(8);
}

void SeteSegmentos::exibirNum9() {
  exibir(9);
}
