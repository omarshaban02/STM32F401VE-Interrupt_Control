/*
 * Exti.c
 *
 *  Created on: May 21, 2024
 *      Author: Mahmoud
 */

#include "Exti.h"

void (*EXTI_Callbacks[EXTI_LINES])(void) = {0};


const EXTIConfig EXTI_Configurations[] = {
    {0, GPIOA, 0, EXTI0_IRQ}, {0, GPIOB, 0, EXTI0_IRQ}, {0, GPIOC, 0, EXTI0_IRQ}, {0, GPIOD, 0, EXTI0_IRQ},
    {1, GPIOA, 1, EXTI1_IRQ}, {1, GPIOB, 1, EXTI1_IRQ}, {1, GPIOC, 1, EXTI1_IRQ}, {1, GPIOD, 1, EXTI1_IRQ},
    {2, GPIOA, 2, EXTI2_IRQ}, {2, GPIOB, 2, EXTI2_IRQ}, {2, GPIOC, 2, EXTI2_IRQ}, {2, GPIOD, 2, EXTI2_IRQ},
    {3, GPIOA, 3, EXTI3_IRQ}, {3, GPIOB, 3, EXTI3_IRQ}, {3, GPIOC, 3, EXTI3_IRQ}, {3, GPIOD, 3, EXTI3_IRQ},
    {4, GPIOA, 4, EXTI4_IRQ}, {4, GPIOB, 4, EXTI4_IRQ}, {4, GPIOC, 4, EXTI4_IRQ}, {4, GPIOD, 4, EXTI4_IRQ},
    {5, GPIOA, 5, EXTI9_5_IRQ}, {5, GPIOB, 5, EXTI9_5_IRQ}, {5, GPIOC, 5, EXTI9_5_IRQ}, {5, GPIOD, 5, EXTI9_5_IRQ},
    {6, GPIOA, 6, EXTI9_5_IRQ}, {6, GPIOB, 6, EXTI9_5_IRQ}, {6, GPIOC, 6, EXTI9_5_IRQ}, {6, GPIOD, 6, EXTI9_5_IRQ},
    {7, GPIOA, 7, EXTI9_5_IRQ}, {7, GPIOB, 7, EXTI9_5_IRQ}, {7, GPIOC, 7, EXTI9_5_IRQ}, {7, GPIOD, 7, EXTI9_5_IRQ},
    {8, GPIOA, 8, EXTI9_5_IRQ}, {8, GPIOB, 8, EXTI9_5_IRQ}, {8, GPIOC, 8, EXTI9_5_IRQ}, {8, GPIOD, 8, EXTI9_5_IRQ},
    {9, GPIOA, 9, EXTI9_5_IRQ}, {9, GPIOB, 9, EXTI9_5_IRQ}, {9, GPIOC, 9, EXTI9_5_IRQ}, {9, GPIOD, 9, EXTI9_5_IRQ},
    {10, GPIOA, 10, EXTI15_10_IRQ}, {10, GPIOB, 10, EXTI15_10_IRQ}, {10, GPIOC, 10, EXTI15_10_IRQ}, {10, GPIOD, 10, EXTI15_10_IRQ},
    {11, GPIOA, 11, EXTI15_10_IRQ}, {11, GPIOB, 11, EXTI15_10_IRQ}, {11, GPIOC, 11, EXTI15_10_IRQ}, {11, GPIOD, 11, EXTI15_10_IRQ},
    {12, GPIOA, 12, EXTI15_10_IRQ}, {12, GPIOB, 12, EXTI15_10_IRQ}, {12, GPIOC, 12, EXTI15_10_IRQ}, {12, GPIOD, 12, EXTI15_10_IRQ},
    {13, GPIOA, 13, EXTI15_10_IRQ}, {13, GPIOB, 13, EXTI15_10_IRQ}, {13, GPIOC, 13, EXTI15_10_IRQ}, {13, GPIOD, 13, EXTI15_10_IRQ},
    {14, GPIOA, 14, EXTI15_10_IRQ}, {14, GPIOB, 14, EXTI15_10_IRQ}, {14, GPIOC, 14, EXTI15_10_IRQ}, {14, GPIOD, 14, EXTI15_10_IRQ},
    {15, GPIOA, 15, EXTI15_10_IRQ}, {15, GPIOB, 15, EXTI15_10_IRQ}, {15, GPIOC, 15, EXTI15_10_IRQ}, {15, GPIOD, 15, EXTI15_10_IRQ}
};



 const EXTIConfig *EXTI_Config_Ptrs[EXTI_LINES][4] = {
     {&EXTI_Configurations[0] , &EXTI_Configurations[1] , &EXTI_Configurations[2] ,  &EXTI_Configurations[3]},
     {&EXTI_Configurations[4] , &EXTI_Configurations[5] , &EXTI_Configurations[6] ,  &EXTI_Configurations[7]},
     {&EXTI_Configurations[8] , &EXTI_Configurations[9] , &EXTI_Configurations[10], &EXTI_Configurations[11]},
     {&EXTI_Configurations[12], &EXTI_Configurations[13], &EXTI_Configurations[14], &EXTI_Configurations[15]},
     {&EXTI_Configurations[16], &EXTI_Configurations[17], &EXTI_Configurations[18], &EXTI_Configurations[19]},
     {&EXTI_Configurations[20], &EXTI_Configurations[21], &EXTI_Configurations[22], &EXTI_Configurations[23]},
     {&EXTI_Configurations[24], &EXTI_Configurations[25], &EXTI_Configurations[26], &EXTI_Configurations[27]},
     {&EXTI_Configurations[28], &EXTI_Configurations[29], &EXTI_Configurations[30], &EXTI_Configurations[31]},
     {&EXTI_Configurations[32], &EXTI_Configurations[33], &EXTI_Configurations[34], &EXTI_Configurations[35]},
     {&EXTI_Configurations[36], &EXTI_Configurations[37], &EXTI_Configurations[38], &EXTI_Configurations[39]},
     {&EXTI_Configurations[40], &EXTI_Configurations[41], &EXTI_Configurations[42], &EXTI_Configurations[43]},
     {&EXTI_Configurations[44], &EXTI_Configurations[45], &EXTI_Configurations[46], &EXTI_Configurations[47]},
     {&EXTI_Configurations[48], &EXTI_Configurations[49], &EXTI_Configurations[50], &EXTI_Configurations[51]},
     {&EXTI_Configurations[52], &EXTI_Configurations[53], &EXTI_Configurations[54], &EXTI_Configurations[55]},
     {&EXTI_Configurations[56], &EXTI_Configurations[57], &EXTI_Configurations[58], &EXTI_Configurations[59]},
     {&EXTI_Configurations[60], &EXTI_Configurations[61], &EXTI_Configurations[62], &EXTI_Configurations[63]}
 };

 // Arrays to map EXTI pins to SYSCFG EXTICR registers
 uint32* const EXTICR[4] = {
     &SYSCFG.EXTICR1,
     &SYSCFG.EXTICR2,
     &SYSCFG.EXTICR3,
     &SYSCFG.EXTICR4
 };

 // Bit masks for edge selection
 const uint32 EDGE_SELECT[3] = {
     RISING_EDGE, FALLING_EDGE, RISING_FALLING
 };


 // Define the __disable_irq and __enable_irq functions
 static inline void __disable_irq(void) {
     __asm volatile ("cpsid i" : : : "memory");
 }


 static inline void __enable_irq(void) {
     __asm volatile ("cpsie i" : : : "memory");
 }


 void Exti_Init(EXTI_PORT portID, uint8_t ExtiPin, EXTI_Edge edge) {
     // Disable global interrupts to prevent race conditions
     __disable_irq();

     // Configure SYSCFG to select the port for EXTI line
     uint32* exticr = EXTICR[ExtiPin / 4];
     uint32 pos = (ExtiPin % 4) * 4;

     CLEAR_BIT_REG((*exticr), 0xf, pos, 1);
     SET_BIT_REG((*exticr), portID, pos, 1);

     // Configure EXTI line trigger
     if (edge == EDGE_SELECT[0]) {
         SET_BIT_REG((EXTI->RTSR), 0x01, ExtiPin, 1);
     } else if (edge == EDGE_SELECT[1]) {
         SET_BIT_REG((EXTI->FTSR), 0x01, ExtiPin, 1);
     } else if (edge == EDGE_SELECT[2]) {
         SET_BIT_REG((EXTI->FTSR), 0x01, ExtiPin, 1);
         SET_BIT_REG((EXTI->RTSR), 0x01, ExtiPin, 1);
     }

     // Enable EXTI line
     SET_BIT_REG((EXTI->IMR), 0x01, ExtiPin, 1);

     // Enable NVIC IRQ
     const EXTIConfig* config = NULL;
     for (int i = 0; i < sizeof(EXTI_Configurations) / sizeof(EXTI_Configurations[0]); i++) {
         if (EXTI_Configurations[i].LINE == ExtiPin && EXTI_Configurations[i].PORT == portID) {
             config = &EXTI_Configurations[i];
             break;
         }
     }

     if (config != NULL) {
         Nvic_EnableInterrupt(config->IRQ);
     }

     // Re-enable global interrupts
     __enable_irq();
 }



void Exti_Deinit(uint8 ExtiPin) {
    uint8 extiPinMode = ExtiPin % 4;
    vuint32_t* exticr = EXTICR[ExtiPin / 4];
    const EXTIConfig *config = EXTI_Config_Ptrs[ExtiPin][extiPinMode];

    // Disable the NVIC interrupt
	uint8 NVIC_index = config->IRQ / 32;
	uint32 NVIC_bit = 1 << (config->IRQ % 32);

    // Clear the EXTI configuration for the specific pin
	CLEAR_BIT_REG((*exticr), 0x0FU, extiPinMode, 4);

    Nvic_DisableInterrupt(config->IRQ);
}


void EXTI_Enable(uint16 Exti_line) {
	SET_BIT_REG((EXTI->IMR), 0x01, Exti_line, 1);
	Nvic_EnableInterrupt(EXTI_Configurations[Exti_line].IRQ);
}



void EXTI_Disable(uint16 Exti_line) {
	CLEAR_BIT_REG((EXTI->IMR), 0x01, Exti_line, 1);
	Nvic_DisableInterrupt(EXTI_Configurations[Exti_line].LINE);
}


void EXTI_RegisterCallback(uint16 EXTI_Line, void (*P_IRQ_Callback)(void)) {
    EXTI_Callbacks[EXTI_Line] = P_IRQ_Callback;
}


void EXTI_IRQHandler(uint16 Exti_line) {

	if((READ_BIT_REG((EXTI->PR), 0x01, Exti_line, 1)) != 0) {
    	SET_BIT_REG((EXTI->PR), 0x01, Exti_line, 1);

    	if (EXTI_Callbacks[Exti_line] != 0) {
            EXTI_Callbacks[Exti_line]();
        }

    }
}


void EXTI_PendingFlag(uint8 Exti_line){
	SET_BIT_REG((EXTI->PR), 0x01, Exti_line, 1);
}
