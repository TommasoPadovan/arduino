/**
*  connect:
*    - vcc -> 5v
*    - gnd -> gnd
*    - x -> a0
*    - y -> a1
*    - sw(select) -> 2
*/
const int SWPin = 2;
const int xPin = 0;  //analog
const int yPin = 1;  //analog


void setup() {
  pinMode(SWPin, INPUT);
  digitalWrite(SWPin, HIGH);
  Serial.begin(9600);
}


void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SWPin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(xPin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(yPin));
  Serial.print("\n\n");
  delay(500);
}
