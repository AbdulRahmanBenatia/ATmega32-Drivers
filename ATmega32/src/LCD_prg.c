#include "../HAL/LCD/LCD_int.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../LIB/types.h"

//Check All ports and pins are valid in init() ....
//Make them output in init() ....
//Do initialization as in datasheet

//Send Enable To Tell LCD of the change
static LCD_tenuErrorStatus LCD_Private_enuSendInstruction(LCD_tstrPortsPins* Ref_strPortsPins)
{
    DIO_enuSetOutputPinValue(Ref_strPortsPins->E_Port, Ref_strPortsPins->E_Pin, DIO_u8_HIGH);
    DIO_enuSetOutputPinValue(Ref_strPortsPins->E_Port, Ref_strPortsPins->E_Pin, DIO_u8_LOW);
    _delay_ms(1);
    DIO_enuSetOutputPinValue(Ref_strPortsPins->E_Port, Ref_strPortsPins->E_Pin, DIO_u8_HIGH);
}

LCD_tenuErrorStatus LCD_enuValidate(LCD_tstrPortsPins* Ref_strPortsPins)
{
    LCD_tenuErrorStatus Local_enuValidStat =LCD_OK;

    {
        (((Ref_strPortsPins->Rs_Port)>DIO_enuPORTD)
        ||
        ((Ref_strPortsPins->Rw_Port)>DIO_enuPORTD)
        ||
        ((Ref_strPortsPins->E_Port)>DIO_enuPORTD)
        ||
        ((Ref_strPortsPins->Rs_Pin)>DIO_enuPIN7)
        ||
        ((Ref_strPortsPins->Rw_Pin)>DIO_enuPIN7)
        ||
        ((Ref_strPortsPins->E_Pin)>DIO_enuPIN7))
        ?
        (Local_enuValidStat=LCD_NOK)
        :
        (Local_enuValidStat =LCD_OK);

        for (u8 i=0; i< 8; i++)
        {
            if(Ref_strPortsPins->D_Ports>DIO_enuPORTD || Ref_strPortsPins->D_Pins)
            {
                Local_enuValidStat=LCD_NOK;
            }
        }

    }
    return Local_enuValidStat;
}

LCD_tenuErrorStatus LCD_enuInit(LCD_tstrPortsPins* Ref_strPortsPins)
{
    LCD_tenuErrorStatus Local_enuErrorStat =LCD_OK;

    //Validation :
    Local_enuErrorStat=LCD_enuValidate(Ref_strPortsPins);
    
    if(Local_enuErrorStat==LCD_OK)
    {
        //Set D Pins to output low
        for (u8 i=0; i< 8; i++)
        {
            DIO_enuSetPinDirection(Ref_strPortsPins->D_Ports[i], Ref_strPortsPins->D_Pins[i], DIO_u8_OUTPUT);
            DIO_enuSetOutputPinValue(Ref_strPortsPins->D_Pins[i], Ref_strPortsPins->D_Pins[i], DIO_u8_LOW);
        }
        
        DIO_enuSetPinDirection(Ref_strPortsPins->Rs_Port, Ref_strPortsPins->Rs_Pin, DIO_u8_OUTPUT);
        DIO_enuSetOutputPinValue(Ref_strPortsPins->Rs_Port, Ref_strPortsPins->Rs_Pin, DIO_u8_LOW);
        DIO_enuSetPinDirection(Ref_strPortsPins->Rw_Port, Ref_strPortsPins->Rw_Pin, DIO_u8_OUTPUT);
        DIO_enuSetOutputPinValue(Ref_strPortsPins->Rw_Port, Ref_strPortsPins->Rw_Pin, DIO_u8_LOW);
        DIO_enuSetPinDirection(Ref_strPortsPins->E_Port, Ref_strPortsPins->E_Pin, DIO_u8_OUTPUT);
        DIO_enuSetOutputPinValue(Ref_strPortsPins->E_Port, Ref_strPortsPins->E_Pin, DIO_u8_LOW);
        //Initialization from datasheet...
        _delay_ms(30);

        //function set
        Local_enuErrorStat = LCD_enuSendInstruction(Ref_strPortsPins, (0b00110000 | (LCD_u8_NUMBER_OF_LINES<<3) | (LCD_u8_FONT_SIZE<<2)));
        _delay_us(50);

        if(Local_enuErrorStat==LCD_OK)
        {
            //display on-off
            Local_enuErrorStat = LCD_enuSendInstruction(Ref_strPortsPins, 0b00001111);
            _delay_us(50);
            if(Local_enuErrorStat==LCD_OK)
            {
                //clear display
                Local_enuErrorStat= LCD_enuSendInstruction(Ref_strPortsPins, LCD_enuClearDisp);
                _delay_ms(2);

                if(Local_enuErrorStat==LCD_OK)
                {
                    //entry mode set
                    Local_enuErrorStat = LCD_enuSendInstruction(Ref_strPortsPins, 0b00000110);
                    _delay_ms(2);

                    //end of initialization
                }
            }
        }
    }


    return Local_enuErrorStat;
}

LCD_tenuErrorStatus LCD_enuSendInstruction(LCD_tstrPortsPins* Ref_strPortsPins,u8 Copy_u8_Instruction)
{
    DIO_enuSetOutputPinValue(Ref_strPortsPins->Rs_Port, Ref_strPortsPins->Rs_Pin ,DIO_u8_HIGH);
    DIO_enuSetOutputPinValue(Ref_strPortsPins->Rw_Port, Ref_strPortsPins->Rw_Pin ,DIO_u8_HIGH);

    //Send Instruction

    for( u8 i = 0 ; i <LCD_u8_NUMBER_OF_D_BITS; i++)
    {
        DIO_enuSetOutputPinValue(Ref_strPortsPins->D_Ports[i], Ref_strPortsPins->D_Pins[i] ,GET_BIT(Copy_u8_Instruction,i));
    }

    // DIO_enuSetOutputPinValue(Ref_strPortsPins->D0_Port, Ref_strPortsPins->D0_Pin ,GET_BIT(Copy_u8_Instruction,0));
    // DIO_enuSetOutputPinValue(Ref_strPortsPins->D1_Port, Ref_strPortsPins->D1_Pin ,GET_BIT(Copy_u8_Instruction,1));
    ///................etc

    //Send Enable

    LCD_Private_enuSendInstruction(Ref_strPortsPins);
}

LCD_tenuErrorStatus LCD_enuSendData(LCD_tstrPortsPins* Ref_strPortsPins,u8 Copy_u8_Data, u8* Ref_TEST_pu8_returnTypedData)
{
    // DIO_enuSetPinDirection(Ref_strPortsPins->Rs_Port, Ref_strPortsPins->Rs_Pin ,DIO_u8_OUTPUT);
    DIO_enuSetOutputPinValue(Ref_strPortsPins->Rs_Port, Ref_strPortsPins->Rs_Pin ,DIO_u8_HIGH);
    DIO_enuSetOutputPinValue(Ref_strPortsPins->Rw_Port, Ref_strPortsPins->Rw_Pin ,DIO_u8_LOW);

    //Send Data

    for( u8 i = 0 ; i <LCD_u8_NUMBER_OF_D_BITS; i++)
    {
        DIO_enuSetOutputPinValue(Ref_strPortsPins->D_Ports[i], Ref_strPortsPins->D_Pins[i] ,GET_BIT(Copy_u8_Data,i));
        if(GET_BIT(Copy_u8_Data,i)==1) SET_BIT(*Ref_TEST_pu8_returnTypedData,GET_BIT(Copy_u8_Data,i));
    }

    // DIO_enuSetOutputPinValue(Ref_strPortsPins->D0_Port, Ref_strPortsPins->D0_Pin ,GET_BIT(Copy_u8_Data,0));
    // DIO_enuSetOutputPinValue(Ref_strPortsPins->D1_Port, Ref_strPortsPins->D1_Pin ,GET_BIT(Copy_u8_Data,1));
    ///................etc

    //Send Enable
    LCD_Private_enuSendInstruction(Ref_strPortsPins);

}

LCD_tenuErrorStatus LCD_enuSendChar(LCD_tstrPortsPins* Ref_strPortsPins,u8 Copy_u8_Cahracter,u8* Ref_TEST_pu8_returnTypedData)
{
    LCD_enuSendData(Ref_strPortsPins,Copy_u8_Cahracter,Ref_TEST_pu8_returnTypedData);

}

//************************************* COMMENTED FOR TESTING *****************************************



// LCD_tenuErrorStatus LCD_enuSendString(LCD_tstrPortsPins* Ref_strPortsPins,u8 Copy_String[])
// {
//     //null terminator '\0'

//     u8 i = 0 ;
//     while(Copy_String[i]!='\0')
//     {
//         LCD_enuSendChar(Ref_strPortsPins,Copy_String[i]);
//         _delay_us(50);
//         i++;
//     }

// }

// LCD_tenuErrorStatus LCD_enuSendNumber(LCD_tstrPortsPins* Ref_strPortsPins,u32 Copy_u32_Number)
// {
//     u8 Local_u8_charToDisplay = 0;
//     while(Copy_u32_Number>0)
//     {
//         Local_u8_charToDisplay= Copy_u32_Number%10;
//         LCD_enuSendChar(Ref_strPortsPins,Local_u8_charToDisplay);
//         Copy_u32_Number/=10;
//         _delay_ms(1);

//         //let AC be decreasing from right to left
//     }
// }

LCD_tenuErrorStatus LCD_enuGoTo(LCD_tstrPortsPins* Ref_strPortsPins,u8 Copy_u8_Row, u8 Copy_u8_Col)
{
    LCD_tenuErrorStatus Local_enuErrorStat =LCD_OK;
    //0000-0000
    //0000-0001
    //0000-0010

    //0x00  0x01  0x02  0x03 ....
    //0x40  0x41
    Copy_u8_Row==1? (LCD_enuSendInstruction(Ref_strPortsPins, (0x80 | (Copy_u8_Col)))) :
    Copy_u8_Row==2? (LCD_enuSendInstruction(Ref_strPortsPins, (0x80 | 0x40 | (Copy_u8_Col)))) :
    (Local_enuErrorStat =LCD_NOK);

    return Local_enuErrorStat;

}


// LCD_tenuErrorStatus LCD_enuSendCustomCharacter(LCD_tstrPortsPins* Ref_strPortsPins,u8* Copy_pu8_Pattern, u8 Copy_u8_Row, u8 Copy_u8_Col, u8 Copy_u8_patternNumberAtCGRAM /* 0 to 7 */)
// {
    
//     //Send AC to CGRAM
//     LCD_enuSendInstruction(Ref_strPortsPins,0x40 | (Copy_u8_patternNumberAtCGRAM * 8));

//     //Send Pattern
//     for(u8 i = 0 ; i <8; i++)
//     {
//         LCD_enuSendChar(Ref_strPortsPins,Copy_pu8_Pattern[i]);
//     }

//     //Send AC to DDRAM
//     LCD_enuGoTo(Ref_strPortsPins,Copy_u8_Row,Copy_u8_Col);
//     // LCD_enuSendInstruction(Ref_strPortsPins,0x80 | (Copy_u8_patternNumberAtCGRAM * 8));

//     //Display char
//     LCD_enuSendChar(Ref_strPortsPins, Copy_u8_patternNumberAtCGRAM);



// }













