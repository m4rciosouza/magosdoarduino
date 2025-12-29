/**
 * Código do curso Magos do Arduino para utilizar módulo de cartão SD
 * com o Arduino. 
 * 
 * Código que cria um novo arquivo no cartão SD, escreve um texto nele, e depois realiza 
 * sua leitura imprimindo o seu conteúdo no Monitor Serial.
 * 
 * Depende da biblioteca SD, que já vem instalada por padrão na IDE do Arduino.
 * 
 * Cartão SD deve estar formatado em FAT16 ou FAT32 para funcionar corretamente.
 * 
 *  Pinos do módulo de cartão SD conectado ao Arduino UNO via SPI:
 * - SDO/MOSI - pino 11
 * - SDI/MISO - pino 12
 * - CLK/SCK  - pino 13
 * - CS       - pino  4
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#include <SD.h>

#define PINO_CS 4 // pino conectado ao CS (Chip Select) do módulo

File arquivo;

void setup() {
  Serial.begin(9600); // inicializa a conexão serial
  while (!Serial) {
    ;  // aguarda pela conexão serial
  }

  Serial.println("inicializando o cartão SD...");

  // inicializa a conexão com o cartão SD
  if (!SD.begin(PINO_CS)) {
    Serial.println("erro inicializando cartão SD, verifique a conexão do módulo");
    while (1);
  }

  Serial.println("inicialização do cartão SD realizada com sucesso!");

  // abre um arquivo, somente um arquivo pode ser aberto de cada vez,
  // para abrir outro arquivo, feche o aberto primeiramente
  arquivo = SD.open("teste.txt", FILE_WRITE);

  // verifica se o arquivo foi aberto, e então escreve nele
  if (arquivo) {
    Serial.println("\nescrevendo no arquivo teste.txt...");
    arquivo.println("Magos do Arduino, por Kazale IT!");
    // fecha o arquivo
    arquivo.close();
    Serial.println("operação de escrita realizada com sucesso!");
  } else {
    // exibe erro caso não consiga abrir o arquivo para escrita
    Serial.println("erro abrindo o arquivo teste.txt para escrita");
  }

  // abre o arquivo novamente, mas agora para leitura dos dados
  arquivo = SD.open("teste.txt");
  if (arquivo) {
    Serial.println("\nconteúdo do arquivo teste.txt:");

    // lê e imprime to do o conteúdo do arquivo
    while (arquivo.available()) {
      Serial.write(arquivo.read());
    }
    // fecha o arquivo
    arquivo.close();
  } else {
    // exibe erro caso não consiga abrir o arquivo para escrita
    Serial.println("erro abrindo o arquivo teste.txt para leitura dos dados");
  }
}

void loop() {
}
