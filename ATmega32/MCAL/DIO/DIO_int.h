/*
 * DIO_int.h
 *
 *  Created on: Sep 2, 2023
 *      Author: abdul
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

#include "../../LIB/types.h"


#define SET_BIT(var,bitNo) (var |= (1<<bitNo))
#define CLR_BIT(var,bitNo) (var &= ~(1<<bitNo))
#define TGL_BIT(var,bitNo) (var ^= (1<<bitNo))
#define GET_BIT(var,bitNo) (var & (1<<bitNo))

/* Defining DIO Ports  */
// #define DIO_u8_PORTA 0
// #define DIO_u8_PORTB 1
// #define DIO_u8_PORTC 2
// #define DIO_u8_PORTD 3
typedef enum{
	DIO_enuPORTA,
	DIO_enuPORTB,
	DIO_enuPORTC,
	DIO_enuPORTD 
} DIO_tenuPorts;  

/* Defining DIO Pins */
// #define DIO_u8_PIN0 0 
// #define DIO_u8_PIN1 1 
// #define DIO_u8_PIN2 2
// #define DIO_u8_PIN3 3
// #define DIO_u8_PIN4 4
// #define DIO_u8_PIN5 5
// #define DIO_u8_PIN6 6
// #define DIO_u8_PIN7 7
typedef enum{
	DIO_enuPIN0, 
	DIO_enuPIN1, 
	DIO_enuPIN2,
	DIO_enuPIN3,
	DIO_enuPIN4,
	DIO_enuPIN5,
	DIO_enuPIN6,
	DIO_enuPIN7
} DIO_tenuPins;  

#define DIO_u8_INPUT 0
#define DIO_u8_OUTPUT 1

#define DIO_u8_HIGH 1
#define DIO_u8_LOW 0

//For active low:
#define DIO_u8_HIGH_AL 0
#define DIO_u8_LOW_AL 1

/* Definie combinations */
// typedef enum{
// 	PINA0,
// 	PINA1,
// 	PINA2,
// 	PINA3,
// 	PINA4,
// 	PINA5,
// 	PINA6,
// 	PINA7,
	
// 	PINB0,
// 	PINB1,
// 	PINB2,
// 	PINB3,
// 	PINB4,
// 	PINB5,
// 	PINB6,
// 	PINB7,

// 	PINC0,
// 	PINC1,
// 	PINC2,
// 	PINC3,
// 	PINC4,
// 	PINC5,
// 	PINC6,
// 	PINC7,

// 	PIND0,
// 	PIND1,
// 	PIND2,
// 	PIND3,
// 	PIND4,
// 	PIND5,
// 	PIND6,
// 	PIND7,
// }DIO_tenuPortPin;


typedef enum{
	DIO_OK,
	DIO_NOK,
} DIO_tenuErrorStatus;


/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
DIO_tenuErrorStatus DIO_enuInitialize();

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
DIO_tenuErrorStatus DIO_enuSetPinDirection( u8 Copy_u8PortNum,
											u8 Copy_u8PinNum,
											u8 Copy_u8Direction);

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
DIO_tenuErrorStatus DIO_enuSetPortDirection(u8 Copy_u8PortNum,
											u8 Copy_u8Direction);

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
DIO_tenuErrorStatus DIO_enuSetOutputPinValue(   u8 Copy_u8PortNum,
												u8 Copy_u8PinNum,
												u8 Copy_u8Value);
/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
DIO_tenuErrorStatus DIO_enuToggleOutputPinValue(   u8 Copy_u8PortNum,
												u8 Copy_u8PinNum);

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
DIO_tenuErrorStatus DIO_enuSetOutputPortValues(u8 Copy_u8PortNum,
											    u8 Copy_u8Value);

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
DIO_tenuErrorStatus DIO_enuGetInputPinValue(u8  Copy_u8PortNum,
											u8  Copy_u8PinNum,
										    u8* Ref_pu8InputCarrier);

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
DIO_tenuErrorStatus DIO_enuGetInputPortValues(u8  Copy_u8PortNum,
										      u8* Ref_pu8InputCarrier);

DIO_tenuErrorStatus DIO_setPinAsPullUp(DIO_tenuPorts Copy_enuPort,DIO_tenuPins Copy_enuPin );




#endif /* MCAL_DIO_DIO_INT_H_ */
