int const PULSADOR = 9;
int const LED_RED = 8;
int const LED_YELLOW = 7;
int const LED_GREEN = 6;

int opcionActual = 0;
bool pulsadorAnterior = HIGH;
bool infinito = false;

unsigned long ultimoTiempo = 0;
const int tiempoRebote = 200;
unsigned long ultimoCambioIntermitencia = 0;
const int tiempoIntermitencia = 300;

char opt;

void Menu() {
  Serial.println(" - - - Main Menu - - - ");
  Serial.println("1. Turn on LED Red");
  Serial.println("2. Turn off LED Red");
  Serial.println("3. Turn on LED Yellow");
  Serial.println("4. Turn off LED Yellow");
  Serial.println("5. Turn on LED Green");
  Serial.println("6. Turn off LED Green");
  Serial.println("7. Turn on all LEDs");
  Serial.println("8. Turn off all LEDs");
  Serial.println("9. Intermitence");
  Serial.print("Current mode: ");
  Serial.println(opcionActual);
  Serial.println("Press any option (1-9): ");
}

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(PULSADOR, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Sistema listo. Presiona el boton para cambiar de opcion o una tecla para mostrar el menu.");
}

void loop() {
  bool estadoPulsador = digitalRead(PULSADOR);
  unsigned long tiempoActual = millis();

  if (pulsadorAnterior == HIGH && estadoPulsador == LOW && (tiempoActual - ultimoTiempo) > tiempoRebote) {
    opcionActual = opcionActual + 1;
    Serial.print("Opcion actual: ");
    Serial.println(opcionActual);
    infinito = false;

    if (opcionActual == 1) {
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
    }
    if (opcionActual == 2) {
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_GREEN, LOW);
    }
    if (opcionActual == 3) {
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, HIGH);
    }
    if (opcionActual == 4) {
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
    }
    if (opcionActual == 5) {
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_GREEN, HIGH);
    }
    if (opcionActual == 6) {
      infinito = true;
      ultimoCambioIntermitencia = tiempoActual;
    }
    if (opcionActual == 7) {
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
      opcionActual = 0;
    }

    ultimoTiempo = tiempoActual;
  }
  pulsadorAnterior = estadoPulsador;

  if (infinito) {
    if (tiempoActual - ultimoCambioIntermitencia >= tiempoIntermitencia) {
      bool estado = digitalRead(LED_RED);
      digitalWrite(LED_RED, !estado);
      digitalWrite(LED_YELLOW, !estado);
      digitalWrite(LED_GREEN, !estado);
      ultimoCambioIntermitencia = tiempoActual;
    }
  }

  if (Serial.available() > 0) {
    while (Serial.available() > 0) {
      opt = Serial.read();
      if (opt >= '1' && opt <= '9') {
        Menu();
        infinito = false;
        opcionActual = 0;

        if (opt == '1') {
          digitalWrite(LED_RED, HIGH);
          opcionActual = 1;
        }
        if (opt == '2') {
          digitalWrite(LED_RED, LOW);
          opcionActual = 1;
        }
        if (opt == '3') {
          digitalWrite(LED_YELLOW, HIGH);
          opcionActual = 2;
        }
        if (opt == '4') {
          digitalWrite(LED_YELLOW, LOW);
          opcionActual = 2;
        }
        if (opt == '5') {
          digitalWrite(LED_GREEN, HIGH);
          opcionActual = 3;
        }
        if (opt == '6') {
          digitalWrite(LED_GREEN, LOW);
          opcionActual = 3;
        }
        if (opt == '7') {
          digitalWrite(LED_RED, HIGH);
          digitalWrite(LED_YELLOW, HIGH);
          digitalWrite(LED_GREEN, HIGH);
          opcionActual = 5;
        }
        if (opt == '8') {
          digitalWrite(LED_RED, LOW);
          digitalWrite(LED_YELLOW, LOW);
          digitalWrite(LED_GREEN, LOW);
          opcionActual = 4;
        }
        if (opt == '9') {
          infinito = true;
          ultimoCambioIntermitencia = tiempoActual;
          opcionActual = 6;
        }
      }
    }
  }
}