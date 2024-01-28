#pragma once

#include "../../LIB/types.h"
#include "../MCAL/DIO/DIO_int.h"

#define SEG_u8_NUMBER_OF_SEGMENTS 7

#define SEG_u8_SECOND_DURATION_IN_MS 100

typedef enum{
	SEG_OK,
	SEG_NOK,
} SEG_tenuErrorStatus;

typedef enum{
	SEG_enuActiveHigh,
	SEG_enuActiveLow,
} SEG_tenuActiveType;

// a b c d e f g
//   b c
// a b   d     g

typedef struct
{
    DIO_tenuPorts enuPorts2[2]; 
    DIO_tenuPins enuPins2[2];

}SEG_strPortsPinsTwoDigitSegments;


typedef struct
{
    /* data */

    // a -> g
    DIO_tenuPorts enuPorts[SEG_u8_NUMBER_OF_SEGMENTS]; 
    DIO_tenuPins enuPins[SEG_u8_NUMBER_OF_SEGMENTS];

}SEG_strPortsPins;

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
SEG_tenuErrorStatus SEG_enuViewNumber(SEG_strPortsPins * Copy_pstrSegPortsPins , u8 Copy_u8_NumToView);

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
SEG_tenuErrorStatus SEG_enuIncrement(SEG_strPortsPins * Copy_pstrSegPortsPins);

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
SEG_tenuErrorStatus SEG_enuDecrement(SEG_strPortsPins * Copy_pstrSegPortsPins);

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
SEG_tenuErrorStatus SEG_enuCountUp(SEG_strPortsPins * Copy_pstrSegPortsPins , u8 Copy_u8_Start , u8 Copy_u8_End);

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
SEG_tenuErrorStatus SEG_enuCountDown(SEG_strPortsPins * Copy_pstrSegPortsPins , u8 Copy_u8_Start , u8 Copy_u8_End);

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
SEG_tenuErrorStatus SEG_enuCountDownWithStep(SEG_strPortsPins * Copy_pstrSegPortsPins , u8 Copy_u8_Start , u8 Copy_u8_End, u8 Copy_u8_DecStep);

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
SEG_tenuErrorStatus SEG_enuCountZeroToNinetyNine(SEG_strPortsPins * Copy_pstrSegPortsPins_FIRST , SEG_strPortsPins * Copy_pstrSegPortsPins_SECOND, SEG_strPortsPinsTwoDigitSegments* Copy_pstrCommonsInOrder);

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
SEG_tenuErrorStatus SEG_enuCountNinetyNineToZero(SEG_strPortsPins * Copy_pstrSegPortsPins , u8 Copy_u8_Start , u8 Copy_u8_End);

// SEG_tenuErrorStatus SEF_enuFourDigitCounterUpZeroTo9999(SEG_strPortsPins* Copy_pstrSegPortsPins,SEG_strPortsPinsTwoDigitSegments* Copy_pstrPortsD1_D2);

SEG_tenuErrorStatus SEG_enuTurnOffDigitTwoSegments(SEG_strPortsPins* Copy_pstrSegPortsPins, SEG_strPortsPinsTwoDigitSegments* Copy_pstrPortsD1_D2, u8 Copy_u8_digitNum, SEG_tenuActiveType Copy_enuType);
SEG_tenuErrorStatus SEG_enuTurnOnDigitTwoSegments(SEG_strPortsPins* Copy_pstrSegPortsPins, SEG_strPortsPinsTwoDigitSegments* Copy_pstrPortsD1_D2, u8 Copy_u8_digitNum, SEG_tenuActiveType Copy_enuType);
