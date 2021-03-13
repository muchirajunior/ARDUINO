#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

#define trigPin 10
#define echoPin 13

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ULTRASONIC SENSOR");
  lcd.setCursor(0,1);
  lcd.print("MEASURING DISTANCE");
  delay(1500);
  
  
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if (distance >= 400 || distance <= 2){
    Serial.print("Distance = ");
    Serial.println("Out of range");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Distance = ");
    lcd.setCursor(0,1);
    lcd.print("Out of range");
  }
  else {
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Distance = ");
    lcd.setCursor(1,1);
    lcd.print(distance);
    lcd.print(" cm");
    delay(500);
  }
  delay(500);
}
