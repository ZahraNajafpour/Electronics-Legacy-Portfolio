#include <mega32.h>
#include <delay.h>
unsigned char data[4]={0x0f,0x0f,0x0f,0x0f};
void display(void)
{
register unsigned char i;
unsigned char select[4]={0x80,0x40,0x20,0x10};
 for(i=0; i<4; i++){
 PORTA=data[i];
 PORTA=PORTA | select[i];
 delay_ms(20);
 PORTA=0x0f;
  }
  }
    
unsigned char keybord(void){
register unsigned char i,j;
unsigned char select[4]={0xf0,0x68,0x58,0x38};
 for(i=0; i<4; i++){
 PORTD=select[i];
 delay_ms(20);
 if((PIND & 0x07)!=0x07) {
  for(j=0; j<3; j++)
  if((PIND & (1<<j))==0)
  return i*3+j+1; 
  delay_ms(2);
 }  
 PORTD=0XF8;
 }
 return 20;
 }
  
void main(void)
{
unsigned char j,key=20;
unsigned int i=0, i1;
DDRD=0XF8;
PORTD=0XF8;

DDRA=0XFF;
PORTA=0X0F;
    
while (1)
{
key=keybord();
if(key==1) key=0;
if((key!=20)&&(key<10)){
i=i*10+key;
key=20;
i1=i;
    for(j=0;j<4;j++)
    {
    data[j]=i1%10;
    i1=i1/10;
    }  
    for(j=0;j<10;j++) display();
    
}    
}
}