#include "SPI_int.h"

#define SPI_u8_SPCR_REG (*(volatile u8*) 0x2D)
#define SPI_SPCR_SPR0_BIT 0
#define SPI_SPCR_SPR1_BIT 1
#define SPI_SPCR_CPHA_BIT 2
#define SPI_SPCR_CPOL_BIT 3
#define SPI_SPCR_MSTR_BIT 4
#define SPI_SPCR_DORD_BIT 5
#define SPI_SPCR_SPE_BIT 6
#define SPI_SPCR_SPIE_BIT 7


#define SPI_u8_SPSR_REG (*(volatile u8*) 0x2E)
#define SPI_SPSR_SPI2X_BIT 0
// Bit 1:5 are reserved and always 0
#define SPI_SPSR_WCOL_BIT 6
#define SPI_SPSR_SPIF_BIT 7

#define SPI_u8_SPDR_REG (*(volatile u8*) 0x2F)

