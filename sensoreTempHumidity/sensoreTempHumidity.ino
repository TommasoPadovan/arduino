#include <SimpleDHT.h>

const int dht11Pin = 2;

SimpleDHT11 dht11;

void setup() {
  Serial.begin(9600);
}


void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  byte temp = 0;
  byte humidity = 0;
  byte data[40] = {0};
  if ( dht11.read(dht11Pin, &temp, &humidity, data) ) {
    Serial.println("reading failed");
    return;
  }
  
  Serial.print("Sample RAW Bits: ");
  for (int i = 0; i < 40; i++) {
    Serial.print((int)data[i]);
    if (i > 0 && ((i + 1) % 4) == 0) {
      Serial.print(' ');
    }
  }
  Serial.println("");
  
  Serial.print("Sample OK: ");
  Serial.print((int)temp); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" %");
  
  // DHT11 sampling rate is 1HZ.
  delay(1000);
  
}

