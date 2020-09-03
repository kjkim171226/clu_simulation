/******************************************************************************
 * @file     Event.h
 * @brief    Event header file
 * @version  V1.1.0
 * @date     2020/04/06
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
#ifndef __EVENT_H
#define __EVENT_H

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

/* Exported functions --------------------------------------------------------*/
extern void SystemReset(void);

extern void Lcan_deepsleepmode_l(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8);
extern void Lcan_mcwarn(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8);
extern void Lcan_mcind(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8);
extern void Lcan_mcind1(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8);
extern void Lcan_acbh(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8);
extern void Lcan_clutest_l(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8);
extern void Ccan_bmsatat0(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8);
extern void Ccan_bmsatat1(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8);
extern void Ccan_bmsatat3(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8);
extern void Ccan_speedpower(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8);
extern void Ccan_clutest_c(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8);

extern void Clu_Test_CCan(uint8_t true);
extern void Clu_Test_LCan(uint8_t true);
extern void Clu_Test_Buzzer(uint8_t true);
extern void Clu_Test_All(uint8_t true);

extern void Dot_Lcd_Set(uint8_t option);

#endif  /* __EVENT_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
