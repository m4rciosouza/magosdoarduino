/**
 * Código do curso Magos do Arduino para utilizar um fotoresistor com o Arduino
 * e imprimir o seu valor no monitor serial.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_FOTORESISTOR A0

void setup() {
    Serial.begin(9600);
}

int valor = 0;
void loop() {
  valor = analogRead(PINO_FOTORESISTOR);

  Serial.println("Valor do fotoresistor: ");
  Serial.println(valor);
    
  if (valor > 650) {
    Serial.println("Apagar LED...");
  } else {
    Serial.println("Acender LED...");
  }

  delay(250);
}
