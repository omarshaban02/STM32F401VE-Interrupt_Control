/**
 * Nvic.h
 *
 *  Created on: Mon May 13 2024
 *  Author    : Omar Abd Elnasser
 */

#ifndef NVIC_H
#define NVIC_H

#include "Std_Types.h"
#include "Bit_Operations.h"
#include "Nvic_Private.h"


void Nvic_EnableInterrupt(uint8 IRQn);
void Nvic_DisableInterrupt(uint8 IRQn);
void Nvic_setPending(uint8 IRQn);
void Nvic_ClearPending(uint8 IRQn);
void Nvic_ActiveBitRegister(uint8 IRQn);


#endif /* NVIC_H */
