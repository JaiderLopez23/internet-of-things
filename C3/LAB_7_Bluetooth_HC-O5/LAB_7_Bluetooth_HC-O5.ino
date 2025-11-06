# define L1 5

void setup() {
  // put your setup code here, to run once:
 pinMode(L1, OUTPUT);
 Serial.begin(9600);
 Serial.println("Menu");
 Serial.println("[1]. Turn on L1");
 Serial.println("[2]. Turn off L1");
 Serial.println("Press any option");
}

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available() > 0){
  char opt = Serial.read();
  if (opt == '\r' || opt == '\n'){
    return;
  }
  if(opt == '1'){
    digitalWrite(L1, HIGH);
  }else{
    if(opt == '2'){
      digitalWrite(L1, LOW);
    }else{
      Serial.print("Invalid option");
    }
  }
 }
}
