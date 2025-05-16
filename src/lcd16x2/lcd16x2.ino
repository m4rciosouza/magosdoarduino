/**
 * Código do curso Magos do Arduino para conectar um display 
 * LCD de 16x2 com o Arduino.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#include <LiquidCrystal.h>

#define PINO_RS 12
#define PINO_ENABLE 11
#define PINO_D4 5
#define PINO_D5 4
#define PINO_D6 3
#define PINO_D7 2

byte sorriso[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte coracao[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte casa[8] = {
  0b00100,
  0b01110,
  0b11111,
  0b01110,
  0b01010,
  0b01010,
  0b01110,
  0b00000
};

// cria uma instância do LCD
LiquidCrystal lcd(PINO_RS, PINO_ENABLE, PINO_D4, PINO_D5, PINO_D6, PINO_D7);

void setup() {
  // iniciailiza o LCD com as dimensões corretas
  lcd.begin(16, 2);

  // cria novos caracteres
  lcd.createChar(0, sorriso);
  lcd.createChar(1, coracao);
  lcd.createChar(2, casa);
}

void loop() {
  // move o cursor para a primeira coluna na primeira linha
  lcd.setCursor(0, 0);
  // imprime uma mensagem no display
  lcd.print("Magos do Arduino!");
  delay(3000);

  for (int i=0; i<17; i++) {
    // faz a rolagem do texto para a esquerda
    lcd.scrollDisplayLeft();
    delay(150);
  }

  for (int i=0; i<17; i++) {
    // faz a rolagem do texto para a direita
    lcd.scrollDisplayRight();
    delay(150);
  }

  // limpa a tela
  lcd.clear();
  lcd.print("Teste cursor");
  // move o cursor para a primeira coluna na segunda linha
  lcd.setCursor(0, 1);
  lcd.print("Parado:");
  // exibe o cursor
  lcd.cursor();
  delay(3000);

  // limpa a tela
  lcd.clear();
  lcd.print("Teste cursor");
  // move o cursor para a primeira coluna na segunda linha
  lcd.setCursor(0, 1);
  lcd.print("Piscando:");
  // piscar cursor
  lcd.blink();
  delay(3000);

  // limpa a tela
  lcd.clear();
  lcd.print("Teste cursor");
  // move o cursor para a primeira coluna na segunda linha
  lcd.setCursor(0, 1);
  lcd.print("Parado:");
  // parar de piscar o cursor
  lcd.noBlink();
  delay(3000);

  // limpa a tela
  lcd.clear();
  lcd.print("Teste cursor");
  // move o cursor para a primeira coluna na segunda linha
  lcd.setCursor(0, 1);
  lcd.print("Sem cursor:");
  // remove o cursor
  lcd.noCursor();
  delay(3000);

  // limpa a tela
  lcd.clear();
  // exibem os novos caracteres
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));
  delay(3000);

  // limpa a tela
  lcd.clear();
}
