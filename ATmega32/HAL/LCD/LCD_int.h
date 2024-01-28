#pragma once
#include "../MCAL/DIO/DIO_int.h"
#include "LCD_cfg.h"


#define LCD_u8_NUMBER_OF_D_BITS 8
typedef enum{
    LCD_OK,
    LCD_NOK
}LCD_tenuErrorStatus;

typedef enum{
    LCD_enuClearDisp = 0x01,
    LCD_enuReturnHome = 0x02,


}LCD_tenuInstructions;


/* 
    Struct Components: 
        - array of 8 ports (D0 -> D7 Ports) IN ORDER
        - array of 8 pints (D0 -> D7 Pins)  IN ORDER
        - Rs port
        - Rs pin
        - Rw port
        - Rw pin
        - E port
        - E pin
 */
typedef struct{
    DIO_tenuPorts D_Ports[LCD_u8_NUMBER_OF_D_BITS];
    //DIO_tenuPorts D0_Port,
    //DIO_tenuPorts D1_Port,
    //DIO_tenuPorts D2_Port,
    //DIO_tenuPorts D3_Port,
    //DIO_tenuPorts D4_Port,
    //DIO_tenuPorts D5_Port,
    //DIO_tenuPorts D6_Port,
    //DIO_tenuPorts D7_Port,
    
    DIO_tenuPins D_Pins[LCD_u8_NUMBER_OF_D_BITS];
    // DIO_tenuPins D0_Pin,
    // DIO_tenuPins D1_Pin,
    // DIO_tenuPins D2_Pin,
    // DIO_tenuPins D3_Pin,
    // DIO_tenuPins D4_Pin,
    // DIO_tenuPins D5_Pin,
    // DIO_tenuPins D6_Pin,
    // DIO_tenuPins D7_Pin,

    DIO_tenuPorts Rs_Port;
    DIO_tenuPins Rs_Pin;

    DIO_tenuPorts Rw_Port;
    DIO_tenuPins Rw_Pin;

    DIO_tenuPorts E_Port;
    DIO_tenuPins E_Pin;

}LCD_tstrPortsPins;

LCD_tenuErrorStatus LCD_enuInit(LCD_tstrPortsPins* Ref_strPortsPins);

LCD_tenuErrorStatus LCD_enuSendInstruction(LCD_tstrPortsPins* Ref_strPortsPins,u8 Copy_u8_Instruction);

// LCD_tenuErrorStatus LCD_enuSendData(LCD_tstrPortsPins* Ref_strPortsPins,u8 Copy_u8_Data);
//Testing
LCD_tenuErrorStatus LCD_enuSendData(LCD_tstrPortsPins* Ref_strPortsPins,u8 Copy_u8_Data,u8* Ref_TEST_pu8_returnTypedData);

LCD_tenuErrorStatus LCD_enuSendString(LCD_tstrPortsPins* Ref_strPortsPins,u8 Copy_String[]);

// LCD_tenuErrorStatus LCD_enuSendChar(LCD_tstrPortsPins* Ref_strPortsPins,u8 Copy_u8_Cahracter);
//TEsting
LCD_tenuErrorStatus LCD_enuSendChar(LCD_tstrPortsPins* Ref_strPortsPins,u8 Copy_u8_Cahracter,u8* Ref_TEST_pu8_returnTypedData);

LCD_tenuErrorStatus LCD_enuGoTo(LCD_tstrPortsPins* Ref_strPortsPins,u8 Copy_u8_Row, u8 Copy_u8_Col);

LCD_tenuErrorStatus LCD_enuSendNumber(LCD_tstrPortsPins* Ref_strPortsPins,u32 Copy_u32_Number);

LCD_tenuErrorStatus LCD_enuSendString(LCD_tstrPortsPins* Ref_strPortsPins,u8 Copy_String[]);



/* 
LCD_vidInit();
LCD_enuSendChar();
LCD_enuSendCNumber(); //1959
LCD_enuSendInstruction();
LCD_enuGoTo();
LCD_enuSendString();
LCD_enuSendCustomChar();
*/