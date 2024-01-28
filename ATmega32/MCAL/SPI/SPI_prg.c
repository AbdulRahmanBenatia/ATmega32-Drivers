#include "SPI_int.h"
#include "SPI_prv.h"
#include "../INTERRUPT/INT_int.h"
/* void SPI_vidInit(SPI_tenuMode Copy_enuMode,
                SPI_tenuPolarity Copy_enuPolarity =SPI_enuRisingLeading,
                SPI_tenuPhase Copy_enuPhase=SPI_enuSetupLeading,
                SPI_tenuDataOrder Copy_enuDataOrder=SPI_enuFirstMSB,
                SPI_tenuClkFrequency Copy_enuDesiredFreq=SPI_enuOscFreq_over_4)
    {

    } */

SPI_tenuErrorStatus SPI_enuInit(SPI_strInitConfigurations * Ref_strConfg)
{
    SPI_tenuErrorStatus Local_enuErrorStat= SPI_OK;
    if(Ref_strConfg==NULL || Ref_strConfg->Copy_enuMode==NULL)  //Mode input is a MUST
    {
        Local_enuErrorStat==SPI_NOK;
        return Local_enuErrorStat;
    }
    else
    {
        // #define Local_definedMode  (Ref_strConfg->Copy_enuMode)
        //Enable SPI
        SET_BIT(SPI_u8_SPCR_REG,SPI_SPCR_SPE_BIT);

        //enable interrupt
        INT_vidGlobalEnable();
        SET_BIT(SPI_u8_SPSR_REG,SPI_SPSR_SPIF_BIT);
        SET_BIT(SPI_u8_SPCR_REG,SPI_SPCR_SPIE_BIT);
        //Set mode: 
        Ref_strConfg->Copy_enuMode==SPI_enuMasterMode
        ?
            SET_BIT(SPI_u8_SPCR_REG,SPI_SPCR_MSTR_BIT)
            :
            CLR_BIT(SPI_u8_SPCR_REG,SPI_SPCR_MSTR_BIT);
        
        //Cannot use preprocessor dirs as it's dependent on the input
        // #if Local_definedMode==SPI_enuMasterMode
        // #endif

        //Assign some defaults
        if(Ref_strConfg->Copy_enuDataOrder==NULL) Ref_strConfg->Copy_enuDataOrder= SPI_enuFirstMSB;
        if(Ref_strConfg->Copy_enuPhase==NULL) Ref_strConfg->Copy_enuPhase=SPI_enuSetupLeading;
        if(Ref_strConfg->Copy_enuPolarity==NULL) Ref_strConfg->Copy_enuPolarity=SPI_enuRisingLeading;

        if(Ref_strConfg->Copy_enuMode==SPI_enuSlaveMode)
        {
            return Local_enuErrorStat; //done with configuratrion
        }

        else if (Ref_strConfg->Copy_enuMode==SPI_enuMasterMode)
        {
            if(Ref_strConfg->Copy_enuDesiredFreq==NULL) Ref_strConfg->Copy_enuDesiredFreq =SPI_enuOscFreq_over_32;

            //Now assign these values to their places in the registers
            Ref_strConfg->Copy_enuDataOrder==SPI_enuFirstLSB
            ?
                SET_BIT(SPI_u8_SPCR_REG,SPI_SPCR_DORD_BIT)
                :
                CLR_BIT(SPI_u8_SPCR_REG,SPI_SPCR_DORD_BIT);
            
            Ref_strConfg->Copy_enuPolarity==SPI_enuFallingLeading
            ?
                SET_BIT(SPI_u8_SPCR_REG,SPI_SPCR_CPOL_BIT)
                :
                CLR_BIT(SPI_u8_SPCR_REG,SPI_SPCR_CPOL_BIT);
            
            Ref_strConfg->Copy_enuPhase==SPI_enuSetupLeading
            ?
                SET_BIT(SPI_u8_SPCR_REG,SPI_SPCR_CPHA_BIT)
                :
                CLR_BIT(SPI_u8_SPCR_REG,SPI_SPCR_CPHA_BIT);
            
            //set frequency...
            (GET_BIT(Ref_strConfg->Copy_enuDesiredFreq, 2)==1)
            ?
                SET_BIT(SPI_u8_SPSR_REG,SPI_SPSR_SPI2X_BIT)
                :
                CLR_BIT(SPI_u8_SPSR_REG,SPI_SPSR_SPI2X_BIT);

            (GET_BIT(Ref_strConfg->Copy_enuDesiredFreq, 1)==1)
            ?
                SET_BIT(SPI_u8_SPCR_REG,SPI_SPCR_SPR1_BIT)
                :
                CLR_BIT(SPI_u8_SPCR_REG,SPI_SPCR_SPR1_BIT);

            (GET_BIT(Ref_strConfg->Copy_enuDesiredFreq, 0)==1)
            ?
                SET_BIT(SPI_u8_SPCR_REG,SPI_SPCR_SPR0_BIT)
                :
                CLR_BIT(SPI_u8_SPCR_REG,SPI_SPCR_SPR0_BIT);
        }
    }

    return Local_enuErrorStat;
}

SPI_tenuErrorStatus SPI_enuTransceive(u8 Copy_u8_dataToSend,u8* Ref_u8_dataToRecieve)
{
    SPI_tenuErrorStatus Local_enuErrorStat=DIO_OK;
    u32 Local_u32_timerTimeOut=0;
    SPI_u8_SPDR_REG=Copy_u8_dataToSend;
    while(!GET_BIT(SPI_u8_SPSR_REG,SPI_SPSR_SPIF_BIT) && Local_u32_timerTimeOut<SPI_u32TIMEOUT_VALUE)
    {
        Local_u32_timerTimeOut++;
    }
    if(Local_u32_timerTimeOut>=SPI_u32TIMEOUT_VALUE)
    {
        Local_enuErrorStat=SPI_TIMEOUT;
    }
    else
    {
    *Ref_u8_dataToRecieve = SPI_u8_SPDR_REG;
    }

    return Local_enuErrorStat;

}