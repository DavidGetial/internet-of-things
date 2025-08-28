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

  digitalWrite(LEDROJO, HIGH);
  digitalWrite(LEDAMARILLO, HIGH);
  digitalWrite(LEDVERDE, HIGH);
  delay(1000);
  digitalWrite(LEDROJO, LOW);
  digitalWrite(LEDAMARILLO, LOW);
  digitalWrite(LEDVERDE, LOW);
  delay(1000);

}
