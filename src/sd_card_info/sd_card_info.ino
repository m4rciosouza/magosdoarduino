/**
 * Código do curso Magos do Arduino para utilizar módulo de cartão SD
 * com o Arduino. 
 * 
 * Código que imprime no monitor serial as principais informações sobre o cartão SD, 
 * como tipo, tamanho da partição e lista de arquivos presentes no cartão.
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

#include <SPI.h>
#include <SD.h>

#define PINO_CS 4 // pino conectado ao CS (Chip Select) do módulo

// variáveis de conexão do módulo SD
Sd2Card cartao;
SdVolume volume;
SdFile root;

void setup() {
  Serial.begin(9600); // inicializa a conexão serial
  while (!Serial) {
    ;  // aguarda pela conexão serial
  }

  Serial.println("inicializando o cartão SD...");

  // inicializa a conexão com o cartão SD
  if (!cartao.init(SPI_HALF_SPEED, PINO_CS)) {
    Serial.println("erro inicializando cartão SD, verifique a conexão do módulo");
    while (1);
  }
  
  Serial.println("inicialização do cartão SD realizada com sucesso!");

  // imprime o tipo do cartão SD
  Serial.print("\nTipo do cartão SD:   ");
  switch (cartao.type()) {
    case SD_CARD_TYPE_SD1:
      Serial.println("SD1");
      break;
    case SD_CARD_TYPE_SD2:
      Serial.println("SD2");
      break;
    case SD_CARD_TYPE_SDHC:
      Serial.println("SDHC");
      break;
    default:
      Serial.println("desconhecido");
  }

  // verifica se o cartão SD está formatado em FAT16 ou FAT32
  if (!volume.init(cartao)) {
    Serial.println("partição FAT16/FAT32 não encontrada, insira um cartão formatado em FAT16 ou FAT32");
    while (1);
  }

  Serial.print("Clusters:            ");
  Serial.println(volume.clusterCount());
  Serial.print("Setores por cluster: ");
  Serial.println(volume.blocksPerCluster());
  Serial.print("Total de setores:    ");
  Serial.println(volume.blocksPerCluster() * volume.clusterCount());

  // imprime o tipo da partição e seus valores
  uint32_t tamanhoParticao;
  Serial.print("\nPartição:            FAT");
  Serial.println(volume.fatType(), DEC);

  tamanhoParticao = volume.blocksPerCluster() * volume.clusterCount();
  tamanhoParticao /= 2; // setores do cartão SD são sempre de 512 bytes (2 setores são 1 KB)
  Serial.print("Partição (KB):       ");
  Serial.println(tamanhoParticao);
  Serial.print("Partição (MB):       ");
  tamanhoParticao /= 1024;
  Serial.println(tamanhoParticao);
  Serial.print("Partição (GB):       ");
  Serial.println((float) tamanhoParticao / 1024.0);

  Serial.println("\nArquivos encontrados no cartão SD (nome, data e tamanho em bytes): ");
  root.openRoot(volume);

  // listam todos os arquivos do cartão SD
  root.ls(LS_R | LS_DATE | LS_SIZE);
  root.close();
}

void loop() {
}