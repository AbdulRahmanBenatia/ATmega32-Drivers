#pragma once
#include "../7SEG/SEG7_int.h"

typedef struct
{
    /* data */

    // a -> g
    DIO_tenuPorts enuPorts4[4]; 
    DIO_tenuPins enuPins4[4];

}SEG_strPortsPinsFourDig;

SEG_tenuErrorStatus SEG_enuFourDigitCounterUpZeroTo9999(SEG_strPortsPins* Copy_pstrSegPortsPins,SEG_strPortsPinsFourDig* Copy_pstrPortsD1_D2_D3_D4);
SEG_tenuErrorStatus SEG_enuStopWatch(SEG_strPortsPins* Copy_pstrSegPortsPins,SEG_strPortsPinsFourDig* Copy_pstrPortsD1_D2_D3_D4);
SEG_tenuErrorStatus SEG_enuTimer(SEG_strPortsPins* Copy_pstrSegPortsPins,SEG_strPortsPinsFourDig* Copy_pstrPortsD1_D2_D3_D4,u8 Copy_u8_startingTime);

SEG_tenuErrorStatus SEG_enuTurnOnDigit(SEG_strPortsPins* Copy_pstrSegPortsPins, SEG_strPortsPinsFourDig* Copy_pstrPortsD1_D2_D3_D4, u8 Copy_u8_digitNum);
SEG_tenuErrorStatus SEG_enuTurnOffDigit(SEG_strPortsPins* Copy_pstrSegPortsPins, SEG_strPortsPinsFourDig* Copy_pstrPortsD1_D2_D3_D4, u8 Copy_u8_digitNum);