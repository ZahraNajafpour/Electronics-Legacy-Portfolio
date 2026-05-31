#include"Timer0.h"
#include"akareza.h"


ISR(TIMER0_COMPA_vect)
{
  static uint16_t timcont=0;
  timcont++;
  if(timcont == 1000)
  {
  Bittoggle(PORTB,5);
  timcont = 0;

  };
};
void Timer0_Init(bool  _initstatus)
{
    if(_initstatus)
    {
      //mode CTC
      Bitclear(TCCR0A,WGM00);
      Bitset(TCCR0A,WGM01);
      Bitclear(TCCR0B,WGM02);
      // OC0A toggle mode for compare match
      Bitset(TCCR0A,COM0A0);
      Bitclear(TCCR0A,COM0A1);
      GPIO_config_output(DDRD,6);
      // prescaler
      Bitset(TCCR0B,CS00);
      Bitset(TCCR0B,CS01);
      Bitclear(TCCR0B,CS02);

      //  active CTC int
      Bitset(TIMSK0,OCIE0A);
      GlobalInt_enabel;

      GPIO_config_output(DDRB,5);
      // compare match reg value set
      OCR0A=249;
      intflag_clear(TIFR0,OCF0A);  
      // چون یکبار عمل میکنه میبریمش داخل روتین وقفهTCNT0=6;

    }

    else

    {

      //mode CTC
      Bitclear(TCCR0A,WGM00);
      Bitclear(TCCR0A,WGM01);
      Bitclear(TCCR0B,WGM02);
      // OC0A toggle mode for compare match
      Bitclear(TCCR0A,COM0A0);
      Bitclear(TCCR0A,COM0A1);
      GPIO_config_iutput(DDRD,6);
      // prescaler
      Bitclear(TCCR0B,CS00);
      Bitclear(TCCR0B,CS01);
      Bitclear(TCCR0B,CS02);

      //  active CTC int
      Bitclear(TIMSK0,OCIE0A);
      // compare match reg value set
      OCR0A=0;

    };

};