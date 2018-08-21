#define TRIG_PIN 11   // HC_SR04 trig pin to Arduino pin 11
#define ECHO_PIN 12   // HC_SR04 echo pin to Arduino pin 12 


void setup() {

  pinMode(TRIG_PIN,          OUTPUT);
  pinMode(ECHO_PIN,          INPUT);
  
  // initialize serial communication:
  Serial.begin(9600);
}

void loop() {

  int distance = getDistance();  //call the getDistance function to get the distance in front of the robot

  Serial.print(", Obstacle:");
  Serial.print(distance);
  Serial.println("cm");

  if (distance < 20) //if object is closer than 20 centimeters, then display warning 
  {
    Serial.println("TOO CLOSE! Step Away!!");
    delay(300);
  }
  else //if path is blocked
  { 
    Serial.println("Clear...");
  }

  delay(100);
}

float getDistance()
{
  float duration, distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) * 0.0344;
  return distance;
}
