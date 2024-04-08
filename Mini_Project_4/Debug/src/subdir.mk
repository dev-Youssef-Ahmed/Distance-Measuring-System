################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gpio.c \
../src/icu.c \
../src/lcd.c \
../src/main.c \
../src/ultrasonic.c 

OBJS += \
./src/gpio.o \
./src/icu.o \
./src/lcd.o \
./src/main.o \
./src/ultrasonic.o 

C_DEPS += \
./src/gpio.d \
./src/icu.d \
./src/lcd.d \
./src/main.d \
./src/ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Youssef\Desktop\Youssef_Ahmed_85_All_Mini_Projects\Mini_Project_4\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


