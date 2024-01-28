#include "INT_int.h"
#include "INT_cfg.h"
void INT_vidGlobalEnable()
{
    SET_BIT(INT_u8_SREG,INT_u8_SREG_GIE_BIT);
}

void INT_vidGlobalDisable()
{
    CLR_BIT(INT_u8_SREG,INT_u8_SREG_GIE_BIT);
}

INT_tenuErrorStatus INT_EXT_enuExternalEnable(INT_tenuInterruptPins Copy_enuIntPin,INT_tenuTriggerSource Copy_enuTrigSrc)
{
    //Enable Global
    INT_vidGlobalEnable();
    //Set Source
    INT_EXT_setTriggerSource(Copy_enuIntPin,Copy_enuIntPin);
    //Enable desired ext interrupt
    switch(Copy_enuIntPin)
    {
        case INT_enuINT0:
            SET_BIT(INT_u8_GICR,INT_u8_GICR_INT0_BIT);
            break;
        case INT_enuINT1:
            SET_BIT(INT_u8_GICR,INT_u8_GICR_INT1_BIT);
            break;
        case INT_enuINT2:
            SET_BIT(INT_u8_GICR,INT_u8_GICR_INT2_BIT);
            break;
    }

}
INT_tenuErrorStatus INT_EXT_enuExternalDisable(INT_tenuInterruptPins Copy_enuIntPin)
{
    switch(Copy_enuIntPin)
    {
        case INT_enuINT0:
            CLR_BIT(INT_u8_GICR,INT_u8_GICR_INT0_BIT);
            break;
        case INT_enuINT1:
            CLR_BIT(INT_u8_GICR,INT_u8_GICR_INT1_BIT);
            break;
        case INT_enuINT2:
            CLR_BIT(INT_u8_GICR,INT_u8_GICR_INT2_BIT);
            break;
    }
}

INT_tenuErrorStatus INT_EXT_enuClearFlag(INT_tenuInterruptPins Copy_enuIntPin)
{
    //Note that falgs are cleared by writing logical 1 to it.
    switch (Copy_enuIntPin)
    {
    case INT_enuINT0:
        SET_BIT(INT_u8_GIFR,INT_u8_GIFR_INTF0_BIT);
        break;
    case INT_enuINT1:
        SET_BIT(INT_u8_GIFR,INT_u8_GIFR_INTF1_BIT);
        break;
    case INT_enuINT2:
        SET_BIT(INT_u8_GIFR,INT_u8_GIFR_INTF2_BIT);
        break;
    
    default:
        break;
    }
}

INT_tenuErrorStatus INT_EXT_setTriggerSource(INT_tenuInterruptPins Copy_enuIntPin,INT_tenuTriggerSource Copy_enuTrigSrc)
{
    switch(Copy_enuIntPin)
    {
        case 0:
            switch(Copy_enuTrigSrc)
            {
                case INT_enuLowLevel:
                    CLR_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC00_BIT);
                    CLR_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC01_BIT);
                break;

                case INT_enuOnChange:
                    SET_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC00_BIT);
                    CLR_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC01_BIT);
                break;

                case INT_enuFallingEdge:
                    CLR_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC00_BIT);
                    SET_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC01_BIT);
                break;

                case INT_enuRisingEdge:
                    SET_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC00_BIT);
                    SET_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC01_BIT);
                break;
            }
        break;
        case 1:
            switch(Copy_enuTrigSrc)
            {
                case INT_enuLowLevel:
                    CLR_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC10_BIT);
                    CLR_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC11_BIT);
                break;

                case INT_enuOnChange:
                    SET_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC10_BIT);
                    CLR_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC11_BIT);
                break;

                case INT_enuFallingEdge:
                    CLR_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC10_BIT);
                    SET_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC11_BIT);
                break;

                case INT_enuRisingEdge:
                    SET_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC10_BIT);
                    SET_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC11_BIT);
                break;

                default: //OnChange
                    SET_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC10_BIT);
                    CLR_BIT(INT_u8_MCUCR_REG,INT_u8_MCUCR_ISC11_BIT);
                break;
            }
        break;

        case 2:
            switch(Copy_enuTrigSrc)
            {
                case INT_enuRisingEdge:
                    SET_BIT(INT_u8_MCUCSR_REG,INT_u8_MCUSCR_ISC2_BIT);
                break;

                case INT_enuFallingEdge:
                    CLR_BIT(INT_u8_MCUCSR_REG,INT_u8_MCUSCR_ISC2_BIT);
                break;
            }
        break;

        default:  //Other INT not in {0,1,2}
            return INT_NOK;
        break; 
    }

}

// void __vector_#num (void)
void __vector_1(void) __attribute__((signal,used));  //for INT0
void __vector_1(void)
{
    cnfg_ISR0();
}
void __vector_2(void) __attribute__((signal,used));  //for INT1
void __vector_2(void)   //for INT1
{
    cnfg_ISR1();
}
void __vector_3(void) __attribute__((signal,used));  //for INT2
void __vector_3(void)   //for INT2
{
    cnfg_ISR2();
}