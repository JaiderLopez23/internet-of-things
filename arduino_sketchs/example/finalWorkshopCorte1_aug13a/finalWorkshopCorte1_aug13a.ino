int const LED_RED = 5;
int const LED_YELLOW = 18;
int const LED_GREEN = 19;
int const BUTTON = 4;  
int nextOption = 1;

char opt;
unsigned long previousMillis = 0;
bool blinking = false;  // Estado de intermitencia

// Variables para control del pulsador
int buttonState = HIGH;        
int lastButtonState = HIGH;    
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(LED_RED, OUTPUT); 
  pinMode(LED_YELLOW, OUTPUT); 
  pinMode(LED_GREEN, OUTPUT); 
  pinMode(BUTTON, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Welcome");
  Serial.println("Press any key to show menu...");
}

void loop() {
  // Lectura del menú por Serial 
  if (Serial.available() > 0) {
    menu();
    opt = Serial.read();
    int selected = opt - '0'; // convertir char a número

    if (selected == nextOption) {
      ejecutarOpcion(opt);
      avanzarMenu();
      menu();
    } else {
      Serial.print("Opción invalida. Debe elegir la opcion: ");
      Serial.println(nextOption);
    }
  }

  // Lectura del pulsador con anti-rebote 
  int reading = digitalRead(BUTTON);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        // Ejecuta la opción actual con el botón
        Serial.print("Pulsador ejecuta opcion ");
        Serial.println(nextOption);
        ejecutarOpcion(nextOption + '0'); // Ejecuta como si fuera del menú
        avanzarMenu();
        menu();
      }
    }
  }
  lastButtonState = reading;
  
  // Intermitencia no bloqueante 
  if (blinking) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 500) {
      previousMillis = currentMillis;
      digitalWrite(LED_RED, !digitalRead(LED_RED));
      digitalWrite(LED_YELLOW, !digitalRead(LED_YELLOW));
      digitalWrite(LED_GREEN, !digitalRead(LED_GREEN));
    }
  }
}

void ejecutarOpcion(char opt) {
  switch (opt) {
    case '1': digitalWrite(LED_RED, HIGH); break;
    case '2': digitalWrite(LED_RED, LOW); break;
    case '3': digitalWrite(LED_YELLOW, HIGH); break;
    case '4': digitalWrite(LED_YELLOW, LOW); break;
    case '5': digitalWrite(LED_GREEN, HIGH); break;
    case '6': digitalWrite(LED_GREEN, LOW); break;
    case '7':
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_GREEN, HIGH);
      break;
    case '8':
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
      break;
    case '9':
      blinking = !blinking;  // Alterna intermitencia
      break;
  }
}
// Avanza en el flujo secuencial
void avanzarMenu() {
  if (nextOption < 4) {
    nextOption++;
  } else if (nextOption == 4) {
    nextOption = 5;
  } else if (nextOption < 9) {
    nextOption++;
  } else if (nextOption == 9) {
    nextOption = 1; // Reinicia después de la 9
  }
}

void accionPulsador() {
  static int contador = 0;
  contador++;
  if (contador > 6) contador = 1;  // Reinicia ciclo

  switch (contador) {
    case 1: // Pulsación 1
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
      break;
    case 2: // Pulsación 2
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      break;
    case 3: // Pulsación 3
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, LOW);
      break;
    case 4: // Pulsación 4
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
      break;
    case 5: // Pulsación 5
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_GREEN, HIGH);
      break;
    case 6: // Pulsación 6
      blinking = !blinking;  // Alterna intermitencia infinita
      break;
  }
}

void menu() {
  Serial.println("\nMain menu");
  Serial.println("1. Turn on led red");
  Serial.println("2. Turn off led red");
  Serial.println("3. Turn on led yellow");
  Serial.println("4. Turn off led yellow");
  Serial.println("5. Turn on led green");
  Serial.println("6. Turn off led green");
  Serial.println("7. Turn on all");
  Serial.println("8. Turn off all");
  Serial.println("9. Intermitence");
  Serial.print("Press option: ");
  Serial.println(nextOption);
}