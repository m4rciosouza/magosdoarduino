/**
 * Código do curso Magos do Arduino para conectar um sensor 
 * de distância ultrassônico HC-SR04 com o Arduino.
 * 
 * Ele imprime a distância em centímetros no Serial Monitor.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_TRIGGER 9
#define PINO_ECHO 10

float duracao; // duração até o som retornar de trigger para echo
float distancia; // distância final calculada em centímetros(cm)

void setup() {
  pinMode(PINO_TRIGGER, OUTPUT);
  pinMode(PINO_ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  // envia um sinal para medir a duração do sinal
  digitalWrite(PINO_TRIGGER, LOW);
  delayMicroseconds(2); // aguarda 2 microsegundos para garantir que o pino está em LOW
  digitalWrite(PINO_TRIGGER, HIGH);
  delayMicroseconds(10); // envia o sinal por 10 microsegundos
  digitalWrite(PINO_TRIGGER, LOW);

  // utiliza a função pulseIn para detectar o tempo de acionamento do pino echo
  // consulte https://docs.arduino.cc/language-reference/en/functions/advanced-io/pulseIn/
  // para maiores detalhes sobre o pulseIn
  duracao = pulseIn(PINO_ECHO, HIGH);

  // calcula a distância em centímetros fazendo a conversão da duração comparada com 
  // a velocidade da luz em metros por segundo
  // o valor é dividido por 2 pois o sinal tem que ir e voltar do alvo
  distancia = (duracao * 0.0343) / 2;

  Serial.print("Distância (cm): ");
  Serial.println(distancia);
  delay(100);
}