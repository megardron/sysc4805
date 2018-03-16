void setup() {
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(2, INPUT);
}

int wall = LOW;
int noWall = HIGH;
int left;
int forward;
int swtch;
int leftSpeed = 180;
int rightSpeed = 205;

int rightForward = 6;
int rightBackward = 5;
int leftForward = 9;
int leftBackward = 10;
int leftSensor = 8;
int forwardSensor = 7;

void turnOff(){
    digitalWrite(10, LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(5,LOW);
    //delay(500);
}

void turnLeft() {
  turnOff();
  analogWrite(leftForward, leftSpeed);
  analogWrite(rightForward, rightSpeed);
  delay(700);
  turnOff();
  left = digitalRead(leftSensor);
  while (left!=wall) {
    left = digitalRead(leftSensor);
    analogWrite(rightForward, rightSpeed);
    analogWrite(leftBackward, leftSpeed);
  }
  turnOff();
}

void turnRight() {
//  turnOff();
//  analogWrite(leftBackward, leftSpeed);
//  analogWrite(rightBackward, rightSpeed);
//  delay(300);
  turnOff();
  analogWrite(leftForward, leftSpeed);
  analogWrite(rightBackward, rightSpeed);
  delay(800);
//  left = digitalRead(leftSensor);
//  while (left==wall) {
//    left = digitalRead(leftSensor);
//    analogWrite(leftForward, leftSpeed);
//    analogWrite(rightBackward, rightSpeed);
//  }
//  turnOff();
//    forward = digitalRead(forwardSensor);
//  while (forward ==noWall) {
//     forward = digitalRead(forwardSensor);
//    analogWrite(leftForward, leftSpeed);
//    analogWrite(rightForward, rightSpeed);
//  }
//  turnOff();
//  while (forward==wall) {
//    forward = digitalRead(forwardSensor);
//    analogWrite(leftForward, leftSpeed);
//    analogWrite(rightBackward, rightSpeed);
//  }
  turnOff();
  
}

void loop() {
  left = digitalRead(leftSensor);
  forward = digitalRead(forwardSensor);
  if (left==wall&&forward==noWall) {
    //go forward
    digitalWrite(leftBackward, LOW);
    digitalWrite(rightBackward, LOW);
    analogWrite(leftForward, leftSpeed);
    analogWrite(rightForward, rightSpeed);
  } else if (left==wall&&forward==wall) {
    //turn right
    turnRight();
  } else if (left==noWall&&forward==noWall) {
    turnLeft();
  } else {
    digitalWrite(leftBackward, LOW);
    digitalWrite(rightForward, LOW);
    analogWrite(leftForward, leftSpeed);
    analogWrite(rightBackward, rightSpeed);
  }
}
