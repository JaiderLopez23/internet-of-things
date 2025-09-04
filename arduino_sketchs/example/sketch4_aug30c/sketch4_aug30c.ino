int const LED_RED = 11;
int const LED_YELLOW = 12;
int const LED_GREEN =13;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
     // LED ROJO parpadea 5 veces
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED_RED, HIGH);
    delay(500);
    digitalWrite(LED_RED, LOW);
    delay(500);
  }

  // LED AMARILLO parpadea 5 veces
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED_YELLOW, HIGH);
    delay(500);
    digitalWrite(LED_YELLOW, LOW);
    delay(500);
  }

  // LED VERDE parpadea 5 veces
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED_GREEN, HIGH);
    delay(500);
    digitalWrite(LED_GREEN, LOW);
    delay(500);
  }
}
