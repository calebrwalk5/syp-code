//www.elegoo.com
//2016.12.12

// define the LED digit patterns, from 0 - 9
// 1 = LED on, 0 = LED off, in this order:
//                74HC595 pin     Q0,Q1,Q2,Q3,Q4,Q5,Q6,Q7 
//                Mapping to      a,b,c,d,e,f,g of Seven-Segment LED
byte seven_seg_digits[10] = { B11111100,  // = 0
                              B01100000,  // = 1
                              B11011010,  // = 2
                              B11110010,  // = 3
                              B01100110,  // = 4
                              B10110110,  // = 5
                              B10111110,  // = 6
                              B11100000,  // = 7
                              B11111110,  // = 8
                              B11100110   // = 9
                             };
 
int latchPin = 3;
int clockPin = 4;
int dataPin = 2;
 
void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}
 
void sevenSegWrite(byte digit) {
  digitalWrite(latchPin, LOW);
    
  shiftOut(dataPin, clockPin, LSBFIRST, seven_seg_digits[digit]);  
 
  digitalWrite(latchPin, HIGH);
}
 
void loop() {       
  // count from 9 to 0 on the clock
  for (byte digit = 10; digit > 0; --digit) {
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    delay(1000);
    sevenSegWrite(digit - 1); 
  }
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  delay(3000);
}
