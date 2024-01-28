#pragma once

//GICR:: general interrupt control register
#define INT_u8_GICR (*(volatile u8*) 0x5B)
#define INT_u8_GICR_INT1_BIT 7
#define INT_u8_GICR_INT0_BIT 6
#define INT_u8_GICR_INT2_BIT 5

#define INT_u8_GIFR (*(volatile u8*) 0x5A)
#define INT_u8_GIFR_INTF1_BIT 7
#define INT_u8_GIFR_INTF0_BIT 6
#define INT_u8_GIFR_INTF2_BIT 5

#define INT_u8_SREG (*(volatile u8*) 0x5F)
#define INT_u8_SREG_GIE_BIT 7

#define INT_u8_MCUCR_REG (*(volatile u8*) 0x55)
#define INT_u8_MCUCR_ISC00_BIT 0
#define INT_u8_MCUCR_ISC01_BIT 1
#define INT_u8_MCUCR_ISC10_BIT 2
#define INT_u8_MCUCR_ISC11_BIT 3

#define INT_u8_MCUCSR_REG (*(volatile u8*) 0x54)
#define INT_u8_MCUSCR_ISC2_BIT 6
