/**
* connect:
*   - red led to 13
*   - green led to 11
*   - active buzzer to 8
*   - ball tilter to 2
*/
const int ledR = 13;
const int ledG = 11;
const int buzzer = 8;
const int ballTilter = 2;

void setup () {
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
}


void loop() {
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
