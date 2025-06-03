/**
 * Código do curso Magos do Arduino para controlar um motor dc 
 * com o módulo L298N no Arduino.
 * 
 * Controle de um motor dc de ~5v utilizando o módulo L298N.
 * Permite controle de velocidade com um potenciômetro e rotacionar o motor 
 * em ambas as direções ao pressionar um push button.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_POTENCIOMETRO A0
#define PINO_BOTAO_DIRECAO 2
#define PINO_VELOCIDADE 3
#define PINO_MOTOR_1 6
#define PINO_MOTOR_2 7

// mantém a direção da rotação do motor, que pode ser 1 ou -1
int direcao = 1;

void setup() {
  pinMode(PINO_POTENCIOMETRO, INPUT);
  pinMode(PINO_BOTAO_DIRECAO, INPUT_PULLUP);
  pinMode(PINO_VELOCIDADE, OUTPUT);
  pinMode(PINO_MOTOR_1, OUTPUT);
  pinMode(PINO_MOTOR_2, OUTPUT);

  // inicializa a rotação padrão do motor
  digitalWrite(PINO_MOTOR_1, LOW);
  digitalWrite(PINO_MOTOR_2, HIGH);
}

void loop() {
  // controla a velocidade do motor
  int valorPotenciometro = analogRead(PINO_POTENCIOMETRO);
  int velocidade = map(valorPotenciometro, 0, 1023, 0, 255);
  analogWrite(PINO_VELOCIDADE, velocidade);
  delay(200);

  // controla a rotação do motor
  int estadoBotao = digitalRead(PINO_BOTAO_DIRECAO);
  if (estadoBotao == LOW) {
    inverterDirecao();
    delay(200);
  }
}

// inverte a direção de rotação do motor
void inverterDirecao() {
  if (direcao == 1) {
    digitalWrite(PINO_MOTOR_1, HIGH);
    digitalWrite(PINO_MOTOR_2, LOW);
  } else {
    digitalWrite(PINO_MOTOR_1, LOW);
    digitalWrite(PINO_MOTOR_2, HIGH);
  }

  // alterna o valor entre 1 e -1
  direcao *= -1;
}
