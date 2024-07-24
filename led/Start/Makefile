  # 定义编译器  
CC = arm-none-eabi-gcc  
AS = arm-none-eabi-as  # 通常不需要单独指定，但这里保留以供参考  
  
# 定义编译选项  
# 定义编译选项，这里需要根据你的STM32型号和配置进行调整  
CFLAGS=   -I/home/wls/wls/linux_stm32f103_gcc_makefile/led/System \
									-I/home/wls/wls/linux_stm32f103_gcc_makefile/led/Library \
									-I./
ASFLAGS = $(CFLAGS)  # 汇编器选项通常与C编译器选项相同  
  
# 定义源文件和目标文件  
SRCS = core_cm3.c startup_stm32f10x_md.s system_stm32f10x.c  
OBJS = $(SRCS:.c=.o) $(SRCS:.s=.o)  # 将.c和.s文件扩展名替换为.o以生成目标文件名  
  
# 默认目标  
all: $(OBJS)  
  
# 编译规则  
%.o: %.c  
    $(CC) -c $(CFLAGS) $< -o $@  
%.o: %.s  
    $(CC) -c $(ASFLAGS) $< -o $@  # 或者直接使用 $(AS) $< -o $@ 如果需要显式调用汇编器  
  
# 清理编译生成的文件  
clean:  
    rm -f $(OBJS)  
  
.PHONY: all clean