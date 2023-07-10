int clockPin = 6;
int latchPin = 5;
int dataPin = 4;

byte leds = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(clockPin,OUTPUT);
pinMode(latchPin,OUTPUT);
pinMode(dataPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
leds = 0;
updateShiftRegister();
delay(500);
for(int i=0 ;i<=8 ;i++)
  {
    bitSet(leds,i);
    updateShiftRegister();
    delay(500);
  }
}

void updateShiftRegister()
{
  digitalWrite(latchPin,HIGH);
  shiftOut(dataPin,clockPin,MSBFIRST,leds);
  digitalWrite(latchPin,LOW);
}
