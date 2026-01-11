#include <XInput.h>

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

  XInput.setAutoSend(false); // aguarda todos os comandos antes de enviar os dados
  XInput.begin(); // inicializa o XInput
}

void loop() {
  // realiza a leitura dos botões, inverte o valor porque LOW significa pressionado
  boolean valorBotaoA = !digitalRead(BTN_A_PIN);
  boolean valorBotaoB = !digitalRead(BTN_B_PIN);
  boolean valorBotaoC = !digitalRead(BTN_C_PIN);
  boolean valorBotaoD = !digitalRead(BTN_D_PIN);
  boolean valorBotaoE = !digitalRead(BTN_E_PIN);
  boolean valorBotaoF = !digitalRead(BTN_F_PIN);
  boolean valorBotaoJoystick = !digitalRead(JOYSTICK_BTN_PIN);

  // adiciona os valores dos botões
  XInput.setButton(BUTTON_A, valorBotaoC);
  XInput.setButton(BUTTON_B, valorBotaoB);
  XInput.setButton(BUTTON_X, valorBotaoD);
  XInput.setButton(BUTTON_Y, valorBotaoA);
  XInput.setButton(BUTTON_BACK, valorBotaoF);
  XInput.setButton(BUTTON_START, valorBotaoE);
  XInput.setButton(BUTTON_L3, valorBotaoJoystick);

  // obtém valores do joystick analógico (X e Y)
  boolean joystickEsquerda = false;
  boolean joystickDireita = false;
  boolean joystickCima = false;
  boolean joystickBaixo = false;
  int valorX = analogRead(JOYSTICK_X_PIN);
  if (valorX < 250) {
    joystickEsquerda = true;
  }
  if (valorX > 450) {
    joystickDireita = true;
  }
  // adicione um pequeno atraso para estabilizar a leitura do sinal analógico
  // e evitar leituras inconsistentes
  delay(75);
  int valorY = analogRead(JOYSTICK_Y_PIN);
  if (valorY < 250) {
    joystickBaixo = true;
  }
  if (valorY > 450) {
    joystickCima = true;
  }

  // define os do Dpad
  XInput.setDpad(joystickCima, joystickBaixo, joystickEsquerda, joystickDireita);

  // envia dados dos botões para o pc
  XInput.send();
}
