#include<SoftwareSerial.h>
int LDR = A0;
int Relay = 9;
void setup(){
  Serial.begin(9600);
  pinMode(LDR,INPUT);
  pinMode(Relay,OUTPUT);
  digitalWrite(Relay,OUTPUT);
}
void loop(){
  int data = digitalRead(LDR);
  Serial.print("LDR digital reading:");
  Serial.println(data);
  delay(1000);
  if(data == 1){
    digitalWrite(Relay,HIGH);
    delay(200);
  }
  if(data == 0){
    digitalWrite(Relay,LOW);
    delay(200);
  }
  
}
