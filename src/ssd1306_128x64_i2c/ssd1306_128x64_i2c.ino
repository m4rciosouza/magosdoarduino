/**
 * Código do curso Magos do Arduino para controlar um display SSD1306 I2C com o Arduino 
 * 
 * Código que demonstra como conectar um display SSD1306 I2C com o Arduino, 
 * utilizando a biblioteca da Adafruit para exibir no display formas geométricas, texto, 
 * bitmaps e também scroll de tela.
 * 
 * Conexão utiliza o protocolo I2C, por isso utilize os seguintes pinos do Arduino:
 * Arduino UNO:       A4(SDA), A5(SCL)
 * Arduino MEGA 2560: 20(SDA), 21(SCL)
 * Arduino LEONARDO:   2(SDA),  3(SCL)
 * 
 * Códigos da fonte no padrão 437: https://en.wikipedia.org/wiki/Code_page_437
 * Gerar código bitmap a partir de imagens: https://javl.github.io/image2cpp/
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define SSD1306_NO_SPLASH  // desabilita a splash screen

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define LARGURA_TELA 128  // largura da tela em pixels
#define ALTURA_TELA 64    // altura da tela em pixels

#define PINO_RESET_DISPLAY -1  // pino de reset (-1 se compartilhado com o pino de reset do Arduino, que é o caso)
#define ENDERECO_DISPLAY 0x3C  // endereço I2C do display

#define ESPERA_TRANSICAO 2000  // delay em milisegundos para transições de telas

// cria instância do display
Adafruit_SSD1306 display(LARGURA_TELA, ALTURA_TELA, &Wire, PINO_RESET_DISPLAY);

// define um bitmap de um gato em tamanho de 16x16 pixels
#define ALTURA_IMG  16
#define LARGURA_IMG 16
static const unsigned char PROGMEM gato16x16[] = {
	0x10, 0x22, 0x08, 0x36, 0x30, 0x3e, 0x40, 0x2a, 0x80, 0x6a, 0x80, 0x78, 0xc0, 0x38, 0x60, 0xd8, 
	0x1f, 0xe0, 0x1f, 0xf0, 0x1f, 0xf8, 0x3f, 0xe0, 0x30, 0x60, 0x68, 0x6c, 0x48, 0xc4, 0x44, 0x84
};

void setup() {
  Serial.begin(9600);  // inicializa conexão serial para debug

  // inicializa o display no endereço fornecido
  if (!display.begin(SSD1306_SWITCHCAPVCC, ENDERECO_DISPLAY)) {
    Serial.println("Erro inicializando display SSD1306");
    for (;;); // para a execução do programa
  }

  // desenha um único pixel no display
  display.clearDisplay();  // limpa o display
  display.drawPixel(10, 10, SSD1306_WHITE);
  display.display();        // exibe o pixel no display
  delay(ESPERA_TRANSICAO);

  // desenham duas linhas no display
  display.clearDisplay(); // limpa o display
  display.drawLine(10, 10, display.width() - 10, 10, SSD1306_WHITE);
  display.drawLine(10, 20, display.width() - 10, 20, SSD1306_WHITE);
  display.display(); // exibe o pixel no display
  delay(ESPERA_TRANSICAO);

  // desenha um retângulo
  display.clearDisplay(); // limpa o display
  display.drawRect(10, 10, display.width() - 10, display.height() - 10, SSD1306_WHITE);
  display.display();
  delay(ESPERA_TRANSICAO);

  // desenha um retângulo preenchido
  display.clearDisplay(); // limpa o display
  display.fillRect(10, 10, display.width() - 10, display.height() - 10, SSD1306_INVERSE);
  display.display();
  delay(ESPERA_TRANSICAO);

  // desenha um círculo
  display.clearDisplay(); // limpa o display
  display.drawCircle(display.width() / 2, display.height() / 2, 30, SSD1306_WHITE);
  display.display();
  delay(ESPERA_TRANSICAO);

  // desenha um círculo preenchido
  display.clearDisplay(); // limpa o display
  display.fillCircle(display.width() / 2, display.height() / 2, 20, SSD1306_INVERSE);
  display.display();
  delay(ESPERA_TRANSICAO);

  // desenha um retângulo com as bordas arredondadas
  display.clearDisplay(); // limpa o display
  display.drawRoundRect(10, 10, display.width() - 10, display.height() - 10, 30, SSD1306_WHITE);
  display.display();
  delay(ESPERA_TRANSICAO);

  // desenha um retângulo preenchido com as bordas arredondadas
  display.clearDisplay(); // limpa o display
  display.fillRoundRect(20, 20, display.width() - 20, display.height() - 20, 40, SSD1306_INVERSE);
  display.display();
  delay(ESPERA_TRANSICAO);

  // desenha um triângulo
  display.clearDisplay(); // limpa o display
  display.drawTriangle(
    display.width() / 2, display.height() / 2 - 10,
    display.width() / 2 - 10, display.height() / 2 + 10,
    display.width() / 2 + 10, display.height() / 2 + 10, SSD1306_WHITE);
  display.display();
  delay(ESPERA_TRANSICAO);

  // desenha um triângulo preenchido
  display.clearDisplay(); // limpa o display
  display.fillTriangle(
    display.width() / 2, display.height() / 2 - 20,
    display.width() / 2 - 20, display.height() / 2 + 20,
    display.width() / 2 + 20, display.height() / 2 + 20, SSD1306_INVERSE);
  display.display();
  delay(ESPERA_TRANSICAO);

  // imprime todos os caracteres no display
  display.clearDisplay();               // limpa o display
  display.setTextSize(1);               // tamanho de 1:1
  display.setTextColor(SSD1306_WHITE);  // define a cor
  display.setCursor(0, 0);              // posiciona o cursor
  display.cp437(true);                  // usa os caracteres da fonte de 256 códigos
  for (int i = 0; i < 256; i++) {
    if (i == '\n') {
      display.write(' ');
    } else {
      display.write(i);
    }
  }
  display.display();
  delay(ESPERA_TRANSICAO);

  // exibe um texto no display
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("KazaleIT");
  display.display(); // exibe o texto
  delay(ESPERA_TRANSICAO);

  // faz o scroll do texto em diferentes direções
  realizarScroll();

  // desenha um bitmap no display
  desenharBitmapGato();
  delay(ESPERA_TRANSICAO);

  // inverte e restaura as cores do display
  display.invertDisplay(true);
  delay(1000);
  display.invertDisplay(false);
  delay(1000);
}

void loop() {
  // faz scroll do bitmap em múltiplas direções
  realizarScroll();
}

// realiza o scroll em diferentes direções
void realizarScroll() {
  display.startscrollright(0, 30);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0, 15);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrolldiagright(0, 7);
  delay(2000);
  display.startscrolldiagleft(0, 7);
  delay(2000);
  display.stopscroll();
  delay(1000);
}
 
// desenha o bitmap gato16x16 no display
void desenharBitmapGato() {
  display.clearDisplay();
  display.drawBitmap(
    (display.width() - LARGURA_IMG) / 2,
    (display.height() - ALTURA_IMG) / 2,
    gato16x16, LARGURA_IMG, ALTURA_IMG, 1);
  display.display();
}
