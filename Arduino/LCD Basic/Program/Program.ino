#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.setCursor(0,1);
}

void loop() {
  // put your main code here, to run repeatedly:
  int number = 1;
  switch(number)
  {
  case 1:
  lcd.setCursor(0,0);
  lcd.print("ONE");
  case 2:
  lcd.print("PIECE");
  default :
  lcd.setCursor(5,1);
  lcd.print("PIRATE KING");
}
}
