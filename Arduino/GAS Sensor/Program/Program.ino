#include<SoftwareSerial.h>
int GAS_SENSOR = 8;
int RED = 3 ;
int GREEN = 2;
int BUZZ = 7;
const int Frequency = 500;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(GAS_SENSOR,INPUT);
pinMode(RED,OUTPUT);
pinMode(GREEN,OUTPUT);
pinMode(BUZZ,OUTPUT);
digitalWrite(RED,LOW);
digitalWrite(GREEN,HIGH);
noTone(BUZZ);

}

void loop() {
  // put your main code here, to run repeatedly:
int DATA = analogRead(GAS_SENSOR);
Serial.println(DATA);
delay(1000);
if( DATA > 350) // Analog data is read
  {   
    Serial.println("Found GAS");
    digitalWrite(RED,HIGH);
    digitalWrite(GREEN,LOW);
    tone(BUZZ,1000,Frequency);
   }
else if (DATA < 350)
  { 
    Serial.println("All Clear");
    digitalWrite(RED,LOW);
    digitalWrite(GREEN,HIGH);
    noTone(BUZZ);
  }
}
