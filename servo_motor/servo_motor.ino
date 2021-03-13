
#include<Servo.h>
Servo motor;

int p=0;

void setup() {
  motor.attach(8);
  motor.write(80);
}

void loop() {
  for(p=0;p<360;p++)
  {
    motor.write(p);
    delay(10);
    }
 
}
