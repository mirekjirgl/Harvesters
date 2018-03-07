################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 16
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := "$(GNU_Make_Install_DirEnv)/rm" -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Sources/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include Generated_Code/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
EnergyHarvesting.elf \

EXECUTABLES_QUOTED += \
"EnergyHarvesting.elf" \

EXECUTABLES_OS_FORMAT += \
EnergyHarvesting.elf \

SECONDARY_FLASH += \
EnergyHarvesting.hex \

SECONDARY_FLASH_QUOTED += \
"EnergyHarvesting.hex" \

SECONDARY_FLASH_OS_FORMAT += \
EnergyHarvesting.hex \

SECONDARY_SIZE += \
EnergyHarvesting.siz \

SECONDARY_SIZE_QUOTED += \
"EnergyHarvesting.siz" \

SECONDARY_SIZE_OS_FORMAT += \
EnergyHarvesting.siz \


# All Target
all: warning-messages explicit-dependencies EnergyHarvesting.elf secondary-outputs

# Tool invocations
EnergyHarvesting.elf: $(OBJS) $(USER_OBJS) ../Project_Settings/Linker_Files/ProcessorExpert.ld
	@echo 'Building target: $@'
	@echo 'Executing target #17 $@'
	@echo 'Invoking: ARM Ltd Windows GCC C Linker'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED) @"EnergyHarvesting.args" -o"EnergyHarvesting.elf"
	@echo 'Finished building target: $@'
	@echo ' '

EnergyHarvesting.hex: EnergyHarvesting.elf
	@echo 'Executing target #18 $@'
	@echo 'Invoking: ARM Ltd Windows GNU Create Flash Image'
	"$(ARMSourceryDirEnv)/arm-none-eabi-objcopy"  -O ihex EnergyHarvesting.elf "EnergyHarvesting.hex"
	@echo 'Finished building: $@'
	@echo ' '

EnergyHarvesting.siz: EnergyHarvesting.elf
	@echo 'Executing target #19 $@'
	@echo 'Invoking: ARM Ltd Windows GNU Print Size'
	"$(ARMSourceryDirEnv)/arm-none-eabi-size"  --format=berkeley EnergyHarvesting.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(S_DEPS_QUOTED) $(SECONDARY_FLASH_QUOTED) "./*/*.o" "./*/*/*.o"  $(S_UPPER_DEPS_QUOTED) $(ASM_DEPS_QUOTED) $(SECONDARY_SIZE_QUOTED) $(ASM_UPPER_DEPS_QUOTED) $(SX_DEPS_QUOTED) $(EXECUTABLES_QUOTED) "./*/*.d" "./*/*/*.d"  $(ProjDirPath)/FLASH/EnergyHarvesting.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: ../Project_Settings/Linker_Files/ProcessorExpert.ld EnergyHarvesting.elf EnergyHarvesting.elf 

warning-messages: 

