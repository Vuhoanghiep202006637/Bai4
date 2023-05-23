#include<MsTimer2.h>
#include<LiquidCrystal.h>
#define analogPin A0 

LiquidCrystal lcd(13,12,11,10,9,8);

int Dvalue = 0;
float Avalue;

void setup(){
  lcd.begin(16,2);
  pinMode(analogPin,OUTPUT);
  Serial.println("Doc tin hieu ADC");
  analogReference(EXTERNAL);
  MsTimer2::set(10,doctinhieu);
  MsTimer2::start();
}
void loop(){
}
void doctinhieu(){
  Dvalue=analogRead(analogPin);
  lcd.setCursor(0,0);
  lcd.print("Dvalue:");
  lcd.setCursor(7,0);
  lcd.print(Dvalue);
  Avalue= 10.0 *Dvalue/1023;
  lcd.setCursor(0,1);
  lcd.print("Avalue:");
  lcd.setCursor(7,1);
  lcd.print(Avalue);
}