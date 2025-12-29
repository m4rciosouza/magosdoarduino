/**
 * Código do curso Magos do Arduino para escanear e imprimir no monitor serial 
 * os endereços de dispositivos I2C conectados ao Arduino. 
 * 
 * Código que imprime no monitor serial o endereço de dispositivos I2C conectados 
 * ao Arduino, muito útil quando precisamos descobrir o endereço de um 
 * dispositivo em específico.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/
#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("\nI2C Scanner");
}

void loop() {
  byte erro, endereco;
  int dispositivos;
  Serial.println("buscando dispositivos...");
  dispositivos = 0;
  for (endereco = 1; endereco < 127; endereco++) {
    Wire.beginTransmission(endereco);
    erro = Wire.endTransmission();
    if (erro == 0) {
      Serial.print("dispositivo I2C encontrado no endereço 0x");
      if (endereco < 16) {
        Serial.print("0");
      }
      Serial.println(endereco, HEX);
      dispositivos++;
    } else if (erro == 4) {
      Serial.print("erro desconhecido no endereço 0x");
      if (endereco < 16) {
        Serial.print("0");
      }
      Serial.println(endereco, HEX);
    }
  }
  if (dispositivos == 0) {
    Serial.println("Nenhum dispositivo I2C encontrado\n");
  } else {
    Serial.println("fim\n");
  }
  delay(5000);
}