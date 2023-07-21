#include <Key.h>
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
const byte ROWS = 4 ;
const byte COLS = 4 ;
char hexkey [ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowpin[ROWS] = {A0,A1,A2,A3};
byte colpin[COLS] = {6,7,8,9};

const int led = 13;
const int motor = A4;
char code[4];
int keycount = 0;
Keypad custokeypad = Keypad(makeKeymap(hexkey),rowpin,colpin,ROWS,COLS); 
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(motor,OUTPUT);
  lcd.begin(16,2);
  lcd.print("password based assess:");
  lcd.autoscroll();
  delay(5000);
  lcd.clear();
  //lcd.setCursor(0,1);
  digitalWrite(led,LOW);
  digitalWrite(motor,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
char keyvalue = custokeypad.getKey();
if (keyvalue && (keycount <= 4) && (keyvalue != '*') && (keyvalue != '#'))
{
  lcd.setCursor(0,0);
  lcd.print(keyvalue);
 code[keycount] = keyvalue ;
 keycount++ ; 
}
/*if((keyvalue == '#') && (keyvalue != '*')) {
  lcd.setCursor(0,0);
  lcd.print("enter pass");*/
if( (code[0] == '0') && (code[1] == '0') && (code[2] == '0') && (code[3] == '5') )
  {
    digitalWrite(led,HIGH);
    digitalWrite(motor,HIGH);
    lcd.setCursor(0,0); 
    lcd.print("Opening");
    delay(7000);
    Lock ();
  }
  else
  {
   lcd.setCursor(0,0);
    lcd.print("INCORRECT PASSWORD");
    //delay(2000);
    Lock ();
  }
 
 
if ((keyvalue == '*') && (keyvalue != '#') )
{
  Lock ();
}
}

 void Lock ()
  {
    lcd.setCursor(0,0);
    lcd.print("Door Locked");
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print("         ");
    lcd.setCursor(0,0);
    keycount = 0 ;
    digitalWrite(led,LOW);
    digitalWrite(motor,LOW);
  }
