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
Keypad custokeypad = Keypad(makeKeymap(hexkey),rowpin,colpin,ROWS,COLS); 
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
}
void loop() {
  // put your main code here, to run repeatedly: int b ;b = a++ ;
  for(int a = 0;a<=10;a++){
   lcd.setCursor(a,0); 
char keyvalue = custokeypad.getKey();
if (keyvalue)
{
  lcd.print(keyvalue);
  
}
  }
} 
