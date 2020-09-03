/******************************************************************************
 * @file     Pcf8574a.c
 * @brief    This file provides all the Command functions.
 * @version  V1.1.0
 * @date     2020/06/18
 ******************************************************************************/
/*
 * Description : 
 *
 *
 * Compiler    : IAR (Ver 8.40.2.22891)
 * CPU         : STM32F105VC
 * Flash       : 256KByte
 * Ram         : 64KByte
 *
 ******************************************************************************/

/** @addtogroup 
  * @{
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
//Devices
#include "Pcf8574a.h"

/* Private define ------------------------------------------------------------*/
//#define PCF8574A_ADDR 0x4E<<1
//#define PCF8574A_ADDR 0x27<<1
#define PCF8574A_ADDR 0x3F<<1
//#define PCF8574A_ADDR 0x08<<1
//#define PCF8574A_ADDR 0x27<<1
//#define PCF8574A_ADDR 0x40<<1

/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
 * lcd_send_cmd Function.
 ******************************************************************************/
void lcd_send_cmd(char cmd)
{
	char data_u, data_l;
	uint8_t data_t[4];
	
	data_u = (cmd&0xf0);
	data_l = ((cmd<<4)&0xf0);
	data_t[0] = data_u|0x0C;  //en=1, rs=0
	data_t[1] = data_u|0x08;  //en=0, rs=0
	data_t[2] = data_l|0x0C;  //en=1, rs=0
	data_t[3] = data_l|0x08;  //en=0, rs=0
	
	HAL_I2C_Master_Transmit(&hi2c2, PCF8574A_ADDR,(uint8_t *) data_t, 4, 100);
}

/*******************************************************************************
 * lcd_send_data Function.
 ******************************************************************************/
void lcd_send_data(char data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	
	data_u = (data&0xf0);
	data_l = ((data<<4)&0xf0);
	data_t[0] = data_u|0x0D;  //en=1, rs=0
	data_t[1] = data_u|0x09;  //en=0, rs=0
	data_t[2] = data_l|0x0D;  //en=1, rs=0
	data_t[3] = data_l|0x09;  //en=0, rs=0
	
	HAL_I2C_Master_Transmit(&hi2c2, PCF8574A_ADDR,(uint8_t *) data_t, 4, 100);
}

/*******************************************************************************
 * lcd_init Function.
 ******************************************************************************/
void lcd_init(void)
{
	lcd_send_cmd(0x02);
	lcd_send_cmd(0x28);
	lcd_send_cmd(0x0c);
	lcd_send_cmd(LCD_SET_DDRAM_ADDRESS);
}

/*******************************************************************************
 * lcd_send_string Function.
 ******************************************************************************/
void lcd_send_string(char *str)
{
	while (*str) lcd_send_data (*str++);
}

/*******************************************************************************
 * lcd_gotoxy Function.
 ******************************************************************************/
void lcd_gotoxy(uint8_t x, uint8_t y)
{
#if LCD_LINES == 1 
	lcd_send_cmd(LCD_SET_DDRAM_ADDRESS | (LCD_START_LINE_1 + x));
#elif LCD_LINES == 2
	if (y == 0)
		lcd_send_cmd(LCD_SET_DDRAM_ADDRESS | (LCD_START_LINE_1 + x));
	else
		lcd_send_cmd(LCD_SET_DDRAM_ADDRESS | (LCD_START_LINE_2 + x));
#elif LCD_LINES == 4
	if (y == 0)
		lcd_send_cmd(LCD_SET_DDRAM_ADDRESS | (LCD_START_LINE_1 + x));
	else if (y == 1)
		lcd_send_cmd(LCD_SET_DDRAM_ADDRESS | (LCD_START_LINE_2 + x));
	else if (y == 2)
		lcd_send_cmd(LCD_SET_DDRAM_ADDRESS | (LCD_START_LINE_3 + x));
	else
		lcd_send_cmd(LCD_SET_DDRAM_ADDRESS | (LCD_START_LINE_4 + x));
#endif
}

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
