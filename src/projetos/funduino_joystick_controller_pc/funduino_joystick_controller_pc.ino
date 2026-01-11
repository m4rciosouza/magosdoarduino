#include <Keyboard.h>

#define BTN_A_PIN 2
#define BTN_B_PIN 3
#define BTN_C_PIN 4
#define BTN_D_PIN 5
#define BTN_E_PIN 6
#define BTN_F_PIN 7
#define JOYSTICK_BTN_PIN 8
#define JOYSTICK_X_PIN A0
#define JOYSTICK_Y_PIN A1

void setup() {
   // inicializam os pinos dos push buttons como pull up
   pinMode(BTN_A_PIN, INPUT_PULLUP);
   pinMode(BTN_B_PIN, INPUT_PULLUP);
   pinMode(BTN_C_PIN, INPUT_PULLUP);
   pinMode(BTN_D_PIN, INPUT_PULLUP);
   pinMode(BTN_E_PIN, INPUT_PULLUP);
   pinMode(BTN_F_PIN, INPUT_PULLUP);
   pinMode(JOYSTICK_BTN_PIN, INPUT_PULLUP);

  // inicializa controlle do teclado
  Keyboard.begin();
}

void loop() {
  // obtém valores dos push buttons
  int valorBotaoA = digitalRead(BTN_A_PIN);
  if (valorBotaoA == LOW) {
    Keyboard.write('a');
  }

  int valorBotaoB = digitalRead(BTN_B_PIN);
  if (valorBotaoB == LOW) {
    Keyboard.write('s');
  }

  int valorBotaoC = digitalRead(BTN_C_PIN);
  if (valorBotaoC == LOW) {
    Keyboard.write('x');
  }

  int valorBotaoD = digitalRead(BTN_D_PIN);
  if (valorBotaoD == LOW) {
    Keyboard.write('z');
  }

  int valorBotaoE = digitalRead(BTN_E_PIN);
  if (valorBotaoE == LOW) {
    Keyboard.write(KEY_RETURN); // Enter
  }

  int valorBotaoF = digitalRead(BTN_F_PIN);
  if (valorBotaoF == LOW) {
    Keyboard.write(KEY_RIGHT_SHIFT);
  }

  int valorBotaoJoystick = digitalRead(JOYSTICK_BTN_PIN);
  if (valorBotaoJoystick == LOW) {
    Keyboard.write(KEY_F1);
  }

  // obtém valores do joystick analógico (X e Y)
  int valorX = analogRead(JOYSTICK_X_PIN);
  if (valorX < 250) {
    Keyboard.write(KEY_LEFT_ARROW); // Esquerda
  }
  if (valorX > 450) {
    Keyboard.write(KEY_RIGHT_ARROW); // Direita
  }
  // adicione um pequeno atraso para estabilizar a leitura do sinal analógico
  // e evitar leituras inconsistentes
  delay(75);
  int valorY = analogRead(JOYSTICK_Y_PIN);
  if (valorY < 250) {
    Keyboard.write(KEY_DOWN_ARROW); // Baixo
  }
  if (valorY > 450) {
    Keyboard.write(KEY_UP_ARROW); // Cima
  }

  // debouncing
  delay(75);
}
