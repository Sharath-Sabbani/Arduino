#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(1,0); // RX | TX 
int flag ; 
int RELAY = 8; 
void setup() 
{   
 Serial.begin(9600); 
 MyBlue.begin(9600); 
 pinMode(RELAY, OUTPUT); 
 digitalWrite(RELAY,LOW);
 Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 
} 
void loop() 
{ 
 if (MyBlue.available()) {
   flag = Serial.read(); 
 if (flag == '1') 
 { 
   digitalWrite(RELAY, LOW); 
   Serial.println("Bulb On"); 
 } 
 if (flag == '0') 
 { 
   digitalWrite(RELAY, HIGH); 
   Serial.println("Bulb Off"); 
 } 
 }
}  
