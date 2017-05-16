int led = 5;
int btnA = 9;
int btnB = 8;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(btnA, INPUT_PULLUP);
  pinMode(btnB, INPUT_PULLUP);
}

boolean swagMode = false;


void loop() {
  if (digitalRead(btnA) == LOW) {
      swagMode = true;
  }
  
  if (digitalRead(btnB) == LOW) {
    swagMode = false;
  }
  
  if (swagMode) {
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
  }
  
}
