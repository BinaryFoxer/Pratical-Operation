#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Led.h"
#include "OLED.h"
#include "OLED_Data.h"
#include "Key.h"
#include "Encoder.h"
#include "PWM.h"
#include "myExti.h"

int16_t Count;

int main(){
	
	OLED_Init();
//	Key_init();
	LEDInit();
	Encoder_Init();
	PWM_Init();
	myExti_Init();
	
	OLED_ShowString(0, 0, "Count: 0000", OLED_8X16);
	OLED_Update();
	
	while(1)
	{	
		Count = Get_Encoder();		
		OLED_ShowSignedNum(48, 0, Count, 4, OLED_8X16);
		OLED_Update();
		
		Set_CCR(Count);
	}

}

void EXTI4_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line4) == SET)
	{
		if(EXTI_GetITStatus(EXTI_Line4) == SET)
		{
			LED2Turn();
		}
	}
	EXTI_ClearITPendingBit(EXTI_Line4);
}
