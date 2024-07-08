/**
 * Nvic.c
 *
 *  Created on: Mon May 13 2024
 *  Author    : Omar Abd Elnasser
 */

#include "Nvic.h"


volatile uint32 *NVIC_ISER[8] = { &NVIC_ISER0, &NVIC_ISER1, &NVIC_ISER2, &NVIC_ISER3, &NVIC_ISER4, &NVIC_ISER5, &NVIC_ISER6, &NVIC_ISER7 };
volatile uint32 *NVIC_ICER[8] = { &NVIC_ICER0, &NVIC_ICER1, &NVIC_ICER2, &NVIC_ICER3, &NVIC_ICER4, &NVIC_ICER5, &NVIC_ICER6, &NVIC_ICER7 };
volatile uint32 *NVIC_ISPR[8] = { &NVIC_ISPR0, &NVIC_ISPR1, &NVIC_ISPR2, &NVIC_ISPR3, &NVIC_ISPR4, &NVIC_ISPR5, &NVIC_ISPR6, &NVIC_ISPR7 };
volatile uint32 *NVIC_ICPR[8] = { &NVIC_ICPR0, &NVIC_ICPR1, &NVIC_ICPR2, &NVIC_ICPR3, &NVIC_ICPR4, &NVIC_ICPR5, &NVIC_ICPR6 ,&NVIC_ICPR7 };
volatile uint32 *NVIC_IABR[8] = { &NVIC_IABR0, &NVIC_IABR1, &NVIC_IABR2, &NVIC_IABR3, &NVIC_IABR4, &NVIC_IABR5, &NVIC_IABR6, &NVIC_IABR7 };


uint8 registerIndex = 0;
uint8 bitPosistion = 0;


void Nvic_EnableInterrupt(uint8 IRQn) {
  if(IRQn < 240){
	  registerIndex = IRQn / 32;
	  bitPosistion  = IRQn % 32;
	  // Enable interrupt
	  SET_BIT_REG(*NVIC_ISER[registerIndex], 0x01, bitPosistion, 1);
  }
}


void Nvic_DisableInterrupt(uint8 IRQn) {
  if (IRQn < 240) {
	  registerIndex = IRQn / 32;
	  bitPosistion  = IRQn % 32;
	  // Disable interrupt
	  SET_BIT_REG(*NVIC_ICER[registerIndex], 0x01, bitPosistion, 1);
  }
}


void Nvic_setPending(uint8 IRQn) {
  if (IRQn < 240) {
	  registerIndex = IRQn / 32;
	  bitPosistion  = IRQn % 32;
	  // Changes interrupt state to pending
	  SET_BIT_REG(*NVIC_ISPR[registerIndex], 0x01, bitPosistion, 1);
  }
}


void Nvic_ClearPending(uint8 IRQn) {
  if (IRQn < 240) {
	  registerIndex = IRQn / 32;
	  bitPosistion  = IRQn % 32;
	  // Removes the pending state of an interrupt
	  SET_BIT_REG(*NVIC_ICPR[registerIndex], 0x01, bitPosistion, 1);
  }
}


void Nvic_ActiveBitRegister(uint8 IRQn) {
  if (IRQn < 240) {
	  registerIndex = IRQn / 32;
	  bitPosistion  = IRQn % 32;
	  // Interrupt Active
	  SET_BIT_REG(*NVIC_IABR[registerIndex], 0x01, bitPosistion, 1);
  }
}
