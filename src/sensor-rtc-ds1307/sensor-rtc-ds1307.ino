/**
 * Código do curso Magos do Arduino para utilizar um sensor RTC (horas em tempo real) DS1307 com o Arduino.
 * 
 * Imprima no monitor serial a data e hora atual no formato "Sábado, 20 de Setembro de 2025, 9:06:39" com o Arduino.
 * 
 * Utiliza a biblioteca uRTCLib por Naguissa, que pode ser instalada através do gerenciador de bibliotecas do Arduino IDE.
 * 
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 */

#include <Arduino.h>
#include <uRTCLib.h>

// cria uma instância do uRTCLib no endereço 0x68, que é o endereço do DS1307
uRTCLib rtc(0x68);

char diasDaSemana[7][15] = { 
  "Domingo", 
  "Segunda-feira", 
  "Terça-feira", 
  "Quarta-feira", 
  "Quinta-feira", 
  "Sexta-feira", 
  "Sábado"
};

char meses[12][15] = {
  "Janeiro",
  "Fevereiro",
  "Março",
  "Abril",
  "Maio",
  "Junho",
  "Julho",
  "Agosto",
  "Setembro",
  "Outubro",
  "Novembro",
  "Dezembro"
};

void setup() {
  Serial.begin(9600); // inicializa conexão serial

  URTCLIB_WIRE.begin(); // inicializa a conexão I2C do DS1307

  // execute uma única vez para ajustar a data e hora e depois comente o código a seguir
  // parâmetros: segundos, minutos, horas, dia da semana, dia do mês, mês e ano
  // para o dia da semana, use (1=Domingo, 2=Segunda-feira,... , 7=Sábado)
  rtc.set(0, 20, 11, 7, 4, 10, 25);
}

void loop() {
  rtc.refresh(); // utilizado para obter a data e hora atual

  char dataHora[100];
  sprintf(dataHora, "%s, %d de %s de 20%d, %d:%02d:%02d", 
    diasDaSemana[rtc.dayOfWeek() - 1], // dia da semana
  	rtc.day(), // dia do mês
    meses[rtc.month() - 1], // mês
    rtc.year(), // ano
    rtc.hour(), // hora
    rtc.minute(), // minutos
    rtc.second() // segundos
  );
  
  Serial.println(dataHora);

  delay(1000);
}