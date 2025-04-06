/**
 * Código do curso Magos do Arduino para utilizar um fotoresistor com o Arduino
 * e imprimir o seu valor no monitor serial.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

void setup() {
    Serial.begin(9600);
}

void loop() {
  int valor = analogRead(A0);

  Serial.println("Valor do fotoresistor: ");
  Serial.println(valor);
    
  if (valor > 650) {
    Serial.println("Apagar LED...");
  } else {
    Serial.println("Acender LED...");
  }

  delay(250);
}
