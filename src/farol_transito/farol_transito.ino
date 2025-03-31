/**
 * Código do curso Magos do Arduino para criar um farol de trânsito.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

// define os pinos para os componentes
#define PINO_BUZZER 8
#define PINO_BTN 2
#define PINO_VERMELHO 9
#define PINO_AMARELO 10
#define PINO_VERDE 11

// utilizado para controlar o estado corrente dos leds
int estadoVerde = HIGH;
int estadoAmarelo = LOW;
int estadoVermelho = LOW;

unsigned long ultimaMudanca = 0;
unsigned long espera = 5000; // 5 segundos

void setup() {
  // define a direção correta dos pinos de GPIO
  pinMode(PINO_BTN, INPUT_PULLUP);
  pinMode(PINO_VERMELHO, OUTPUT);
  pinMode(PINO_AMARELO, OUTPUT);
  pinMode(PINO_VERDE, OUTPUT);
  pinMode(PINO_BUZZER, OUTPUT);

  // registra a interrupção utilizada quando o push button for pressionado
  attachInterrupt(digitalPinToInterrupt(PINO_BTN), abrirFarol, FALLING); // RISING, CHANGE, HIGH, LOW

  ultimaMudanca = millis();
}

void loop() {
  // acende/apaga os leds
  digitalWrite(PINO_VERDE, estadoVerde);
  digitalWrite(PINO_AMARELO, estadoAmarelo);
  digitalWrite(PINO_VERMELHO, estadoVermelho);

  // caso farol verde, aciona o buzzer
  if (estadoVerde == HIGH) {
    digitalWrite(PINO_BUZZER, HIGH);
    delay(150);
    digitalWrite(PINO_BUZZER, LOW);
    delay(150);
  }

  // verifica se o farol deve mudar de estado/cor
  if ((millis() - ultimaMudanca) > espera) {
    mudarCorFarol();
    espera = (estadoAmarelo == HIGH) ? 2000 : 5000;
    ultimaMudanca = millis();
  }

}

// função utilizada na interrupção caso o push button seja pressionado
void abrirFarol() {
  // retorna caso farol esteja verde
  if (estadoVerde == HIGH) {
    return;
  }

  delay(300);
  espera = 0;
}

// função utilizada para mudar a cor do farol
void mudarCorFarol() {
  if (estadoVerde == HIGH) {
    estadoVerde = LOW;
    estadoAmarelo = HIGH;
    estadoVermelho = LOW;
  } else if (estadoAmarelo == HIGH) {
    estadoVerde = LOW;
    estadoAmarelo = LOW;
    estadoVermelho = HIGH;
  } else {
    estadoVerde = HIGH;
    estadoAmarelo = LOW;
    estadoVermelho = LOW;
  }
}