#include <mega32.h>
#include <delay.h>

unsigned char data[4]={0x01,0x03,0x05,0x06};
void display(void)
{
PORTC=data[0];
PORTC.4=1;
delay_ms(5);
PORTC.4=0;

PORTC=data[1];
PORTC.5=1;
delay_ms(5);
PORTC.5=0;

PORTC=data[2];
PORTC.6=1;
delay_ms(5);
PORTC.6=0;

PORTC=data[3];
PORTC.7=1;
delay_ms(5);
PORTC.7=0;
}
void main(void)
{
    DDRC = 0x0F;   // PA0..PA3 ????? (BCD)
    PORTC = 0x00;
    while (1)
    {
     display();  
    }
}