#include <Servo.h>

Servo servo;

/**
* connect:
*   - red led to 13
*   - green led to 11
*   - active buzzer to 8
*   - ball tilter to 2
*   - servo to 9
*/
const int ledR = 13;
const int ledG = 11;
const int buzzer = 8;
const int ballTilter = 2;
const int servoPin = 9;


void setup() {
  servo.attach(servoPin);
  
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
}

int loopTime = 0;
int pos = 0;

boolean goingUp = true;

void loop() {
  long mil = millis();
  if (mil >= loopTime+15) {
    loopTime = mil;
    servo.write(pos);
    
    if (goingUp) {
      pos++;
      if (pos>=180) goingUp = false;      
    } else {
      pos--;
      if (pos<=0) goingUp = true;
    }   
  }

  
  if (digitalRead(ballTilter) == HIGH) {
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, HIGH);
    digitalWrite(buzzer, LOW);
  } else {
    digitalWrite(ledG, LOW);
    digitalWrite(ledR, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  
}


