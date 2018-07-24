#include <Servo.h>

int servoPin = 9;
Servo theservo;
int servoAngle = 0;
void setup()
{
  Serial.begin(9600);
  theservo.attach(servoPin);
}

void loop()
{
  for(servoAngle = 0; servoAngle < 180; servoAngle++)  //move the micro servo from 0 degrees to 180 degrees
  {                                  
    theservo.write(servoAngle);              
    delay(50);                  
  }

  for(servoAngle = 180; servoAngle > 0; servoAngle--)  //now move back the micro servo from 0 degrees to 180 degrees
  {                                
    theservo.write(servoAngle);          
    delay(10);      
  }
}


