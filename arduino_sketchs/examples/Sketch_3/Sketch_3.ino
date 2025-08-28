int const LEDVERDE = 8;
int const LEDROJO = 7;
int const LEDAMARILLO = 6;



void setup() {
  // put your setup code here, to run once:
  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDROJO, OUTPUT);
  pinMode(LEDAMARILLO, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(LEDROJO, LOW);
  digitalWrite(LEDAMARILLO, LOW);
  digitalWrite(LEDVERDE, LOW);

  digitalWrite(LEDROJO, HIGH);
  delay(500);
  digitalWrite(LEDROJO, LOW);
  digitalWrite(LEDAMARILLO, HIGH);
  delay(500);
  digitalWrite(LEDAMARILLO, LOW);
  digitalWrite(LEDVERDE, HIGH);
  delay(500);
  digitalWrite(LEDVERDE, LOW);
  
}
