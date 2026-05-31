#include"i2c.h"

void i2c_Init(void)
{
  Bitset(TWCR,TWEN);         // enable TWI
  Bitclear(TWSR,TWPS0);    
  // set prescaler = 1
  Bitclear(TWSR,TWPS1);
  TWBR = 72;
};

void i2c_Start(void)
{ 
  TWCR = ( 1<<TWINT) | ( 1<<TWEN) | ( 1<<TWSTA) ;
  //BitWateHigh(TWCR,TWINT);           // wait to high TWINT flag
};

void i2c_Stop(void)
{
TWCR = ( 1<<TWINT) | ( 1<<TWEN) | ( 1<<TWSTO) ;
};


void i2c_Write(uint8_t _Data)
{
  TWDR  = _Data;
  TWCR = ( 1<<TWINT) | ( 1<<TWEN) ;
  //BitWateHigh(TWCR,TWINT);           // wait to high TWINT flag
};
  void i2c_WriteAddress(uint8_t _address, uint8_t* _Data, uint16_t _dataLenghth)
  {

  i2c_Start();
  i2c_Write(_address<<1 | __I2C_WriteCmd);
  while (_dataLenghth)
  {
    i2c_Write(* _Data++);
    _dataLenghth--;
  }

   i2c_Stop();
   
  };
