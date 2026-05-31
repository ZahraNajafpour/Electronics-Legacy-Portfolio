#include"Timer0.h"
#include"akareza.h"
extern uint16_t counter;

ISR(TIMER0_OVF_vect)
{
  static uint16_t timecount = 0;
  seg7_puts(counter);
  timecount++;
  if (timecount == 977)
  {
    
   counter++;
   timecount = 0;
   if (counter > 9999) counter = 0;

  };
  
};
void Timer0_Init(bool  _initstatus)
{
    if(_initstatus)
    {
      //mode Normal
      /*
      Bitset(TCCR0B,CS00);
      Bitset(TCCR0B,CS01);
      Bitclear(TCCR0B,CS02);
      در این کدونویسی روی پری اسکالر برابر 1.024 میلی ثانیه وقفه رخ میدهد 
      که اگر بخواهیم همین 1.024 میلی ثانیه وقفه رخ بده کد seg7_puts رو باید تغییراتی اعمال کنیم 
      که در کد خودش بصورت کامنت نوشتم
      */
     // for prescaler = 256 and t= 4.096
      Bitclear(TCCR0A,WGM00);
      Bitclear(TCCR0A,WGM01);
      Bitset(TCCR0B,WGM02);
      // prescaler
      Bitset(TCCR0B,CS00);
      Bitset(TCCR0B,CS01);
      Bitclear(TCCR0B,CS02);

      // active normal int
      Bitset(TIMSK0,TOIE0);
      GPIO_config_output(DDRB,5);
    }

    else

    {

      Bitclear(TCCR0A,WGM00);
      Bitclear(TCCR0A,WGM01);
      Bitclear(TCCR0B,WGM02);
      Bitclear(TCCR0B,CS00);
      Bitclear(TCCR0B,CS01);
      Bitclear(TCCR0B,CS02);
      Bitclear(TIMSK0,TOIE0);

    };

};