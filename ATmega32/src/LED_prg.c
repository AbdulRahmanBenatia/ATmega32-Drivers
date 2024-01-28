#include "../HAL/LED/LED_int.h"
#include <util/delay.h>


/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
LED_tenuErrorStatus LED_enuTurnOn(DIO_tenuPorts Copy_enuPortNum , DIO_tenuPins Copy_enuPinNum)
{
    LED_tenuErrorStatus Local_errorStatus = LED_OK;
    if(Copy_enuPortNum>DIO_enuPORTD || Copy_enuPinNum >DIO_enuPIN7)
    {
        Local_errorStatus=LED_NOK;
    }
    else 
    {
        DIO_enuSetPinDirection(Copy_enuPortNum,Copy_enuPinNum,DIO_u8_OUTPUT);
        DIO_enuSetOutputPinValue(Copy_enuPortNum,Copy_enuPinNum,1);
    }

    return Local_errorStatus;
}

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
LED_tenuErrorStatus LED_enuTurnOff(DIO_tenuPorts Copy_enuPortNum , DIO_tenuPins Copy_enuPinNum)
{
    LED_tenuErrorStatus Local_errorStatus = LED_OK;
    if(Copy_enuPortNum>DIO_enuPORTD || Copy_enuPinNum >DIO_enuPIN7)
    {
        Local_errorStatus=LED_NOK;
    }
    else 
    {
        DIO_enuSetPinDirection(Copy_enuPortNum,Copy_enuPinNum,DIO_u8_OUTPUT);
        DIO_enuSetOutputPinValue(Copy_enuPortNum,Copy_enuPinNum,0);
    }

    return Local_errorStatus;
}

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
LED_tenuErrorStatus LED_enuToggle(DIO_tenuPorts Copy_enuPortNum , DIO_tenuPins Copy_enuPinNum)
{
    {
    LED_tenuErrorStatus Local_errorStatus = LED_OK;
    if(Copy_enuPortNum>DIO_enuPORTD || Copy_enuPinNum >DIO_enuPIN7)
    {
        Local_errorStatus=LED_NOK;
    }
    else 
    {
        DIO_enuSetPinDirection(Copy_enuPortNum,Copy_enuPinNum,DIO_u8_OUTPUT);
        // DIO_enuSetOutputPinValue(Copy_enuPortNum,Copy_enuPinNum,1);
        DIO_enuToggleOutputPinValue(Copy_enuPortNum,Copy_enuPinNum);
    }

    return Local_errorStatus;
}
}

/* Name:
 * Description:
 * I/P arguments: howManyTimes? (one count = on&off)
 * Return: OK or NOK
 */
LED_tenuErrorStatus LED_enuBlink(DIO_tenuPorts Copy_enuPortNum , DIO_tenuPins Copy_enuPinNum,
                                     u8 Copy_u8_timeInMilliSecond, u8 Copy_u8_howManyTimes)
{
    {
    {
    LED_tenuErrorStatus Local_errorStatus = LED_OK;
    if(Copy_enuPortNum>DIO_enuPORTD || Copy_enuPinNum >DIO_enuPIN7)
    {
        Local_errorStatus=LED_NOK;
    }
    else 
    {
        DIO_enuSetPinDirection(Copy_enuPortNum,Copy_enuPinNum,DIO_u8_OUTPUT);
        for(u8 i = 0 ; i <Copy_u8_howManyTimes ; i ++)
        {
            // DIO_enuSetOutputPinValue(Copy_enuPortNum,Copy_enuPinNum,1);
            LED_enuTurnOn(Copy_enuPortNum,Copy_enuPinNum);
            _delay_ms(Copy_u8_timeInMilliSecond);
            // DIO_enuSetOutputPinValue(Copy_enuPortNum,Copy_enuPinNum,0);
            LED_enuTurnOff(Copy_enuPortNum,Copy_enuPinNum);

            _delay_ms(Copy_u8_timeInMilliSecond);        
        }
        
    }

    return Local_errorStatus;
}
}
}