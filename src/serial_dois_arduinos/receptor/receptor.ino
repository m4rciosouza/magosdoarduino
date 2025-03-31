/**
 * Código do curso Magos do Arduino para criar um receptor de dados seriais.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // inicializa conexão serial
  Serial.begin(9600);
}

int estadoLed = LOW;
void loop() {
  if (Serial.available() > 0) {
    // recebe o valor pela porta serial
    char valor = Serial.read();

    if (valor == '1') {
      // inverte o estado do LED
      estadoLed = (estadoLed == HIGH) ? LOW : HIGH;
      digitalWrite(LED_BUILTIN, estadoLed);
    }
  }
}
