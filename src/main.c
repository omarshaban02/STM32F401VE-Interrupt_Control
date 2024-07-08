// Header files
#include "Bit_Operations.h"
#include "Std_Types.h"
#include "Utils.h"
#include "Gpio.h"
#include "Rcc.h"
#include "Nvic.h"
#include "Exti.h"
#include "Keypad.h"

// Define the counter that display on the 7-Segment
volatile uint8 counter = 0;

// Define the patterns for each digit in the 7-Segment
const uint8 digitPatterns[10][7] = {
    {0, 1, 1, 1, 1, 1, 1}, // 0
    {0, 0, 0, 0, 1, 1, 0}, // 1
    {1, 0, 1, 1, 0, 1, 1}, // 2
    {1, 0, 0, 1, 1, 1, 1}, // 3
    {1, 1, 0, 0, 1, 1, 0}, // 4
    {1, 1, 0, 1, 1, 0, 1}, // 5
    {1, 1, 1, 1, 1, 0, 1}, // 6
    {0, 0, 0, 0, 1, 1, 1}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 0, 1, 1, 1, 1}  // 9
};

// Functions Declarations
void INIT_GPIOS_PINS();
void DELAY(unsigned long timeinMILLS);
void RCC_ENABLE();
void setDigit(uint8 digit);


int main() {
	RCC_ENABLE();
	INIT_GPIOS_PINS();

    // Initialize EXTI for PA9
    Exti_Init(GPIOA, 9, EDGE_SELECT[1]);
    EXTI_Enable(9);
    EXTI_PendingFlag(9);

    // Initialize EXTI for PB4
    Exti_Init(GPIOB, 4, EDGE_SELECT[1]);
    EXTI_Enable(4);
    EXTI_PendingFlag(4);

	while (1) {
		// display the number in the 7-Segment
		setDigit(counter);
		DELAY(1000);
	}

	// De-initialize the EXTI for PA9
    EXTI_Disable(9);
    Exti_Deinit(9);

    // De-initialize the EXTI for PB5
    EXTI_Disable(4);
    Exti_Deinit(4);
	return 0;
}


void setDigit(uint8 digit) {
    for (int i = 0; i < 7; i++) {
        Gpio_WritePin(GPIO_A, i, digitPatterns[digit][i] ? HIGH : LOW);
        DELAY(1000);
    }
}


void DELAY(unsigned long timeinMILLS){
    volatile unsigned int i = 0;
    volatile unsigned int j = 0;

    for(i = 0; i < timeinMILLS; i++)
        // to avoid the warning of the for loop is not guard
        for(j = 0; j< 2 ; j++);
}


void RCC_ENABLE(){
	Rcc_Init();
	Rcc_Enable(RCC_GPIOA);
	Rcc_Enable(RCC_GPIOB);
	Rcc_Enable(RCC_SYSCFG);
}


void INIT_GPIOS_PINS(){
	uint32 i = 0;
	  for (i = 0; i < 7; i++) {
	    Gpio_ConfigPin(GPIO_A, i, GPIO_OUTPUT, GPIO_PUSH_PULL);
	  }
	    Gpio_ConfigPin(GPIO_A, 9, GPIO_INPUT, GPIO_PULL_UP);
	    Gpio_ConfigPin(GPIO_B, 4, GPIO_INPUT, GPIO_PULL_UP);
}


void EXTI4_IRQHandler(void) {
    if (counter > 0) {
        counter--;
    }
}


void EXTI9_5_IRQHandler(void){
    if (counter < 9) {
        counter++;
    }
}
