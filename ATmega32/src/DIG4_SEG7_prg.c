#include "../HAL/DIG4_SEG7/DIG4_SEG7_int.h"
#include "../MCAL/DIO/DIO_int.h"

SEG_tenuErrorStatus SEG_enuTurnOnDigit(SEG_strPortsPins* Copy_pstrSegPortsPins, SEG_strPortsPinsFourDig* Copy_pstrPortsD1_D2_D3_D4, u8 Copy_u8_digitNum)
{
    DIO_enuSetOutputPinValue(Copy_pstrPortsD1_D2_D3_D4->enuPorts4[Copy_u8_digitNum],
                            Copy_pstrSegPortsPins->enuPins[Copy_u8_digitNum],DIO_u8_HIGH_AL);

}
SEG_tenuErrorStatus SEG_enuTurnOffDigit(SEG_strPortsPins* Copy_pstrSegPortsPins, SEG_strPortsPinsFourDig* Copy_pstrPortsD1_D2_D3_D4, u8 Copy_u8_digitNum)
{
    DIO_enuSetOutputPinValue(Copy_pstrPortsD1_D2_D3_D4->enuPorts4[Copy_u8_digitNum],
                            Copy_pstrSegPortsPins->enuPins[Copy_u8_digitNum],DIO_u8_LOW_AL);

}

SEG_tenuErrorStatus SEG_enuFourDigitCounterUpZeroTo9999(SEG_strPortsPins* Copy_pstrSegPortsPins,SEG_strPortsPinsFourDig* Copy_pstrPortsD1_D2_D3_D4)
{
    // DIO_enuSetPinDirection(DIO_enuPORTD, DIO_enuPIN0,DIO_u8_OUTPUT);
    // DIO_enuSetOutputPortValues(DIO_enuPORTD, 1);
    // DIO_enuSetOutputPinValue(DIO_enuPORTD, DIO_enuPIN0,0);

    for (u8 i = 0 ; i <SEG_u8_NUMBER_OF_SEGMENTS ; i++)
    {
        DIO_enuSetPinDirection(Copy_pstrSegPortsPins->enuPorts[i],Copy_pstrSegPortsPins->enuPins[i], DIO_u8_OUTPUT);
    }
    for (u8 i = 0 ; i <4 ; i++)
    {
        DIO_enuSetPinDirection(Copy_pstrPortsD1_D2_D3_D4->enuPorts4[i],Copy_pstrSegPortsPins->enuPins[i], DIO_u8_OUTPUT);
        DIO_enuSetOutputPinValue(Copy_pstrPortsD1_D2_D3_D4->enuPorts4[i],Copy_pstrSegPortsPins->enuPins[i],1);
    }
    u8 i =0;
    while(i<4)
    {
        //Flashing delay in ms
        u8 Local_u8_delayBetweenDigits=6; 
        u8 Local_u8_whoSentYou=0;
        // DIO_enuSetOutputPinValue(Copy_pstrPortsD1_D2_D3_D4->enuPorts4[i],Copy_pstrSegPortsPins->enuPins[i],DIO_u8_HIGH_AL);
        if(i==0)
        {
            SEG_enuTurnOnDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i);
            SEG_enuCountUp(Copy_pstrSegPortsPins,0,9);

        }

        if(i==1)
        {
            u8 scnd=1;
            while (scnd<10)
            {
                u8 fst=0;
                while(fst<10)
                {
                    //do it 10 times:
                    u8 counter=0;
                    // while(counter<SEG_u8_SECOND_DURATION_IN_MS/12)
                    while(counter<SEG_u8_SECOND_DURATION_IN_MS/((i+1)*Local_u8_delayBetweenDigits))
                    {
                        SEG_enuTurnOnDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i);
                        SEG_enuViewNumber(Copy_pstrSegPortsPins, scnd);
                        _delay_ms(Local_u8_delayBetweenDigits);
                        SEG_enuTurnOffDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i);
                        SEG_enuTurnOnDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i-1);
                        SEG_enuViewNumber(Copy_pstrSegPortsPins,fst);
                        _delay_ms(Local_u8_delayBetweenDigits);
                        SEG_enuTurnOffDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i-1);
                        counter++;
                    }
                    fst++;
                }
                scnd++;
            }
                
        }

        if(i==2)
        {
            Local_u8_delayBetweenDigits/=2;
            u8 thrd=1;
            while(thrd<10)
            {
                u8 scnd=0;
                while(scnd<10)
                {
                    u8 fst=0;
                    while(fst<10)
                    {
                        u8 Local_u8_loopCounter=0;
                        while(Local_u8_loopCounter<SEG_u8_SECOND_DURATION_IN_MS/((i+1)*Local_u8_delayBetweenDigits))
                        {
                            SEG_enuTurnOnDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i);
                            SEG_enuViewNumber(Copy_pstrSegPortsPins,thrd);
                            _delay_ms(Local_u8_delayBetweenDigits);
                            SEG_enuTurnOffDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i);
                            SEG_enuTurnOnDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i-1);
                            SEG_enuViewNumber(Copy_pstrSegPortsPins,scnd);
                            _delay_ms(Local_u8_delayBetweenDigits);
                            SEG_enuTurnOffDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i-1);
                            SEG_enuTurnOnDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i-2);
                            SEG_enuViewNumber(Copy_pstrSegPortsPins,fst);
                            _delay_ms(Local_u8_delayBetweenDigits);
                            SEG_enuTurnOffDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i-2);
                            Local_u8_loopCounter++;
                        }

                        fst++;
                    }
                    scnd++;
                }
                thrd++;
            }
        }

        if(i==3)
        {
            Local_u8_delayBetweenDigits/=2;
            u8 frth=1;
            while(frth<10)
            {
                u8 thrd=0;
                while(thrd<10)
                {
                    u8 scnd=0;
                    while(scnd<10)
                    {
                        u8 fst=0;
                        while(fst<10)
                        {
                            u8 Local_u8_loopCounter=0;
                            while(Local_u8_loopCounter<SEG_u8_SECOND_DURATION_IN_MS/((i+1)*Local_u8_delayBetweenDigits))
                            {
                                SEG_enuTurnOnDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i);
                                SEG_enuViewNumber(Copy_pstrSegPortsPins,frth);
                                _delay_ms(Local_u8_delayBetweenDigits);
                                SEG_enuTurnOffDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i);
                                SEG_enuTurnOnDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i-1);
                                SEG_enuViewNumber(Copy_pstrSegPortsPins,thrd);
                                _delay_ms(Local_u8_delayBetweenDigits);
                                SEG_enuTurnOffDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i-1);
                                SEG_enuTurnOnDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i-2);
                                SEG_enuViewNumber(Copy_pstrSegPortsPins,scnd);
                                _delay_ms(Local_u8_delayBetweenDigits);
                                SEG_enuTurnOffDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i-2);
                                SEG_enuTurnOnDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i-3);
                                SEG_enuViewNumber(Copy_pstrSegPortsPins,fst);
                                _delay_ms(Local_u8_delayBetweenDigits);
                                SEG_enuTurnOffDigit(Copy_pstrSegPortsPins,Copy_pstrPortsD1_D2_D3_D4,i-3);
                                Local_u8_loopCounter++;
                            }

                            fst++;
                        }
                        scnd++;
                    }
                    thrd++;
                }
                frth++;
            }
        }
        i++;
    }

}
