/**
 * Código do curso Magos do Arduino para utilizar um display de sete segmentos
 * controlado pelo CI CD4511 no Arduino.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

 // pinos do CD4511
#define PINO_A 2
#define PINO_B 3
#define PINO_C 4
#define PINO_D 5

void setup() {
  pinMode(PINO_A, OUTPUT);
  pinMode(PINO_B, OUTPUT);
  pinMode(PINO_C, OUTPUT);
  pinMode(PINO_D, OUTPUT);
}

// valores em binário para cada número a ser enviado para o CD4511
int valores[10][4] = {
  { 0, 0, 0, 0 }, // 0
  { 0, 0, 0, 1 }, // 1
  { 0, 0, 1, 0 }, // 2
  { 0, 0, 1, 1 }, // 3
  { 0, 1, 0, 0 }, // 4
  { 0, 1, 0, 1 }, // 5
  { 0, 1, 1, 0 }, // 6
  { 0, 1, 1, 1 }, // 7
  { 1, 0, 0, 0 }, // 8
  { 1, 0, 0, 1 }  // 9
};

// dígito a ser exibido
byte digito = 0;
void loop() {
  digitalWrite(PINO_A, valores[digito][3]);
  digitalWrite(PINO_B, valores[digito][2]);
  digitalWrite(PINO_C, valores[digito][1]);
  digitalWrite(PINO_D, valores[digito][0]);
  
  digito++;
  if (digito == 10) { // se o dígito for 10, reinicia para 0
    digito = 0;
  }

  delay(500);
}
