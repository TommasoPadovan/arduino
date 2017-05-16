int lightPin = 0;
int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

int ledsConfig = 0;

void setup()  {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  
  
}



void loop() {
  int lightIntensity = analogRead(lightPin);
  int ledOn = lightIntensity / (112 / 2);
  if (ledOn > 8) ledOn = 8;
  ledsConfig = 0;
  for (int i=0; i<ledOn; ++i) {
    bitSet(ledsConfig, i);
  }
  updateShiftRegister();
}






void updateShiftRegister() {
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, ledsConfig);
   digitalWrite(latchPin, HIGH);
}
