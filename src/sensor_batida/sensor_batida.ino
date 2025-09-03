/**
 * Código do curso Magos do Arduino para utilizar um Sensor de Batida (Knock) 
 * com o Arduino. 
 * 
 * Utilize o sensor de batida para acender e apagar um LED quando o sensor detectar
 * um sinal maior do que o limite definido no código do Arduino.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_LED 2
#define PINO_SENSOR_BATIDA A0
#define LIMITE_SENSOR 40

int valorSensor = 0;  // armazena o valor do sensor
int controleLed = LOW; // armazena se o LED está aceso ou apagado

void setup() {
  pinMode(PINO_LED, OUTPUT);
}

void loop() {
  // realiza a leitura do sensor
  valorSensor = analogRead(PINO_SENSOR_BATIDA);

  // caso valor lido seja maior do que o limite altera o status do LED
  if (valorSensor >= LIMITE_SENSOR) {
    // inverte o valor corrente do LED
    controleLed = !controleLed;
    digitalWrite(PINO_LED, controleLed);
  }

  delay(70);
}
