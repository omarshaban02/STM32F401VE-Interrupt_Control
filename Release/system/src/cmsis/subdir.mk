################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/cmsis/system_stm32f4xx.c \
../system/src/cmsis/vectors_stm32f401xe.c 

C_DEPS += \
./system/src/cmsis/system_stm32f4xx.d \
./system/src/cmsis/vectors_stm32f401xe.d 

OBJS += \
./system/src/cmsis/system_stm32f4xx.o \
./system/src/cmsis/vectors_stm32f401xe.o 


# Each subdirectory must supply rules for building sources it contributes
system/src/cmsis/system_stm32f4xx.o: ../system/src/cmsis/system_stm32f4xx.c system/src/cmsis/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"D:\SBME 3nd yaer\2nd term\Embeded system\lab8\Lib" -I"D:\SBME 3nd yaer\2nd term\Embeded system\lab8\EXTI" -I"D:\SBME 3nd yaer\2nd term\Embeded system\lab8\Rcc" -I"D:\SBME 3nd yaer\2nd term\Embeded system\lab8\Gpio" -I"D:\SBME 3nd yaer\2nd term\Embeded system\lab8\Keypad" -I"D:\SBME 3nd yaer\2nd term\Embeded system\lab8\Nvic" -std=gnu11 -Wno-padded -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

system/src/cmsis/%.o: ../system/src/cmsis/%.c system/src/cmsis/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"D:\SBME 3nd yaer\2nd term\Embeded system\lab8\Lib" -I"D:\SBME 3nd yaer\2nd term\Embeded system\lab8\EXTI" -I"D:\SBME 3nd yaer\2nd term\Embeded system\lab8\Rcc" -I"D:\SBME 3nd yaer\2nd term\Embeded system\lab8\Gpio" -I"D:\SBME 3nd yaer\2nd term\Embeded system\lab8\Keypad" -I"D:\SBME 3nd yaer\2nd term\Embeded system\lab8\Nvic" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


