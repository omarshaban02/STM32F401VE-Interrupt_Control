/**
 * Gpio_Private.h
 *
 *  Created on: Tue Apr 11 2023
 *  Author    : Abdullah Darwish
 */

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#include "Utils.h"

#define GPIOX_BASE_ADDRESS 0x40000000

#define GPIOA_BASE_ADDR (GPIOX_BASE_ADDRESS + 0x00020000)
#define GPIOB_BASE_ADDR (GPIOX_BASE_ADDRESS + 0x00020400)
#define GPIOC_BASE_ADDR (GPIOX_BASE_ADDRESS + 0x00020800)
#define GPIOD_BASE_ADDR (GPIOX_BASE_ADDRESS + 0x00020C00)
#define GPIOE_BASE_ADDR (GPIOX_BASE_ADDRESS + 0x00021000)


typedef struct {
	uint32 GPIO_MODER;
	uint32 GPIO_OTYPER;
	uint32 GPIO_OSPEEDR;
	uint32 GPIO_PUPDR;
	uint32 GPIO_IDR;
	uint32 GPIO_ODR;
	uint32 GPIO_BSRR;
	uint32 GPIO_LCKR;
	uint32 GPIO_AFRL;
	uint32 GPIO_AFRH;
} GpioType;


#endif /* GPIO_PRIVATE_H */
