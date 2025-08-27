/**
 * Código do curso Magos do Arduino para utilizar um receptor 
 * infravermelho (IR) com o Arduino. 
 * 
 * Utilize um receptor IR com o Arduino para receber comandos 
 * de um controle remoto, imprimindo os valores recebidos no 
 * monitor serial e acendendo ou apagando o LED do Arduino.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#include <IRremote.hpp>

#define PINO_RECEPTOR_IR 12
#define BTN_0 0xE916FF00 // valor do botão 0 no controle remoto
#define BTN_1 0xF30CFF00 // valor do botão 1 no controle remoto

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  IrReceiver.begin(PINO_RECEPTOR_IR);
}

unsigned long valor;

void loop() {
  if (IrReceiver.decode()) {
    // imprime comando em hexadecimal
    valor = IrReceiver.decodedIRData.decodedRawData;
    Serial.print("Comando recebido: ");
    Serial.println(valor, HEX);

    // imprime informações completas recebidas
    Serial.println("Todas informações recebidas:");
    IrReceiver.printIRResultShort(&Serial);

    // imprime comando utilizado para envio com emissor IR
    Serial.println("Comando para enviar dados com emissor IR:");
    IrReceiver.printIRSendUsage(&Serial);
    
    // permite receber a próxima leitura
    IrReceiver.resume();
  }

  // verifica os valores recebidos e acende ou apaga o LED do Arduino
  switch (valor) {
    case BTN_0:
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case BTN_1:
      digitalWrite(LED_BUILTIN, HIGH);
      break;
  }

  delay(100);
}
