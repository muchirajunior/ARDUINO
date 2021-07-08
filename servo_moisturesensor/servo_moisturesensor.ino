#include <LiquidCrystal_I2C.h>
#include <Servo.h> 

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

//#include <LiquidCrystal.h>
//LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int sensorPin = A0;
int sensorValue= 0;
int percentValue = 0;
String tap="CLOSED";


Servo servo;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  servo.attach(8); 
  servo.write(0); 
  Serial.print("testing .........");
 
}

void loop() {

  sensorValue = analogRead(sensorPin);
  Serial.print("\n\nAnalog Value: ");
  Serial.print(sensorValue);
  
  percentValue = map(sensorValue, 1023, 200, 0, 100);
  Serial.print("\nPercentValue: ");
  Serial.print(percentValue);
  Serial.print("%");
  lcd.setCursor(0, 0);
  lcd.print("Moisture: "+String(percentValue)+"%");
  if (percentValue>50){
    Serial.print("\n Tap closed!");
    tap="CLOSED";
    servo.write(90);
    
    }
    else{
      Serial.print("\n Tap Open!");
      tap="OPEN";
       servo.write(0);
     
      }
  
  lcd.setCursor(0, 1);  
  lcd.print("Tap: ");
  lcd.print(tap);
  lcd.print("%");
  delay(1000);
  lcd.clear();
}
