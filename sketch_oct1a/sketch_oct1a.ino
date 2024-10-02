// Definindo os pinos do sensor PIR e do buzzer
int pirPin = 2;  // Pino do sensor PIR
int buzzerPin = 8;  // Pino do buzzer
int pirState = LOW;  // Estado inicial do sensor PIR
int val = 0;  // Variável para ler o estado do sensor PIR

void setup() {
  pinMode(pirPin, INPUT);  // Configura o sensor PIR como entrada
  pinMode(buzzerPin, OUTPUT);  // Configura o buzzer como saída
  Serial.begin(9600);  // Inicializa a comunicação serial
}

void loop() {
  val = digitalRead(pirPin);  // Lê o estado do sensor PIR
  
  if (val == HIGH) {  // Se o sensor detectar movimento
    if (pirState == LOW) {
      Serial.println("Movimento detectado!");
      digitalWrite(buzzerPin, HIGH);  // Ativa o buzzer
      delay(1000);  // Mantém o buzzer ligado por 1 segundo
      digitalWrite(buzzerPin, LOW);  // Desativa o buzzer
      pirState = HIGH;  // Atualiza o estado do sensor PIR
    }
  } else {
    if (pirState == HIGH) {
      Serial.println("Movimento parou.");
      pirState = LOW;  // Atualiza o estado do sensor PIR
    }
  }
}
