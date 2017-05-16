#include <IRremote.h>
#include <IRremoteInt.h>

/**
The lcd monitor:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 
The IR:
 * G-R -> GND - 5V
 * Y -> 4
*/


#include <LiquidCrystal.h>


#define POWER 0xFFA25D
#define FUNC 0xFFE21D
#define VOLPLUS 0xFF629D
#define FASTFORWARD 0xFF22DD
#define PAUSE 0xFF02FD
#define FASTBACK 0xFFC23D
#define DOWN 0xFFE01F
#define VOLMINUS 0xFFA857
#define UP 0xFF906F
#define EQ 0xFF9867
#define ST 0xFFB04F
#define N0 0xFF6897
#define N1 0xFF30CF
#define N2 0xFF18E7
#define N3 0xFF7A85
#define N4 0xFF10EF
#define N5 0xFF38C7
#define N6 0xFF5AA5
#define N7 0xFF42BD
#define N8 0xFF4AB5
#define N9 0xFF52AD



 
//number of the connected pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
 
//initializing the IRrec
const int IRRecPin = 5; 
IRrecv irrecv(IRRecPin);  //receiver
decode_results results;   //decoder
 
void setup() {
  Serial.begin(9600);
  Serial.println("TestLine");
  
  //initializes qith col x row
  lcd.begin(16, 2);
  lcd.print("_");

  irrecv.enableIRIn();
}


long firstPressTime = 0;
const int TIME_LIMIT = 1000;

int cursorX = 0;
int cursorY = 0;

boolean moveCursor = false;
boolean changed = false;
unsigned long keyPressed = 0;
int nTimes = 0;
String lastLetter = "_";
 
void loop() {
  
    
  if (millis() < firstPressTime + TIME_LIMIT && millis() > TIME_LIMIT) {
    moveCursor = true;
    //storing first time I pressed a certain key
    if (irrecv.decode(&results)) {
      firstPressTime = millis();
      if(results.value == keyPressed) nTimes++;
      changed = true;
      
      Serial.println("key pressed again");
      Serial.print("entered here with time = "); Serial.println(millis());
      
      irrecv.resume();
    } 
    
    
  
  } else {
    if (moveCursor) {
      cursorX++;
      keyPressed = UP;
      moveCursor = false;
      changed = true;
      
      Serial.println("signal need to move cursor");
      
    }
    
    if (irrecv.decode(&results)) {
      if (isValid(results.value)) {
        if (results.value != FASTBACK) {
          firstPressTime = millis();
          keyPressed = results.value;
          nTimes = 0;
          changed = true;
        } else {
          if (cursorX>0) {
            cursorX--;
            keyPressed = UP;
            changed = true;
          }
        }
      }
      
      
      irrecv.resume();
    } 
    
  }
  
  if (changed) {
    lcd.setCursor(cursorX, cursorY);
    lastLetter = decodeKeys(keyPressed, nTimes);
    lcd.print(lastLetter);
    
    Serial.println("detected change, printing it...");
    
    changed = false;
  }
  
}


boolean isValid(unsigned long val) {
  return (
    val == N1 ||
    val == N2 ||
    val == N3 ||
    val == N4 ||
    val == N5 ||
    val == N6 ||
    val == N7 ||
    val == N8 ||
    val == N9 ||
    val == N0 ||
    val == UP ||
    val == FASTBACK
  );
}

String decodeKeys(unsigned long k, int n) {
  switch(k) {
    case N1:
      n = n%3;
      switch(n) {
        case 0: return "."; break;
        case 1: return "?"; break;
        case 2: return "!"; break;
      }
      break;
    case N2:
      n = n%3;
      switch(n) {
        case 0: return "A"; break;
        case 1: return "B"; break;
        case 2: return "C"; break;
      }
      break;
    case N3:
      n = n%3;
      switch(n) {
        case 0: return "D"; break;
        case 1: return "E"; break;
        case 2: return "F"; break;
      }
      break;
    case N4:
      n = n%3;
      switch(n) {
        case 0: return "G"; break;
        case 1: return "H"; break;
        case 2: return "I"; break;
      }
      break;
    case N5:
      n = n%3;
      switch(n) {
        case 0: return "J"; break;
        case 1: return "K"; break;
        case 2: return "L"; break;
      }
      break;
    case N6:
      n = n%3;
      switch(n) {
        case 0: return "M"; break;
        case 1: return "N"; break;
        case 2: return "O"; break;
      }
      break;
    case N7:
      n = n%4;
      switch(n) {
        case 0: return "P"; break;
        case 1: return "Q"; break;
        case 2: return "R"; break;
        case 3: return "S"; break;
      }
      break;
    case N8:
      n = n%3;
      switch(n) {
        case 0: return "T"; break;
        case 1: return "U"; break;
        case 2: return "V"; break;
      }
      break;
    case N9:
      n = n%4;
      switch(n) {
        case 0: return "W"; break;
        case 1: return "X"; break;
        case 2: return "Y"; break;
        case 3: return "Z"; break;
      }
      break;
    case N0:
      return " ";
      break;
    case UP:
      return "_";
      break;
  }
}





/*
void translateIR() {
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,0);
  switch(results.value) {
    case 0xFFA25D: lcd.print("POWER"); break;
    case 0xFFE21D: lcd.print("FUNC/STOP"); break;
    case 0xFF629D: lcd.print("VOL+"); break;
    case 0xFF22DD: lcd.print("FAST BACK");    break;
    case 0xFF02FD: lcd.print("PAUSE");    break;
    case 0xFFC23D: lcd.print("FAST FORWARD");   break;
    case 0xFFE01F: lcd.print("DOWN");    break;
    case 0xFFA857: lcd.print("VOL-");    break;
    case 0xFF906F: lcd.print("UP");    break;
    case 0xFF9867: lcd.print("EQ");    break;
    case 0xFFB04F: lcd.print("ST/REPT");    break;
    case 0xFF6897: lcd.print("0");    break;
    case 0xFF30CF: lcd.print("1");    break;
    case 0xFF18E7: lcd.print("2");    break;
    case 0xFF7A85: lcd.print("3");    break;
    case 0xFF10EF: lcd.print("4");    break;
    case 0xFF38C7: lcd.print("5");    break;
    case 0xFF5AA5: lcd.print("6");    break;
    case 0xFF42BD: lcd.print("7");    break;
    case 0xFF4AB5: lcd.print("8");    break;
    case 0xFF52AD: lcd.print("9");    break;
    default: lcd.print(" other button   ");
  }

  delay(500);
}
 */
