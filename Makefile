TARGET = led_project

# 编译器和工具
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy

# 编译器选项
CFLAGS = -mcpu=cortex-m3 -mthumb -Wall -O0 -g3

# 链接器选项
LDFLAGS =

# 链接时使用的脚本
LDSCRIPT = STM32F103C8T6.ld

# 源文件列表
SOURCES = main.c

# 对象文件列表
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET).bin

# 生成目标二进制文件
$(TARGET).bin: $(TARGET).elf
	@$(OBJCOPY) -O binary $< $@

# 生成目标elf文件
$(TARGET).elf: $(OBJECTS)
	@$(LD) $(LDFLAGS) $(OBJECTS) -T $(LDSCRIPT) -o $@

# 编译每个源文件
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS) $(TARGET).elf $(TARGET).bin
