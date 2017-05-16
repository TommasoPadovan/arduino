#include "SR04.h"

const int tringPin = 12;
const int echoPin = 11;

SR04 sr04Sensor = SR04(echoPin, tringPin);


void setup() {
  Serial.begin(9600);
  delay(1000);
}


void loop() {
  Serial.print(sr04Sensor.Distance());
  Serial.println("cm");
  delay(1000);
}

