#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 
const int trigPin1 = 13;
const int echoPin1 = 12;
const int trigPin2 = 11;
const int echoPin2 = 10;
const int relayPin1 = 4;
const int relayPin2 = 2;

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, LOW);
}

void loop() {
  long duration1, distance1, duration2, distance2;
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);gPin2, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;
  digitalWrite(trigPin1, LOW);
  digitalWrite(tri
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;
  lcd.setCursor(0, 0);
  lcd.print("Distance 1: ");
  lcd.print(distance1);
  lcd.print(" cm");
  lcd.setCursor(0, 1);
  lcd.print("Distance 2: ");
  lcd.print(distance2);
  lcd.print(" cm");
  if (distance1 < 100 && distance2 < 100) {
    digitalWrite(relayPin1, HIGH);
    digitalWrite(relayPin2, HIGH);
  } else {
    digitalWrite(relayPin1, LOW);
    digitalWrite(relayPin2, LOW);
  }
  delay(1000); 
  
}
