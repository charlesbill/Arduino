#include <Servo.h>

int servoPin = 9;
Servo theservo;

void setup()
{
  Serial.begin(9600);
  theservo.attach(servoPin);
}

void loop()
{
  theservo.write(45); // turn left to 45 degrees
  delay(1000);
  theservo.write(90);
  delay(1000);
  theservo.write(135);
  delay(1000);
  theservo.write(90);
  delay(1000);
}


