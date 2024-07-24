# 定义编译器  
CC=arm-none-eabi-gcc  
  
# 定义编译选项，这里需要根据你的STM32型号和配置进行调整  
CFLAGS=-mcpu=cortex-m3 -mthumb -g 	-I/home/wls/wls/linux_stm32f103_gcc_makefile/led/System \
									-I/home/wls/wls/linux_stm32f103_gcc_makefile/led/Start \
									-I./

  
# 查找当前目录下所有的.c文件  
SRCS=$(wildcard *.c)  
  
# 将.c文件扩展名替换为.o来生成目标文件名  
OBJS=$(SRCS:.c=.o)  
  
# 默认目标  
all: $(OBJS)  
  
# 编译规则  
%.o: %.c  
	$(CC) $(CFLAGS) -c -o $@ $<  
  
# 清理目标  
clean:  
	rm -f $(OBJS)