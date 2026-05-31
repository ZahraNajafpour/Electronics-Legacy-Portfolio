#include"akareza.h"

extern uint16_t counter;
extern uint8_t delay;
void GPIO_init(void)
{
 GPIO_config_iutput(sw1_control,sw1_Pin);
 GPIO_config_iutput(sw2_control,sw2_Pin);
 GPIO_config_iutput(sw3_control,sw3_Pin); 
};
