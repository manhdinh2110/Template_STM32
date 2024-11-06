#include "stm32f4xx.h"                 
#include "Oven_Timer.h"
#include "GPIO.h"
#include "TFT_LCD.h"
void LED_Config(void);


int main(void)
{

LED_Config();
	GPIO_configuration();
	LCD_Init();
	ILI9486_FillScreen(0xFFFF);

while(1)
{
//GPIO_ResetBits(GPIOA,GPIO_Pin_7);
//delay_01ms(1000);
//GPIO_SetBits(GPIOA,GPIO_Pin_7);
//delay_01ms(1000);
	
//GPIO_ResetBits(GPIOB,GPIO_Pin_6);
//delay_01ms(1000);
//GPIO_SetBits(GPIOB,GPIO_Pin_6);
//delay_01ms(1000);
}
}
void LED_Config(void)
	{
		GPIO_InitTypeDef GPIO_InitStructure;

		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	//	GPIO_Init(GPIOB, &GPIO_InitStructure);

	}
