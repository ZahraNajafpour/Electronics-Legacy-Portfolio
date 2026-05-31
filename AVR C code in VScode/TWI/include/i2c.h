#ifndef _i2c_H_
#define _i2c_H_

#include"aKaReZa.h"

#define __I2C_WriteCmd 0x00
#define __I2C_ReadCmd 0x01

void i2c_Init(void);
void i2c_Start(void);
void i2c_Stop(void);
void i2c_Write(uint8_t _Data);
void i2c_WriteAddress(uint8_t _address, uint8_t* _Data, uint16_t _dataLenghth);

#endif