int trigPin = 7;
int echoPin = 6;
int ledVerde = 4;
int ledAmarillo = 3;
int ledRojo = 2;

long distancia;
long duracion;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  
  Serial.println("Sistema de deteccion de agua iniciado");
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duracion = pulseIn(echoPin, HIGH);
  distancia = duracion * 0.034 / 2; 
  
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
 
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledRojo, LOW);
  
  if (distancia > 150) {
    digitalWrite(ledVerde, HIGH);
    Serial.println("Estado: NORMAL");
  }
  else if (distancia > 100) {
    digitalWrite(ledAmarillo, HIGH);
    Serial.println("Estado: ATENCION");
  }
  else if (distancia > 50) {
    digitalWrite(ledRojo, HIGH);
    Serial.println("Estado: PELIGRO");
  }
  else {
    digitalWrite(ledRojo, HIGH);
    delay(250);
    digitalWrite(ledRojo, LOW);
    delay(250);
    Serial.println("Estado: CRITICO!");
  }
  
  delay(100);
}