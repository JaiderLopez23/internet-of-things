int const LED_RED = 5;
int const LED_YELLOW = 18;
int const LED_GREEN =19;
char opt;
int nextOption = 1;

void setup() {
pinMode(LED_RED, OUTPUT); 
pinMode(LED_YELLOW, OUTPUT); 
pinMode(LED_GREEN, OUTPUT); 
Serial.begin(9600);
Serial.println("Welcome");
Serial.println("Press any key to show menu...");
}

void loop() {
  if (Serial.available() > 0) {
    menu();
    opt = Serial.read();

    // Convertir char a número
    int selected = opt - '0';

    // Verificar si la opción es la siguiente válida
    if (selected == nextOption) {
      ejecutarOpcion(selected);
      nextOption++;  // Avanzar a la siguiente opción
      if (nextOption > 9) {
        nextOption = 1; // Reinicia después de la última opción
      }
    } else {
      Serial.print("Solo puede elegir la opción. ");
      Serial.println(nextOption);
    }
  }
}

void ejecutarOpcion(int option) {
  switch (option) {
    case 1: digitalWrite(LED_RED, HIGH); break;
    case 2: digitalWrite(LED_RED, LOW); break;
    case 3: digitalWrite(LED_YELLOW, HIGH); break;
    case 4: digitalWrite(LED_YELLOW, LOW); break;
    case 5: digitalWrite(LED_GREEN, HIGH); break;
    case 6: digitalWrite(LED_GREEN, LOW); break;
    case 7:
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_GREEN, HIGH);
      break;
    case 8:
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
      break;
    case 9:
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
      break;
  }
}

void menu() {
Serial.println("Main menu");
Serial.println("1. Turn on led red");
Serial.println("2. Turn off led red");
Serial.println("3. Turn on led yellow");
Serial.println("4. Turn off led yellow");
Serial.println("5. Turn on led green");
Serial.println("6. Turn off led green");
Serial.println("7. Turn on all");
Serial.println("8. Turn off all");
Serial.println("9. Intermitence");
Serial.print("Press any option ");
Serial.println(nextOption);
}