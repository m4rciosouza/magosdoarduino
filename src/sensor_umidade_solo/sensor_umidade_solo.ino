/**
 * Código do curso Magos do Arduino para utilizar um sensor de umidade do solo com o Arduino. 
 * 
 * Imprima no monitor serial as leituras digitais e analógicas de um sensor de umidade de solo com o Arduino.
 * Se o valor do sensor for maior que 600, mas menor que 1000, o solo está seco. 
 * Se o valor do sensor estiver entre 370 e 600, o solo está úmido. 
 * Se o valor do sensor for menor que 370, o sensor está na água.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_SENSOR_DIGITAL 2
#define PINO_SENSOR_ANALOGICO A0

int valorDigital = 0;
int valorAnalogico = 0;

void setup() {
  pinMode(PINO_SENSOR_DIGITAL, INPUT);

  Serial.begin(9600);
}

void loop() {
  // faz a leitura do valor digital do sensor
  valorDigital = digitalRead(PINO_SENSOR_DIGITAL);
  // imprime o valor digital obtido pelo sensor
  Serial.print("Valor digital: ");
  Serial.println(valorDigital);

  // imprime uma mensagem com base no valor digital obtido (HIGH ou LOW)
  if (valorDigital == HIGH) {
    Serial.println("Nível da umidade do solo está no nível desejado.");
  } else {
    Serial.println("Nível da umidade do solo está abaixo do valor desejado.");
  }

  // faz a leitura do valor analógico do sensor
  valorAnalogico = analogRead(PINO_SENSOR_ANALOGICO);

  // imprime o valor analógido obtido pelo sensor
  Serial.print("Valor analógico: ");
  Serial.println(valorAnalogico);

  // imprime o nível de umidade do solo.
  Serial.print("Nível de umidade do solo: ");
  if (valorAnalogico > 600) {
    Serial.println("o solo está seco.");
  } else if (valorAnalogico > 370) {
    Serial.println("o solo está úmido.");
  } else { // menor do que 370
    Serial.println("o solo está com excesso de água.");
  }

  Serial.println("");
  delay(500);
}