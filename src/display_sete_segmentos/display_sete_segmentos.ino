/**
 * Código do curso Magos do Arduino para utilizar um display de sete segmentos 
 * com o Arduino.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_A 1
#define PINO_B 2
#define PINO_C 3
#define PINO_D 4
#define PINO_E 5
#define PINO_F 6
#define PINO_G 7

void setup() {
  pinMode(PINO_A, OUTPUT);
  pinMode(PINO_B, OUTPUT);
  pinMode(PINO_C, OUTPUT);
  pinMode(PINO_D, OUTPUT);
  pinMode(PINO_E, OUTPUT);
  pinMode(PINO_F, OUTPUT);
  pinMode(PINO_G, OUTPUT);
}

// mapeamento dos dígitos a serem exibidos no display (0 a 9)
byte digitos[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 }, // 0
  { 0, 1, 1, 0, 0, 0, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1 }, // 2 
  { 1, 1, 1, 1, 0, 0, 1 }, // 3
  { 0, 1, 1, 0, 0, 1, 1 }, // 4
  { 1, 0, 1, 1, 0, 1, 1 }, // 5
  { 1, 0, 1, 1, 1, 1, 1 }, // 6
  { 1, 1, 1, 0, 0, 0, 0 }, // 7
  { 1, 1, 1, 1, 1, 1, 1 }, // 8
  { 1, 1, 1, 1, 0, 1, 1 }  // 9
};

//contém o valor do dígito a ser exibido
byte numero = 0;

void loop() {
  digitalWrite(PINO_A, digitos[numero][0]);
  digitalWrite(PINO_B, digitos[numero][1]);
  digitalWrite(PINO_C, digitos[numero][2]);
  digitalWrite(PINO_D, digitos[numero][3]);
  digitalWrite(PINO_E, digitos[numero][4]);
  digitalWrite(PINO_F, digitos[numero][5]);
  digitalWrite(PINO_G, digitos[numero][6]);

  numero++;
  if (numero == 10) { // se o número for 10, reinicia
    numero = 0;
  }
  
  delay(1000);
}
