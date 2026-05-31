#ifndef _akareza_H_
#define _akareza_H_

#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include<stdio.h>
#include<stdbool.h>
#include"seg7.h"
#include"Timer0.h"

#define Bitset(Reg, Bit)    (Reg |= 1<<Bit)
#define Bitclear(Reg, Bit)  (Reg &= ~(1<<Bit))
#define Bittoggle(Reg, Bit)  (Reg ^= 1<<Bit)
#define Bitchcke(Reg, Bit)  ((Reg>>Bit) & 0x01)
#define Bitchange(Reg, Bit, value) (value == 1 ?  Bitset(Reg, Bit): Bitclear(Reg, Bit))

#define GPIO_config_output(Reg,Bit)   Bitset(Reg,Bit)
#define GPIO_config_iutput(Reg,Bit)   Bitclear(Reg,Bit)

#define sw1_control  DDRD
#define sw1_status   PIND
#define sw1_Pin      2
#define sw1_ispressed  Bitchcke(sw1_status ,sw1_Pin )

#define sw2_control  DDRD
#define sw2_status   PIND
#define sw2_Pin      3
#define sw2_ispressed  Bitchcke(sw2_status ,sw2_Pin )

#define sw3_control  DDRB
#define sw3_status   PINB
#define sw3_Pin      2
#define sw3_ispressed  Bitchcke(sw3_status ,sw3_Pin )
#define GlobalInt_enabel     Bitset(SREG, SREG_I);
#define GlobalInt_disabel    Bitclear(SREG, SREG_I);
#define initialize  true
#define deinitialize  false

void GPIO_init(void);
void soft_Delay(void);

#endif