################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/gpio.c \
../Src/leds.c \
../Src/main.c \
../Src/rcc.c \
../Src/ringbuf.c \
../Src/sysClk.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/timers.c \
../Src/uart.c 

OBJS += \
./Src/gpio.o \
./Src/leds.o \
./Src/main.o \
./Src/rcc.o \
./Src/ringbuf.o \
./Src/sysClk.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/timers.o \
./Src/uart.o 

C_DEPS += \
./Src/gpio.d \
./Src/leds.d \
./Src/main.d \
./Src/rcc.d \
./Src/ringbuf.d \
./Src/sysClk.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/timers.d \
./Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32F103RBTx '-DLED_1_GPIOB_PIN = 1' '-DLED_0_GPIOB_PIN = 0' '-DUART_BAUD_RATE = 9600' -DSTM32 -DSTM32F1 -DNUCLEO_F103RB -DSTM32F103xB -c -I../Inc -I"/Users/teodors.kerimovs/STM32CubeIDE/workspace_1.14.0/gigatik/Inc/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"/Users/teodors.kerimovs/STM32CubeIDE/workspace_1.14.0/gigatik/Inc/Drivers/CMSIS/Core/Include" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/gpio.cyclo ./Src/gpio.d ./Src/gpio.o ./Src/gpio.su ./Src/leds.cyclo ./Src/leds.d ./Src/leds.o ./Src/leds.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/rcc.cyclo ./Src/rcc.d ./Src/rcc.o ./Src/rcc.su ./Src/ringbuf.cyclo ./Src/ringbuf.d ./Src/ringbuf.o ./Src/ringbuf.su ./Src/sysClk.cyclo ./Src/sysClk.d ./Src/sysClk.o ./Src/sysClk.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/timers.cyclo ./Src/timers.d ./Src/timers.o ./Src/timers.su ./Src/uart.cyclo ./Src/uart.d ./Src/uart.o ./Src/uart.su

.PHONY: clean-Src

