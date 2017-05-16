int red = 6;
int green = 5;
int blue = 3;

void setup() {
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
}


void loop() {
  int redValue = 255;
  int greenValue = 0;
  int blueValue = 0;
  
  for (int i=0; i<255; ++i) {
    --redValue;
    ++greenValue;
    analogWrite(red, redValue);
    analogWrite(green, greenValue);  
    delay(1);
  }
  
  for (int i=0; i<255; ++i) {
    --greenValue;
    ++blueValue;
    analogWrite(green, greenValue);  
    analogWrite(blue, blueValue);
    delay(1);
  }
  
  for (int i=0; i<255; ++i) {
    --blueValue;
    ++redValue;
    analogWrite(blue, blueValue);
    analogWrite(red, redValue);  
    delay(1);
  }
  
  
}
  
