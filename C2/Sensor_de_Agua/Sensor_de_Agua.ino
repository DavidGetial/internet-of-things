long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  float distance = 0.01723 * readUltrasonicDistance(2, 3);
  
  if (distance > 200) {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    Serial.println("Nivel normal: > 200 cm");
  }
  else if (distance > 100 && distance <= 200) {
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    Serial.println("Alerta media: 100-200 cm");
  }
  else if (distance > 0 && distance <= 100) {
    digitalWrite(6, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    Serial.println("Alerta alta: <= 100 cm");
  }
  
  delay(500);
}
