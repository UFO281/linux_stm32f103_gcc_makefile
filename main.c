#include "stm32f10x.h"

// 延时函数
void delay(uint32_t count) {
    for(uint32_t i = 0; i < count; i++);
}

int main(void) {
    // 使能GPIOB的时钟
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    
    // 配置PB12引脚为推挽输出模式
    GPIOB->CRH &= ~GPIO_CRH_CNF12;
    GPIOB->CRH |= GPIO_CRH_MODE12;
    
    while(1) {
        // 点亮LED
        GPIOB->BSRR |= GPIO_BSRR_BS12;
        
        // 延时
        delay(1000000);
        
        // 熄灭LED
        GPIOB->BSRR |= GPIO_BSRR_BR12;
        
        // 延时
        delay(1000000);
    }
}
