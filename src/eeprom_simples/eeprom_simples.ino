/**
 * Código do curso Magos do Arduino para gravar dados simples na EEPROM Arduino. 
 * 
 * Código de teste de EEPROM para as funções de write, update e read.
 * Grava os valores de 1 a 10 a partir do endereço de memória 10, e depois 
 * imprime no monitor serial os valores gravados.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // aguarda uma conexão serial
  }

  int endereco = 10; // endereço onde será gravado valores na EEPROM

  // grava os dados na EEPROM usando as funções write e update
  for (int i=0; i<10; i++) {
    // EEPROM.write(endereco, i + 1);
    EEPROM.update(endereco, i + 1);
    endereco++;
  }

  // lê os dados da EEPROM com o read e imprime os valores no monitor serial
  for (int j=10; j<20; j++) {
    int valor = EEPROM.read(j);
    Serial.print("Endereço: ");
    Serial.print(j);
    Serial.print(", Valor: ");
    Serial.println(valor);
  }
}

void loop() {
}
