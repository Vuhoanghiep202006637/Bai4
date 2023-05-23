#include <MsTimer2.h>
#include <TimerOne.h>
int NumberOfLed[4]={5,4,7,9};
int Led =0;
int PortValue[10]={63,6,91,79,102,109,125,7,127,111};

void setup() {
  DDRB=15;
  PORTB=15;
  DDRD=255;
  PORTD=0;
  Timer1.initialize(500000);
  Timer1.attachInterrupt(DisplayLed);

  //MsTimer2::set(10,DisplayLed);
  //MsTimer2::start();
}

void loop() {
}
void DisplayLed()
{
  PORTB=15;
  PORTD=0;
  delayMicroseconds(1);
  PORTB=((1<<Led)^15);
  PORTD=(PortValue[NumberOfLed[Led]]);
  if(Led<3)
  {
    Led++;
  }
  else
  {
    Led=0;
  }
}