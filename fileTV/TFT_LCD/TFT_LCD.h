#ifndef _TFT_LCD_
#define _TFT_LCD_
#include "stm32f4xx.h"

//#define RD	GPIO_Pin_3 //PB3


#define RD_PORT GPIOB
#define RD_Pin  GPIO_Pin_9
#define WR_PORT GPIOB
#define WR_Pin  GPIO_Pin_8
#define RS_PORT GPIOB         // RS PORT
#define RS_Pin  GPIO_Pin_6     // RS Pin
#define CS_PORT GPIOB
#define CS_Pin  GPIO_Pin_7
#define RESET_PORT GPIOA
#define RESET_Pin  GPIO_Pin_0

#define D0_PORT GPIOA						//B0
#define D0_Pin GPIO_Pin_0
#define D1_PORT GPIOA					//B1
#define D1_Pin GPIO_Pin_1
#define D2_PORT GPIOA					//A15
#define D2_Pin GPIO_Pin_2
#define D3_PORT GPIOA					//B3
#define D3_Pin GPIO_Pin_3
#define D4_PORT GPIOA				//B4
#define D4_Pin GPIO_Pin_4
#define D5_PORT GPIOA			//B5
#define D5_Pin GPIO_Pin_5
#define D6_PORT GPIOA   //B6
#define D6_Pin GPIO_Pin_6
#define D7_PORT GPIOA  //a5
#define D7_Pin GPIO_Pin_7


 #define write_8(d) { \
   GPIOA->BSRR = 0b1000000000100000 << 16; \
   GPIOB->BSRR = 0b0000000001111011 << 16; \
   GPIOA->BSRR = (((d) & (1<<2)) << 13) \
               | (((d) & (1<<7)) >> 2); \
   GPIOB->BSRR = (((d) & (1<<0)) << 0) \
               | (((d) & (1<<1)) << 0) \
			   | (((d) & (1<<3)) << 0) \
			   | (((d) & (1<<4)) << 0) \
			   | (((d) & (1<<5)) << 0) \
			   | (((d) & (1<<6)) << 0); \
    }
 
  #define read_8() (          (((GPIOB->IDR & (1<<0)) >> 0) \
                           | ((GPIOB->IDR & (1<<1)) >> 0) \
                           | ((GPIOA->IDR & (1<<15)) >> 13) \
                           | ((GPIOB->IDR & (1<<3)) >> 0) \
                           | ((GPIOB->IDR & (1<<4)) >> 0) \
                           | ((GPIOB->IDR & (1<<5)) >> 0) \
                           | ((GPIOB->IDR & (1<<6)) >> 0) \
                           | ((GPIOA->IDR & (1<<5)) << 2)))

void GPIO_LCD_Config(void);
void LCD_Enable(void);
void LCD_Send4Bit(unsigned char Data);
void LCD_SendCommand(unsigned char command);
void LCD_Clear();
void LCD_Init();
void LCD_Gotoxy(unsigned char x, unsigned char y);
void LCD_PutChar(unsigned char Data);
void LCD_Puts(char *s);
void ILI9486_SetPixel(uint16_t x, uint16_t y, uint16_t color);
void ILI9486_FillScreen(uint16_t color);

#endif 
