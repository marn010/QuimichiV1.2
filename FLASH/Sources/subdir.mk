################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/QuimichiV1.2.c" \

C_SRCS += \
../Sources/QuimichiV1.2.c \

OBJS += \
./Sources/QuimichiV1_2_c.obj \

OBJS_QUOTED += \
"./Sources/QuimichiV1_2_c.obj" \

C_DEPS += \
./Sources/QuimichiV1_2_c.d \

C_DEPS_QUOTED += \
"./Sources/QuimichiV1_2_c.d" \

OBJS_OS_FORMAT += \
./Sources/QuimichiV1_2_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/QuimichiV1_2_c.obj: ../Sources/QuimichiV1.2.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/QuimichiV1.2.args" -ObjN="Sources/QuimichiV1_2_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


