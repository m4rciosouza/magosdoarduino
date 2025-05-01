/**
 * Código do curso Magos do Arduino para conectar uma barra 
 * de LEDs de 10 segmentos com o Arduino.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_LED_1 2
#define PINO_LED_2 3
#define PINO_LED_3 4
#define PINO_LED_4 5
#define PINO_LED_5 6
#define PINO_LED_6 7
#define PINO_LED_7 8
#define PINO_LED_8 9
#define PINO_LED_9 10
#define PINO_LED_10 11

// cria uma lista com os pinos para facilitar a iteração nos leds
int pinosLeds[] = {
  PINO_LED_1,
  PINO_LED_2,
  PINO_LED_3,
  PINO_LED_4,
  PINO_LED_5,
  PINO_LED_6,
  PINO_LED_7,
  PINO_LED_8,
  PINO_LED_9,
  PINO_LED_10
};

void setup() {
  // inicializa todos os leds como saída (OUTPUT)
  for (int i = 0; i < 10; i++) {
    pinMode(pinosLeds[i], OUTPUT);
  }
}

void loop() {
  // apagam todos os leds
  apagarLeds();
  delay(500);

  // acende cada led individualmente, aguardando meio segundo a cada iteração
  for (int i = 0; i < 10; i++) {
    digitalWrite(pinosLeds[i], HIGH);
    delay(500);
  }

}

void apagarLeds() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(pinosLeds[i], LOW);
  }
}
