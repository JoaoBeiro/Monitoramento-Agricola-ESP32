#include "DHT.h"  // Biblioteca para o DHT22 (Temperatura e Umidade)

// Definindo os pinos utilizados para cada sensor e para o controle da irrigação
#define DHTPIN 15      // Pino do DHT22 conectado ao GPIO 15
#define DHTTYPE DHT22  // Tipo do sensor DHT (DHT22)
#define TRIGPIN 5      // Pino Trigger do sensor ultrassônico (HC-SR04)
#define ECHOPIN 18     // Pino Echo do sensor ultrassônico (HC-SR04)
#define PIRPIN 4       // Pino do sensor PIR conectado ao GPIO 4 (detecção de movimento)
#define LDRPIN 34      // Pino analógico do LDR conectado ao GPIO 34 (sensor de luz)
#define IRRIGATION_PIN 12  // Pino de controle da irrigação

// Inicializando o sensor DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Iniciando a comunicação serial para monitorar as leituras dos sensores
  Serial.begin(115200);
  
  // Inicializando o sensor DHT
  dht.begin();
  
  // Configurando os pinos para os sensores e controle de irrigação
  pinMode(TRIGPIN, OUTPUT);  // Definindo o pino Trigger do HC-SR04 como saída
  pinMode(ECHOPIN, INPUT);   // Definindo o pino Echo do HC-SR04 como entrada
  pinMode(PIRPIN, INPUT);    // Definindo o pino do PIR como entrada
  pinMode(LDRPIN, INPUT);    // Definindo o pino do LDR como entrada analógica
  pinMode(IRRIGATION_PIN, OUTPUT);  // Definindo o pino de controle da irrigação como saída
}

void loop() {
  // Leitura do sensor DHT22 (Temperatura e Umidade)
  float temperature = dht.readTemperature();  // Lê a temperatura
  float humidity = dht.readHumidity();        // Lê a umidade

  // Verifica se a leitura do DHT22 falhou (valores inválidos)
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Falha na leitura do sensor DHT!");  // Mensagem de erro
  } else {
    // Exibe os valores de temperatura e umidade no Monitor Serial
    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.print(" °C, Umidade: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  // Leitura do sensor ultrassônico (HC-SR04) para medir o nível de água
  digitalWrite(TRIGPIN, LOW);  // Garante que o Trigger está baixo
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);  // Gera um pulso de 10µs no Trigger
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  // Calcula o tempo que o pulso Echo leva para retornar
  int duration = pulseIn(ECHOPIN, HIGH);
  float distance = duration * 0.034 / 2;  // Converte o tempo em distância (cm)

  // Exibe a distância medida no Monitor Serial
  Serial.print("Distância até a água: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Lógica para ativação da irrigação com base na distância do nível de água e nas condições climáticas
  if (distance > 50.0 && humidity < 50.0 && temperature > 25.0) {
    // Se a água estiver acima de 50 cm e as condições estiverem secas/quentes, aciona a irrigação
    digitalWrite(IRRIGATION_PIN, HIGH);  // Liga a irrigação
    Serial.println("Irrigação ativada.");
  } else {
    // Caso contrário, desliga a irrigação
    digitalWrite(IRRIGATION_PIN, LOW);  // Desliga a irrigação
    Serial.println("Irrigação desativada.");
  }

  // Leitura do sensor PIR (Movimento)
  int motion = digitalRead(PIRPIN);  // Lê o estado do PIR (se detectou movimento)
  if (motion == HIGH) {
    // Se o sensor detectou movimento, exibe uma mensagem no Monitor Serial
    Serial.println("Movimento detectado!");
  } else {
    // Caso contrário, exibe que não houve movimento
    Serial.println("Nenhum movimento.");
  }

  // Leitura do sensor LDR (Nível de Luz)
  int lightLevel = analogRead(LDRPIN);  // Lê o valor analógico do LDR
  Serial.print("Nível de Luz: ");
  Serial.println(lightLevel);  // Exibe o valor da luz no Monitor Serial

  // Pausa de 2 segundos antes da próxima leitura
  delay(2000);
}
