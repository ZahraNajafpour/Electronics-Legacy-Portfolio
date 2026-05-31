#ifndef _aKaReZa_H_
#define _aKaReZa_H_

#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include<stdio.h>
#include<stdbool.h>


#define Bitset(_Reg, _Bit)    (_Reg |= (1<<_Bit))
#define Bitclear(_Reg, _Bit)  (_Reg &= ~(1<<_Bit))
#define Bittoggle(_Reg, _Bit)  (_Reg ^= (1<<_Bit))
#define Bitchcke(_Reg, _Bit)  ((_Reg>>_Bit) & 0x01)
#define Bitchange(_Reg, _Bit, _value) (_value == 1 ?  Bitset(_Reg, _Bit): Bitclear(_Reg, _Bit))

#define GPIO_config_output(_Reg,_Bit)   Bitset(_Reg,_Bit)
#define GPIO_config_iutput(_Reg,_Bit)   Bitclear(_Reg,_Bit)



#endif