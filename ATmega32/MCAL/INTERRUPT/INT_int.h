#pragma once
#include "../DIO/DIO_int.h"
#include "INT_prv.h"

typedef enum{
    INT_enuINT0,
    INT_enuINT1,
    INT_enuINT2,
}INT_tenuInterruptPins;

typedef enum{
    INT_enuFallingEdge,
    INT_enuRisingEdge,
    INT_enuLowLevel,
    INT_enuOnChange,
}INT_tenuTriggerSource;

typedef enum{
	INT_OK,
	INT_NOK,
} INT_tenuErrorStatus;

void INT_vidGlobalEnable();
void INT_vidGlobalDisable();
INT_tenuErrorStatus INT_EXT_enuExternalEnable(INT_tenuInterruptPins Copy_enuIntPin,INT_tenuTriggerSource Copy_enuTrigSrc);
INT_tenuErrorStatus INT_EXT_enuExternalDisable(INT_tenuInterruptPins Copy_enuIntPin);
INT_tenuErrorStatus INT_EXT_enuClearFlag(INT_tenuInterruptPins Copy_enuIntPin);
INT_tenuErrorStatus INT_EXT_setTriggerSource(INT_tenuInterruptPins Copy_enuIntPin,INT_tenuTriggerSource Copy_enuTrigSrc);

//Interrupt
/*
 
#include <avr/interrupt.h>
ISR(INT1_eg)
{
    //implementation
}

global interrupt driver: enable(), disable()

external interrupt: 
    enable(INTpin,sourceType)
    disable(INTpin)
    ISR(INT1)
    ISR(INT2)
    ISR(INT0)

//ISR ::::: ==== :::::
void vector(void)__attribute_((signal,used));
__vector_[somenumber=interrupt index at the vector table (vector number of datasheet - 1)](void)
__attribute__ ((signal,used)) :: telling tool chain to keep it although it thinks it is not used....

search for:     ##      in macros

let ISRs in a cfg file to be adjustable....

search for:  callback function and pointers to functions.

*/