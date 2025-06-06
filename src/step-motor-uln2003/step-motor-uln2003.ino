/**
 * Código do curso Magos do Arduino para controlar um step motor 
 * com o módulo ULN2003 no Arduino.
 * 
 * Controle de um step motor usando o módulo ULN2003 com o Arduino. 
 * Este código demonstra como rotacionar o motor em diferentes 
 * direções e velocidades.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/
#include <Stepper.h>

// define a quantidade de passos para uma volta no motor de passo
// consulte sobre o modelo do step motor e ajuste aqui o valor
#define PASSOS_POR_VOLTA 2048

#define PIN_IN1 8
#define PIN_IN2 9
#define PIN_IN3 10
#define PIN_IN4 11

#define VELOCIDADE_10_RPM 10
#define VELOCIDADE_15_RPM 15

// cria uma instância do objeto do step motor
Stepper stepMotor = Stepper(PASSOS_POR_VOLTA, PIN_IN1, PIN_IN3, PIN_IN2, PIN_IN4);

void setup() {
}

void loop() {
  // rotaciona 360 graus em sentido anti-horário a 10 RPM
  stepMotor.setSpeed(VELOCIDADE_10_RPM);
  stepMotor.step(PASSOS_POR_VOLTA);
  delay(1000);

  // rotaciona 180 graus em sentido horário a 15 RPM
  stepMotor.setSpeed(VELOCIDADE_15_RPM);
  stepMotor.step(-PASSOS_POR_VOLTA/2);
  delay(1000);

  // rotaciona 360 graus em 4 etapas de 90 graus em sentido anti-horário a 15 RPM,
  // con intervalo de 1 segundo a cada etapa
  stepMotor.step(PASSOS_POR_VOLTA/4);
  delay(1000);
  stepMotor.step(PASSOS_POR_VOLTA/4);
  delay(1000);
  stepMotor.step(PASSOS_POR_VOLTA/4);
  delay(1000);
  stepMotor.step(PASSOS_POR_VOLTA/4);
  delay(1000);
}

