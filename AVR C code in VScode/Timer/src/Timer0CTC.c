#include"Timer0.h"
#include"akareza.h"

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

      // compare match reg value set
      OCR0A=249;

      // چون یکبار عمل میکنه میبریمش داخل روتین وقفهTCNT0=6;

    }

    else

    {


    };

};