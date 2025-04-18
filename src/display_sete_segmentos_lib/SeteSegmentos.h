/**
 * Código do curso Magos do Arduino para criar uma biblioteca para controlar um 
 * display de sete segmentos com Arduino.
 * 
 * Este código define o header da classe SeteSegmentos, 
 * que é responsável por controlar um display de sete segmentos.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#ifndef SeteSegmentos_h
#define SeteSegmentos_h

#include "Arduino.h"

class SeteSegmentos {
  public:
    SeteSegmentos(int pinoA, int pinoB, int pinoC, int pinoD, int pinoE, int pinoF, int pinoG);
    void inicializar();
    void exibir(int numero);
    void limpar();
    void exibirNum0();
    void exibirNum1();
    void exibirNum2();
    void exibirNum3();
    void exibirNum4();
    void exibirNum5();
    void exibirNum6();
    void exibirNum7();
    void exibirNum8();
    void exibirNum9();
  private:
    int _pinoA;
    int _pinoB;
    int _pinoC;
    int _pinoD;
    int _pinoE; 
    int _pinoF;
    int _pinoG;
    byte _digitos[10][7] = {
      { 1, 1, 1, 1, 1, 1, 0 }, // 0
      { 0, 1, 1, 0, 0, 0, 0 }, // 1
      { 1, 1, 0, 1, 1, 0, 1 }, // 2 
      { 1, 1, 1, 1, 0, 0, 1 }, // 3
      { 0, 1, 1, 0, 0, 1, 1 }, // 4
      { 1, 0, 1, 1, 0, 1, 1 }, // 5
      { 1, 0, 1, 1, 1, 1, 1 }, // 6
      { 1, 1, 1, 0, 0, 0, 0 }, // 7
      { 1, 1, 1, 1, 1, 1, 1 }, // 8
      { 1, 1, 1, 1, 0, 1, 1 }  // 9
    };
};

#endif