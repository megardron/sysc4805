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
int leftSpeed = 180;
int rightSpeed = 205;
int turnNumber = 6;
int turns[11] = {1,0,0,1,0,0,0,1,0,0};
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
    //delay(500);
}

void turnLeft() {
  analogWrite(leftForward, 200); //
  analogWrite(rightForward, 225); //
  if(turnNumber < 8){
  delay(400); 
  }
  else{
    delay(350);
  }
  turnOff();
  //delay(1000);
  while(digitalRead(leftSensor)== white ){
   analogWrite(leftBackward, 165);
   analogWrite(rightForward, 190);
 //  delay(75);
 //  turnOff();
 //  delay(30);
  }
  if(turnNumber > 8){
  analogWrite(rightBackward, 245);
  analogWrite(leftBackward, 225);
  delay(350);
  }
  turnOff();
}

void turnRight() {
  analogWrite(leftForward, 180); //
  analogWrite(rightForward, 205); //
  if(turnNumber < 8){
  delay(400); 
  }
  else{
    delay(350);
  }
  turnOff();
 // delay(1000); 
   while(digitalRead(rightSensor)== white){
   analogWrite(rightBackward, 190);
   analogWrite(leftForward, 165);
  // delay(75);
  // turnOff();
  // delay(30);
   } 
   if(turnNumber > 8){
  analogWrite(rightBackward, 245);
  analogWrite(leftBackward, 225);
  delay(350);
  }
  turnOff();
}

void turn() {
  turnOff();
    if (turns[turnNumber]) {
      turnLeft();
    } else {
      turnRight();
    }
    turnNumber++;
    if (turnNumber>11) {
        delay(1000000000);
    }
    turnOff();
    delay(150);
}
void loop() {  
  left = digitalRead(leftSensor);
  right = digitalRead(rightSensor); 
  while (swtch == HIGH){
    swtch = digitalRead(swatch);
  }
  if (turnNumber>6 && !turns[turnNumber-1]) {
    if (right==black&&left==white) {
      analogWrite(leftForward, 165);
      analogWrite(rightForward, 200);
    } else if (left==black&&right==black) {
       turn();
    } else if (left==white&&right==white) {
      analogWrite(leftForward, 175);
      digitalWrite(rightForward, LOW);
    }
  } else if (turnNumber>6) {
  if (right==white&&left==black) {
      analogWrite(leftForward, 165);
      analogWrite(rightForward, 200);
    } else if (left==black&&right==black) {
       turn();
    } else if (left==white&&right==white) {
      analogWrite(rightForward, 175);
      digitalWrite(leftForward, LOW);
    }
  
  }
  else {
  if (left==white) {
    if (turnNumber>6) {
       analogWrite(leftForward, 145);
    } else {
       analogWrite(leftForward, 225);
    }
 }
 if (right==white) {
  if (turnNumber>6) {
    analogWrite(rightForward, 165);
  } else {
    analogWrite(rightForward, 225);
  }
 }
 if (right==black&&left==black) {
    turn();
  }
  else if (right==black) {
    digitalWrite(rightForward, LOW);
  }
  else if (left==black) {
    digitalWrite(leftForward, LOW);
  }
  }
 // if (turnNumber>7) {
//     delay(75);
//     turnOff();
 //    delay(10 );
//  }
 
}

