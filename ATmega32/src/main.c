// #include "../Applications/test.c"
// #include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LED/LED_int.h"
#include "../HAL/7SEG/SEG7_int.h"
#include "../HAL/DIG4_SEG7/DIG4_SEG7_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/KEYPAD/KEYPAD_int.h"
#include <avr/io.h>
#include <avr/interrupt.h>
// #include <avr/delay.h>
#include <util/delay.h>
#include <avr/interrupt.h>
// void Command(u8 cmnd)
// {
//     PORTB=cmnd;
//     PORTA1=
// }
int main()
{
    // ISR
    // test();
    
    // DIO_enuSetPortDirection(DIO_enuPORTC,DIO_u8_OUTPUT);
    // // DIO_enuSetPortDirection(DIO_enuPORTD,DIO_u8_OUTPUT);
    // DIO_enuSetPortDirection(DIO_enuPORTD,DIO_u8_INPUT);
    // DIO_enuSetPinDirection(DIO_enuPORTD,DIO_enuPIN0,DIO_u8_OUTPUT);
    // // DDRC=0xff;
    // // DIO_enuSetOutputPortValues(DIO_enuPORTD,1);
    // DIO_enuSetOutputPinValue(DIO_enuPORTD, PIN0, 0);

    SEG_strPortsPins main_str = 
        {
            {DIO_enuPORTC,
            DIO_enuPORTC,
            DIO_enuPORTC,
            DIO_enuPORTC,
            DIO_enuPORTC,
            DIO_enuPORTC,
            DIO_enuPORTC} , 
            {
                DIO_enuPIN0, 
                DIO_enuPIN1, 
                DIO_enuPIN2, 
                DIO_enuPIN3, 
                DIO_enuPIN4, 
                DIO_enuPIN5, 
                DIO_enuPIN6, 
            }
        };

        // SEG_strPortsPinsFourDig dig4 =
        // {
        //     {DIO_enuPORTD,
        //     DIO_enuPORTD,
        //     DIO_enuPORTD,
        //     DIO_enuPORTD}  , 

        //     {
        //         PIN0,
        //         PIN1,
        //         PIN2,
        //         PIN3
        //     }
        // };
        SEG_strPortsPinsTwoDigitSegments dig2 =
        {
            {DIO_enuPORTD,
            DIO_enuPORTD,} 
             , 

            {
                PIN0,
                PIN1
            }
        };

        DIO_tenuPorts lcd_D_ports[8]={DIO_enuPORTB,DIO_enuPORTB,DIO_enuPORTB,DIO_enuPORTB,DIO_enuPORTB,DIO_enuPORTB,DIO_enuPORTB,DIO_enuPORTB};
        DIO_tenuPins lcd_D_pins[8]= {DIO_enuPIN0,DIO_enuPIN1,DIO_enuPIN2,DIO_enuPIN3,DIO_enuPIN4,DIO_enuPIN5,DIO_enuPIN6,DIO_enuPIN7};

        LCD_tstrPortsPins lcd=
        {
            //D ports
            // lcd_D_ports,
            {DIO_enuPORTB,DIO_enuPORTB,DIO_enuPORTB,DIO_enuPORTB,DIO_enuPORTB,DIO_enuPORTB,DIO_enuPORTB,DIO_enuPORTB},
            //D_pins
            // lcd_D_pins,
            {DIO_enuPIN0,DIO_enuPIN1,DIO_enuPIN2,DIO_enuPIN3,DIO_enuPIN4,DIO_enuPIN5,DIO_enuPIN6,DIO_enuPIN7},

            //Rs Port
            DIO_enuPORTA,
            //Rs pin
            DIO_enuPIN0,
            
            //Rw Port
            DIO_enuPORTA,
            //Rw pin
            DIO_enuPIN1,
            
            //E Port
            DIO_enuPORTA,
            //E pin
            DIO_enuPIN7,
        };

        // LCD_enuInit(&lcd);

        // LCD_enuSendChar(&lcd,'a');

        u8 testingVar=0;

        // DIO_enuSetPortDirection(DIO_enuPORTA,DIO_u8_OUTPUT);
        // DIO_enuSetOutputPortValues(DIO_enuPORTA,DIO_u8_LOW);
        // DIO_enuSetPortDirection(DIO_enuPORTB,DIO_u8_OUTPUT);
        // DIO_enuSetOutputPortValues(DIO_enuPORTB,DIO_u8_LOW);




        // DDRD=0xff;
        // PORTD=0xff;

        // PORTA=0;

        DIO_enuSetPortDirection(DIO_enuPORTA,DIO_u8_OUTPUT);
        DIO_enuSetOutputPortValues(DIO_enuPORTA,DIO_u8_LOW);
        DIO_enuSetPortDirection(DIO_enuPORTB,DIO_u8_OUTPUT);
        // DIO_enuSetOutputPortValues(DIO_enuPORTB,DIO_u8_LOW);



    // while(1)
    // {
        // for(u8 i = 0 ; i <8 ; i++)
        // {
        //     // DIO_enuSetOutputPinValue(DIO_enuPORTC, i, 1);
        //     // PORTC= 1<<i;
        //     // _delay_ms(500);
        //     // DIO_enuSetOutputPinValue(DIO_enuPORTC, i, 0);
        // } 
        
        // DIO_enuSetOutputPortValues(DIO_enuPORTC,0b00000000);
        // _delay_ms(500);
        // DIO_enuSetOutputPortValues(DIO_enuPORTC,0b11111111);
        // _delay_ms(500);

        // DIO_enuSetOutputPinValue(DIO_enuPORTC,2,1);
        // _delay_ms(500);

        // DIO_enuSetOutputPinValue(DIO_enuPORTC,2,0);
        // DIO_enuSetOutputPortValues(DIO_enuPORTC,0b00000000);
        
        // _delay_ms(500);

        // for (u8 i = 0 ; i< 8 ; i ++)
        // {
        //     LED_enuBlink(DIO_enuPORTC, i, 100 , 5);
        // }

        // LED_enuToggle(DIO_enuPORTC, 2);
        // _delay_ms(300);

        // for(u8 i = 0 ; i<10 ; i++)
        // {
        //     SEG_enuViewNumber(&main_str,i);
        //     _delay_ms(400);
        // }

        // SEG_enuCountUp(&main_str , 0 , 5);
        // SEG_enuCountDown(&main_str , 9 , 4);

        // SEG_enuViewNumber(&main_str, 1);
        // _delay_ms(500);
        // SEG_enuIncrement(&main_str);
        // _delay_ms(500);


        // SEG_enuViewNumber(&main_str, 50);

        // SEG_enuFourDigitCounterUpZeroTo9999(&main_str, &dig4);

        // SEG_enuCountZeroToNinetyNine(&main_str,&main_str,&dig2);

        // DIO_enuSetOutputPinValue(dig2.enuPorts2[1],dig2.enuPins2[1],DIO_u8_HIGH);
        // DIO_enuSetOutputPinValue(dig2.enuPorts2[0],dig2.enuPins2[0],DIO_u8_LOW);
        // SEG_enuViewNumber(&main_str,5);
        // SEG_enuCountUp(&main_str,0,9);

        // DIO_enuSetOutputPinValue(dig2.enuPorts2[0],dig2.enuPins2[0],DIO_u8_HIGH);
        // DIO_enuSetOutputPinValue(dig2.enuPorts2[1],dig2.enuPins2[1],DIO_u8_HIGH);

        // Test LCD
        // SEG_enuViewChar(&main_str,65);
        // LCD_enuSendChar(&lcd,65,testingVar);
        // _delay_ms(1000);

        // LCD_tenuErrorStatus errorLcd = LCD_enuSendChar(&lcd,65,&testingVar);
        // if(errorLcd==LCD_NOK) SEG_enuViewNumber(&main_str,7);
        // else
        // {
        //     SEG_tenuErrorStatus errorSeg = SEG_enuViewNumber(&main_str,4);
        //     _delay_ms(1000);
        //     SEG_enuViewNumber(&main_str,5);
        //     _delay_ms(1000);
        //     SEG_enuViewNumber(&main_str,4);
        //     _delay_ms(1000);
        //     if(errorSeg==SEG_NOK) SEG_enuViewNumber(&main_str,9);
        //     else SEG_enuViewNumber(&main_str,2);
        //     _delay_ms(1000);
        // }


        //***************LCD TRIAL HARD CODE***********************
//         _delay_ms(50); //30
//         DIO_enuSetOutputPinValue(lcd.Rs_Port,lcd.Rs_Pin,DIO_u8_LOW);
//         DIO_enuSetOutputPinValue(lcd.Rw_Port,lcd.Rw_Pin,DIO_u8_LOW);
//         // DIO_enuSetOutputPortValues(DIO_enuPORTB,0b00111100);
//         LCD_enuSendInstruction(&lcd,0b00111100);                  //WORKING
//         // LCD_enuSendInstruction(&lcd,0b00111000);                //WORKING

//         // LCD_enuSendInstruction(&lcd,0x38);      //online
// DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
// _delay_us(2);
// DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_LOW);
// _delay_us(100);
// DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
//         // _delay_ms(50000);

//         // _delay_ms(2000);

//         /* DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
//         DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_LOW);
//         DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH); */
//         _delay_us(50);
//         // DIO_enuSetOutputPinValue(lcd.Rs_Port,lcd.Rs_Pin,DIO_u8_LOW);
//         // DIO_enuSetOutputPinValue(lcd.Rw_Port,lcd.Rw_Pin,DIO_u8_LOW);

//         DIO_enuSetOutputPortValues(DIO_enuPORTB,0b00001111);
//         // DIO_enuSetOutputPortValues(DIO_enuPORTB,0b00001100);
//         // LCD_enuSendInstruction(&lcd,0x0C);      //online

// DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
// _delay_us(2);

// DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_LOW);
// _delay_us(100);
// DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
//         // _delay_ms(2000);


//         /* DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
//         DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_LOW);
//         DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH); */

//         // DIO_enuSetOutputPortValues(DIO_enuPORTB,0b0001100); ///int
// //INSERTED FROM DOWN
//         _delay_ms(2);


//         DIO_enuSetOutputPortValues(DIO_enuPORTB,0b0000110);


//         _delay_us(50);
// //INSERTED FROM DOWN end

        
//         // DIO_enuSetOutputPortValues(DIO_enuPORTB,0b0000110);  //int
//         // _delay_us(50);

//         // DIO_enuSetOutputPortValues(DIO_enuPORTB,0b0000001);

//         DIO_enuSetOutputPortValues(DIO_enuPORTB,0b0000001);
//         // DIO_enuSetOutputPortValues(DIO_enuPORTB,0b0000111);
//         // LCD_enuSendInstruction(&lcd,0x06);      //online

// DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
// _delay_us(2);
// DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_LOW);
// _delay_us(100);
// DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
//         // _delay_ms(2000);


//        /* DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
//         DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_LOW);
//         DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH); */
//     // _delay_ms(2);


//     // DIO_enuSetOutputPortValues(DIO_enuPORTB,0b0000110);
//         // LCD_enuSendInstruction(&lcd,0x01);      //online

// DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
// _delay_us(2);
// DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_LOW);
// _delay_us(100);
// DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
//         // _delay_ms(2000);


//         /* DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
//         DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_LOW);
//         DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH); */
//         _delay_ms(1);

//         //take it to first address of DDRAM
//         // LCD_enuSendInstruction(&lcd,0b01000000);
//         // _delay_ms(50000);


//         //*************ONLY ONLINE
//         // LCD_enuSendInstruction(&lcd,0x80);      //online
//         // DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
//         // _delay_ms(1);
//         // DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_LOW);
//         // _delay_ms(1);
//         // DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
//         // _delay_ms(1);





//         //send data

//         DIO_enuSetOutputPinValue(lcd.Rs_Port,lcd.Rs_Pin,DIO_u8_HIGH);
//         DIO_enuSetOutputPinValue(lcd.Rs_Port,lcd.Rw_Pin,DIO_u8_LOW);
//         // DIO_enuSetOutputPortValues(DIO_enuPORTB,65);


//         //go to first pos
//         LCD_enuSendInstruction(&lcd,0x80+1);
//         while(1)
//         {
//         LCD_enuSendChar(&lcd,67,&testingVar);             //WORKING
//         // _delay_ms(50000);

//         DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
//         _delay_us(2);
//         DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_LOW);
//         _delay_us(100);
//         DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
            
//         }

        // DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
        //***************LCD TRIAL HARD CODE END***********************


        // LCD_enuInit(&lcd);
        // // LCD_enuSendInstruction(&lcd,0x01);
        // // LCD_enuGoTo(&lcd,1,4);
        // LCD_enuSendData(&lcd,64,&testingVar);
        // LCD_enuSendData(&lcd,9,&testingVar);
        // while(1)
        // {
        //     LCD_enuSendData(&lcd,64,&testingVar);

        // }







        // DIO_enuSetOutputPinValue(lcd.Rs_Port,lcd.Rs_Pin,DIO_u8_HIGH);
        // DIO_enuSetOutputPinValue(lcd.Rw_Port,lcd.Rw_Pin,DIO_u8_LOW);

        // DIO_enuSetOutputPinValue(lcd.D_Ports[0],lcd.D_Pins[0],DIO_u8_HIGH);
        // DIO_enuSetOutputPinValue(lcd.D_Ports[1],lcd.D_Pins[1],DIO_u8_LOW);
        // DIO_enuSetOutputPinValue(lcd.D_Ports[2],lcd.D_Pins[2],DIO_u8_LOW);
        // DIO_enuSetOutputPinValue(lcd.D_Ports[3],lcd.D_Pins[3],DIO_u8_LOW);
        // DIO_enuSetOutputPinValue(lcd.D_Ports[4],lcd.D_Pins[4],DIO_u8_LOW);
        // DIO_enuSetOutputPinValue(lcd.D_Ports[5],lcd.D_Pins[5],DIO_u8_LOW);
        // DIO_enuSetOutputPinValue(lcd.D_Ports[6],lcd.D_Pins[6],DIO_u8_HIGH);
        // DIO_enuSetOutputPinValue(lcd.D_Ports[7],lcd.D_Pins[7],DIO_u8_LOW);

        // DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
        // DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_LOW);
        // DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);

        
        
        // _delay_ms(10);
        // DDRA =0b00000000;

        // DIO_enuSetOutputPinValue(DIO_enuPORTA,DIO_enuPIN6,DIO_u8_HIGH);
        // _delay_ms(500);
        // DIO_enuSetOutputPinValue(DIO_enuPORTA,DIO_enuPIN6,DIO_u8_LOW);
        // _delay_ms(1000);
    // }



    //KEYPAD:
    // DIO_enuSetPortDirection(DIO_enuPORTD,DIO_u8_OUTPUT);
    // DIO_enuSetOutputPortValues(DIO_enuPORTD,DIO_u8_LOW);
    // DIO_enuSetPortDirection(DIO_enuPORTC,DIO_u8_OUTPUT);
    // DIO_enuSetOutputPortValues(DIO_enuPORTC,DIO_u8_LOW);

    // KEYPAD_tstrPortsPins keypad=
    // {
    //     //C
    //     {DIO_enuPORTD, DIO_enuPORTD, DIO_enuPORTD, DIO_enuPORTD},
    //     {DIO_enuPIN4,DIO_enuPIN5,DIO_enuPIN6,DIO_enuPIN7},
    //     //R
    //     {DIO_enuPORTD, DIO_enuPORTD, DIO_enuPORTD, DIO_enuPORTD},
    //     {DIO_enuPIN0,DIO_enuPIN1,DIO_enuPIN2,DIO_enuPIN3}

    // };
    // u8 inpCar=0;

    // KEYPAD_vidInit(&keypad);


   


    // while(1)
    // {

    //     KEYPAD_vidGetPressedKey(&keypad,&inpCar);

    //     SEG_enuViewNumber(&main_str,inpCar);
    //     // _delay_ms(100);

    //     // DIO_enuSetOutputPinValue(DIO_enuPORTA,DIO_enuPIN6,DIO_u8_HIGH);
    //     // _delay_ms(1000);
    //     // DIO_enuSetOutputPinValue(DIO_enuPORTA,DIO_enuPIN6,DIO_u8_LOW);
    //     // _delay_ms(1000);
    //     // LCD_enuSendChar(&lcd,65,testingVar);             //WORKING
    //     // // _delay_ms(50000);

    //     // DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);
    //     // _delay_us(2);
    //     // DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_LOW);
    //     // _delay_us(100);
    //     // DIO_enuSetOutputPinValue(lcd.E_Port,lcd.E_Pin,DIO_u8_HIGH);


    // }

    //PWM:: 
    //fast pwm
    DIO_enuSetOutputPinValue(DIO_enuPORTB,PIN2,DIO_u8_HIGH);
    TCCR0|=0x48;
    //inverting pwm
    TCCR0|=0x30;
    //value to compare
    OCR0=0xff;
    //prescalar
    TCCR0|=0x01;
    while(1)
    {
        OCR0-=10;
        // SEG_enuCountZeroToNinetyNine(&main_str,&main_str,&dig2);
        // DIO_enuSetOutputPinValue(dig2.enuPorts2[0],dig2.enuPins2[0],DIO_u8_HIGH);
        // SEG_enuCountUp(&main_str,0,3);
        _delay_ms(100);
        // 0b00010100
    }





    return 0;


    ///Stepper

    // DIO_tenuPorts bluePort=DIO_enuPORTB;
    // DIO_tenuPorts pinkPort=DIO_enuPORTB;
    // DIO_tenuPorts yellowPort=DIO_enuPORTB;
    // DIO_tenuPorts orangePort=DIO_enuPORTB;

    // DIO_tenuPins bluePin=DIO_enuPIN4;
    // DIO_tenuPins pinkPin=DIO_enuPIN5;
    // DIO_tenuPins yellowPin=DIO_enuPIN6;
    // DIO_tenuPins orangePin=DIO_enuPIN7;
    // //set themm output 
    // DIO_enuSetPortDirection(DIO_enuPORTA,DIO_u8_OUTPUT);
    // DIO_enuSetOutputPortValues(DIO_enuPORTA,DIO_u8_LOW_AL);
    // //set them low   done above

    // //fullStep()::::::::::::::::::::::::::::::::::::: strideHalf(5.625/64) ->full ((5.625*2/64)) deg
    // //Clockwise ... anticlockwise? reverse it.

    // float minorStepAgle = 0.17578125;
    // float majorStepAngle= 4*minorStepAgle; 
    // //better loop on an array
    // DIO_enuSetOutputPinValue(bluePort,bluePin,DIO_u8_HIGH_AL);
    // _delay_ms(10);
    // DIO_enuSetOutputPinValue(bluePort,bluePin,DIO_u8_LOW_AL);
    // _delay_ms(10);

    // DIO_enuSetOutputPinValue(pinkPort,pinkPin,DIO_u8_HIGH_AL);
    // _delay_ms(10);
    // DIO_enuSetOutputPinValue(pinkPort,pinkPin,DIO_u8_LOW_AL);
    // _delay_ms(10);

    // DIO_enuSetOutputPinValue(yellowPort,yellowPin,DIO_u8_HIGH_AL);
    // _delay_ms(10);
    // DIO_enuSetOutputPinValue(yellowPort,yellowPin,DIO_u8_LOW_AL);
    // _delay_ms(10);

    // DIO_enuSetOutputPinValue(orangePort,orangePin,DIO_u8_HIGH_AL);
    // _delay_ms(10);
    // DIO_enuSetOutputPinValue(orangePort,orangePin,DIO_u8_LOW_AL);
    // _delay_ms(10);  //after each step //to cope with stepper frequency


    //rotateWithAngle()
    //for range(desiredAngle/majorStepAngle)   512 iterations for 360 deg
}


//Interrupt
/*
 
#include <avr/interrupt.h>
ISR(INT1_eg)
{
    //implementation
}

global interrupt driver: enable(), disable()

external interrupt: 
    enable(INTpin,sourceType)
    disable(INTpin)
    ISR(INT1)
    ISR(INT2)
    ISR(INT0)

//ISR ::::: ==== :::::
void vector(void)__attribute_((signal,used));
__vector_[somenumber=interrupt index at the vector table (vector number of datasheet - 1)](void)
__attribute__ ((signal,used)) :: telling tool chain to keep it although it thinks it is not used....

search for:     ##      in macros

let ISRs in a cfg file to be adjustable....

search for:  callback function and pointers to functions.

*/

//install Protus and try to simulate using it


//ADC
/* 
ADC::::::


//Counter   GPT:
init()
startTimer(#timer, time_ms)
stopTimer(#timer)
setMode(#timer,mode,compareValueforCTC)  //(optional)
registerCallbackFunc(#timer,func*)  //instead of functions in cfg.c file (optional)
3 ISRs, one for each timer

//servo:: 
init()
setAngle()


//pwm:
init
setMode() // fast or C
startPWM() //generate pwm sig


*/

/* 
    SPI::
    #19 in the datasheet
    masterInit(freq, clkphase,clkpol,dataorder)
    {
        assign inputs to their places
        enable spi
    }
    slaveInit()
    Trancieve(u8 data)

*/

/*  
    I2C:: 
    notes::
    you always clr flag then wait for it then decide ur status
        TWCR:: TWEN_bit=1
        TWCR:: TWEA_bit=1
        TWCR:: TWSTA=1 .. Clr Flag TWINT

    functions::
    init(mode,myaddress)
    {
        //set mdoe
        //set freq if master
        //enable TWEN
        //store myaddress (<<1) at addres reg 
    }

    sendStart()
    {
        //TWSTA=1 ,,
        // clrFlg TWINT
        // wait for flg
        //read flg 
    }
    sendStop()
    {
        //TWSTO=1 ,, clrFlg TWINT
        //wait flg
        //read status reg
    }

    sendRepeatedStart()
    {
        //do
        //clr flg
    }

    sendSlaveAddress(address, rw)
    {
        // clr TWSTA
        // write address and rw
        // clr flg
        // wait for flg
        // read statreg (TWSR(7:3))
    }

    sendData(u8 data)
    {
        // TWDR=data
        // clr flg
        // wait for flg
        // read stat
    }

*/












 //