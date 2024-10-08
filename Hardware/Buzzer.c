#include "stm32f10x.h"                  // Device header

void Buzzer_Init(void)
{
	//开RCC_IO时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	//io初始化
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_12);//设置初始为高电平，即不响
	
}

void Buzzer_On(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);
	
}

void Buzzer_Off(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_12);
	
}
