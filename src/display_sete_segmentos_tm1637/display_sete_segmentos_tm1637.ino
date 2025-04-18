/**
 * Código do curso Magos do Arduino para utilizar um display de sete segmentos
 * de 4 dígitos controlado pelo TM1637 que exibe a hora e minutos.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#include <Arduino.h>
#include <TM1637Display.h>

#define PINO_CLK 2
#define PINO_DIO 3

TM1637Display display(PINO_CLK, PINO_DIO);

void setup() {
  // valores entre 0 e 7 para menos e mais brilho
  display.setBrightness(3);
}

// defina a hora e minuto inicial
int horas = 9;
int minutos = 56;
int segundos = 0;
void loop() {
  if (segundos == 60) {
    segundos = 0;
    minutos++;
  }

  if (minutos == 60) {
    minutos = 0;
    horas++;
  }

  if (horas == 24) {
    horas = 0;
  }

  char horasBuffer[4];
  sprintf(horasBuffer, "%02d%02d", horas, minutos);
 
  display.showNumberDecEx(atoi(horasBuffer), SEG_G, false, 4, 0);
  delay(1000);
  segundos++;

  display.showNumberDecEx(atoi(horasBuffer), 0, false, 4, 0);
  delay(1000);
  segundos++;
}
