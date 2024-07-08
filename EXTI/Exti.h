/*
 * Exti.h
 *
 *  Created on: May 21, 2024
 *      Author: pc
 */

#ifndef EXTI_H_
#define EXTI_H_

#include "Exti_private.h"

#define EXTI 		((ExtiType *)(EXTI_BASE))
#define SYSCFG 		(*(SYSCFGtype *)(SYSCFG_BASE))

// Define EXTI configurations
extern const uint32 EDGE_SELECT[3];

extern void (*EXTI_Callbacks[EXTI_LINES])(void);  // Array to hold callback functions

// Function Prototypes
void Exti_Init(EXTI_PORT portID, uint8 ExtiPin, EXTI_Edge edge);
void Exti_Deinit(uint8 ExtiPin);

void EXTI_Enable(uint16 Exti_line);
void EXTI_Disable(uint16 Exti_line);

void EXTI_RegisterCallback(uint16 Exti_line, void (*P_IRQ_Callback)(void));
void EXTI_IRQHandler(uint16 Exti_line);
void EXTI_PendingFlag(uint8 Exti_line);


#endif /* EXTI_H_ */
