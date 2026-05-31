#include"seg7.h"
#include"akareza.h"

uint8_t segment[4]={0, 0, 0, 0};
uint8_t forLoopcounter= 0;
const uint8_t segments_cc[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};


void seg7_init(void)
{

 GPIO_config_output(_7seg_A_config, _7seg_A_Pin);
 GPIO_config_output(_7seg_B_config, _7seg_B_Pin);
 GPIO_config_output(_7seg_C_config, _7seg_C_Pin);
 GPIO_config_output(_7seg_D_config, _7seg_D_Pin);
 GPIO_config_output(_7seg_E_config, _7seg_E_Pin);
 GPIO_config_output(_7seg_F_config, _7seg_F_Pin);
 GPIO_config_output(_7seg_G_config, _7seg_G_Pin);
 GPIO_config_output(_7seg_DP_config, _7seg_DP_Pin);
 GPIO_config_output(_7seg_Digit1_config, _7seg_Digit1_Pin);
 GPIO_config_output(_7seg_Digit2_config, _7seg_Digit2_Pin);
 GPIO_config_output(_7seg_Digit3_config, _7seg_Digit3_Pin);
 GPIO_config_output(_7seg_Digit4_config, _7seg_Digit4_Pin);

 GPIO_config_output(_7seg_Digit1_control, _7seg_Digit1_Pin);
 GPIO_config_output(_7seg_Digit2_control, _7seg_Digit2_Pin);
 GPIO_config_output(_7seg_Digit3_control, _7seg_Digit3_Pin);
 GPIO_config_output(_7seg_Digit4_control, _7seg_Digit4_Pin);

};


void seg7_puts(uint16_t _7segvalue)
{ 

    uint8_t _digit = 0;
    segment[0] = (_7segvalue/1000);
    segment[1] = ((_7segvalue%1000)/100);
    segment[2] = ((_7segvalue%100)/10);
    segment[3] = (_7segvalue%10);

    for(forLoopcounter=0; forLoopcounter<=3; forLoopcounter++ )
    {
        Bitchange(_7seg_A_control,  _7seg_A_Pin,  Bitchcke(segments_cc[segment[forLoopcounter]], 0));
        Bitchange(_7seg_B_control,  _7seg_B_Pin,  Bitchcke(segments_cc[segment[forLoopcounter]], 1));
        Bitchange(_7seg_C_control,  _7seg_C_Pin,  Bitchcke(segments_cc[segment[forLoopcounter]], 2));
        Bitchange(_7seg_D_control,  _7seg_D_Pin,  Bitchcke(segments_cc[segment[forLoopcounter]], 3));
        Bitchange(_7seg_E_control,  _7seg_E_Pin,  Bitchcke(segments_cc[segment[forLoopcounter]], 4));
        Bitchange(_7seg_F_control,  _7seg_F_Pin,  Bitchcke(segments_cc[segment[forLoopcounter]], 5));
        Bitchange(_7seg_G_control,  _7seg_G_Pin,  Bitchcke(segments_cc[segment[forLoopcounter]], 6));

        _digit = 1 << forLoopcounter;   // 0001   0010  0100   1000  
        Bitchange(_7seg_Digit1_control,_7seg_Digit1_Pin,  Bitchcke(_digit, 0));
        Bitchange(_7seg_Digit2_control,_7seg_Digit2_Pin,  Bitchcke(_digit, 1));
        Bitchange(_7seg_Digit3_control,_7seg_Digit3_Pin,  Bitchcke(_digit, 2));
        Bitchange(_7seg_Digit4_control,_7seg_Digit4_Pin,  Bitchcke(_digit, 3));
          
        _7seg_refreshdelay;

        };

   /*
   
   void seg7_puts(uint16_t _7segvalue)
{ 

        uint8_t _digit = 0;

        segment[0] = (_7segvalue/1000);
        segment[1] = ((_7segvalue%1000)/100);
        segment[2] = ((_7segvalue%100)/10);
        segment[3] = (_7segvalue%10);

        Bitchange(_7seg_A_control,  _7seg_A_Pin,  Bitchcke(segments_cc[segment[forLoopcounter]], 0));
        Bitchange(_7seg_B_control,  _7seg_B_Pin,  Bitchcke(segments_cc[segment[forLoopcounter]], 1));
        Bitchange(_7seg_C_control,  _7seg_C_Pin,  Bitchcke(segments_cc[segment[forLoopcounter]], 2));
        Bitchange(_7seg_D_control,  _7seg_D_Pin,  Bitchcke(segments_cc[segment[forLoopcounter]], 3));
        Bitchange(_7seg_E_control,  _7seg_E_Pin,  Bitchcke(segments_cc[segment[forLoopcounter]], 4));
        Bitchange(_7seg_F_control,  _7seg_F_Pin,  Bitchcke(segments_cc[segment[forLoopcounter]], 5));
        Bitchange(_7seg_G_control,  _7seg_G_Pin,  Bitchcke(segments_cc[segment[forLoopcounter]], 6));

        _digit = 1 << forLoopcounter;   // 0001   0010  0100   1000  
        Bitchange(_7seg_Digit1_control,_7seg_Digit1_Pin,  Bitchcke(_digit, 0));
        Bitchange(_7seg_Digit2_control,_7seg_Digit2_Pin,  Bitchcke(_digit, 1));
        Bitchange(_7seg_Digit3_control,_7seg_Digit3_Pin,  Bitchcke(_digit, 2));
        Bitchange(_7seg_Digit4_control,_7seg_Digit4_Pin,  Bitchcke(_digit, 3));
}   forLoopcounter++;
   if(forLoopcounter == 4)  forLoopcounter=0;  
   */     
};