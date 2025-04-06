/**
 * Código do curso Magos do Arduino para utilizar um potenciômetro 
 * imprimindo o valor lido no monitor serial.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_POT A3

void setup() {
  Serial.begin(9600);
}

int valorPot = 0;
void loop() {
  // faz a leitura do valor do potenciômetro
  valorPot = analogRead(PINO_POT);

  Serial.println(valorPot);
  
  delay(100);
}
