#include <mega32.h>
#include <alcd.h>
#include <delay.h>
#include <stdio.h>

unsigned char c[16];
unsigned char key=20;


void keyboard(void)
{
PORTD.4=0;
delay_ms(2);
if(PIND.0==0) key=7;
if(PIND.1==0) key=4;
if(PIND.2==0) key=1;
if(PIND.3==0) lcd_clear();
PORTD.4=1;

PORTD.5=0;
delay_ms(2);
if(PIND.0==0) key=8;
if(PIND.1==0) key=5;
if(PIND.2==0) key=2;
if(PIND.3==0) key=0;
PORTD.5=1;

PORTD.6=0;
delay_ms(2);
if(PIND.0==0) key=9;
if(PIND.1==0) key=6;
if(PIND.2==0) key=3;
if(PIND.3==0) {lcd_putchar('=');  delay_ms(300);}
PORTD.6=1;

PORTD.7=0;
delay_ms(2);
if(PIND.0==0) {lcd_putchar('/');  delay_ms(300);}
if(PIND.1==0) {lcd_putchar('*');  delay_ms(300);}
if(PIND.2==0) {lcd_putchar('-');  delay_ms(300);}
if(PIND.3==0) {lcd_putchar('+');  delay_ms(300);}
PORTD.7=1;
}


interrupt [EXT_INT2] void ext_int2_isr(void)
{
unsigned char i;
#asm("cli");
PORTD=0xFF;
for(i=0;i<5;i++)
keyboard();
PORTD=0x0F;
#asm("sei");
}


void main(void)
{
PORTA=0x00;
DDRA=0x00;

PORTB=0x00;
DDRB=0x00;

PORTC=0x00;
DDRC=0xF7;

PORTD=0x0F;
DDRD=0xF0;

GICR|=0x20;
MCUCR=0x00;
MCUCSR=0x40;
GIFR=0x20;

lcd_init(16);
lcd_clear();


#asm("sei")

while (1)
      {
      if(key!=20){
      sprintf(c,"%d",key);
      lcd_puts(c);
      delay_ms(300);
      key=20;
      }
}
}

