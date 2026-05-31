# ifndef _USART_H_
# define _USART_H_

#include "aKaReZa.h"
#define __Usart_RxBufferSize  33   // 32 byte data + null
#define usart_FrameError     Bitchcke(UCSR0A,FE0)
#define usart_DataOvrRun     Bitchcke(UCSR0A,DOR0)

#define __usart_TX_cinfig  DDRD
#define __usart_TX_control PORTD
#define __usart_TX_pin     1

#define __usart_RX_cinfig  DDRD
#define __usart_RX_control PORTD
#define __usart_RX_pin     0

void usart_Init(bool _initstatus);
void usart_Write(uint8_t _data);
void usart_Puts(char* _data);
void usart_Putsln(char* _data);
uint8_t usart_getchar(void);
void usart_Flush(void);

#endif