#include <LiquidCrystal.h>

// Definiciones de pines
const int temperatura= A0;
const int pinRojo= 13;
const int Motor= 10;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(pinRojo, OUTPUT); 
  pinMode(Motor, OUTPUT); 
  lcd_1.begin(16, 2);       
}

void loop() {
  int sensorValue = analogRead(temperatura);
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperaturaerature = (voltage - 0.5) * 100; 

  lcd_1.clear();

 lcd_1.setCursor(0, 0);
  lcd_1.print("Temperatura: ");
  lcd_1.print(temperaturaerature);
  lcd_1.print(" C");

  // Validaciones
  if (temperaturaerature <= 10) {
    digitalWrite(pinRojo, HIGH); 
    delay(500);    
    digitalWrite(pinRojo, LOW);
    delay(500);
    digitalWrite(Motor, LOW); 
  } else if (temperaturaerature >= 11 && temperaturaerature <= 25) {
    digitalWrite(pinRojo, LOW);   
    digitalWrite(Motor, LOW);
  } else if (temperaturaerature >= 26) {
    digitalWrite(pinRojo, HIGH); 
    digitalWrite(Motor, HIGH);
  }

  delay(1000); 
}
