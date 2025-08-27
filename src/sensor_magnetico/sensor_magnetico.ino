/**
 * Código do curso Magos do Arduino para utilizar um sensor magnético com o Arduino. 
 * 
 * Utilize o sensor magnético para acender e apagar um LED quando um ímã for 
 * aproximado no sensor. As leituras digital e analógica do sensor são 
 * impressas no monitor serial.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_LED 2
#define PINO_SENSOR_DIGITAL 3
#define PINO_SENSOR_ANALOGICO A0

int valorDigital = 0;
int valorAnalogico = 0;

void setup() {
  pinMode(PINO_LED, OUTPUT);
  pinMode(PINO_SENSOR_DIGITAL, INPUT);

  Serial.begin(9600);
}

void loop() {
  // faz a leitura do valor digital do sensor
  valorDigital = digitalRead(PINO_SENSOR_DIGITAL);
  // imprime o valor digital obtido pelo sensor
  Serial.print("Valor digital: ");
  Serial.println(valorDigital);

  // define o LED de acordo com o valor do sensor
  if (valorDigital == HIGH) {
    digitalWrite(PINO_LED, HIGH);
  } else {
    digitalWrite(PINO_LED, LOW);
  }

  // faz a leitura do valor analógico do sensor
  valorAnalogico = analogRead(PINO_SENSOR_ANALOGICO);
  // imprime o valor analógido obtido pelo sensor
  Serial.print("Valor analógico: ");
  Serial.println(valorAnalogico);

  delay(100);
}