/**
 * Código do curso Magos do Arduino para demonstrar como ler dados seriais.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

void setup() {
  // inicia a conexão serial
  Serial.begin(9600);
}

void loop() {
  // verifica se existe dados a serem lidos na porta serial
  if (Serial.available() > 0) {
    int valor = Serial.read();
    
    //int valor = Serial.parseInt();
    
    //float valor = Serial.parseFloat();
    
    //String valor = Serial.readString();

    // imprime o valor recebido
    Serial.print("Valor recebido: ");
    Serial.println(valor);
  }
}
