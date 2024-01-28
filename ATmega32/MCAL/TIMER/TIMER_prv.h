#pragma once
#include "../../LIB/types.h"
#define TIMER_TCCR0_REG (*(volatile u8*)0x53)
#define TIMER_TCCR0_F0C0_BIT 7
#define TIMER_TCCR0_WGM00_BIT 6
#define TIMER_TCCR0_COM01_BIT 5
#define TIMER_TCCR0_COM00_BIT 4
#define TIMER_TCCR0_WGM01_BIT 3
#define TIMER_TCCR0_CS02_BIT 2
#define TIMER_TCCR0_CS01_BIT 1
#define TIMER_TCCR0_CS00_BIT 0


#define TIMER_TCCR1A_REG (*(volatile u8*) 0x4F)
#define TIMER_TCCR1A_COM1A1 7
#define TIMER_TCCR1A_COM1A1 7
#define TIMER_TCCR1A_COM1A1 7
#define TIMER_TCCR1A_COM1A1 7
#define TIMER_TCCR1A_COM1A1 7
#define TIMER_TCCR1A_COM1A1 7
#define TIMER_TCCR1A_COM1A1 7
#define TIMER_TCCR1A_COM1A1 7


#define TIMER_TCCR1B_REG (*(volatile u8*) 0x4E)


#define TIMER_TCCR2_REG  (*(volatile u8*) 0x45)


#define TIMER_TCNT0_REG  (*(volatile u8*) 0x52)
#define TIMER_TCNT1_REG  (*(volatile u16*) 0x4D)
#define TIMER_TCNT1H_REG (*(volatile u8*) 0x4D)
#define TIMER_TCNT1L_REG (*(volatile u8*) 0x4C)
#define TIMER_TCNT2_REG  (*(volatile u8*) 0x44)