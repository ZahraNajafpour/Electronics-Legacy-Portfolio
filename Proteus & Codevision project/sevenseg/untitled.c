#include <mega32.h>
#include <delay.h>

unsigned char i = 0;

void main(void)
{
    DDRC = 0x0F;   // PA0..PA3 ????? (BCD)
    PORTC = 0x00;
    while (1)
    {
        for ( i = 0; i <= 9; i++)
        {
            PORTC = (PORTC & 0xF0) | i;  // ????? BCD
            delay_ms(500);
        }
    }
}
