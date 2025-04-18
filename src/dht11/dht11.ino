/**
 * Código do curso Magos do Arduino para utilizar o sensor de umidade e 
 * temperatura DHT11 com o Arduino.
 * Os dados do sensor são lidos e impressos via conexão serial.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/
 
#include <DFRobot_DHT11.h>

#define PINO_DHT11 10

DFRobot_DHT11 DHT11;

void setup() {
  // inicializa a conexão serial
  Serial.begin(9600);
}

void loop() {
  // realiza a leitura dos dados do sensor
  DHT11.read(PINO_DHT11);

  // obtém a temperatura e umidade do ar e imprime os valores via conexão serial
  char buffer[40];
  sprintf(buffer, "Temperatura: %d, Umidade: %d%%", DHT11.temperature, DHT11.humidity);
  Serial.println(buffer);
  
  // aguarda 1 segundo para fazer uma nova leitura
  delay(1000);
}
