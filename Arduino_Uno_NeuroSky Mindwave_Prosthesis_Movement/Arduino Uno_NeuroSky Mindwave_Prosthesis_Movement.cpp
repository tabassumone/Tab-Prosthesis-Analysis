//#include <Servo.h>               //Since we are using more advanced library so it is not necessary to include servo.h library
#include <Brain.h>
// Set up the brain parser, pass it the hardware serial object you want to listen on.
#include <VarSpeedServo.h>
Brain brain(Serial);

VarSpeedServo servothumb;          // Define thumb servo
VarSpeedServo servoindex;          // Define index servo
VarSpeedServo servomajeure;
VarSpeedServo servoringfinger;
VarSpeedServo servopinky;
VarSpeedServo servowrist;


long attention; // Attention value read
 long val;
  long val2;

void setup() { 
  // Start the hardware serial.
  Serial.begin(9600);
  servothumb.attach(2);  // Set thumb servo to digital pin 2
  servoindex.attach(3);  // Set index servo to digital pin 3
  servomajeure.attach(4);
  servoringfinger.attach(5);
  servopinky.attach(6);
  servowrist.attach(7);
  
  long val;
  long val2;
} 

void loop() {     

 // Expect packets about once per second.
        // The .readCSV() function returns a string (well, char*) listing the most recent brain data, in the following format:
        // "signal strength, attention, meditation, delta, theta, low alpha, high alpha, low beta, high beta, low gamma, high gamma"   
        if (brain.update()) {
        //Commented out the serial output for graphing untill troubleshooting complete
        Serial.println(brain.readCSV());
                
                
  attention = brain.readAttention();  // Retrieve Attention Value 0 - 100
        }

// Make sure we have a signal.
  //if(brain.readSignalQuality() == 0) {

// Close hand if attention value high enough
    if (attention > 1) {
          pinch();
//} 
    } 
  else {
        alltorest();
  }

     if (attention > 25){
         point();
    }
   else {
        alltovirtual();
   }
    if (attention > 50){
         peace();
    }
   else {
       alltorest();
   }
   if (attention > 75){
         rock();
   }
  else {
      alltorest();
  }
// Loop through motion tests
  alltovirtual();        // Example: alltovirtual
  delay(4000);           // Wait 4000 milliseconds (4 seconds)
  delay(8000); 
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
  servothumb.slowmove(0,75);
  servoindex.slowmove(0,75);
  servomajeure.slowmove(0,60);
  servoringfinger.slowmove(0,75);
  servopinky.slowmove(0,75);
  servowrist.slowmove(0,75);

}
// Motion to set the servo into "rest" position: alltorest
void alltorest() {         
  servothumb.slowmove(15,80);//Thumb binds dont go to zero
  servoindex.slowmove(0,75);
  servomajeure.slowmove(0,75);
  servoringfinger.slowmove(0,75);
  servopinky.slowmove(0,75);
  servowrist.slowmove(0,75);

}



// Motion to set the servo into "max" position: alltomax
void alltomax() {
  servothumb.slowmove(95,50);       //Never more than (95 degree)
  servoindex.slowmove(90,75);
  servomajeure.slowmove(90,75);
  servoringfinger.slowmove(90,75);
  servopinky.slowmove(90,75);
  servowrist.slowmove(120,75);
 
}
void peace() {
  servothumb.slowmove(95,50);      //Never more than (95 degree)
  servoindex.slowmove(0,75);
  servomajeure.slowmove(0,60);
  servoringfinger.slowmove(90,75);
  servopinky.slowmove(90,75);
  servowrist.slowmove(120,75);

 
}

void rock() {
  servothumb.slowmove(95,50);  
  servoindex.slowmove(0,75);
  servomajeure.slowmove(80,75);        //Never more than (80 degree)
  servoringfinger.slowmove(90,75);
  servopinky.slowmove(0,75);
  servowrist.slowmove(120,75);
 
}

void point() {
  servothumb.slowmove(95,75);        //Never more than (95 degree)
  servoindex.slowmove(0,75);
  servomajeure.slowmove(80,75);
  servoringfinger.slowmove(90,75);
  servopinky.slowmove(90,75);
  servowrist.slowmove(120,75);

 
}
//Slowed down pinch a bit compared to others for testing
void pinch() {
  val=attention;
  val2=attention;
  val = map(val, 0, 65, 0, 95);
  servothumb.slowmove(val,50);      //Never more than (95 degree)
  //servothumb.slowmove(95,50);
  val2 = map(val2, 0, 65, 0, 90);   
  servoindex.slowmove(val2,70);     //Never more than (90 degree)
  //servoindex.slowmove(90,70);
  servomajeure.slowmove(0,70);      
  servoringfinger.slowmove(0,70);
  servopinky.slowmove(0,70);
  servowrist.slowmove(120,70);

 
}


