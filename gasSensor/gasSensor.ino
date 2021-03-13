#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

int redLed = 10;
int greenLed = 8;
//int buzzer = 8;
int smokeA0 = A0;
// Your threshold value
int sensorThres = 100;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  //pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("GAS SENSOR");
  lcd.setCursor(0,1);
  lcd.print("CHECKING GASES ");
  delay(1500);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Smoke Level:");
  lcd.print(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor>110)
  {
    digitalWrite(redLed, HIGH);
    lcd.setCursor(0,1);
    lcd.print("Alert....!!!");
    digitalWrite(greenLed, LOW);
   // tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    lcd.setCursor(0, 1);
    lcd.print(".....Normal.....");
   // noTone(buzzer);
  }
  delay(500);
  lcd.clear();
}
