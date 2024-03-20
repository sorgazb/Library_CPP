################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Libros.cpp \
../src/Usuarios.cpp \
../src/biblioteca.cpp \
../src/prog_principal.cpp \
../src/vov_libros.cpp \
../src/vov_usuarios.cpp 

OBJS += \
./src/Libros.o \
./src/Usuarios.o \
./src/biblioteca.o \
./src/prog_principal.o \
./src/vov_libros.o \
./src/vov_usuarios.o 

CPP_DEPS += \
./src/Libros.d \
./src/Usuarios.d \
./src/biblioteca.d \
./src/prog_principal.d \
./src/vov_libros.d \
./src/vov_usuarios.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


