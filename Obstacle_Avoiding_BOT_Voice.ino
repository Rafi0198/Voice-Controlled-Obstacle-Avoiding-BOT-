#include <NewPing.h>
#include<Servo.h>

//our L298N control pins
int LeftMotorForward = 7;
int LeftMotorBackward = 6;
int RightMotorForward = 4;
int RightMotorBackward = 5;
int LeftMotorSpeed = A0 ; int RightMotorSpeed = A5;
int SpeedLeft; int SpeedRight;

int trigPin = A1; int echoPin = A2;
int maxDistance = 250;
int distance;
int cmd; int count; 

NewPing sonar(trigPin, echoPin, maxDistance);
//Servo servo_motor;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(RightMotorSpeed, OUTPUT);
  pinMode(LeftMotorSpeed, OUTPUT);

  //servo_motor.attach(10); //our servo pin

  //servo_motor.write(100); //60

  //delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);

  //  SpeedLeft = 150;
  //  SpeedRight = 150;
  //
  //  analogWrite(LeftMotorSpeed, SpeedLeft);
  //  analogWrite(RightMotorSpeed, SpeedRight);

}

void loop() {
  // put your main code here, to run repeatedly:

  distance = readPing();

  if (distance > 20) {

    if (Serial.available())
      cmd = Serial.read();



    if (cmd == 'F') {
      moveForward();
    }

    if (cmd == 'B') {
      moveBackward();
    }

    if (cmd == 'L') {
      turnLeft();
    }

    if (cmd == 'R') {
      turnRight();
    }

    if (cmd == 'S') {
      moveStop();
    }

    if (cmd == 'I') {
      ForwardRight();
    }

    if (cmd == 'G') {
      ForwardLeft();
    }

    if (cmd == 'H') {
      BackwardLeft();
    }

    if (cmd == 'J') {
      BackwardRight();

    }

    count = 0;
  }

  else {

    count++;

    if (Serial.available())
      cmd = Serial.read();

    if (count == 1) { 
      moveStop();
    } 
    
    if (cmd == 'B') {
      moveBackward();
    }

    if (cmd == 'S') {
      moveStop();
    }

  }

  //  Serial.println(cmd);
  //  Serial.println("Distance");
  Serial.println(distance);
  Serial.println(count);
  //delay(500);

}



int readPing() {
  //delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0) {
    cm = 250;
  }
  return cm;
}

void moveForward() {

  Serial.println("==Forward==");
  //Speed(150,150);

  analogWrite(LeftMotorSpeed, 150);
  analogWrite(RightMotorSpeed, 150);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

void moveBackward() {

  Serial.println("==Backward==");
  //Speed(150,150);

  analogWrite(LeftMotorSpeed, 160);
  analogWrite(RightMotorSpeed, 150);

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);

}

void ForwardRight() {
  Serial.println("==ForwardRight==");
  //Speed(150,120);

  analogWrite(LeftMotorSpeed, 160);
  analogWrite(RightMotorSpeed, 130);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);

}

void ForwardLeft() {
  Serial.println("==ForwardLeftt==");
  //Speed(120,150);

  analogWrite(LeftMotorSpeed, 130);
  analogWrite(RightMotorSpeed, 160);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);

}

void BackwardRight() {

  Serial.println("==BackwardRight==");
  //Speed(150,120);

  analogWrite(LeftMotorSpeed, 160);
  analogWrite(RightMotorSpeed, 130);

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);

}

void BackwardLeft() {

  Serial.println("==BackwardLeft==");
  // Speed(120,150);

  analogWrite(LeftMotorSpeed, 130);
  analogWrite(RightMotorSpeed, 160);


  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);

}



void turnRight() {

  Serial.println("==turnRight==");
  //Speed(100,100);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);

}

void turnLeft() {

  Serial.println("==turnLeft==");
  //Speed(100,100);

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

}

void moveStop() {

  Serial.println("==moveStop==");
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}



void Speed (int SpeedLeft, int SpeedRight) {

  analogWrite(LeftMotorSpeed, SpeedLeft);
  analogWrite(RightMotorSpeed, SpeedRight);

}
