#ifndef __PWM_H_
#define __PWM_H_
#include "stm32f10x.h"                  // Device header

void PWM_Init(void);
void Set_CCR(uint16_t Compare);

#endif
