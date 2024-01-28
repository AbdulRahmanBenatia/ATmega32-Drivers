#pragma once
#include "../../LIB/types.h"
#include "../DIO/DIO_int.h"
typedef enum{
	TIMER_OK,
	TIMER_NOK,
} TIMER_tenuErrorStatus;

typedef enum{
	enuTIMER_0,
	enuTIMER_1,
	enuTIMER_2,
} TIMER_tenuTimers;

typedef enum{
	TIMER_enuNormal,
	TIMER_enuPWM_PhaseCorrect,
	TIMER_enuFast_PWM,
	TIMER_enuCTC,
} TIMER_tenuTimerModes;


TIMER_tenuErrorStatus TIMER_enuInit();
TIMER_tenuErrorStatus TIMER_enuSetPreload(TIMER_tenuTimers Copy_enuTimer, u16 Copy_u16_preload);
TIMER_tenuErrorStatus TIMER_enuSetCTC(TIMER_tenuTimers Copy_enuTimerToStart, u16 Copy_u8_CTC_Value);
TIMER_tenuErrorStatus TIMER_enuStartTimer(TIMER_tenuTimers Copy_enuTimerToStart, u8 Copy_u8_time_ms);
TIMER_tenuErrorStatus TIMER_enuStopTimer(TIMER_tenuTimers Copy_enuTimerToStart);
TIMER_tenuErrorStatus TIMER_enuSetTimerMode(TIMER_tenuTimers Copy_enuTimerToStart,TIMER_tenuTimerModes Copy_enuMode);

//Counter   GPT:
// init()
// startTimer(#timer, time_ms)
// stopTimer(#timer)
// setMode(#timer,mode,compareValueforCTC)  //(optional)
// registerCallbackFunc(#timer,func*)  //instead of functions in cfg.c file (optional)
// 3 ISRs, one for each timer
