/**
 * Código do curso Magos do Arduino para utilizar um módulo detector de som (KY-038) 
 * com o Arduino que quando acionado acende um LED.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_MIC_A A0
#define PINO_MIC_D 2
#define PINO_LED 8

void setup() {
  pinMode(PINO_MIC_D, INPUT);
  pinMode(PINO_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // teste com a leitura digital
  //testeLeituraDigital();

  // teste com a leitura analógica
  testeLeituraAnalogica();

  delay(10);
}

void testeLeituraDigital() {
  int micDigital = digitalRead(PINO_MIC_D);
  Serial.print("Leitura mic digital: ");
  Serial.println(micDigital);
  if (micDigital == 1) {
    digitalWrite(PINO_LED, HIGH);
    delay(1500);
    digitalWrite(PINO_LED, LOW);
  }
}

void testeLeituraAnalogica() {
  int micAnalogico = analogRead(PINO_MIC_A);
  Serial.print("Leitura mic analógico: ");
  Serial.println(micAnalogico);
  if (micAnalogico > 600) { // ajuste a sensibilidade aqui (0-1023)
    digitalWrite(PINO_LED, HIGH);
    delay(1500);
    digitalWrite(PINO_LED, LOW);
  }
}