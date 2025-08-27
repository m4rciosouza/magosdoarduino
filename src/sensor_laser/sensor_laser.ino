/**
 * Código do curso Magos do Arduino para utilizar um sensor transmissor e 
 * receptor de laser com o Arduino. 
 * 
 * Utilize o sensor de laser para acender e apagar um LED quando o feixe de laser 
 * estiver interrompido pelo obstáculo.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_LASER 2
#define PINO_RECEPTOR 3
#define PINO_LED 4

void setup() {
  pinMode(PINO_LASER, OUTPUT);
  pinMode(PINO_RECEPTOR, INPUT);
  pinMode(PINO_LED, OUTPUT);

  // ativa o laser
  digitalWrite(PINO_LASER, HIGH);
}

void loop() {
  // obtém o valor do receptor
  int valorReceptor = digitalRead(PINO_RECEPTOR);

  if (valorReceptor == LOW) {
    digitalWrite(PINO_LED, HIGH);
  } else {
    digitalWrite(PINO_LED, LOW);
  }
  
}