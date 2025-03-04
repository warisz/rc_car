//L293D + bluetooth rc car

#include <SoftwareSerial.h>
SoftwareSerial BT(12, 11); 
//Motor A
const int motorPin1  = 5; 
const int motorPin2  = 6; 
//Motor B
const int motorPin3  = 10;
const int motorPin4  = 9;   

//This will run only one time.
void setup(){
    BT.begin(9600); //Init serial communication
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);

}


void loop(){
    if (BT.available()){
      char data = BT.read();
      if(data == 'a'){
        //Forwards
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, HIGH);
        
      }else if(data == 'b'){
        //Backwards
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, HIGH);
        digitalWrite(motorPin3, HIGH);
        digitalWrite(motorPin4, LOW);
        
      }else if(data == 'c'){
        //Turn
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, HIGH);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, HIGH);
        
      }else if(data == 'd'){
        //Stop
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
      }

    }

  delay(50);

}
