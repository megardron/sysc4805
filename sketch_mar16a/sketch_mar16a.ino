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

void turnOff(){
    digitalWrite(10, LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(5,LOW);
    //delay(500);
}
void loop() {
// Clears the trigPin
digitalWrite(trigForward, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigForward, HIGH);
delayMicroseconds(10);
digitalWrite(trigForward, LOW);
forwardDuration = pulseIn(echoForward, HIGH);
// Reads the echoPin, returns the sound wave travel time in microseconds
digitalWrite(trigRight, LOW);
delayMicroseconds(2);
digitalWrite(trigRight, HIGH);
delayMicroseconds(10);
digitalWrite(trigRight, LOW);
rightDuration = pulseIn(echoRight, HIGH);
digitalWrite(trigLeft, LOW);
delayMicroseconds(2);
digitalWrite(trigLeft, HIGH);
delayMicroseconds(10);
digitalWrite(trigLeft, LOW);
leftDuration = pulseIn(echoLeft, HIGH);
// Calculating the distance
rightDistance= rightDuration*0.034/2;
leftDistance = leftDuration*0.034/2;
forwardDistance= forwardDuration*0.034/2;
// Prints the distance on the Serial Monitor
if (forwardDistance < 5) {
 turnOff();
} 
if (forwardDistance > 5) {
  
  if ((leftDistance < 5) && (rightDistance > 5)){
    digitalWrite(rightForward, LOW);
   digitalWrite(leftForward, HIGH);
  }
  else if ((leftDistance > 5) && (rightDistance < 5)) {
    digitalWrite(rightForward, HIGH);
    digitalWrite(leftForward, LOW);
  } else {
    digitalWrite(rightForward, HIGH);
   digitalWrite(leftForward, HIGH);
  }
}

}
