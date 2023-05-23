#include<LiquidCrystal.h>
#include<string.h>

LiquidCrystal lcd(13,12,11,10,9,8);
int dem=0;
void DemPhimBam()
{
  dem++;
  String s=String(dem);
  PrintLCD(10,1,s);
}

void setup() {
  lcd.begin(16,2);
  lcd.print("Xin chao cac ban");
  attachInterrupt(0,DemPhimBam,FALLING);

}

void loop() {
  // put your main code here, to run repeatedly:

}
void PrintLCD(char x, char y, String s)
{
  lcd.setCursor(x,y);
  lcd.print(s);

}
