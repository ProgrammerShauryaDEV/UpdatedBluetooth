int MOTOR1_DIRECTION_PIN = 12;
int MOTOR2_DIRECTION_PIN = 13;

int MOTOR1_SPEED_PIN = 10;
int MOTOR2_SPEED_PIN = 11;

int trigpin = 11;
int echopin = 12;

long duration;
int distance;

#define Buzzer 4

char command;
void setup() {
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(MOTOR1_DIRECTION_PIN, OUTPUT);
  pinMode(MOTOR2_DIRECTION_PIN, OUTPUT);
  pinMode(MOTOR1_SPEED_PIN, OUTPUT);
  pinMode(MOTOR2_SPEED_PIN, OUTPUT);
  pinMode(4,OUTPUT)
  
//  _servo.attach(SERVO_PIN);
}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop(); 
    switch(command){
    case 'F':  
      Forward();
      break;
    case 'B':  
       Back();
      break;
    case 'L':  
      Left();
      break;
    case 'R':
      Right();
      break;
     
   
    }
  } 
}
void Forward(){
  digitalWrite(MOTOR1_DIRECTION_PIN,HIGH);
  digitalWrite(MOTOR2_DIRECTION_PIN,HIGH);
  analogWrite(MOTOR1_SPEED_PIN,255);
  analogWrite(MOTOR2_SPEED_PIN,255);
}
void Back(){
  digitalWrite(MOTOR1_DIRECTION_PIN,LOW);
  digitalWrite(MOTOR2_DIRECTION_PIN,LOW);
  analogWrite(MOTOR1_SPEED_PIN,255);
  analogWrite(MOTOR2_SPEED_PIN,255);
  
}
void Right(){
  digitalWrite(MOTOR1_DIRECTION_PIN,HIGH);
  digitalWrite(MOTOR2_DIRECTION_PIN,LOW);
  analogWrite(MOTOR1_SPEED_PIN,255);
  analogWrite(MOTOR2_SPEED_PIN,255);
}
void Left(){
  digitalWrite(MOTOR1_DIRECTION_PIN,LOW);
  digitalWrite(MOTOR2_DIRECTION_PIN,HIGH):
  analogWrite(MOTOR1_SPEED_PIN,255);
  analogWrite(MOTOR2_SPEED_PIN,255);
}
void Stop(){
  digitalWrite(MOTOR1_DIRECTION_PIN,HIGH);
  digitalWrite(MOTOR2_DIRECTION_PIN,HIGH);
  analogWrite(MOTOR1_SPEED_PIN,0);
  analogWrite(MOTOR2_SPEED_PIN,0);
}
void AutoPilot(){
  if (distance<=10){
    Stop();
    delay(500);
    Back();
    delay(500);
    Right();
    ReadDistance();
    if (distance<=10){
      Left();
    else{
    Forward();
    }
    }
 else{
    Forward();
  }
}
void ReadDistance(){
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
