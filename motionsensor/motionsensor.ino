
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

int sensor_input=2;
int alarm_output=8;
void setup() {
  Serial.begin(9600);// setup Serial Monitor to display information
  pinMode(sensor_input, INPUT);// Input from sensor
  pinMode(alarm_output, OUTPUT);// OUTPUT to alarm or LED
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MOTION SENSOR");
  lcd.setCursor(0,1);
  lcd.print(" JUNIOR IOTs");
  delay(2000);
}

void loop() {
  int motion =digitalRead(sensor_input);
  lcd.clear();
  if(motion){
    Serial.println("Motion detected");
    digitalWrite(8,HIGH);
    lcd.setCursor(1,0);
    lcd.print("Motion detected");
  }else{
     Serial.println("===nothing moves");
     digitalWrite(8,LOW);
      lcd.setCursor(1,0);
    lcd.print("===nothing moves");
  }
  delay(500);

}
 
