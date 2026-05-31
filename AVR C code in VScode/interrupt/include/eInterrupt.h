#ifndef _eInterrupt_H_
#define _eInterrupt_H_

#include "akareza.h"
void eINT0_Init(bool initstatus);
void eINT1_Init(bool initstatus);
//void eINT1_deInit(void); اولین روش تعریف داینیت
void pcINT0_Init(bool initstatus);  // چرا اینو pcint5 ننوشت؟

#endif