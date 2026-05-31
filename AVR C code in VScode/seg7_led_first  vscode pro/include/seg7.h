#ifndef _seg7_H_
#define _seg7_H_

#include"akareza.h"


#define _7seg_A_control PORTC
#define _7seg_A_config  DDRC
#define _7seg_A_Pin     0

#define _7seg_B_control PORTC
#define _7seg_B_config  DDRC
#define _7seg_B_Pin     1

#define _7seg_C_control PORTC
#define _7seg_C_config  DDRC
#define _7seg_C_Pin     2

#define _7seg_D_control PORTC
#define _7seg_D_config  DDRC
#define _7seg_D_Pin     3

#define _7seg_E_control PORTD
#define _7seg_E_config  DDRD
#define _7seg_E_Pin     0

#define _7seg_F_control PORTD
#define _7seg_F_config  DDRD
#define _7seg_F_Pin     1

#define _7seg_G_control PORTD
#define _7seg_G_config  DDRD
#define _7seg_G_Pin     4


#define _7seg_DP_control PORTD
#define _7seg_DP_config  DDRD
#define _7seg_DP_Pin     7


#define _7seg_Digit1_control PORTB
#define _7seg_Digit1_config  DDRB
#define _7seg_Digit1_Pin     0


#define _7seg_Digit2_control PORTB
#define _7seg_Digit2_config  DDRB
#define _7seg_Digit2_Pin     1


#define _7seg_Digit3_control PORTB
#define _7seg_Digit3_config  DDRB
#define _7seg_Digit3_Pin     2


#define _7seg_Digit4_control PORTB
#define _7seg_Digit4_config  DDRB
#define _7seg_Digit4_Pin     4

#define _7seg_refreshdelay  delay_ms(1)



void seg7_puts(uint16_t _7segvalue);

void seg7_init(void);

#endif
