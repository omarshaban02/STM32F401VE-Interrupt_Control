/*
 * Exti_private.h
 *
 *  Created on: May 21, 2024
 *      Author: pc
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#include "Bit_Operations.h"
#include "Std_Types.h"
#include "Utils.h"
#include "NVIC.h"

#include <stddef.h>  // This includes the definition for NULL
#include <stdint.h>  // For uint8_t, uint16_t, etc.


#define EXTI_LINES 16   /* 0 -> 15*/

#define EXTI_BASE     0x40013C00
#define SYSCFG_BASE   0x40013800

// Define GPIO Ports
#define GPIOA 0
#define GPIOB 1
#define GPIOC 2
#define GPIOD 3
#define GPIOE 4
#define GPIOH 7

// EXTI Interrupt Request (IRQ) Numbers
#define EXTI0_IRQ       6   // External Interrupt 0
#define EXTI1_IRQ       7   // External Interrupt 1
#define EXTI2_IRQ       8   // External Interrupt 2
#define EXTI3_IRQ       9   // External Interrupt 3
#define EXTI4_IRQ       10  // External Interrupt 4
#define EXTI9_5_IRQ     23  // External Interrupts 5 to 9
#define EXTI15_10_IRQ   40 	// External Interrupts 10 to 15


#define FALLING_EDGE       		0
#define RISING_EDGE 			1
#define RISING_FALLING			2


#define EXTI_DISABLE				0
#define EXTI_ENABLE					1


typedef struct {
	uint32 IMR;
	uint32 EMR;
	uint32 RTSR;
	uint32 FTSR;
	uint32 SWIER;
	uint32 PR;
} ExtiType;


typedef struct{
	uint32 MEMRMP;
	uint32 PMC;
	uint32 EXTICR1;
	uint32 EXTICR2;
	uint32 EXTICR3;
	uint32 EXTICR4;
	uint32 CMPCR;
}SYSCFGtype;


// Define a struct for EXTI configuration
typedef struct {
    uint16 LINE;
    uint8  PORT;
    uint16 PIN;
    uint8  IRQ;
} EXTIConfig;


// Define enums for EXTI port and edge
typedef enum {
    EXTI_PORTA = GPIOA,
    EXTI_PORTB = GPIOB,
    EXTI_PORTC = GPIOC,
    EXTI_PORTD = GPIOD,
    EXTI_PORTE = GPIOE,
} EXTI_PORT;


typedef enum {
    EXTI_RISING_EDGE,
    EXTI_FALLING_EDGE,
    EXTI_RISING_FALLING_EDGES
} EXTI_Edge;

#endif /* EXTI_PRIVATE_H_ */
