int buzzer = 5 ;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
tone(buzzer,400);
delay(500);
noTone(buzzer);
delay(500);

}
