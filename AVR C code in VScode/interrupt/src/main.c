#include"akareza.h"
// به دلایلی کلا تابع تاخیر رو وارد نکردم درصورتیکه برای اجرای کل برنامه بهش نیاز هست//س
uint16_t counter = 0;
uint8_t delay = 0;


int main(void)
{
 GPIO_init();
 seg7_init();
 eINT0_Init(initialize);
 eINT1_Init(initialize);
 pcINT0_Init(initialize);

GlobalInt_enabel;


 while (1)
 {
    delay++;
    if(delay > 250)
    { 
    delay = 0;
    counter++;
    };

    if (counter > 9999) counter = 0;

        seg7_puts(counter);
  };
};