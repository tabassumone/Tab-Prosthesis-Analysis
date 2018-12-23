//creating for loop

//Add the servo library.This library is standard library
#include <Servo.h>

//Define our servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

 
//servo position in degrees
int servoPos = 0;

void setup()
{
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);

  
}
void loop()
{
 
  //scan from 0 to 180 degrees
  for(servoPos = 0; servoPos <180; servoPos++)
  {
    servo1.write(servoPos);
    //it also map the degree values to miliseconds values.
    servo2.write(servoPos);
    servo3.write(servoPos);
    servo4.write(servoPos);
    servo5.write(servoPos);
    delay(40);
  }
   // goes from 180 degrees to 0 degrees
  for (servoPos = 180; servoPos > 0; servoPos--)
  {
    servo1.write(servoPos); 
    servo2.write(servoPos);
    servo3.write(servoPos);
    servo4.write(servoPos);
    servo5.write(servoPos);
    delay(40);         
  }
}
