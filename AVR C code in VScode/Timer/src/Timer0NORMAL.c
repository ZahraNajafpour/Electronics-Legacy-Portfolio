#include"Timer0.h"
#include"akareza.h"

ISR(Timer0_ovf_vect)
{
 // دیگه نمیخواست ایین تاگل اتفاق بیفتهBittoggle(PORTB,5);
  TCNT0=6;
};


void Timer0_Init(bool  _initstatus)
{
    if(_initstatus)
    {
      //mode normal
      Bitclear(TCCR0A,WGM00);
      Bitclear(TCCR0A,WGM01);
      Bitclear(TCCR0B,WGM02);
      // toggle mode for compare match
      Bitset(TCCR0A,COM0A0);
      Bitclear(TCCR0A,COM0A1);
      GPIO_config_output(DDRD,6);
      // prescaler
      Bitset(TCCR0B,CS00);
      Bitset(TCCR0B,CS01);
      Bitclear(TCCR0B,CS02);
      // int for timer normal
      Bitset(TIMSK0,TOIE0);
      GlobalInt_enabel;
      // compare match reg value set

      OCR0A=0xFF;

      // چون یکبار عمل میکنه میبریمش داخل روتین وقفهTCNT0=6;

    }

    else

    {


    };

};