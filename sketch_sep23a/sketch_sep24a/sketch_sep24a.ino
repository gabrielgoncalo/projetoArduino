#include <LiquidCrystal.h>  // Biblioteca para o display LCD (se não for I2C)
// Para o I2C, use: #include <Wire.h> e #include <LiquidCrystal_I2C.h>

// Se for usar LCD com I2C, use:
// LiquidCrystal_I2C lcd(0x27, 16, 2);

// Para LCD sem I2C:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // Pinos conectados ao LCD

int pirPin = 7;  // Pino do sensor PIR
int buzzerPin = 8;  // Pino do buzzer
bool alarmeAtivado = true;  // Estado do alarme

void setup() {
  lcd.begin(16, 2);  // Inicializa o LCD 16x2
  pinMode(pirPin, INPUT);  // Define o pino do PIR como entrada
  pinMode(buzzerPin, OUTPUT);  // Define o pino do buzzer como saída
  lcd.print("Alarme ativado");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (digitalRead(pirPin) == HIGH) {  // Se movimento for detectado
    lcd.clear();
    lcd.print("Movimento!");
    if (alarmeAtivado) {
      digitalWrite(buzzerPin, HIGH);  // Liga o buzzer
      delay(1000);  // Buzzer ativo por 1 segundo
      digitalWrite(buzzerPin, LOW);  // Desliga o buzzer
    }
  } else {
    lcd.clear();
    lcd.print("Sem movimento");
  }
  delay(500);  // Pequeno atraso para evitar falsos positivos
}
