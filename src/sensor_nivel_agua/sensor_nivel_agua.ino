/**
 * Código do curso Magos do Arduino para utilizar um sensor de água com o Arduino. 
 * 
 * Imprima no monitor serial a leitura analógica de um sensor de água com o Arduino.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_SENSOR_ANALOGICO A0

int valorAnalogico = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // faz a leitura do valor analógico do sensor
  valorAnalogico = analogRead(PINO_SENSOR_ANALOGICO);

  // imprime o valor analógido obtido pelo sensor
  Serial.print("Valor analógico: ");
  Serial.println(valorAnalogico);

  delay(300);
}