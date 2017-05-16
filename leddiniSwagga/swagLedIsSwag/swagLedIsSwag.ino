int r = 2;
int g = 3;
int b = 4;

int delayTime = 333;

void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}



void loop() {
  rgbLight(1,0,0);
  delay(delayTime);
  rgbLight(0,1,0);
  delay(delayTime);
  rgbLight(0,0,1);
  delay(delayTime);
  rgbLight(0,1,0);
  delay(delayTime);
}

void rgbLight(boolean rof, boolean gof, boolean bof) {
  digitalWrite(r, rof);
  digitalWrite(g, gof);
  digitalWrite(b, bof);
}
