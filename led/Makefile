# Makefile for STM32F103C8T6 LED blink example

CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
GDB = arm-none-eabi-gdb

CFLAGS = -mcpu=cortex-m3 -mthumb -Wall -O2 -I./inc -I./lib/CMSIS -I./lib/STM32F10x_StdPeriph_Driver/inc
LDFLAGS = -T linker/stm32f103c8t6.ld

SRCS = $(wildcard src/*.c lib/STM32F10x_StdPeriph_Driver/src/*.c)
OBJS = $(SRCS:.c=.o)

all: led_blink.bin

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

led_blink.elf: $(OBJS)
    $(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

led_blink.bin: led_blink.elf
    $(OBJCOPY) -O binary $< $@

clean:
    rm -f src/*.o lib/STM32F10x_StdPeriph_Driver/src/*.o led_blink.elf led_blink.bin

flash: led_blink.bin
    st-flash write led_blink.bin 0x8000000
