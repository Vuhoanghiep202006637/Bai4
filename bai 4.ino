#include<LiquidCrystal.h>
#include<String.h>

LiquidCrystal lcd(13,12,11,10,9,8);
int dem =0;
int demsanpham=0;

const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;

void demphimbam(){
  dem++;
  String s = String(dem);
  //PrintLCD(10,1);
  lcd.setCursor(10,1);
}
void setup() {
  lcd.begin(16,2); 
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
  
}

void loop() {
  
  //digitalWrite(ledPin, state);
  lcd.setCursor(0,0);
  lcd.print("Bo dem san pham");
  lcd.setCursor(0,1);
  lcd.print("So chai : ");
  lcd.setCursor(10,1);
  lcd.print(demsanpham);

}

void blink() {
  state =! state;
  demsanpham++;
}
