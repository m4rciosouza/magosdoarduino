
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
  Serial.begin(9600);

   // inicializam os pinos dos push buttons como pull up
   pinMode(BTN_A_PIN, INPUT_PULLUP);
   pinMode(BTN_B_PIN, INPUT_PULLUP);
   pinMode(BTN_C_PIN, INPUT_PULLUP);
   pinMode(BTN_D_PIN, INPUT_PULLUP);
   pinMode(BTN_E_PIN, INPUT_PULLUP);
   pinMode(BTN_F_PIN, INPUT_PULLUP);
   pinMode(JOYSTICK_BTN_PIN, INPUT_PULLUP);
}

void loop() {
  // obtém valores dos push buttons
  int valorBotaoA = digitalRead(BTN_A_PIN);
  if (valorBotaoA == LOW) {
    Serial.println("Botão A pressionado.");
  }

  int valorBotaoB = digitalRead(BTN_B_PIN);
  if (valorBotaoB == LOW) {
    Serial.println("Botão B pressionado.");
  }

  int valorBotaoC = digitalRead(BTN_C_PIN);
  if (valorBotaoC == LOW) {
    Serial.println("Botão C pressionado.");
  }

  int valorBotaoD = digitalRead(BTN_D_PIN);
  if (valorBotaoD == LOW) {
    Serial.println("Botão D pressionado.");
  }

  int valorBotaoE = digitalRead(BTN_E_PIN);
  if (valorBotaoE == LOW) {
    Serial.println("Botão E pressionado.");
  }

  int valorBotaoF = digitalRead(BTN_F_PIN);
  if (valorBotaoF == LOW) {
    Serial.println("Botão F pressionado.");
  }

  int valorBotaoJoystick = digitalRead(JOYSTICK_BTN_PIN);
  if (valorBotaoJoystick == LOW) {
    Serial.println("Botão do Joystick pressionado.");
  }

  // obtém valores do joystick analógico (X e Y)
  int valorX = analogRead(JOYSTICK_X_PIN);
  if (valorX < 250) {
    Serial.print("Joystick Eixo X Esquerda: ");
    Serial.println(valorX);
  }
  if (valorX > 450) {
    Serial.print("Joystick Eixo X Direita: ");
    Serial.println(valorX);
  }
  // adicione um pequeno atraso para estabilizar a leitura do sinal analógico
  // e evitar leituras inconsistentes
  delay(75);
  int valorY = analogRead(JOYSTICK_Y_PIN);
  if (valorY < 250) {
    Serial.print("Joystick Eixo Y Baixo: ");
    Serial.println(valorY);
  }
  if (valorY > 450) {
    Serial.print("Joystick Eixo Y Cima: ");
    Serial.println(valorY);
  }

  // debouncing
  delay(75);
}
