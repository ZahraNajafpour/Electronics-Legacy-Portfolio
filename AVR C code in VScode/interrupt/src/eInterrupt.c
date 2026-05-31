#include"eInterrupt.h"
#include"akareza.h"

extern uint16_t counter;

void eINT0_Init(bool initstatus)
{
    if (initstatus) 
    {
        Bitset(EIMSK, INT0);
        Bitclear(EICRA, ISC00),
        Bitset(EICRA, ISC01); 
    
    }
    else
    {
        Bitclear(EIMSK, INT0);
        Bitclear(EICRA, ISC00),
        Bitclear(EICRA, ISC01);
    };
};

void eINT1_Init(bool initstatus)
{
    if (initstatus)  
    { 
        Bitset(EIMSK, INT1);
        Bitset(EICRA, ISC10),
        Bitset(EICRA, ISC11);
        //Bitset(EIFR, INTF0);
        intflag_clear(EIFR, INTF0);
    }
    else
    {
        Bitclear(EIMSK, INT1);
        Bitclear(EICRA, ISC10),
        Bitclear(EICRA, ISC11);
    };
};


void pcINT0_Init(bool initstatus)
{
    if(initstatus)  
    {
        Bitset(PCICR, PCIE0);
        Bitset(PCMSK1, PCINT5);
    }
     else
    {

        Bitclear(PCICR, PCIE0);
        Bitclear(PCMSK1, PCINT5);  
    };
 
};


ISR(INT0_vect) //sw1
{
    counter += 1000;
    eINT1_Init(deinitialize);
};


ISR(INT1_vect) //sw2
{
    counter += 100;
};

ISR(PCINT0_vect) //sw3
{
    static bool pcINT0_status = false;
    pcINT0_status =! pcINT0_status;
    if(pcINT0_status) counter += 10; 
    eINT1_Init(initialize);
// رفع نرم افزاری خطای افزایش شمارنده با هر فشار کلید در هر دو لبته بالا و پایی رونده
};
