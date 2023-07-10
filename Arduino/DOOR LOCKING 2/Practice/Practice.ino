#include <Servo.h>
#include <LiquidCrystal.h>
#include <Key.h>
#include <Keypad.h>
#define buzzer A4 
LiquidCrystal lcd(12,11,5,4,3,2);
Servo myServo ;
const byte Rows = 4 ;
const byte Cols = 3 ;
char keys[Rows][Cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
const int rowPins [Rows] = {A0,A1,A2,A3};
const int colPins [Cols] = {6,7,8};
String password = "2431" ;
int position = 0 ;
int wrong = 0 ;
int RED_LED = 13;
int GREEN_LED = 10;
Keypad keypad = Keypad(makeKeymap(keys),Rows,Cols,rowPins,colPins);

int total = 0 ;

void setup() {
  // put your setup code here, to run once:
  
myServo.attach(9);
pinMode(buzzer,OUTPUT);
pinMode(RED_LED,OUTPUT);
pinMode(GREEN_LED,OUTPUT);
lcd.begin(16,2);
lcd.setCursor(1,0);
lcd.print("Door Lock Sys");
lcd.setCursor(1,1);
lcd.print("Welcome");
delay(2000);
lcd.clear();
setLocked(true);
delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.clear();
lcd.setCursor(1,0);
lcd.print("Enter Password");
delay(100);

char pressed = keypad.getKey();
String key[4];

if(pressed){
  lcd.clear();
  lcd.print("Enter Passcode");
  lcd.setCursor(position ,1);
  lcd.print(pressed);
  delay(500);
  if(pressed == '*' || pressed == '#')
    {
      position = 0;
      setLocked(true);
      lcd.clear();
    }
    else if (pressed == password[position])
    {
      key[position] = pressed ;
      position++ ;
    }
    else if (pressed != password[position])
    {
      wrong++ ;
      position ++ ;
    }
    if(position == 3)
    {
      if(wrong > 0)
      {
        total++ ;
        wrong = 0;
        position = 0 ;
        lcd.clear();
        lcd.print("Wrong");
        lcd.setCursor(5,1);
        lcd.print("Passcode");
        delay(1000);
        setLocked(true);                      
      }
      else if (position == 3 && wrong == 0)
      {
        position = 0;
        wrong = 0;
        lcd.clear();
        lcd.print("passcode");
        lcd.setCursor(5,1);
        lcd.print("Accepted");
        delay(2000);
        lcd.clear();
        lcd.print("Door Opening");
        delay(2000);
        setLocked(false);
      }
      if(total == 3)
      {
        total = 0 ;
        buzzer_beep();
        delay(2000);
      }
      }
      
    }
  
}
void setLocked(int locked)// FUNCTION TO CHANGE STATUS OF SERVO MOTOR.
  {
    if (locked)
      {
          digitalWrite(RED_LED, HIGH);
          digitalWrite(GREEN_LED, LOW);
          delay(1000);
          myServo.attach(3);
          myServo.write(10);
          delay(1000);
          myServo.detach();
      }
    else
      {
          digitalWrite(RED_LED, LOW);
          digitalWrite(GREEN_LED, HIGH);
          delay(1000);
          myServo.attach(3);
          myServo.write(90);
          delay(1000);
          myServo.detach();
      }
  }
void buzzer_beep()// FUNCTION TO BEEP THE BUZZER.
{
   tone(buzzer,400);
   delay(1000);
   noTone(buzzer);
   delay(1000);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("THANK YOU");
   while(1)
   {
   lcd.scrollDisplayLeft();
   delay(200);
   }
}
