/**
 * Código do curso Magos do Arduino para gravar dados complexos na EEPROM do Arduino. 
 * 
 * Código de teste de EEPROM para as funções de put e get.
 * Grava os valores complexos (struct), e depois imprime no monitor serial os valores gravados.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#include <EEPROM.h>

struct Sensor {
  float temperatura;
  int umidade;
  char titulo[20];
};

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // aguarda uma conexão serial
  }

  // gera dados a serem gravados na EEPROM
  Sensor dadosSensor = {
    26.5f,
    75,
    "Magos do Arduino"
  };

  // grava os dados na EEPROM
  EEPROM.put(0, dadosSensor);

  // realiza a leitura dos dados da EEPROM
  Sensor leituraDados = {};
  EEPROM.get(0, leituraDados);

  Serial.println("Valores obtidos da EEPROM: ");
  Serial.print("Temperatura: ");
  Serial.println(leituraDados.temperatura);
  Serial.print("Umidade: ");
  Serial.println(leituraDados.umidade);
  Serial.print("Título: ");
  Serial.println(leituraDados.titulo);
}

void loop() {
}
