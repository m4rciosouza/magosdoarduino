/**
 * Código do curso Magos do Arduino para utilizar uma matriz de LEDs RGB (NeoPixel) com o Arduino
 * e exibir uma imagem em pixel art.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#include <Adafruit_NeoPixel.h>

#define PINO_DATA_LEDS 6 
#define NUMERO_PIXELS 256

#define PRETO pixels.Color(0, 0, 0)
#define LARANJA pixels.Color(255, 140, 0)
#define VERDE pixels.Color(0, 150, 0)
#define BRANCO pixels.Color(255, 255, 255)
#define ROXO pixels.Color(128, 0, 128)
#define AZUL pixels.Color(0, 0, 255)
#define VERMELHO pixels.Color(255, 0, 0)

Adafruit_NeoPixel pixels(NUMERO_PIXELS, PINO_DATA_LEDS, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

int imagemDragao[16][16] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 2, 2, 2, 2, 3, 3, 2, 3, 2, 0, 0 },
  { 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 0, 2, 0, 3, 0, 0 },
  { 0, 0, 0, 1, 2, 2, 2, 2, 3, 3, 0, 2, 0, 3, 0, 0 },
  { 0, 0, 0, 0, 2, 2, 2, 2, 3, 3, 0, 2, 0, 3, 2, 0 },
  { 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 0, 2, 0, 3, 2, 0 },
  { 0, 0, 0, 1, 2, 2, 2, 2, 2, 3, 3, 2, 3, 2, 2, 0 },
  { 0, 0, 0, 0, 2, 1, 2, 2, 0, 0, 0, 3, 0, 0, 0, 0 },
  { 0, 0, 0, 2, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 0, 0 },
  { 2, 0, 0, 2, 1, 1, 1, 2, 2, 3, 3, 3, 3, 0, 0, 0 },
  { 2, 1, 1, 2, 1, 1, 2, 2, 3, 3, 3, 3, 3, 3, 0, 0 },
  { 0, 2, 2, 2, 2, 2, 2, 1, 1, 3, 3, 3, 3, 3, 0, 0 },
  { 0, 0, 2, 2, 2, 2, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1 }
};

int paletaCores[4][4] = {
  { PRETO, LARANJA, VERDE, BRANCO }, // 0,1,2,3
  { PRETO, ROXO, AZUL, BRANCO },
  { PRETO, VERMELHO, LARANJA, BRANCO },
  { PRETO, ROXO, VERMELHO, LARANJA }
};

void loop() {
  int indice = 0; // restaura o valor inicial dos leds/pixels
  int idxPaleta = random(4); // 0-3
  pixels.clear(); // define os leds como desligado
  pixels.setBrightness(10); // define a intensidade dos leds

  for (int i=0; i<16; i++) { // itera nas linhas da imagem
    if (i % 2 == 0) { // caso linha par itera do fim para o início
      for (int j=15; j>=0; j--) {
        int cor = imagemDragao[i][j];
        pixels.setPixelColor(indice++, paletaCores[idxPaleta][cor]);
      }

    } else { // ou do início da linha para o fim
      for (int j=0; j<16; j++) {
        int cor = imagemDragao[i][j];
        pixels.setPixelColor(indice++, paletaCores[idxPaleta][cor]);
      }
    }
  }

  pixels.show();
  delay(5000);
}
