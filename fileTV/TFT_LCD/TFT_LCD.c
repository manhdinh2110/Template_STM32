#include "TFT_LCD.h"
#include "Oven_Timer.h"
#include "GPIO.h"
//void GPIO_LCD_Config(void)
//{
//    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOE, ENABLE);
//    GPIO_InitTypeDef        GPIO_InitStruct;
//    
//    /*Configure GPIO pin Output Level */
//    GPIO_WriteBit(GPIOE, LCD_D4|LCD_D7, 0); 
//    GPIO_WriteBit(GPIOA, LCD_RS|LCD_RW, 0); 
//        GPIO_WriteBit(GPIOB, LCD_D5|LCD_EN|LCD_D6, 0); 

//  	GPIO_InitStruct.GPIO_Pin =  LCD_D4|LCD_D5|LCD_D6|LCD_D7;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
//	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP ;
//	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;
//	GPIO_Init(GPIOE,&GPIO_InitStruct);
//	GPIO_Init(GPIOB,&GPIO_InitStruct);

//    GPIO_InitStruct.GPIO_Pin =  LCD_EN|LCD_RS|LCD_RW;
//    GPIO_Init(GPIOA, &GPIO_InitStruct);
//}

//void LCD_Enable(void)
//{
//    GPIO_SetBits(GPIOB, LCD_EN);
//    delay_01ms(1);
//    GPIO_ResetBits(GPIOB, LCD_EN);
//    delay_01ms(1);
//}

void LCD_Send8Bit(unsigned char Data)
{
  GPIO_WriteBit(GPIOE, D0_Pin, Data & 0x01);
  GPIO_WriteBit(GPIOB, D1_Pin, (Data>>1)&1);
  GPIO_WriteBit(GPIOB, D2_Pin, (Data>>2)&1);
  GPIO_WriteBit(GPIOE, D3_Pin, (Data>>3)&1);
	
}

void xulyhex(int d)
{
GPIO_WriteBit(D0_PORT,D0_Pin,(d>>7)&1);
	GPIO_WriteBit(D1_PORT,D1_Pin,(d>>6)&1);
	GPIO_WriteBit(D2_PORT,D2_Pin,(d>>5)&1);
	GPIO_WriteBit(D3_PORT,D3_Pin,(d>>4)&1);
	GPIO_WriteBit(D4_PORT,D4_Pin,(d>>3)&1);
	GPIO_WriteBit(D5_PORT,D5_Pin,(d>>2)&1);
	GPIO_WriteBit(D6_PORT,D6_Pin,(d>>1)&1);
	GPIO_WriteBit(D7_PORT,D7_Pin,(d>>0)&1);

}
void LCD_SendCommand(unsigned char command)
{
	GPIO_ResetBits(CS_PORT,CS_Pin);//Chon chip(CS=0)
  GPIO_ResetBits(RS_PORT,RS_Pin);//Ghi lenh
	GPIO_Write(GPIOA,(uint16_t)command);
	GPIO_ResetBits(WR_PORT,WR_Pin); 
	GPIO_SetBits(WR_PORT,WR_Pin);
	GPIO_SetBits(CS_PORT,CS_Pin);

}
void LCD_Sendata(unsigned char data)
{
GPIO_ResetBits(CS_PORT,CS_Pin);
	GPIO_SetBits(RS_PORT,RS_Pin);//Ghi data
	GPIO_Write(GPIOA,(uint16_t)data);
		GPIO_ResetBits(WR_PORT,WR_Pin); 
	GPIO_SetBits(WR_PORT,WR_Pin);
GPIO_SetBits(CS_PORT,CS_Pin);


}

void LCD_Clear()
{
  LCD_SendCommand(0x01);
  delay_01ms(10);
}

void LCD_Init()
{
	LCD_SendCommand(0x01);
	delay_01ms(200);
	LCD_SendCommand(0x28);
	LCD_SendCommand(0x3A);
	LCD_Sendata(0x55);
	LCD_SendCommand(0x36);
	LCD_Sendata(0x48);
	LCD_SendCommand(0x29);
	delay_01ms(200);
	
	
}
void ILI9486_FillScreen(uint16_t color) {
    uint16_t x, y;
    for (x = 0; x < 320; x++) {  // Kích thu?c màn hình ILI9486 là 320x480
        for (y = 0; y < 480; y++) {
            ILI9486_SetPixel(x, y, color);
        }
    }
}
void ILI9486_SetPixel(uint16_t x, uint16_t y, uint16_t color) {
    LCD_SendCommand(0x2A);  //
    LCD_Sendata(x >> 8);   // 
    LCD_Sendata(x & 0xFF); // 

    LCD_SendCommand(0x2B);  // 
    LCD_Sendata(y >> 8);   // 
    LCD_Sendata(y & 0xFF); 

    LCD_SendCommand(0x2C);  

    LCD_Sendata(color >> 8);  
    LCD_Sendata(color & 0xFF); 
}
void LCD_Gotoxy(unsigned char x, unsigned char y)
{
  unsigned char address;
  if(y == 0)address=(0x80 + x);
  else if(y == 1) address=(0xc0 + x);
  LCD_SendCommand(address);
}

//void LCD_PutChar(unsigned char Data)
//{
//  GPIO_SetBits(GPIOA, LCD_RS);
//  LCD_SendCommand(Data);
//  GPIO_ResetBits(GPIOA, LCD_RS);
//}

//void LCD_Puts(char *s)
//{
//  while (*s)
//  {
//    LCD_PutChar(*s);
//    s++;
//  }
//}