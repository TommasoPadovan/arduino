const int dataPin = 12;
const int latchPin = 11;
const int clockPin = 9;


const int delayTime = 500;



byte ledsConfig = 0;

void setup() {
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
}

void loop() {
  ledsConfig = 0;
  updateShiftRegister();
  delay(delayTime);
  
  for (int i=0; i<0xFF; i++) {
    ledsConfig = i;
    //bitSet(ledsConfig, i);
    updateShiftRegister();
    delay(delayTime);
  }
   
}




void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, ledsConfig);
  digitalWrite(latchPin, HIGH);
}

