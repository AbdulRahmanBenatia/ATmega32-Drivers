#pragma once

// #include "../../LIB/types.h"
#include "../../LIB/types.h"
#include "../../MCAL/DIO/DIO_int.h"

typedef enum{
	LED_OK,
	LED_NOK,
} LED_tenuErrorStatus;

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
LED_tenuErrorStatus LED_enuTurnOn(DIO_tenuPorts Copy_enuPortNum , DIO_tenuPins Copy_enuPinNum);

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
LED_tenuErrorStatus LED_enuTurnOff(DIO_tenuPorts Copy_enuPortNum , DIO_tenuPins Copy_enuPinNum);

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
LED_tenuErrorStatus LED_enuToggle(DIO_tenuPorts Copy_enuPortNum , DIO_tenuPins Copy_enuPinNum);

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
LED_tenuErrorStatus LED_enuBlink(DIO_tenuPorts Copy_enuPortNum , DIO_tenuPins Copy_enuPinNum,
                                    u8 Copy_timeInMilliSecond, u8 Copy_u8_howManyTimes);

