/**
 * Código do curso Magos do Arduino para usar o sprintf para formatar strings.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

void setup() {
  Serial.begin(9600);
}

int contador = 1;
float pi = 3.1415;
char placa[] = "Arduino";

void loop() {
  // usando o print serial sem o sprintf
  Serial.print("Contador: ");
  Serial.print(contador);
  Serial.print(", texto: ");
  Serial.print(placa);
  Serial.print(", PI: ");
  Serial.println(pi);

  // usando o print serial com o sprintf
  char buffer[40];
  sprintf(buffer, "Contador: %d, texto: %s, PI: %.4f", 
    contador, placa, pi);
  Serial.println(buffer);

  contador++;
  delay(1000);
}
