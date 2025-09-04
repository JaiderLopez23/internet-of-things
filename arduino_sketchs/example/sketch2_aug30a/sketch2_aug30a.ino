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
  digitalWrite(LED_RED, HIGH);
  delay(1000); //mlsegundo
  digitalWrite(LED_RED, LOW);

  digitalWrite(LED_YELLOW, HIGH);
  delay(1000); //mlsegundo
  digitalWrite(LED_YELLOW, LOW);

  digitalWrite(LED_GREEN, HIGH);
  delay(1000); //mlsegundo
  digitalWrite(LED_GREEN, LOW);
}
