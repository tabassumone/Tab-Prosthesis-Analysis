#include <VarSpeedServo.h>

VarSpeedServo servothumb;          // Define thumb servo
VarSpeedServo servoindex;          // Define index servo
VarSpeedServo servomajeure;
VarSpeedServo servoringfinger;
VarSpeedServo servopinky;



void setup() { 
  Serial.begin(9600);
  servothumb.attach(2);  // Set thumb servo to digital pin 2
  servoindex.attach(3);  // Set index servo to digital pin 3
  servomajeure.attach(4);
  servoringfinger.attach(5);
  servopinky.attach(6);
 
  
} 

void loop() {            // Loop through motion tests
   alltovirtual();        // Example: alltovirtual
  delay(4000);           // Wait 4000 milliseconds (4 seconds)
  alltorest();         
  delay(1500);          
  alltomax();           
  delay(1500);           
  peace();           
  delay(1500);
  alltorest();
  delay(2000);
  rock();           
  delay(1500); 
  alltorest();
  delay(1000);
  point();           
  delay(1500);  
  alltovirtual();
  delay(1500);
  pinch();           
  delay(1500);
}
// Motion to set the servo into "virtual" 0 position: alltovirtual
void alltovirtual() {         
  servothumb.write(0);
  servoindex.write(0);
  servomajeure.write(0);
  servoringfinger.write(0);
  servopinky.write(0);
 
}
// Motion to set the servo into "rest" position: alltorest
void alltorest() {         
   servothumb.write(0);
  servoindex.write(0);
  servomajeure.write(0);
  servoringfinger.write(0);
  servopinky.write(0);
 
}



// Motion to set the servo into "max" position: alltomax
void alltomax() {
  servothumb.write(180);
  servoindex.write(180);
  servomajeure.write(180);
  servoringfinger.write(180);
  servopinky.write(180);
 
 
}
void peace() {
  servothumb.slowmove(95,50);      //Never more than (95 degree)
  servoindex.slowmove(0,75);
  servomajeure.slowmove(0,60);
  servoringfinger.slowmove(90,75);
  servopinky.slowmove(90,75);
  

 
}

void rock() {
  servothumb.slowmove(95,50);  
  servoindex.slowmove(0,75);
  servomajeure.slowmove(80,75);        //Never more than (80 degree)
  servoringfinger.slowmove(90,75);
  servopinky.slowmove(0,75);
  
 
}

void point() {
  servothumb.slowmove(95,75);        //Never more than (95 degree)
  servoindex.slowmove(0,75);
  servomajeure.slowmove(80,75);
  servoringfinger.slowmove(90,75);
  servopinky.slowmove(90,75);


 
}

void pinch() {

 
  servothumb.slowmove(95,50);
  servoindex.slowmove(90,70);
  servomajeure.slowmove(0,70);      
  servoringfinger.slowmove(0,70);
  servopinky.slowmove(0,70);
 

 
}
