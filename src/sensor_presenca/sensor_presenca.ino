/**
 * Código do curso Magos do Arduino para conectar um sensor 
 * de presença PIR modelo HC-SR501 com o Arduino.
 * 
 * Ele imprime no Serial Monitor a mensagem de movimento detectado.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_SENSOR 2

int detectado = LOW; // define que não existe detecção ao iniciar
int valorSensor = 0; // valor da leitura do sensor

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PINO_SENSOR, INPUT);
  Serial.begin(9600);
}

void loop() {
  // realiza a leiura do valor corrente do sensor
  valorSensor = digitalRead(PINO_SENSOR);

  // caso movimento detectado
  if (valorSensor == HIGH) {
    // acende o LED da placa
    digitalWrite(LED_BUILTIN, HIGH); 

    // imprime mensagem somente quando mudar o estado
    if (detectado == LOW) { 
      Serial.println("Movimento detectado!");
      detectado = HIGH;
    }
  } else {
    // apaga o LED da placa
    digitalWrite(LED_BUILTIN, LOW); 

    // imprime mensagem somente quando mudar o estado
    if (detectado == HIGH) {
      Serial.println("Movimento não detectado.");
      detectado = LOW;
    }
  }
}