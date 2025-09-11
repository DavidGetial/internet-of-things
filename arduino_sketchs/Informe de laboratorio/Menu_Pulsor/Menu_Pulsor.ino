int const PULSADOR = 9;
int const LED_RED = 8;
int const LED_YELLOW = 7;
int const LED_GREEN = 6;

int opcionActual = 0;
bool pulsadorAnterior = HIGH;

unsigned long ultimoTiempo  = 0;
const int tiempoRebote = 200;

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(PULSADOR, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Sistema listo. Presiona el boton para cambiar de opcion.");
}

void loop() {
  
  bool estadoPulsador = digitalRead(PULSADOR);
  unsigned long tiempoActual = millis();
  

  if (pulsadorAnterior == HIGH && estadoPulsador == LOW && (tiempoActual - ultimoTiempo) > tiempoRebote) {
    
    opcionActual = opcionActual + 1;
    
    if (opcionActual > 9) {
      opcionActual = 1;
    }
    
    Serial.print("Opcion actual: ");
    Serial.println(opcionActual);
    
    if (opcionActual == 1) {
      digitalWrite(LED_RED, HIGH);
    }

    if (opcionActual == 2) {
      digitalWrite(LED_RED, LOW);
    }

    if (opcionActual == 3) {
      digitalWrite(LED_YELLOW, HIGH);
    }

    if (opcionActual == 4) {
      digitalWrite(LED_YELLOW, LOW);
    }

    if (opcionActual == 5) {
      digitalWrite(LED_GREEN, HIGH);
    }

    if (opcionActual == 6) {
      digitalWrite(LED_GREEN, LOW);
    }

    if (opcionActual == 7) {
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_GREEN, HIGH);
    }

    if (opcionActual == 8) {
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
    }

    if (opcionActual == 9) {
      for (int i = 0; i < 5; i++) {
        digitalWrite(LED_RED, HIGH);
        digitalWrite(LED_YELLOW, HIGH);
        digitalWrite(LED_GREEN, HIGH);
        delay(500);

        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_GREEN, LOW);
        delay(500);
      }
    }

    ultimoTiempo = tiempoActual;
  }

  pulsadorAnterior = estadoPulsador;
}