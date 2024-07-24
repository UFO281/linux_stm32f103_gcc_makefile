# 定义编译器  
CC=arm-none-eabi-gcc  
  
# 定义编译选项，这里需要根据你的STM32型号和配置进行调整  
CFLAGS=-mcpu=cortex-m3 -mthumb -g 	-I/home/wls/wls/linux_stm32f103_gcc_makefile/led/System \
									-I/home/wls/wls/linux_stm32f103_gcc_makefile/led/Library \
									-I./

  
# Source files
C_SRCS = $(wildcard *.c)
ASM_SRCS = $(wildcard *.s)

# Object files
C_OBJS = $(C_SRCS:.c=.o)
ASM_OBJS = $(ASM_SRCS:.s=.o)

OBJS = $(C_OBJS) $(ASM_OBJS)
  
# 默认目标  
all: $(OBJS)  
  
# 编译规则  
%.o: %.c  
	$(CC) $(CFLAGS) -c -o $@ $<  
  
# 清理目标  
clean:  
	rm -f $(OBJS)