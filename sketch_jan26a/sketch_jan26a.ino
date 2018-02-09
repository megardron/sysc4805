void setup() {
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(2, INPUT);
}

int white = LOW;
int black = HIGH;

int left;
int right;
int swtch;
int leftSpeed = 200;
int rightSpeed = 225;
int turnNumber = 0;
int turns[11] = {1,0,0,1,0,0,0,1,1,0,1};
int swatch = 2;

int rightForward = 6;
int rightBackward = 5;
int leftForward = 9;
int leftBackward = 10;
int leftSensor = 8;
int rightSensor = 7;

void turnOff(){
    digitalWrite(10, LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(5,LOW);
    delay(500);
}

void turnLeft() {
  analogWrite(leftForward, leftSpeed); //
  analogWrite(rightForward, rightSpeed); //
  delay(500); 
  turnOff();
  delay(1000);
  while(digitalRead(leftSensor)== white ){
   analogWrite(leftBackward, leftSpeed);
   analogWrite(rightForward, rightSpeed);
   delay(75);
   turnOff();
   delay(30);
  }
  turnOff();
}

void turnRight() {
  analogWrite(leftForward, leftSpeed); //
  analogWrite(rightForward, rightSpeed); //
  delay(500); 
  turnOff();
  delay(1000); 
   while(digitalRead(rightSensor)== white){
   analogWrite(rightBackward, rightSpeed);
   analogWrite(leftForward, leftSpeed);
   delay(75);
   turnOff();
   delay(30);
   } 
  turnOff();
}
void loop() {  
  left = digitalRead(leftSensor);
  right = digitalRead(rightSensor); 
  while (swtch == HIGH){
    swtch = digitalRead(swatch);
  }
  if (left==white) {
    analogWrite(leftForward, leftSpeed);
   
 }
 if (right==white) {
    analogWrite(rightForward, rightSpeed);
 }
 if (right==black&&left==black) {
    turnOff();
    if (turns[turnNumber]) {
      turnLeft();
    } else {
      turnRight();
    }
    turnNumber++;
    if (turnNumber>10) {
        delay(1000000000);
    }
  }
  else if (right==black) {
    digitalWrite(rightForward, LOW);
  }
  else if (left==black) {
    digitalWrite(leftForward, LOW);
  }
delay(75);
turnOff();
delay(2);
 
}

