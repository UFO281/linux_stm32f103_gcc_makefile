/**
 * @file main.c
 * @author wls
 * @brief at linux use arm-gcc +makefile code stm32f103c8t6
 * @version 0.1
 * @date 2023-08-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "stm32f10x.h"





/**
 * @brief 延时函数
 * 
 * @param count 
 */
void delay(uint32_t count); 



int main(void) 
{

    
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;// 使能GPIOB的时钟
    
    // 配置PB12引脚为推挽输出模式
    GPIOB->CRH &= ~GPIO_CRH_CNF12;
    GPIOB->CRH |= GPIO_CRH_MODE12;
    
    while(1) 
    {
        // 点亮LED
        GPIOB->BSRR |= GPIO_BSRR_BS12;
        
        // 延时
        delay(1000000);
        
        // 熄灭LED
        GPIOB->BSRR |= GPIO_BSRR_BR12;
        
        // 延时
        delay(1000000);
    }

    return 0;
}





void delay(uint32_t count) 
{
    for(uint32_t i = 0; i < count; i++);
}