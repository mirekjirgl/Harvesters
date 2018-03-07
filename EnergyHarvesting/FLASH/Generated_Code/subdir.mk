################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/CS.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/CsIO1.c" \
"../Generated_Code/IO1.c" \
"../Generated_Code/LED.c" \
"../Generated_Code/MISO.c" \
"../Generated_Code/MOSI.c" \
"../Generated_Code/PE_LDD.c" \
"../Generated_Code/SCL.c" \
"../Generated_Code/Vectors.c" \
"../Generated_Code/WAIT1.c" \

C_SRCS += \
../Generated_Code/CS.c \
../Generated_Code/Cpu.c \
../Generated_Code/CsIO1.c \
../Generated_Code/IO1.c \
../Generated_Code/LED.c \
../Generated_Code/MISO.c \
../Generated_Code/MOSI.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/SCL.c \
../Generated_Code/Vectors.c \
../Generated_Code/WAIT1.c \

OBJS += \
./Generated_Code/CS.o \
./Generated_Code/Cpu.o \
./Generated_Code/CsIO1.o \
./Generated_Code/IO1.o \
./Generated_Code/LED.o \
./Generated_Code/MISO.o \
./Generated_Code/MOSI.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/SCL.o \
./Generated_Code/Vectors.o \
./Generated_Code/WAIT1.o \

OBJS_QUOTED += \
"./Generated_Code/CS.o" \
"./Generated_Code/Cpu.o" \
"./Generated_Code/CsIO1.o" \
"./Generated_Code/IO1.o" \
"./Generated_Code/LED.o" \
"./Generated_Code/MISO.o" \
"./Generated_Code/MOSI.o" \
"./Generated_Code/PE_LDD.o" \
"./Generated_Code/SCL.o" \
"./Generated_Code/Vectors.o" \
"./Generated_Code/WAIT1.o" \

C_DEPS += \
./Generated_Code/CS.d \
./Generated_Code/Cpu.d \
./Generated_Code/CsIO1.d \
./Generated_Code/IO1.d \
./Generated_Code/LED.d \
./Generated_Code/MISO.d \
./Generated_Code/MOSI.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/SCL.d \
./Generated_Code/Vectors.d \
./Generated_Code/WAIT1.d \

OBJS_OS_FORMAT += \
./Generated_Code/CS.o \
./Generated_Code/Cpu.o \
./Generated_Code/CsIO1.o \
./Generated_Code/IO1.o \
./Generated_Code/LED.o \
./Generated_Code/MISO.o \
./Generated_Code/MOSI.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/SCL.o \
./Generated_Code/Vectors.o \
./Generated_Code/WAIT1.o \

C_DEPS_QUOTED += \
"./Generated_Code/CS.d" \
"./Generated_Code/Cpu.d" \
"./Generated_Code/CsIO1.d" \
"./Generated_Code/IO1.d" \
"./Generated_Code/LED.d" \
"./Generated_Code/MISO.d" \
"./Generated_Code/MOSI.d" \
"./Generated_Code/PE_LDD.d" \
"./Generated_Code/SCL.d" \
"./Generated_Code/Vectors.d" \
"./Generated_Code/WAIT1.d" \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/CS.o: ../Generated_Code/CS.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/CS.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/CS.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cpu.o: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Cpu.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/CsIO1.o: ../Generated_Code/CsIO1.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/CsIO1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/CsIO1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/IO1.o: ../Generated_Code/IO1.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/IO1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/IO1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LED.o: ../Generated_Code/LED.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/LED.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/LED.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/MISO.o: ../Generated_Code/MISO.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/MISO.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/MISO.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/MOSI.o: ../Generated_Code/MOSI.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/MOSI.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/MOSI.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_LDD.o: ../Generated_Code/PE_LDD.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PE_LDD.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PE_LDD.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SCL.o: ../Generated_Code/SCL.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/SCL.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/SCL.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors.o: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Vectors.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Vectors.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/WAIT1.o: ../Generated_Code/WAIT1.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/WAIT1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/WAIT1.o"
	@echo 'Finished building: $<'
	@echo ' '


