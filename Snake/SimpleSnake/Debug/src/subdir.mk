################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Console.c \
../src/Eingabe.c \
../src/Element.c \
../src/Liste.c \
../src/Schlange.c \
../src/SimpleSnake.c \
../src/Spiel.c 

C_DEPS += \
./src/Console.d \
./src/Eingabe.d \
./src/Element.d \
./src/Liste.d \
./src/Schlange.d \
./src/SimpleSnake.d \
./src/Spiel.d 

OBJS += \
./src/Console.o \
./src/Eingabe.o \
./src/Element.o \
./src/Liste.o \
./src/Schlange.o \
./src/SimpleSnake.o \
./src/Spiel.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -lncurses -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Console.d ./src/Console.o ./src/Eingabe.d ./src/Eingabe.o ./src/Element.d ./src/Element.o ./src/Liste.d ./src/Liste.o ./src/Schlange.d ./src/Schlange.o ./src/SimpleSnake.d ./src/SimpleSnake.o ./src/Spiel.d ./src/Spiel.o

.PHONY: clean-src

