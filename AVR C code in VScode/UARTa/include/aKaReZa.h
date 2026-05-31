#ifndef _akareza_H_
#define _akareza_H_

#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include<stdio.h>
#include<stdbool.h>
#include"USART.h"
#include"alcd.h"

#define Bitset(Reg, Bit)    (Reg |= (1<<Bit))
#define Bitclear(Reg, Bit)  (Reg &= ~(1<<Bit))
#define Bittoggle(Reg, Bit)  (Reg ^= (1<<Bit))
#define Bitchcke(Reg, Bit)  ((Reg>>Bit) & 0x01)
#define Bitchange(Reg, Bit, value) (value == 1 ?  Bitset(Reg, Bit): Bitclear(Reg, Bit))

#define GPIO_config_output(Reg,Bit)   Bitset(Reg,Bit)
#define GPIO_config_iutput(Reg,Bit)   Bitclear(Reg,Bit)


#define GlobalInt_enabel     Bitset(SREG, SREG_I);
#define GlobalInt_disabel    Bitclear(SREG, SREG_I);
#define intflag_clear(Reg,Bit)   Bitset(Reg,Bit)
#define initialize  true
#define deinitialize  false


#endif