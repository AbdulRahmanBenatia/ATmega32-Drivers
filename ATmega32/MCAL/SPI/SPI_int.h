#include "../DIO/DIO_int.h"

#define SPI_u32TIMEOUT_VALUE 10000

typedef enum{
    SPI_enuMasterMode,
    SPI_enuSlaveMode,
}SPI_tenuMode;
typedef enum{
    SPI_enuRisingLeading = 0,
    SPI_enuFallingLeading = 1,
}SPI_tenuPolarity;
typedef enum{
    SPI_enuSampleLeading = 0,
    SPI_enuSetupLeading = 1,
}SPI_tenuPhase;
typedef enum{
    SPI_enuFirstMSB = 0,
    SPI_enuFirstLSB = 1,
}SPI_tenuDataOrder;
typedef enum{
    SPI_enuOscFreq_over_4   = 0,
    SPI_enuOscFreq_over_16  = 1,
    SPI_enuOscFreq_over_64  = 2,
    SPI_enuOscFreq_over_128 = 3,
    SPI_enuOscFreq_over_2   = 4,
    SPI_enuOscFreq_over_8   = 5,
    SPI_enuOscFreq_over_32  = 6,
    SPI_enuOscFreq_over_64  = 7,
}SPI_tenuClkFrequency;

typedef enum{
	SPI_OK,
	SPI_NOK,
    SPI_TIMEOUT
} SPI_tenuErrorStatus;

typedef struct{

    SPI_tenuMode Copy_enuMode;
    SPI_tenuPolarity Copy_enuPolarity;
    SPI_tenuPhase Copy_enuPhase;
    SPI_tenuDataOrder Copy_enuDataOrder;
    SPI_tenuClkFrequency Copy_enuDesiredFreq
} SPI_strInitConfigurations;





/* void SPI_vidInit(
                SPI_tenuMode Copy_enuMode,
                SPI_tenuPolarity Copy_enuPolarity =SPI_enuRisingLeading,
                SPI_tenuPhase Copy_enuPhase=SPI_enuSetupLeading,
                SPI_tenuDataOrder Copy_enuDataOrder=SPI_enuFirstMSB,
                SPI_tenuClkFrequency Copy_enuDesiredFreq=SPI_enuOscFreq_over_4
                ); */

SPI_tenuErrorStatus SPI_enuInit(SPI_strInitConfigurations * Ref_strConfg);

SPI_tenuErrorStatus SPI_enuTransceive(u8 Copy_u8_dataToSend,u8* Ref_u8_dataToRecieve);




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