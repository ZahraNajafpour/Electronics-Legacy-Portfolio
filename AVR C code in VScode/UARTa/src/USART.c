#include"USART.h"

uint8_t BufferIndex = 0;
char Usart_RxBuffer[__Usart_RxBufferSize];
volatile bool Usart_RxFlag = false;
bool Usart_RxBufferOV = false;
bool Usart_errFlag = false;
void usart_Init(bool _initstatus)
{
    if(_initstatus)
    {
        Bitset(__usart_TX_cinfig,__usart_TX_pin);    // TX pin as output
        Bitset(__usart_TX_control,__usart_TX_pin);   // tx level >> high

        Bitclear(__usart_RX_cinfig,__usart_RX_pin);    // RX pin as output
        Bitset(__usart_RX_control,__usart_RX_pin);    // RX set to pull_up 

            // mode asyncron  
        Bitclear(UCSR0C,UMSEL00);   
        Bitclear(UCSR0C,UMSEL01);   
            // disable parity bit
        Bitclear(UCSR0C,UPM01);
        Bitclear(UCSR0C,UPM00); 

        Bitclear(UCSR0C,USBS0);    // one stopbit

        // 8 bit fram data
        Bitclear(UCSR0B,UCSZ02);  
        Bitset(UCSR0C,UCSZ00);     
        Bitset(UCSR0C,UCSZ01); 

        Bitset(UCSR0B,TXEN0);    // Enable Transmision mode
        Bitset(UCSR0B,RXEN0);    // Enable Recieve mode
        Bitset(UCSR0A,U2X0);     // enable double mode

        Bitset(UCSR0B,RXCIE0);   // enable RX compelet interrupt

        // buadrate
        UBRR0H = 0;
        //UBRR0L = 8;  for normal mode
        UBRR0L = 16;
        usart_Flush();
    }
    else
    {
        Bitclear(__usart_TX_cinfig,__usart_TX_pin);    // TX pin as output
        Bitclear(__usart_TX_control,__usart_TX_pin);   // tx level >> high
        Bitclear(__usart_RX_cinfig,__usart_RX_pin);    // RX pin as output
        Bitclear(__usart_RX_control,__usart_RX_pin);    // RX set to pull_up  
        Bitclear(UCSR0C,UMSEL00);   
        Bitclear(UCSR0C,UMSEL01);  
        Bitclear(UCSR0C,UPM01);
        Bitclear(UCSR0C,UPM00); 
        Bitclear(UCSR0C,USBS0);   
        Bitclear(UCSR0B,UCSZ02);  
        Bitclear(UCSR0C,UCSZ00);     
        Bitclear(UCSR0C,UCSZ01); 
        Bitclear(UCSR0B,TXEN0);    
        Bitclear(UCSR0B,RXEN0);   
        Bitclear(UCSR0A,U2X0);     
        Bitclear(UCSR0B,RXCIE0); 
        UBRR0H = 0;
        UBRR0L = 0;
        
    };


};

ISR(USART_RX_vect)
{
   uint8_t _RXData;
   Usart_errFlag = false;
   ///محل خواندن خطاهای فریم و اوررایت و پریتی
   Usart_errFlag  = Usart_RxBufferOV | usart_FrameError | usart_DataOvrRun;
   _RXData = UDR0;
   if(!Usart_errFlag)
   {
        if(_RXData == '\n')
        {
            Usart_RxBuffer[BufferIndex] = '\0';
            Usart_RxFlag = true;
        }
        else

        {
            if(_RXData != '\r')
            {
            Usart_RxBuffer[BufferIndex] = _RXData;
            BufferIndex++;
            if(BufferIndex>__Usart_RxBufferSize) Usart_RxBufferOV = true;
            }
        }
    }

};

void usart_Flush(void)
{
  uint8_t _index;
  for(_index = 0 ; _index <__Usart_RxBufferSize ; _index++)
  {
    Usart_RxBuffer[_index] = '\0';
  };
   BufferIndex = 0;
   Usart_RxFlag = false;
   Usart_RxBufferOV = false;
   Usart_errFlag = false;
};


void usart_Write(uint8_t _data)
{
    while (!Bitchcke(UCSR0A, UDRE0));
    UDR0 = _data;
    while (!Bitchcke(UCSR0A, TXC0));
    
};

void usart_Puts(char* _data)
{
    while (*_data != '\0')  usart_Write(*_data++);
};

void usart_Putsln(char* _data)
{
    usart_Puts( _data);
    usart_Write('\r');
    usart_Write('\n');
};

uint8_t usart_getchar(void)
{
    while (!Bitchcke(UCSR0A,RXC0));
    return UDR0;
    
};

