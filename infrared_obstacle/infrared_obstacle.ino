
/*
 * This is the Arduino code Infrared Obstacle Avoidance module
 * watch the video for details and demo https://youtu.be/T3Li128GBlM
 *  * 
 * Written by Ahmad Nejrabi for Robojax Video channel www.Robojax.com
 * Date: Dec 28, 2017, in Ajax, Ontario, Canada
 * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 * this code has been downloaded from http://robojax.com/learn/arduino/
 * 
 * 
  */

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

int infrared=8;
int led1=10;
int led2=12;
void setup() {
 Serial.begin(9600);
 lcd.begin(16,2);
 pinMode(infrared, INPUT);// set pin as input
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);

 lcd.clear();
 lcd.setCursor(1,0);
 lcd.print("MUCHIRA JUNIOR");
 lcd.setCursor(1,1);
 lcd.print("AI & IOTs");
 delay(3000);

}

void loop() {
  //Written for Robojax on Dec 28, 2017
  int detect = digitalRead(infrared);// read obstacle status and store it into "detect"
  if(detect == LOW){
    
   Serial.print("Obastacle on the way \n"); 
   lcd.clear();
   lcd.setCursor(1,0);
   lcd.print("infrared sensor");
   lcd.setCursor(1,1);
   lcd.print("Obastacle near");
   digitalWrite(led1,HIGH);
   digitalWrite(led2,LOW);
  }else{
    
   Serial.print("All clear \n"); 
   lcd.clear();lcd.clear();
   lcd.setCursor(1,0);
   lcd.print("infrared sensor");
   lcd.setCursor(1,1);
   lcd.print("All clear "); 
   digitalWrite(led2,HIGH);
   digitalWrite(led1,LOW);
  }
  delay(300);
}
   
