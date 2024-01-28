#include "TIMER_int.h"
#include "TIMER_prv.h"

TIMER_tenuErrorStatus TIMER_enuInit()
{

}

TIMER_tenuErrorStatus TIMER_enuSetPreload(TIMER_tenuTimers Copy_enuTimer,u16 Copy_u16_preload)
{
    switch(Copy_enuTimer)
    {
        case enuTIMER_0:
            TIMER_TCNT0_REG = Copy_u16_preload;
            break;
        case enuTIMER_2:
            TIMER_TCNT2_REG = Copy_u16_preload;
            break;
        case enuTIMER_1:
            TIMER_TCNT1_REG = Copy_u16_preload;
            break;
    }

}

TIMER_tenuErrorStatus TIMER_enuSetCTC(TIMER_tenuTimers Copy_enuTimerToStart, u16 Copy_u8_CTC_Value);

TIMER_tenuErrorStatus TIMER_enuStartTimer(TIMER_tenuTimers Copy_enuTimerToStart, u8 Copy_u8_time_ms)
{
    //set prescalar
}

TIMER_tenuErrorStatus TIMER_enuStopTimer(TIMER_tenuTimers Copy_enuTimerToStart);

TIMER_tenuErrorStatus TIMER_enuSetTimerMode(TIMER_tenuTimers Copy_enuTimer,TIMER_tenuTimerModes Copy_enuMode)
{
    //What Is the suitable type for it??   //**************************************************************************************QUESTION.
    u8 Local_timer_TCCR_register=NULL;

    switch(Copy_enuTimer)
    {
        case enuTIMER_0:
        Local_timer_TCCR_register=TIMER_TCCR0_REG;
            break;
        case enuTIMER_1:
        // Local_timer_TCCR_register=TIMER_TCCR1_REG;    //**************************************************************COME HERE
        break;
        case enuTIMER_2:
        Local_timer_TCCR_register=TIMER_TCCR2_REG;

        break;
    }

    switch(Copy_enuMode)
            {
                case TIMER_enuNormal:
                    CLR_BIT(Local_timer_TCCR_register,TIMER_TCCR0_WGM00_BIT);
                    CLR_BIT(Local_timer_TCCR_register,TIMER_TCCR0_WGM01_BIT);
                    break;

                case TIMER_enuFast_PWM:
                    SET_BIT(Local_timer_TCCR_register,TIMER_TCCR0_WGM00_BIT);
                    SET_BIT(Local_timer_TCCR_register,TIMER_TCCR0_WGM01_BIT);
                    break;
                case TIMER_enuPWM_PhaseCorrect:
                    SET_BIT(Local_timer_TCCR_register,TIMER_TCCR0_WGM00_BIT);
                    CLR_BIT(Local_timer_TCCR_register,TIMER_TCCR0_WGM01_BIT);
                    break;
                case TIMER_enuCTC:
                    CLR_BIT(Local_timer_TCCR_register,TIMER_TCCR0_WGM00_BIT);
                    SET_BIT(Local_timer_TCCR_register,TIMER_TCCR0_WGM01_BIT);
                    break;
            }

}