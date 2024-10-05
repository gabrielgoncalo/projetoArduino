//medidor de temperatura

#include <DHT.h>

#define DHTPIN 2      // Pino onde o sensor DHT está conectado
#define DHTTYPE DHT11 // Tipo de sensor DHT

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Inicializando a comunicação serial a 9600 bps
  Serial.begin(9600);
  
  // Inicializando o sensor DHT
  dht.begin();
}

void loop() {
  // Leitura da temperatura e umidade
  float temp = dht.readTemperature(); // Leitura em Celsius
  float hum = dht.readHumidity();     // Leitura da umidade

  // Verificando se houve erro na leitura
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Erro ao ler o sensor DHT!");
  } else {
    // Enviando os dados para o PC via serial
    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.print(" °C");
    Serial.print(" - Umidade: ");
    Serial.print(hum);
    Serial.println(" %");
  }

  // Aguardando 2 segundos antes de nova leitura
  delay(2000);
}
