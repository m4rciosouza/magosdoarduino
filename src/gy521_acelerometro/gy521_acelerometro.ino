/**
 * Código do curso Magos do Arduino para utilizar o acelerômetro e giroscópio GY-521 
 * com o Arduino. 
 * 
 * Código que imprime no monitor serial os valores lidos do acelerômetro e giroscópio. 
 * Ele também controla dois LEDs que indicam a inclinação do eixo Y do acelerômetro.
 * 
 * Depende da biblioteca GY521, que pode ser instalada via gerenciador de bibliotecas 
 * da IDE do Arduino.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#include "GY521.h"

#define GY521_ENDERECO 0x68
#define PINO_LED_1 2
#define PINO_LED_2 3

// cria instância do sensor GY521
GY521 sensor(GY521_ENDERECO);

void setup() {
  pinMode(PINO_LED_1, OUTPUT);
  pinMode(PINO_LED_2, OUTPUT);

  Serial.begin(115200); // inicializa conexão serial

  Wire.begin(); // inicializa conexão I2C para o GY521

  // aguarda sensor estar pronto para leitura dos dados
  delay(100);
  while (sensor.wakeup() == false) {
    Serial.println("erro conectando ao sensor GY521, verifique se a conexão está correta.");
    delay(1000);
  }

  // define configurações padrões para o sensor
  sensor.setAccelSensitivity(0); // 2g
  sensor.setGyroSensitivity(0); // 250 graus
  sensor.setThrottle();

  // define valores padrões de calibração
  sensor.axe = 0;
  sensor.aye = 0;
  sensor.aze = 0;
  sensor.gxe = 0;
  sensor.gye = 0;
  sensor.gze = 0;
}

void loop() {
  sensor.read(); // realiza a leitura dos valores do sensor
  // leituras do acelerômetro
  float ax = sensor.getAccelX();
  float ay = sensor.getAccelY();
  float az = sensor.getAccelZ();
  // leituras do giroscópio
  float gx = sensor.getGyroX();
  float gy = sensor.getGyroY();
  float gz = sensor.getGyroZ();
  // leitura da temperatura em graus celsius
  float t = sensor.getTemperature();

  char buffer[200];
  sprintf(buffer, "Acelerômetro: (x:%4f, y:%4f, z:%4f), Giroscópio: (x:%4f, y:%4f, z:%4f), Temperatura: %f", 
    ax, ay, az, gx, gy, gz, t);
  Serial.println(buffer);

  // controlam os leds que monitoram o eixo Y do acelerômetro
  if (ay > 0.5) {
    digitalWrite(PINO_LED_1, HIGH);
  } else {
    digitalWrite(PINO_LED_1, LOW);
  }
  if (ay < -0.5) {
    digitalWrite(PINO_LED_2, HIGH);
  } else {
    digitalWrite(PINO_LED_2, LOW);
  }

  delay(500);
}