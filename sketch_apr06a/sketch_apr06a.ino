const int rightSensor = 11;
const int leftSensor = 12;

int left;
int right;

const int trigForward = 3;
const int echoForward = 2;
double forwardDistance;
long duration;

const int rightForward = 6;
const int rightBackward = 5;
const int leftForward = 9;
const int leftBackward = 10;


double pingDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return  duration*0.034/2;
}

void turnOff(){
    digitalWrite(10, LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(5,LOW);
    //delay(500);
}

void turn() {
 turnOff();
 analogWrite(leftForward,225);
 analogWrite(rightForward, 200);
 delay(250);
 turnOff();
 left = digitalRead(leftSensor);
 right = digitalRead(rightSensor);
 if (right) {
    analogWrite(leftForward, 225);
    analogWrite(rightBackward, 200);
    delay(900);
 } else {
    analogWrite(leftBackward, 200);
    analogWrite(rightForward, 225);
    delay(900);
 }
 turnOff();
 analogWrite(leftForward,225);
 analogWrite(rightForward, 200);
 delay(250);
 turnOff();
 delay(500);
}

void setup() {
  pinMode(rightSensor,INPUT);
  pinMode(leftSensor,INPUT);
  
  pinMode(rightBackward,OUTPUT);
  pinMode(rightForward,OUTPUT);
  pinMode(leftForward,OUTPUT);
  pinMode(leftBackward,OUTPUT);
  
  pinMode(trigForward, OUTPUT);
  pinMode(echoForward, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  forwardDistance = pingDistance(trigForward, echoForward);
  left = digitalRead(leftSensor);
  right = digitalRead(rightSensor);
  Serial.print(forwardDistance);
  Serial.print("\n");
  if (forwardDistance < 5.0 && forwardDistance > 1.9) {
    turn();
  } 
  else {
    if (!left&&right) {
    digitalWrite(leftBackward, LOW);
    digitalWrite(rightBackward, LOW);
    digitalWrite(rightForward, LOW);
    analogWrite(leftForward,200);
  } else if (!right&&left) {
    digitalWrite(leftBackward, LOW);
    digitalWrite(rightBackward, LOW);
    digitalWrite(leftForward, LOW);
    analogWrite(rightForward,200);
  } else {
    digitalWrite(leftBackward, LOW);
    digitalWrite(rightBackward, LOW);
    analogWrite(leftForward, 200);
    analogWrite(rightForward, 200);
  }
 }
}
