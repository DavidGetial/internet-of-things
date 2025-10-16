int const led_red = 7;
int const led_yellow = 6;
int const led_green = 5;
int const fan1 = 9;
int sensor_value;
float temperature;

unsigned long previousMillis = 0;
const long interval = 500; 
bool ledState = LOW;

void setup() {
  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(fan1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensor_value = analogRead(A0);
  temperature = ((((5.0 / 1023) * sensor_value) * 100) - 50);

  Serial.print("Valor de temperatura: ");
  Serial.print(temperature);
  Serial.println(" °C");
  delay(1000);

  unsigned long currentMillis = millis();

  if (temperature < 0) {
    digitalWrite(fan1, LOW);
    digitalWrite(led_red, LOW);
    digitalWrite(led_yellow, HIGH);
    digitalWrite(led_green, LOW);
  }
  else if (temperature >= 0 && temperature <= 25) {
    digitalWrite(fan1, LOW);
    digitalWrite(led_red, LOW);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_green, HIGH);
  }
  else if (temperature > 25 && temperature <= 38) {
    digitalWrite(fan1, HIGH);
    digitalWrite(led_red, HIGH);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_green, LOW);
  }
  else if (temperature > 38 && temperature <= 45) {
    digitalWrite(fan1, HIGH);
    digitalWrite(led_red, HIGH);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_green, LOW);
    Serial.println("Mensaje de advertencia: Temperatura alta!");
  }
  else if (temperature > 45) {
    if (currentMillis - previousMillis >= 3000) {
      ledState = !ledState;
      digitalWrite(fan1, ledState);
      previousMillis = currentMillis;
    }
    if (currentMillis - previousMillis >= 500) {
      ledState = !ledState;
      digitalWrite(led_red, ledState);
      digitalWrite(led_yellow, ledState);
      digitalWrite(led_green, ledState);
      previousMillis = currentMillis;
    }
    Serial.println("Mensaje de alerta: Temperatura crítica!");
  }
}