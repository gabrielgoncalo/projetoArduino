// Definir pinos dos LEDs
const int ledVerde = 11;
const int ledAmarelo = 10;
const int ledVermelho = 9;

// Definir pinos do sensor ultrassônico
const int triggerPin = 7;
const int echoPin = 6;

// Variáveis para distância
long duracao;
int distancia;

void setup() {
  // Inicializar LEDs como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  // Inicializar pinos do sensor ultrassônico
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Iniciar a comunicação serial para monitoramento
  Serial.begin(9600);
}

void loop() {
  // Enviar pulso ao sensor
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Receber a resposta do sensor
  duracao = pulseIn(echoPin, HIGH);
  
  // Calcular a distância em centímetros
  distancia = duracao * 0.034 / 2;

  // Imprimir a distância no monitor serial
  Serial.print("Distância: ");
  Serial.println(distancia);

  // Lógica do semáforo inteligente
  if (distancia < 30) {
    // Se um carro estiver a menos de 30 cm, muda para verde
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho
