/**
 * Código do curso Magos do Arduino para utilizar um emissor/transmissor 
 * infravermelho (IR) com o Arduino. 
 * 
 * Utilize um emissor IR com o Arduino para enviar comandos para outro 
 * dispositivo. Este exemplo usa como referência o projeto ir_receptor.ino.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#include <IRremote.hpp>

#define PINO_EMISSOR_IR 12

void setup() {
  // inicializa o objeto de emissão IR
  IrSender.begin(PINO_EMISSOR_IR);
}

void loop() {
  // comando do botão 0, apaga o LED
  IrSender.sendNEC(0x0, 0x16, 0);
  delay(1000);

  // comando do botão 1, acende o LED
  IrSender.sendNEC(0x0, 0xC, 0);
  delay(1000);
}
