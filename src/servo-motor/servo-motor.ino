/**
 * Código do curso Magos do Arduino para controlar um servo motor 
 * com o Arduino.
 * 
 * Controle de um servo motor com o Arduino. Um potenciômetro é utilizado 
 * para controlar a posição do servo motor (entre 0 e 180 graus).
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/
#include <Servo.h>

#define PINO_POTENCIOMETRO A0
#define PINO_SERVO 9

// cria um objeto para controlar o servo motor
Servo servoMotor;

void setup() {
  // registra o pino onde está conectado o servo motor
  servoMotor.attach(PINO_SERVO);
}

void loop() {
  // obtém o valor corrente do potenciômetro (valor entre 0 e 1023)
  int valorPot = analogRead(PINO_POTENCIOMETRO);

  // mapeia o valor do potenciômetro para ser 
  // compatível com o servo (valor entre 0 e 180)
  int posicaoServo = map(valorPot, 0, 1023, 0, 180);

  // move o servo para a posição desejada
  servoMotor.write(posicaoServo);

  delay(15);
}
