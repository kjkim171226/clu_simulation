/******************************************************************************
 * @file     Pcf8574a.h
 * @brief    Pcf8574a header file
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PCF8574A_H
#define __PCF8574A_H

//==============================================================================
/* Includes ------------------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported define -----------------------------------------------------------*/
/* Exported typedef ----------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
//==============================================================================

/** Display size ------------------------------------------------------------ */
// Number of visible lines of the display (1 or 2/4)
#define LCD_LINES			4
// Visible characters per line of the display
#define LCD_DISP_LENGTH		20
// DDRAM address of first char of line 1
#define LCD_START_LINE_1	0x00
// DDRAM address of first char of line 2
#define LCD_START_LINE_2	0x40
// DDRAM address of first char of line 3
#define LCD_START_LINE_3	0x14
// DDRAM address of first char of line 4
#define LCD_START_LINE_4	0x54

#define CLEARROW 0x01

#define LCD_SET_DDRAM_ADDRESS 0x80

/* Exported functions --------------------------------------------------------*/
extern void lcd_init(void);
extern void lcd_send_cmd(char cmd);
extern void lcd_send_data(char data);
extern void lcd_send_string(char *str);
extern void lcd_gotoxy(uint8_t x, uint8_t y);

#endif  /* __PCF8574A_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
