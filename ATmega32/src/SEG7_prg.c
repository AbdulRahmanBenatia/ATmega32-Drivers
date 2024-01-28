#include "../HAL/7SEG/SEG7_int.h"
#include "../HAL/7SEG/SEG7_prv.h"

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */

u8 SEG_u8_currentValue = 0;

SEG_tenuErrorStatus SEG_enuViewNumber(SEG_strPortsPins * Copy_pstrSegPortsPins , u8 Copy_u8_NumToView)
{
    SEG_tenuErrorStatus Local_enuErrorStat = SEG_OK;
    u8 Local_u8_valueCarrier = 0;
    //validation....

    //set these pins as output
    for (u8 i = 0 ; i <SEG_u8_NUMBER_OF_SEGMENTS ; i++)
    {
        DIO_enuSetPinDirection(Copy_pstrSegPortsPins->enuPorts[i],Copy_pstrSegPortsPins->enuPins[i], DIO_u8_OUTPUT);
    }


        for (u8 i=0 ; i<SEG_u8_NUMBER_OF_SEGMENTS ; i++)
        {
            DIO_enuSetOutputPinValue(Copy_pstrSegPortsPins->enuPorts[i],
                                        Copy_pstrSegPortsPins->enuPins[i],
                                        GET_BIT(~SEG_u8_SegValuesCathodeA0[Copy_u8_NumToView],(SEG_u8_NUMBER_OF_SEGMENTS-i)));
    
        }

        SEG_u8_currentValue = Copy_u8_NumToView;
        
}

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
SEG_tenuErrorStatus SEG_enuIncrement(SEG_strPortsPins * Copy_pstrSegPortsPins)
{
    SEG_enuViewNumber(Copy_pstrSegPortsPins,++SEG_u8_currentValue);
}

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
SEG_tenuErrorStatus SEG_enuDecrement(SEG_strPortsPins * Copy_pstrSegPortsPins)
{
    SEG_enuViewNumber(Copy_pstrSegPortsPins,--SEG_u8_currentValue);

    
}

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
SEG_tenuErrorStatus SEG_enuCountUp(SEG_strPortsPins * Copy_pstrSegPortsPins , u8 Copy_u8_Start , u8 Copy_u8_End)
{
    for(u8 i = Copy_u8_Start ; i<=Copy_u8_End ; i++)
        {
            SEG_enuViewNumber(Copy_pstrSegPortsPins,i);
            _delay_ms(SEG_u8_SECOND_DURATION_IN_MS);
        }
}

SEG_tenuErrorStatus SEG_enuCountUp_DefinedDelay(SEG_strPortsPins * Copy_pstrSegPortsPins , u8 Copy_u8_Start , u8 Copy_u8_End, u32 Copy_u32_Delay)
{
    for(u8 i = Copy_u8_Start ; i<=Copy_u8_End ; i++)
        {
            SEG_enuViewNumber(Copy_pstrSegPortsPins,i);
            _delay_ms(Copy_u32_Delay);
        }
}
/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
SEG_tenuErrorStatus SEG_enuCountUpWithStep(SEG_strPortsPins * Copy_pstrSegPortsPins , u8 Copy_u8_Start , u8 Copy_u8_End, u8 Copy_u8_IncStep);

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
SEG_tenuErrorStatus SEG_enuCountDown(SEG_strPortsPins * Copy_pstrSegPortsPins , u8 Copy_u8_Start , u8 Copy_u8_End)
{
    for(u8 i = Copy_u8_Start ; i>=Copy_u8_End ; i--)
        {
            SEG_enuViewNumber(Copy_pstrSegPortsPins,i);
            _delay_ms(SEG_u8_SECOND_DURATION_IN_MS);
        }
}

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
SEG_tenuErrorStatus SEG_enuCountDownWithStep(SEG_strPortsPins * Copy_pstrSegPortsPins , u8 Copy_u8_Start , u8 Copy_u8_End, u8 Copy_u8_DecStep);

SEG_tenuErrorStatus SEG_enuTurnOnDigitTwoSegments(SEG_strPortsPins* Copy_pstrSegPortsPins, SEG_strPortsPinsTwoDigitSegments* Copy_pstrPortsD1_D2, u8 Copy_u8_digitNum , SEG_tenuActiveType Copy_enuType)
{
    Copy_enuType==SEG_enuActiveLow?
    DIO_enuSetOutputPinValue(Copy_pstrPortsD1_D2->enuPorts2[Copy_u8_digitNum],
                            Copy_pstrSegPortsPins->enuPins[Copy_u8_digitNum],DIO_u8_HIGH_AL)
                            :
    DIO_enuSetOutputPinValue(Copy_pstrPortsD1_D2->enuPorts2[Copy_u8_digitNum],
                            Copy_pstrSegPortsPins->enuPins[Copy_u8_digitNum],DIO_u8_HIGH);

}
SEG_tenuErrorStatus SEG_enuTurnOffDigitTwoSegments(SEG_strPortsPins* Copy_pstrSegPortsPins, SEG_strPortsPinsTwoDigitSegments* Copy_pstrPortsD1_D2, u8 Copy_u8_digitNum, SEG_tenuActiveType Copy_enuType)
{
    Copy_enuType==SEG_enuActiveLow?
    DIO_enuSetOutputPinValue(Copy_pstrPortsD1_D2->enuPorts2[Copy_u8_digitNum],
                            Copy_pstrSegPortsPins->enuPins[Copy_u8_digitNum],DIO_u8_LOW_AL)
                            :
    DIO_enuSetOutputPinValue(Copy_pstrPortsD1_D2->enuPorts2[Copy_u8_digitNum],
                            Copy_pstrSegPortsPins->enuPins[Copy_u8_digitNum],DIO_u8_LOW);
}

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
SEG_tenuErrorStatus SEG_enuCountZeroToNinetyNine(SEG_strPortsPins * Copy_pstrSegPortsPins_FIRST , SEG_strPortsPins * Copy_pstrSegPortsPins_SECOND, SEG_strPortsPinsTwoDigitSegments* Copy_pstrCommonsInOrder)
{
    for (u8 i = 0 ; i <SEG_u8_NUMBER_OF_SEGMENTS ; i++)
    {
        DIO_enuSetPinDirection(Copy_pstrSegPortsPins_FIRST->enuPorts[i],Copy_pstrSegPortsPins_FIRST->enuPins[i], DIO_u8_OUTPUT);
        DIO_enuSetPinDirection(Copy_pstrSegPortsPins_SECOND->enuPorts[i],Copy_pstrSegPortsPins_SECOND->enuPins[i], DIO_u8_OUTPUT);

    }
    for (u8 i = 0 ; i <2 ; i++)
    {
        DIO_enuSetPinDirection(Copy_pstrCommonsInOrder->enuPorts2[i],Copy_pstrCommonsInOrder->enuPins2[i], DIO_u8_OUTPUT);
        DIO_enuSetOutputPinValue(Copy_pstrCommonsInOrder->enuPorts2[i],Copy_pstrCommonsInOrder->enuPins2[i],1);
    }

    u8 Local_u8_counterForDigits=0;
    u8 Local_u8_delayBetweenDigits=6; 


    while(Local_u8_counterForDigits<2)
    {
        if(Local_u8_counterForDigits==0)
        {
            SEG_enuTurnOnDigitTwoSegments(Copy_pstrSegPortsPins_FIRST,Copy_pstrCommonsInOrder,Local_u8_counterForDigits,SEG_enuActiveLow);
            SEG_enuCountUp(Copy_pstrSegPortsPins_FIRST,0,9);
        }
        if(Local_u8_counterForDigits==1)
        {
            u8 Local_u8_secondDigit=1;
            while(Local_u8_secondDigit<10)
            {
                u8 Local_u8_firstDigit=0;
                while(Local_u8_firstDigit<10)
                {
                    u8 Local_u8_stayinCounter=0;

                    while(Local_u8_stayinCounter<SEG_u8_SECOND_DURATION_IN_MS/(2*Local_u8_delayBetweenDigits))
                    {
                        SEG_enuTurnOnDigitTwoSegments(Copy_pstrSegPortsPins_SECOND,Copy_pstrCommonsInOrder,Local_u8_counterForDigits,SEG_enuActiveHigh);
                        SEG_enuViewNumber(Copy_pstrSegPortsPins_SECOND,Local_u8_secondDigit);
                        _delay_ms(Local_u8_delayBetweenDigits);
                        SEG_enuTurnOffDigitTwoSegments(Copy_pstrSegPortsPins_SECOND,Copy_pstrCommonsInOrder,Local_u8_counterForDigits,SEG_enuActiveHigh);
                        SEG_enuTurnOnDigitTwoSegments(Copy_pstrSegPortsPins_FIRST,Copy_pstrCommonsInOrder,Local_u8_counterForDigits-1,SEG_enuActiveHigh);
                        SEG_enuViewNumber(Copy_pstrSegPortsPins_FIRST,Local_u8_firstDigit);
                        _delay_ms(Local_u8_delayBetweenDigits);
                        SEG_enuTurnOffDigitTwoSegments(Copy_pstrSegPortsPins_FIRST,Copy_pstrCommonsInOrder,Local_u8_counterForDigits-1,SEG_enuActiveHigh);
                        Local_u8_stayinCounter++;
                    }

                    Local_u8_firstDigit++;
                }

                Local_u8_secondDigit++;
            }
            
        }

        Local_u8_counterForDigits++;
    }

}

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
SEG_tenuErrorStatus SEG_enuCountNinetyNineToZero(SEG_strPortsPins * Copy_pstrSegPortsPins , u8 Copy_u8_Start , u8 Copy_u8_End);

