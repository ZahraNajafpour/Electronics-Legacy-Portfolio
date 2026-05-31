#include "aKaReZa.h"
extern uint8_t BufferIndex;
extern bool Usart_RxFlag;
extern bool Usart_errFlag;
extern char Usart_RxBuffer[__Usart_RxBufferSize];

int main (void)
{
 alcd_init();
 alcd_puts("hey");
  usart_Init(initialize);
 GlobalInt_enabel;
 usart_Putsln( "Leila Dooset Daram" );
 while (1)

  {
    if(Usart_RxFlag)
    {
      alcd_clear();
      alcd_puts(Usart_RxBuffer);
      usart_Flush();
    };

    if(Usart_errFlag)
    {
      alcd_clear();
      alcd_puts("Usart_errFlag");
      usart_Flush();
    };


  };
 
};
