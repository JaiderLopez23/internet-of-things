#include<DHT.h>
#define DHTPIN 7
#define DHTTYPE DHT11
#define LED_RED  34
float humidity, temperature;

DHT dht (DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_RED, OUTPUT);
  dht.begin();
  Serial.begin(9600);
  Serial.print(":: Hello to weather Satation ::");
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.println(humidity);
  Serial.println("%");
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.println("°C");
  delay(2000);

  //NaN: Not a Number
}
