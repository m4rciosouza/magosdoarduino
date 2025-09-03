/**
 * Código do curso Magos do Arduino para utilizar um sensor de detecção de gás com o Arduino. 
 * 
 * Imprima no monitor serial as leituras digitais e analógicas de um sensor de detecção de gás com o Arduino.
 * Para um sensor MQ135 novo ou previamente armazenado, é necessário um período de teste de 24 horas para garantir leituras estáveis e precisas. 
 * Após o teste inicial, o sensor precisa de um tempo de aquecimento de alguns minutos para que o aquecedor interno se estabilize antes de fornecer dados normais. 
 * Para monitoramento contínuo, normalmente é possível realizar leituras a cada 1 a 5 segundos ou com mais frequência, mas também pode ocorrer um tempo de resposta lento dependendo do gás e de sua concentração.
 * Portanto, um intervalo de leitura de 1 a 5 minutos pode ser necessário para valores estáveis ​​em alguns casos.
 *
 * Exemplos de leituras no Arduino (0–1023):
 * 0 – 100	Ar muito limpo	Pode ser difícil alcançar (ambiente controlado)
 * 100 – 300	Ar limpo/normal	CO₂ ~ 350–600 ppm, baixa presença de gases
 * 300 – 600	Ar moderado	Pode indicar aumento de CO₂ (> 1000 ppm) ou álcool/fumaça leve
 * 600 – 800	Ar poluído	Gases nocivos perceptíveis, fumaça, solventes
 * 800 – 1023	Muito poluído / saturado	Alta concentração de CO₂ (> 5000 ppm) ou presença forte de NH₃, álcool, benzeno etc.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

#define PINO_SENSOR_DIGITAL 2
#define PINO_SENSOR_ANALOGICO A0

int valorDigital = 0;
int valorAnalogico = 0;

void setup() {
  pinMode(PINO_SENSOR_DIGITAL, INPUT);

  Serial.begin(9600);
}

void loop() {
  // faz a leitura do valor digital do sensor
  valorDigital = digitalRead(PINO_SENSOR_DIGITAL);
  // imprime o valor digital obtido pelo sensor
  Serial.print("Valor digital: ");
  Serial.println(valorDigital);

  // imprime uma mensagem com base no valor digital obtido (HIGH ou LOW)
  if (valorDigital == HIGH) {
    Serial.println("Presença de gases detectada!");
  } else {
    Serial.println("Nenhuma presença de gases detectada.");
  }

  // faz a leitura do valor analógico do sensor
  valorAnalogico = analogRead(PINO_SENSOR_ANALOGICO);

  // imprime o valor analógido obtido pelo sensor
  Serial.print("Valor analógico: ");
  Serial.println(valorAnalogico);
  if (valorAnalogico < 100) {
    Serial.println("Ar muito limpo");
  } else if (valorAnalogico < 300) {
    Serial.println("Ar limpo/normal");
  } else if (valorAnalogico < 600) {
    Serial.println("Ar moderado, existe aumento de CO₂ ou álcool/fumaça leve");
  } else if (valorAnalogico < 800) {
    Serial.println("Ar poluído, presença de gases nocivos perceptíveis como fumaça ou solventes");
  } else { // 800-1023
    Serial.println("Muito poluído / saturado, alta concentração de CO₂");
  }

  Serial.println("");
  delay(3000);
}