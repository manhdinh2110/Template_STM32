#include "GPIO.h"
void GPIO_configuration(){
	GPIO_InitTypeDef GPIO_InitStruc;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	GPIO_InitStruc.GPIO_Mode =GPIO_Mode_OUT;
	GPIO_InitStruc.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStruc.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_15|GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStruc.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_InitStruc.GPIO_Speed=GPIO_High_Speed ;
	GPIO_Init(GPIOA,&GPIO_InitStruc);
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	
	GPIO_InitStruc.GPIO_Mode =GPIO_Mode_OUT;
	GPIO_InitStruc.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStruc.GPIO_Pin=GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_9|GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
	GPIO_InitStruc.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_InitStruc.GPIO_Speed=GPIO_High_Speed ;
	GPIO_Init(GPIOB,&GPIO_InitStruc);
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	
	GPIO_InitStruc.GPIO_Mode =GPIO_Mode_OUT;
	GPIO_InitStruc.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStruc.GPIO_Pin=GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12;
	GPIO_InitStruc.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_InitStruc.GPIO_Speed=GPIO_High_Speed ;
	GPIO_Init(GPIOC,&GPIO_InitStruc);
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
	GPIO_InitStruc.GPIO_Mode =GPIO_Mode_OUT;
	GPIO_InitStruc.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStruc.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1;
	GPIO_InitStruc.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_InitStruc.GPIO_Speed=GPIO_High_Speed ;
	GPIO_Init(GPIOE,&GPIO_InitStruc);
	
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	GPIO_InitStruc.GPIO_Mode =GPIO_Mode_OUT;
	GPIO_InitStruc.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStruc.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStruc.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_InitStruc.GPIO_Speed=GPIO_High_Speed ;
	GPIO_Init(GPIOD,&GPIO_InitStruc);
	
}
