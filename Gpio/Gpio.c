/**
 * Gpio.c
 *
 *  Created on: Tue Apr 11 2023
 *  Author    : Abdullah Darwish
 */

#include "Gpio.h"
#include "Gpio_Private.h"
#include "RCC.h"
#include "Bit_Operations.h"

uint32 GPIO_Addresses[5] = { GPIOA_BASE_ADDR, GPIOB_BASE_ADDR, GPIOC_BASE_ADDR, GPIOD_BASE_ADDR, GPIOE_BASE_ADDR };

// For looping
uint32 bit_pos = 0;

#define GPIO_REG(REG_ID, PORT_ID) ((uint32*)((PORT_ID) + (REG_ID)))


void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode, uint8 DefaultState) {
	uint8 PortId = PortName - GPIO_A;
	GpioType * gpioReg =  GPIO_Addresses[PortId];

	uint8 OutputState = DefaultState & 0x1;
	uint8 InputState = DefaultState >> 1;

	CLEAR_BIT_REG(gpioReg->GPIO_MODER, 0x3, PinNum, 2);
	SET_BIT_REG(gpioReg->GPIO_MODER, PinMode, PinNum, 2);

	CLEAR_BIT_REG(gpioReg->GPIO_OTYPER, 0x01, PinNum, 1);
	SET_BIT_REG(gpioReg->GPIO_OTYPER, OutputState, PinNum, 1);

	CLEAR_BIT_REG(gpioReg->GPIO_PUPDR, 0x3, PinNum, 2);
	SET_BIT_REG(gpioReg->GPIO_PUPDR, InputState, PinNum, 2);

}


void Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data) {
	uint8 PortId = PortName - GPIO_A;
	GpioType * gpioReg =  GPIO_Addresses[PortId];

	CLEAR_BIT_REG(gpioReg->GPIO_ODR, 0x01, PinNum, 1);
	SET_BIT_REG(gpioReg->GPIO_ODR, Data, PinNum, 1);
}


uint8 Gpio_ReadPin(uint8 PortName, uint8 PinNum) {
	uint8 data = 0;
	uint8 PortId = PortName - GPIO_A;
	GpioType * gpioReg =  GPIO_Addresses[PortId];

	data = READ_BIT_REG(gpioReg->GPIO_IDR, 1, PinNum, 1);
	return data;
}


void GPIO_TogglePin(uint8 PortName, uint8 PinNum) {
	uint8 PortId = PortName - GPIO_A;
	GpioType * gpioReg = GPIO_Addresses[PortId];
	TOGGLE_BIT_REG(gpioReg->GPIO_ODR, 1, PinNum, 1);
}


void GPIO_DISABLE_PINS(uint8 PortName) {
	uint8 PortId = PortName - GPIO_A;
	GpioType * gpioReg = GPIO_Addresses[PortId];
	for (bit_pos = 0; bit_pos < 7; bit_pos++) {
		CLEAR_BIT_REG(gpioReg->GPIO_ODR, 0x03, bit_pos, 2);
		SET_BIT_REG(gpioReg->GPIO_ODR, 0x03, bit_pos, 2);
	}
	Rcc_Disable(RCC_GPIOA + PortId);
}

