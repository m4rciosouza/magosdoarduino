/**
 * Código do curso Magos do Arduino para utilizar um teclado numérico matriz de 4x4 com o Arduino.
 * 
 * Imprima no monitor serial as leituras dos valores de cada tecla pressionada 
 * no teclado numérico matriz de 4x4 com o Arduino.
 * 
 * Utiliza a biblioteca Adafruit_Keypad, que pode ser instalada através do gerenciador de bibliotecas do Arduino IDE.
 * 
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 */

#include <Adafruit_Keypad.h>

// define os pinos de conexão do teclado com o Arduino
#define R1 2
#define R2 3
#define R3 4
#define R4 5
#define C1 8
#define C2 9
#define C3 10
#define C4 11

// dimensões do teclado
const byte LINHAS = 4;
const byte COLUNAS = 4;

// caracteres do teclado
char caracteres[LINHAS][COLUNAS] = { 
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' } 
};

// array com informações dos pinos das linhas e colunas
byte pinosLinhas[LINHAS] = { R1, R2, R3, R4 };
byte pinosColunas[COLUNAS] = { C1, C2, C3, C4 };

// criar uma instância da classe de controle do teclado
Adafruit_Keypad teclado4x4 = Adafruit_Keypad(makeKeymap(caracteres), pinosLinhas, pinosColunas, LINHAS, COLUNAS);

void setup() {
  // inicializa conexão serial
  Serial.begin(9600);
  // inicializa a classe de controle do teclado
  teclado4x4.begin();
}

void loop() {
  // faz a leitura e processamento caso botão pressionado ou liberado
  teclado4x4.tick();
  while (teclado4x4.available()) {
    keypadEvent e = teclado4x4.read();
    Serial.print((char)e.bit.KEY);
    if (e.bit.EVENT == KEY_JUST_PRESSED) {
      Serial.println(" pressionado");
    } else if (e.bit.EVENT == KEY_JUST_RELEASED) {
      Serial.println(" liberado");
    }
  }

  delay(10);
}
