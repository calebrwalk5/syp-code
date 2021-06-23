byte leds = 0;
 
void setup() 
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);  
  pinMode(7, OUTPUT);

  Serial.begin(9600);
}
 
void loop() 
{
  leds = 0;
  updateShiftRegister();
  delay(1000);
  for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    updateShiftRegister();

    for (int i = 7; i >= 0; i--)
    {
        bool b = bitRead(leds, i);
        Serial.print(b);
    }
    
    delay(1000);
    Serial.println(" ");
  }
}
 
void updateShiftRegister()
{
   digitalWrite(5, LOW);
   shiftOut(6, 7, LSBFIRST, leds);
   digitalWrite(5, HIGH);
}
