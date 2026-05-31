#include"akareza.h"


extern uint16_t counter = 0;
extern uint8_t delay = 0;
void GPIO_init(void)
{
 GPIO_config_iutput(sw1_control,sw1_Pin);
 GPIO_config_iutput(sw2_control,sw2_Pin);
 GPIO_config_iutput(sw3_control,sw3_Pin); 
};

 void soft_Delay(void)
 {
    delay++;
    if(delay > 250)
    { 
    delay = 0;
    counter++;

    };

 };