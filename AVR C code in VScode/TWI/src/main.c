#include "aKaReZa.h"
i2c_txBuffer[] = {0x00,'Z','a','h','r','a'};
int main(void)
{
  usart_Init(initialize);
  usart_Putsln("Hello World");
  i2c_Init();

  //i2c_WriteAddress( 0x50, i2c_txBuffer, sizeof(i2c_txBuffer));

  

  while (1)
  {
    
  }
  


};