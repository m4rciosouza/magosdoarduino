/**
 * Código do curso Magos do Arduino para utilizar um potenciômetro 
 * para controlar a luminosidade de um LED.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_POT A3
#define PINO_LED 3

void setup() {
  pinMode(PINO_LED, OUTPUT);
}

int valorPot = 0;
void loop() {
  // faz a leitura do valor do potenciômetro
  valorPot = analogRead(PINO_POT);

  // mapeia p valor para o intervalo de 0-255 e o utiliza para acender o led
  analogWrite(PINO_LED, map(valorPot, 0, 1023, 0, 255));
  
  delay(50);
}
