char opt;
int const LED_RED = 12;
int const LED_YELLOW = 11;
int const LED_GREEN = 10;


void Menu() {
  
  Serial.println(" - - - Main Menu - - - ");
  Serial.println("1. Turn on led Red");
  Serial.println("2. Turn off led Red");
  Serial.println("3. Turn on led Yellow");
  Serial.println("4. Turn off led Yellow");
  Serial.println("5. Turn on led Green");
  Serial.println("6. Turn off led Green");
  Serial.println("7. Turn on all");
  Serial.println("8. Turn off all");
  Serial.println("9. Intermitence");
  Serial.println("Press any option: ___ ");

}

void setup() {

  pinMode (LED_RED, OUTPUT);

  Serial.begin(9600);
  Serial.println("Welcome");
  Serial.println("Press any key to show menu: ___ ");

}

void loop() {

  if(Serial.available() > 0){

    Menu();
    opt = Serial.read();

    if(opt == '1'){

        digitalWrite(LED_RED, HIGH);
    }

    if(opt == '2'){

        digitalWrite(LED_RED, LOW);

    }
    
    if(opt == '3'){

        digitalWrite(LED_YELLOW, HIGH);
    }

    if(opt == '4'){

        digitalWrite(LED_YELLOW, LOW);

    }
    
    if(opt == '5'){

        digitalWrite(LED_GREEN, HIGH);
    }

    if(opt == '6'){

        digitalWrite(LED_GREEN, LOW);

    }

    if(opt == '7'){

        digitalWrite(LED_RED, HIGH);
        digitalWrite(LED_YELLOW, HIGH);
        digitalWrite(LED_GREEN, HIGH);

    }

    if(opt == '8'){

        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_GREEN, LOW);

    }

    if(opt == '9'){

        digitalWrite(LED_RED, HIGH);
        delay(500);
        digitalWrite(LED_RED, LOW);
        delay(500);
        digitalWrite(LED_YELLOW, HIGH);
        delay(500);
        digitalWrite(LED_YELLOW, LOW);
        delay(500);
        digitalWrite(LED_GREEN, HIGH);
        delay(500);
        digitalWrite(LED_GREEN, LOW);
        delay(500);

    }
  }
}

