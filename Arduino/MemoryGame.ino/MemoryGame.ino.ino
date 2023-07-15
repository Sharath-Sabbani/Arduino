#include<stdlib.h>
#define noConnection A0
int SWITCH=0;
int load=10;
const int ledValue[5];

void setup() {
  // put your setup code here, to run once:
  pinMode(load,INPUT);
  pinMode(noConnection,INPUT);
  pinMode(SWITCH,INPUT);
  digitalWrite(SWITCH,LOW); 
  for(int i=1;i<=9;i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int rand[5];
  if(digitalRead(SWITCH)==1){
    for(int i=0;i<4;i++){
      rand[i] = random(1,9);
      randomSeed(analogRead(noConnection));
      if(rand[i]){
        digitalWrite(rand[i],HIGH);    
        delay(250);    
        digitalWrite(rand[i],LOW);        
        delay(250);
      }      
    }
    delay(500);
    for(int j=0;j<4;j++){
      ledValue[i]=rand[i];
    }
  }
}
