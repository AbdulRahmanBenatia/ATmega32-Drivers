/*
 * DIO_prg.c
 *
 *  Created on: Sep 2, 2023
 *      Author: abdul
 */

// #define __AVR_ATmega32__
// #include "DIO_int.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/DIO/DIO_prv.h"
// #include "DIO_prv.h"
#include <avr/io.h>

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
DIO_tenuErrorStatus DIO_enuInitialize()
{
	DIO_tenuErrorStatus Local_errorStatus = DIO_OK;
	DIO_u8_DDRA_REG=0xff;
	DIO_u8_DDRB_REG=0xff;
	DIO_u8_DDRC_REG=0xff;
	DIO_u8_DDRD_REG=0xff;
	// DIO_enuSetPinDirection(DIO_u8_PORTA,)
	return Local_errorStatus;

}


/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
DIO_tenuErrorStatus DIO_enuSetPinDirection( u8 Copy_u8PortNum,
											u8 Copy_u8PinNum,
											u8 Copy_u8Direction)
{
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
	//  Inputs Validation
	if(Copy_u8PortNum > DIO_enuPORTD || Copy_u8PinNum > DIO_enuPIN7 || Copy_u8Direction > DIO_u8_OUTPUT)
	{
		// return DIO_NOK; 			//bad practice
		Local_enuErrorStatus=DIO_NOK;
	}


	switch(Copy_u8PortNum)
	{
		case DIO_enuPORTA:
			(Copy_u8Direction==DIO_u8_OUTPUT)? (SET_BIT(DIO_u8_DDRA_REG, Copy_u8PinNum)): (CLR_BIT(DIO_u8_DDRA_REG, Copy_u8PinNum));
			break;
		case DIO_enuPORTB:
			Copy_u8Direction==DIO_u8_OUTPUT? SET_BIT(DIO_u8_DDRB_REG, Copy_u8PinNum): CLR_BIT(DIO_u8_DDRB_REG, Copy_u8PinNum);

			break;
		case DIO_enuPORTC:
			Copy_u8Direction==DIO_u8_OUTPUT? SET_BIT(DIO_u8_DDRC_REG, Copy_u8PinNum): CLR_BIT(DIO_u8_DDRC_REG, Copy_u8PinNum);
			break;
		case DIO_enuPORTD:
			Copy_u8Direction==DIO_u8_OUTPUT? SET_BIT(DIO_u8_DDRD_REG, Copy_u8PinNum): CLR_BIT(DIO_u8_DDRD_REG, Copy_u8PinNum);

			break;
		
		/* switch (Copy_u8PinNum)
		{
		case DIO_u8_PIN0:
			DIO_u8_DDRA &= 0b11111110;   //replace with SET_PIN
			break;
		case DIO_u8_PIN1:
			DIO_u8_DDRA &= 0b11111101;   //replace with SET_PIN
			break;
		case DIO_u8_PIN2:
			DIO_u8_DDRA &= 0b11111011;   //replace with SET_PIN
			break;
		case DIO_u8_PIN3:
			DIO_u8_DDRA &= 0b11110111;   //replace with SET_PIN
			break;
		case DIO_u8_PIN4:
			DIO_u8_DDRA &= 0b11101111;   //replace with SET_PIN
			break;
		case DIO_u8_PIN5:
			DIO_u8_DDRA &= 0b11011111;   //replace with SET_PIN
			break;
		case DIO_u8_PIN6:
			DIO_u8_DDRA &= 0b10111111;   //replace with SET_PIN
			break;
		case DIO_u8_PIN7:
			DIO_u8_DDRA &= 0b01111111;   //replace with SET_PIN
			break;
		} */
	
	}

	return Local_enuErrorStatus;

}

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
DIO_tenuErrorStatus DIO_enuSetPortDirection(u8 Copy_u8PortNum, u8 Copy_u8Direction)
{
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
	if(Copy_u8PortNum > DIO_enuPORTD || Copy_u8Direction > DIO_u8_OUTPUT)
	{
		Local_enuErrorStatus=DIO_NOK;
	}
	else 
	{
		for (u8 i = 0; i < 8; i++)
		{
			DIO_enuSetPinDirection(Copy_u8PortNum,i,Copy_u8Direction);
		}
	}

	return Local_enuErrorStatus;
}

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
DIO_tenuErrorStatus DIO_enuSetOutputPinValue(   u8 Copy_u8PortNum,
												u8 Copy_u8PinNum,
												u8 Copy_u8Value)
{
	
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
	//  Inputs Validation
	if(Copy_u8PortNum > DIO_enuPORTD || Copy_u8PinNum > DIO_enuPIN7)
	{
		// return DIO_NOK; 			//bad practice
		Local_enuErrorStatus=DIO_NOK;
	}
	else
	{
		DIO_enuSetPinDirection(Copy_u8PortNum, Copy_u8PinNum, DIO_u8_OUTPUT);
		
		switch (Copy_u8PortNum)
		{
		case DIO_enuPORTA:
			Copy_u8Value==0? (CLR_BIT(DIO_u8_PORTA_REG, Copy_u8PinNum)) : (SET_BIT(DIO_u8_PORTA_REG, Copy_u8PinNum));
			break;
		case DIO_enuPORTB:
			Copy_u8Value==0? (CLR_BIT(DIO_u8_PORTB_REG, Copy_u8PinNum)) : (SET_BIT(DIO_u8_PORTB_REG, Copy_u8PinNum));
			break;
		case DIO_enuPORTC:
			Copy_u8Value==0? (CLR_BIT(DIO_u8_PORTC_REG, Copy_u8PinNum)) : (SET_BIT(DIO_u8_PORTC_REG, Copy_u8PinNum));
			break;
		case DIO_enuPORTD:
			Copy_u8Value==0? (CLR_BIT(DIO_u8_PORTD_REG, Copy_u8PinNum)) : (SET_BIT(DIO_u8_PORTD_REG, Copy_u8PinNum));
			break;
		
		default:
			break;
		}

	}

	return Local_enuErrorStatus;
}

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
DIO_tenuErrorStatus DIO_enuSetOutputPortValues( u8 Copy_u8PortNum,
											    u8 Copy_u8Value)
{
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
	//  Inputs Validation
	if(Copy_u8PortNum > DIO_enuPORTD)
	{
		Local_enuErrorStatus=DIO_NOK;
	}
	else
	{
		DIO_enuSetPortDirection(Copy_u8PortNum,DIO_u8_OUTPUT);
		Copy_u8PortNum==DIO_enuPORTA? (DIO_u8_PORTA_REG=Copy_u8Value) 
		:
		Copy_u8PortNum==DIO_enuPORTB? (DIO_u8_PORTB_REG=Copy_u8Value)
		:
		Copy_u8PortNum==DIO_enuPORTC? (DIO_u8_PORTC_REG=Copy_u8Value)
		:
		(DIO_u8_PORTD_REG=Copy_u8Value); 
	}

	return Local_enuErrorStatus;
}

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
DIO_tenuErrorStatus DIO_enuGetInputPinValue(u8  Copy_u8PortNum,
											u8  Copy_u8PinNum,
										    u8* Ref_pu8InputCarrier)
{
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
	//  Inputs Validation
	if(Copy_u8PortNum > DIO_enuPORTD || Copy_u8PinNum > DIO_enuPIN7 || Ref_pu8InputCarrier != NULL)
	{
		Local_enuErrorStatus=DIO_NOK;
	}
	else
	{
		DIO_enuSetPinDirection(Copy_u8PortNum,Copy_u8PinNum, DIO_u8_INPUT);

		Copy_u8PortNum==DIO_enuPORTA? (*Ref_pu8InputCarrier= GET_BIT(DIO_u8_PINA_REG,Copy_u8PinNum))
		:
		Copy_u8PortNum==DIO_enuPORTB? (*Ref_pu8InputCarrier= GET_BIT(DIO_u8_PINB_REG,Copy_u8PinNum))
		:
		Copy_u8PortNum==DIO_enuPORTC? (*Ref_pu8InputCarrier= GET_BIT(DIO_u8_PINC_REG,Copy_u8PinNum))
		:
		GET_BIT(DIO_u8_PINC_REG,Copy_u8PinNum);


	}

	return Local_enuErrorStatus;
}

/* Name:
 * Description:
 * I/P arguments:
 * Return: OK or NOK
 */
DIO_tenuErrorStatus DIO_enuGetInputPortValues(u8  Copy_u8PortNum,
										      u8* Ref_pu8InputCarrier)
{
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
	//  Inputs Validation
	if(Copy_u8PortNum > DIO_enuPORTD || Ref_pu8InputCarrier != NULL)
	{
		Local_enuErrorStatus=DIO_NOK;
	}
	else
	{
		DIO_enuSetPortDirection(Copy_u8PortNum,DIO_u8_INPUT);
		Ref_pu8InputCarrier=DIO_u8_PINA_REG;
	}

	return Local_enuErrorStatus;
}


DIO_tenuErrorStatus DIO_enuToggleOutputPinValue(u8 Copy_u8PortNum,
												u8 Copy_u8PinNum)
{
	DIO_tenuErrorStatus Local_enuErrorStatus = DIO_OK;
	//  Inputs Validation
	if(Copy_u8PortNum > DIO_enuPORTD || Copy_u8PinNum > DIO_enuPIN7)
	{
		Local_enuErrorStatus=DIO_NOK;
	}
	else
	{
		DIO_enuSetPinDirection(Copy_u8PortNum, Copy_u8PinNum, DIO_u8_OUTPUT);
		
		switch (Copy_u8PortNum)
		{
		case DIO_enuPORTA:
			TGL_BIT(DIO_u8_PORTA_REG,Copy_u8PinNum);
			break;
		case DIO_enuPORTB:
			TGL_BIT(DIO_u8_PORTB_REG,Copy_u8PinNum);
			break;
		case DIO_enuPORTC:
			TGL_BIT(DIO_u8_PORTC_REG,Copy_u8PinNum);
			break;
		case DIO_enuPORTD:
			TGL_BIT(DIO_u8_PORTD_REG,Copy_u8PinNum);
			break;
		
		default:
			break;
		}

	}

	return Local_enuErrorStatus;
}

DIO_tenuErrorStatus DIO_setPinAsPullUp(DIO_tenuPorts Copy_enuPort,DIO_tenuPins Copy_enuPin )
{
	DIO_enuSetPinDirection(Copy_enuPort,Copy_enuPin,DIO_u8_INPUT);
	DIO_enuSetOutputPinValue(Copy_enuPort,Copy_enuPin,DIO_u8_HIGH);
}