#ifndef __ENCODER_H_
#define __ENCODER_H_
#include "stm32f10x.h"                  // Device header

void Encoder_Init(void);
int16_t Get_Encoder(void);

#endif
