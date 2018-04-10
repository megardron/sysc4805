/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/
// defines pins numbers

const int echoForward = 4;
const int echoRight = 12;
const int echoLeft = 11;
const int rightForward = 6;
const int rightBackward = 5;
const int leftForward = 9;
const int leftBackward = 10;
const int trigRight = 7;
const int trigForward = 3;
const int trigLeft = 8;
// defines variables
long forwardDuration;
int forwardDistance;

long leftDuration;
int leftDistance;

long rightDuration;
int rightDistance;
void setup() {
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(rightBackward,OUTPUT);
  pinMode(rightForward,OUTPUT);
  pinMode(leftForward,OUTPUT);
  pinMode(leftBackward,OUTPUT);
  pinMode(2, INPUT);
  pinMode(trigRight, OUTPUT); // Sets the trigPin as an Output
  pinMode(trigLeft, OUTPUT);
  pinMode(trigForward, OUTPUT);
  pinMode(echoForward, INPUT); // Sets the echoPin as an Input
  pinMode(echoLeft, INPUT);
  pinMode(echoRight, INPUT);
  Serial.begin(9600); // Starts the serial communication
}

void turnOn(int rForward, int rSpeed, int lForward, int lSpeed) {
  if (rForward == 2) {
    digitalWrite(rightForward, LOW);
    digitalWrite(rightBackward, LOW);
  } else if (rForward) {
    analogWrite(rightForward, rSpeed);
    digitalWrite(rightBackward, LOW);
  } else {
    analogWrite(rightBackward, rSpeed);
    digitalWrite(rightForward, LOW);
  }
  if (lForward == 2) {
    digitalWrite(leftForward, LOW);
    digitalWrite(leftBackward, LOW);
  } else if (lForward) {
    analogWrite(leftForward, lSpeed);
    digitalWrite(leftBackward, LOW);
  } else {
    analogWrite(leftBackward, lSpeed);
    digitalWrite(leftForward, LOW);
  }
}

void turnOff(){
    digitalWrite(10, LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(5,LOW);
    //delay(500);
}

int pingDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration *0.034/2;
}

void turn() {
  turnOff();
  //delay(500);
  forwardDistance = pingDistance(trigForward, echoForward);
  rightDistance= pingDistance(trigRight, echoRight); 
  leftDistance = pingDistance(trigLeft, echoLeft);
  if (leftDistance>10) {
      turnOn(1,225,0,255);
      delay(800);
      turnOff();
      delay(500);
      turnOn(1,240,1,225);
      delay(500);
      turnOff();
  } else if (rightDistance>10) {
    turnOn(0,255,1,200);
    delay(800);
    turnOff();
    delay(500);
    turnOn(1,240,1,225);
    delay(500);
    turnOff();
  }
  delay(500);
}

void loop() {
// Clears the trigPin
forwardDistance = pingDistance(trigForward, echoForward);
rightDistance= pingDistance(trigRight, echoRight);
leftDistance = pingDistance(trigLeft, echoLeft);
// Prints the distance on the Serial Monitor
if (forwardDistance < 5) {
 turn();
} 
else {
  
  if ((leftDistance < 3)&& (rightDistance >3) && (rightDistance <10)){
    turnOn(2,145,1,240);
  }
  else if ((rightDistance < 3 ) && (leftDistance >3) && (leftDistance<10)) {
    turnOn(1,240,2,145);
  } else {
    turnOn(1,240,1,225);
  }
}

}
