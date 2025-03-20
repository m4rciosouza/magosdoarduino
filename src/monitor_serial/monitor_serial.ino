
void setup() {
  // inicializa a conexão serial
  Serial.begin(9600);
  while (!Serial) {
    ;  // aguarda pela conexão
  }
}

void loop() {
  Serial.print("mensagem sem quebra de linha, ");
  // imprime uma mensagem no console e move para a próxima linha
  Serial.println("mensagem serial com quebra de linha");
  Serial.write("nova linha");
  delay(3000);

  if (Serial.available() > 0) {
    // read the incoming byte:
    int incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte);
  }
}
