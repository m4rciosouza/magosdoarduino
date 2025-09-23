/**
 * Código do curso Magos do Arduino para utilizar um sensor de leitura RFID de cartões com o Arduino
 * 
 * Código de demonstração que grava e lê dados de um cartão RFID, imprimindo no monitor serial 
 * detalhes do processo com o Arduino.
 * 
 * Utiliza a biblioteca MFRC522 para a operação deste sensor com o Arduino. 
 * Esta biblioteca pode ser instalada diretamente através do Arduino IDE.
 * 
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 */

#include <SPI.h> // importa biblioteca para comunicação SPI
#include <MFRC522.h> // importa biblioteca para RFID

#define PINO_SDA 10
#define PINO_RESET 9

MFRC522 mfrc522(PINO_SDA, PINO_RESET); // cria instância do objeto MFRC522
MFRC522::MIFARE_Key key; // chave de armazenamento da chave de segurança do cartão

int bloco = 2; // bloco onde será escrito e lida as informções do cartão

byte conteudoBloco[16] = { "Kazale IT" };  // array de 16 bytes com o conteúdo a ser inscrito no cartão
byte valorLeituraBloco[18]; // array para a leitura de um bloco, tamanho 18 por causa da biblioteca

void setup() {
  Serial.begin(9600);  // inicializa a comunicação serial
  SPI.begin();         // inicializa a comunicação SPI
  mfrc522.PCD_Init();  // inicializa o objeto MFRC522

  Serial.println("Escaneamento de um cartão MIFARE");

  // prepara chave de segurança utilizada para autenticação e realização dos processos de leitura e escrita
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;  // chave padrão definida para este tipo de cartões
  }
}

void loop() {
  // verifica se existe cartão disponível para leitura
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // seleciona o cartão
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.println("cartão selecionado");

  // realiza a gravação dos dados no cartão por bloco
  gravarBloco(bloco, conteudoBloco);

  // realiza a leitura dos dados do cartão por bloco
  lerBloco(bloco, valorLeituraBloco);

  // imprime todos os dados do cartão
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));

  // imprime os dados lidos do cartão
  Serial.print("dados do cartão: ");
  for (int i = 0; i < 16; i++) {
    if (valorLeituraBloco[i] > 0) {
      Serial.write(valorLeituraBloco[i]);
    }
  }
  Serial.println("");
}

// grava no cartão o conteúdo passado como parâmetro no bloco informado
void gravarBloco(int numeroBloco, byte conteudo[]) {
  // realiza cálculos para validação do bloco
  int maiorModulo4 = numeroBloco / 4 * 4;
  int trailerBloco = maiorModulo4 + 3;
  if (numeroBloco > 2 && (numeroBloco + 1) % 4 == 0) {
    Serial.println("erro validando bloco.");
    return;
  }

  // autentica para acesso ao bloco
  MFRC522::StatusCode status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBloco, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("erro ao autenticar cartão: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  // realiza a escrita dos dados no bloco
  status = mfrc522.MIFARE_Write(numeroBloco, conteudo, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("erro gravando dados no cartão: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  Serial.println("bloco gravado com sucesso!");
}

// realiza a leitura dos dados de um bloco do cartão
void lerBloco(int numeroBloco, byte conteudo[]) {
  int maiorModulo4 = numeroBloco / 4 * 4;
  int trailerBloco = maiorModulo4 + 3;

  // autentica para acesso ao bloco
  MFRC522::StatusCode status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBloco, &key, &(mfrc522.uid));

  if (status != MFRC522::STATUS_OK) {
    Serial.print("erro ao autenticar cartão: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  // realiza a leitura dos dados de um bloc do cartão
  byte tamanhoBuffer = 18;
  status = mfrc522.MIFARE_Read(numeroBloco, conteudo, &tamanhoBuffer);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("erro lendo dados no cartão: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  Serial.println("bloco lido com sucesso!");
}
