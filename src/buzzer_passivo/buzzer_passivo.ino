/**
 * Código do curso Magos do Arduino para utilizar um buzzer passivo.
 *
 * (c) Copyright KazaleIT
 * @kazaleitoficial no YouTube
 **/

// frequências das notas musicais
#define DO 262
#define RE 294
#define MI 330
#define FA 349
#define SOL 392
#define LA 440
#define SI 494

// pino do buzzer
#define BUZZER_PIN 8

// melodias
int melodia[] = {
  DO, SOL, SOL, LA, SOL, 0, SI, DO
};

// tempos das notas: 4 = quarto de tempo, 8 = oitavo de tempo...
int temposNotas[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

// utilizado para gerar som de alarme
float valorSeno;
int frequencia;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  for (int notaIdx = 0; notaIdx < 8; notaIdx++) {
    tone(BUZZER_PIN, melodia[notaIdx]);

    // para calcular o tempo da nota, divida um segundo pelo tempo da nota
    // ex.: quarto de tempo = 1000 / 4, oitavo de tempo = 1000 / 8
    int tempoNota = 1000 / temposNotas[notaIdx];
    delay(tempoNota);

    // para de emitir som
    noTone(BUZZER_PIN);
  }

  // código para o som de alarme
  /*for (int x = 0; x < 180; x++) {
    // converte graus em radianos e obter o valor do seno
    valorSeno = sin(x * (3.1412 / 180));
    // gera frequência a partir do valor do seno
    frequencia = 2000 + (int(valorSeno * 1000));
    tone(BUZZER_PIN, frequencia);
    delay(2);
  }*/
}