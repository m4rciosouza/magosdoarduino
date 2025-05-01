/**
 * Código do curso Magos do Arduino para conectar uma matriz
 * de LEDs 8x8 com o Arduino. 
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

// pinos das colunas
#define COL_1 2  // 13
#define COL_2 3  // 3
#define COL_3 4  // 4
#define COL_4 5  // 10
#define COL_5 6  // 6
#define COL_6 7  // 11
#define COL_7 8  // 15
#define COL_8 9  // 16

// pinos da linhas
#define LINHA_1 10  // 9
#define LINHA_2 11  // 14
#define LINHA_3 12  // 8
#define LINHA_4 13  // 12
#define LINHA_5 A2  // 1
#define LINHA_6 A3  // 7
#define LINHA_7 A4  // 2
#define LINHA_8 A5  // 5

// adicionam as linhas em uma lista
int linhas[8] = { 
  LINHA_1, LINHA_2, LINHA_3, LINHA_4, LINHA_5, LINHA_6, LINHA_7, LINHA_8 
};

// adicionam as colunas em uma lista
int colunas[8] = { 
  COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8 
};

// mapeiam as imagens a serem exibidas
int coracao[8][8] = {
  { 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 1, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 1, 0, 0, 0, 0, 1, 1 },
  { 1, 1, 1, 0, 0, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1 }
};

int sorriso[8][8] = {
  { 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 0, 1, 1, 1, 1, 0, 1 },
  { 1, 1, 0, 1, 1, 0, 1, 1 },
  { 1, 1, 1, 0, 0, 1, 1, 1 }
};

int quadrados[8][8] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 1, 1, 0, 1, 0 },
  { 0, 1, 0, 1, 1, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};

int letraA[8][8] = {
  { 1, 1, 0, 0, 0, 0, 1, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 }
};

int letraB[8][8] = {
  { 1, 0, 0, 0, 0, 0, 1, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 1, 1 }
};

int letraC[8][8] = {
  { 1, 1, 0, 0, 0, 0, 1, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 1, 0, 0, 0, 0, 1, 1 }
};

void setup() {
  // define os pinos das linhas e colunas como saída (OUTPUT)
  for (int i = 0; i < 8; i++) {
    pinMode(linhas[i], OUTPUT);
    pinMode(colunas[i], OUTPUT);
  }
}

// controla o tempo de exibição de cada imagem no display
unsigned long ultimoTempo = 0;
unsigned long espera = 2000; // define o tempo de espera em milisegundos
int exibir = 0; // controla a imagem a ser exibida

void loop() {
  // verifica que se deve mudar a imagem a ser exibida 
  // ao término do tempo de espera
  if ((millis() - ultimoTempo) > espera) {
    exibir++;
    if (exibir > 5) {
      exibir = 0;
    }
    ultimoTempo = millis();
  }

  // exibe a imagem 
  if (exibir == 0) {
    exibirImagem(coracao);  
  } else if (exibir == 1) {
    exibirImagem(quadrados);
  } else if (exibir == 2) {
    exibirImagem(sorriso);
  } else if (exibir == 3) {
    exibirImagem(letraA);
  } else if (exibir == 4) {
    exibirImagem(letraB);
  } else if (exibir == 5) {
    exibirImagem(letraC);
  }
}

void exibirImagem(int dados[8][8]) {
  // itera sob todas as linhas
  for (int i=0; i<8; i++) {
    // habilita a linha i para ligar os leds
    digitalWrite(linhas[i], HIGH);
    // itera sob as colunas de uma linha
    for (int j=0; j<8; j++) {
      // acende(0) ou apaga(1) o led da coluna j para a linha i
      digitalWrite(colunas[j], dados[i][j]);
      // tempo de espera que pode ser uilizado para debug
      // delay(20);
      // apaga o led corrente caso esteja aceso
      if (dados[i][j] == 0) {
        digitalWrite(colunas[j], HIGH);
      }
    }
    // desabilita a linha i
    digitalWrite(linhas[i], LOW);
  }
}