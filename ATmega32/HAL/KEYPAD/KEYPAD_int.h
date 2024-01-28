#include "../../MCAL/DIO/DIO_int.h"
#include "../../LIB/types.h"

#define KEYPAD_NUMBER_OF_ROWS 4
#define KEYPAD_NUMBER_OF_COLS 4

typedef struct
{
    DIO_tenuPorts LCD_enu_C_Ports[KEYPAD_NUMBER_OF_COLS];
    DIO_tenuPins LCD_enu_C_Pins[KEYPAD_NUMBER_OF_COLS];

    DIO_tenuPorts LCD_enu_R_Ports[KEYPAD_NUMBER_OF_ROWS];
    DIO_tenuPins LCD_enu_R_Pins[KEYPAD_NUMBER_OF_ROWS];
    


}KEYPAD_tstrPortsPins;

typedef enum{
    R1C1='1',
    R1C2='2',
    R1C3='3',
    R1C4='A',

    R2C1='4',
    R2C2='5',
    R2C3='6',
    R2C4='B',

    R3C1='7',
    R3C2='8',
    R3C3='9',
    R3C4='C',

    R4C1='-',
    R4C2='0',
    R4C3='+',
    R4C4='4',
}KEYPAD_enum;

KEYPAD_enum KEYPAD_2D_goodArray[KEYPAD_NUMBER_OF_COLS][KEYPAD_NUMBER_OF_ROWS]={{R1C1,R2C1,R3C1,R4C1},{R1C2,R2C2,R3C2,R4C3},{R1C3,R2C3,R3C3,R4C3},{R1C4,R2C4,R3C4,R4C4}};

void KEYPAD_vidInit(KEYPAD_tstrPortsPins* Add_pstrPortsPins)
{
    // DIO_enuSetPinDirection(Add)
    for(u8 i =0;i<KEYPAD_NUMBER_OF_COLS;i++)
    {
        DIO_enuSetPinDirection(Add_pstrPortsPins->LCD_enu_C_Ports[i],Add_pstrPortsPins->LCD_enu_C_Pins[i],DIO_u8_OUTPUT);
        DIO_enuSetOutputPinValue(Add_pstrPortsPins->LCD_enu_C_Ports[i],Add_pstrPortsPins->LCD_enu_C_Pins[i],DIO_u8_HIGH);
        // DIO_setPinAsPullUp(Add_pstrPortsPins->LCD_enu_R_Ports[i],Add_pstrPortsPins->LCD_enu_R_Pins[i]);
    }

    //Separate cuz they might be of different dimensions
    for(u8 i =0;i<KEYPAD_NUMBER_OF_ROWS;i++)
    {
        DIO_setPinAsPullUp(Add_pstrPortsPins->LCD_enu_R_Ports[i],Add_pstrPortsPins->LCD_enu_R_Pins[i]);
    }
}

void KEYPAD_vidGetPressedKey(KEYPAD_tstrPortsPins* Add_pstrPortsPins, u8* inpCar)
{
    u8 whoIsPressed=0;
    u8 should_I_End=0;
    u8 myCar=0;
    *inpCar=1;
     for(u8 i = 0 ; i<KEYPAD_NUMBER_OF_COLS;i++)
    {
        DIO_enuSetOutputPinValue(Add_pstrPortsPins->LCD_enu_C_Ports[i],Add_pstrPortsPins->LCD_enu_C_Pins[i],DIO_u8_LOW);
        for(u8 j=0;j<KEYPAD_NUMBER_OF_ROWS;j++)
        {
            DIO_enuGetInputPinValue(Add_pstrPortsPins->LCD_enu_R_Ports[j],Add_pstrPortsPins->LCD_enu_R_Pins[j], &myCar);
            if(myCar==1)
            {
                whoIsPressed=KEYPAD_2D_goodArray[i][j];
                // if(whoIsPressed==R1C1)
                *inpCar=3;
                // else *inpCar=6;
                should_I_End=1;
                break;
            }
            else{
                *inpCar=7;
            }

            if(whoIsPressed==R2C2)
                *inpCar=1;
            else *inpCar=6;

        }
        DIO_enuSetOutputPinValue(Add_pstrPortsPins->LCD_enu_C_Ports[i],Add_pstrPortsPins->LCD_enu_C_Pins[i],DIO_u8_HIGH);
        if(should_I_End) break;
    }

}

void keypad_main()
{
    // u8 inpCar=0;
    // u8 whoIsPressed=0;
    // u8 should_I_End=0;

    // for(u8 i = 0 ; i<KEYPAD_NUMBER_OF_COLS;i++)
    // {
    //     DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[i],Add_pstrPortsPins.LCD_enu_C_Pins[i],DIO_u8_LOW);
    //     for(u8 j=0;j<KEYPAD_NUMBER_OF_ROWS;j++)
    //     {
    //         if(DIO_enuGetInputPinValue(Add_pstrPortsPins.LCD_enu_R_Ports[j],Add_pstrPortsPins.LCD_enu_R_Pins[j],&inpCar)==)
    //         {
    //             whoIsPressed=KEYPAD_goodArray[i][j];
    //             shouldMyWhileEnd=1;
    //             break;
    //         }

    //     }
    //     DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[i],Add_pstrPortsPins.LCD_enu_C_Pins[i],DIO_u8_HIGH);
    //     if(should_I_End) break;
    // }

        //Hard Code:::::::::::::::::::Don't try this at homeXD
        // //C1
        // DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[0],Add_pstrPortsPins.LCD_enu_C_Pins[0],DIO_u8_LOW);
        // DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[1],Add_pstrPortsPins.LCD_enu_C_Pins[1],DIO_u8_HIGH);
        // DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[2],Add_pstrPortsPins.LCD_enu_C_Pins[2],DIO_u8_HIGH);
        // DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[3],Add_pstrPortsPins.LCD_enu_C_Pins[3],DIO_u8_HIGH);
        // //read R pins:::: 
        // // u8 inpCar=0;
        // // u8 whoIsPressed=0;
        // if(DIO_enuGetInputPinValue(Add_pstrPortsPins.LCD_enu_R_Ports[0],Add_pstrPortsPins.LCD_enu_R_Pins[0],&inpCar)== DIO_u8_LOW) whoIsPressed='1';
        // else if(DIO_enuGetInputPinValue(Add_pstrPortsPins.LCD_enu_R_Ports[1],Add_pstrPortsPins.LCD_enu_R_Pins[1],&inpCar)== DIO_u8_LOW) whoIsPressed='4';
        // else if(DIO_enuGetInputPinValue(Add_pstrPortsPins.LCD_enu_R_Ports[2],Add_pstrPortsPins.LCD_enu_R_Pins[2],&inpCar)== DIO_u8_LOW) whoIsPressed='7';
        // else if(DIO_enuGetInputPinValue(Add_pstrPortsPins.LCD_enu_R_Ports[3],Add_pstrPortsPins.LCD_enu_R_Pins[3],&inpCar)== DIO_u8_LOW) whoIsPressed='-';
        // //C2
        // DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[0],Add_pstrPortsPins.LCD_enu_C_Pins[0],DIO_u8_HIGH);
        // DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[1],Add_pstrPortsPins.LCD_enu_C_Pins[1],DIO_u8_LOW);
        // DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[2],Add_pstrPortsPins.LCD_enu_C_Pins[2],DIO_u8_HIGH);
        // DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[3],Add_pstrPortsPins.LCD_enu_C_Pins[3],DIO_u8_HIGH);
        // //read R pins:::: 
        // if(DIO_enuGetInputPinValue(Add_pstrPortsPins.LCD_enu_R_Ports[0],Add_pstrPortsPins.LCD_enu_R_Pins[0],&inpCar)== DIO_u8_LOW) whoIsPressed=R1C2;
        // else if(DIO_enuGetInputPinValue(Add_pstrPortsPins.LCD_enu_R_Ports[1],Add_pstrPortsPins.LCD_enu_R_Pins[1],&inpCar)== DIO_u8_LOW) whoIsPressed=R2C2;
        // else if(DIO_enuGetInputPinValue(Add_pstrPortsPins.LCD_enu_R_Ports[2],Add_pstrPortsPins.LCD_enu_R_Pins[2],&inpCar)== DIO_u8_LOW) whoIsPressed=R3C2;
        // else if(DIO_enuGetInputPinValue(Add_pstrPortsPins.LCD_enu_R_Ports[3],Add_pstrPortsPins.LCD_enu_R_Pins[3],&inpCar)== DIO_u8_LOW) whoIsPressed=R4C2;
        // //C3
        // DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[0],Add_pstrPortsPins.LCD_enu_C_Pins[0],DIO_u8_HIGH);
        // DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[1],Add_pstrPortsPins.LCD_enu_C_Pins[1],DIO_u8_HIGH);
        // DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[2],Add_pstrPortsPins.LCD_enu_C_Pins[2],DIO_u8_LOW);
        // DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[3],Add_pstrPortsPins.LCD_enu_C_Pins[3],DIO_u8_HIGH);
        // //read R pins:::: 
        // if(DIO_enuGetInputPinValue(Add_pstrPortsPins.LCD_enu_R_Ports[0],Add_pstrPortsPins.LCD_enu_R_Pins[0],&inpCar)== DIO_u8_LOW) whoIsPressed=R1C3;
        // else if(DIO_enuGetInputPinValue(Add_pstrPortsPins.LCD_enu_R_Ports[1],Add_pstrPortsPins.LCD_enu_R_Pins[1],&inpCar)== DIO_u8_LOW) whoIsPressed=R2C3;
        // else if(DIO_enuGetInputPinValue(Add_pstrPortsPins.LCD_enu_R_Ports[2],Add_pstrPortsPins.LCD_enu_R_Pins[2],&inpCar)== DIO_u8_LOW) whoIsPressed=R3C3;
        // else if(DIO_enuGetInputPinValue(Add_pstrPortsPins.LCD_enu_R_Ports[3],Add_pstrPortsPins.LCD_enu_R_Pins[3],&inpCar)== DIO_u8_LOW) whoIsPressed=R4C3;
        // //C4
        // DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[0],Add_pstrPortsPins.LCD_enu_C_Pins[0],DIO_u8_HIGH);
        // DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[1],Add_pstrPortsPins.LCD_enu_C_Pins[1],DIO_u8_HIGH);
        // DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[2],Add_pstrPortsPins.LCD_enu_C_Pins[2],DIO_u8_HIGH);
        // DIO_enuSetOutputPinValue(Add_pstrPortsPins.LCD_enu_C_Ports[3],Add_pstrPortsPins.LCD_enu_C_Pins[3],DIO_u8_LOW);
        // //read R pins:::: 
        // if(DIO_enuGetInputPinValue(Add_pstrPortsPins.LCD_enu_R_Ports[0],Add_pstrPortsPins.LCD_enu_R_Pins[0],&inpCar)== DIO_u8_LOW) whoIsPressed=R1C4;
        // else if(DIO_enuGetInputPinValue(Add_pstrPortsPins.LCD_enu_R_Ports[1],Add_pstrPortsPins.LCD_enu_R_Pins[1],&inpCar)== DIO_u8_LOW) whoIsPressed=R2C4;
        // else if(DIO_enuGetInputPinValue(Add_pstrPortsPins.LCD_enu_R_Ports[2],Add_pstrPortsPins.LCD_enu_R_Pins[2],&inpCar)== DIO_u8_LOW) whoIsPressed=R3C4;
        // else if(DIO_enuGetInputPinValue(Add_pstrPortsPins.LCD_enu_R_Ports[3],Add_pstrPortsPins.LCD_enu_R_Pins[3],&inpCar)== DIO_u8_LOW) whoIsPressed=R4C4;

    // _delay_ms(1000);     //

}