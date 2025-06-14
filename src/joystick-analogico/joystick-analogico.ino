/**
 * Código do curso Magos do Arduino para conectar um joystick analógico 
 * no Arduino.
 * 
 * Conecte um joystick analógico no Arduino e imprima os valores 
 * no monitor serial.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_X A0
#define PINO_Y A1
#define PINO_BOTAO 7

void setup() {
  pinMode(PINO_BOTAO, INPUT_PULLUP);
  Serial.begin(9600); // inicializa conexão serial
}

void loop() {
  // obtém valores do joystick analógico
  int valorBotao = digitalRead(PINO_BOTAO);
  int valorX = analogRead(PINO_X);
  // adicione um pequeno atraso para estabilizar a leitura do sinal analógico
  // e evitar leituras inconsistentes
  delay(100);
  int valorY = analogRead(PINO_Y);
  delay(100);

  // imprime os valores obtidos
  char buffer[50];
  sprintf(buffer, "X: %d, Y: %d, Botão: %s (%d)", valorX, valorY, 
    (valorBotao==0 ? "pressionado": "não pressionado"), valorBotao);
  Serial.println(buffer);

  delay(300);
}
