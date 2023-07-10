#include<SoftwareSerial.h>
#include <LiquidCrystal.h>
LiquidCrystal LCD(12,11,5,4,3,2);
int BUZZER = 7;
int LED = 6;
int Module = 13;
int data ;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
LCD.begin(16,2);
pinMode(LED,OUTPUT);
pinMode(BUZZER,OUTPUT);
pinMode(Module,INPUT);
noTone(BUZZER);
digitalWrite(LED,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  data = digitalRead(Module);
  if(data == 0){
  LCD.print("Module Detected");
  delay(1000);
  LCD.clear();
  LCD.print("Value:");
  LCD.print(data);
  LCD.clear();
  delay(1000);
  Serial.println("MODULE DETECTED");
  Serial.print("Value:");
  Serial.println(data);
  delay(1000);
  tone(BUZZER,1000);
  digitalWrite(LED,HIGH);
  }
  if(data == 1){
    LCD.blink();
    LCD.print("Value:");
    LCD.print(data);
    delay(1000);
    LCD.clear();
    Serial.print("Value:");
    Serial.println(data);
    delay(1000);
    digitalWrite(LED,LOW);
    noTone(BUZZER);
  }
}
