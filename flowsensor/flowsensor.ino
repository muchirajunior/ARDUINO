
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);
//ttLiquidCrystal_I2C lcd(0x27,16,2,POSITIVE);
 

int A;
int B;
float Time=0;
float frequency=0;
float water=0;
float rate=0;
float Total=0;
const int input=A0;

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WATER FLOW METER");
  lcd.setCursor(0,1);
  lcd.print("**by MUCHIRA JUNIOR **");
  delay(200);
  pinMode(input,INPUT);
  }

void loop (){
  A=pulseIn(input,HIGH);
  B=pulseIn(input,LOW);
  Time=A+B;
  frequency=1000000/Time;
  water=frequency/0.75;
  rate=water/3600;

  if (frequency>=0){

    if (isinf(frequency)){
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("rate : 0.00");
       lcd.setCursor(0,1);
       lcd.print("TOTAL :");
       lcd.print(Total);
       lcd.print(" L");
      }
     else{
        Total=Total+rate;
        Serial.println(frequency);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("rate : ");
        lcd.print(water);
        lcd.print("L/min");
        lcd.setCursor(0,1);
        lcd.print("TOTAL :");
        lcd.print(Total);
        lcd.print(" L");
      }
    }
    delay(1000);
  }
