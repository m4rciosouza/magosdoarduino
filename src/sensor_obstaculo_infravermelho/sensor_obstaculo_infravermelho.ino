/**
 * Código do curso Magos do Arduino para conectar um sensor 
 * de obstáculo infravermelho com o Arduino.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_SENSOR 2

void setup() {
  Serial.begin(9600);
}

int quantidade = 0;

void loop() {
  int valorSensor = digitalRead(PINO_SENSOR);

  if (valorSensor == HIGH) {
    quantidade++;
    Serial.print("Número de detecções: ");
    Serial.println(quantidade);
  }

  delay(500);
}
