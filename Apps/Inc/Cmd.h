/******************************************************************************
 * @file     Cmd.h
 * @brief    Cmd header file
 * @version  V1.1.0
 * @date     2020/04/03
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
#ifndef __CMD_H
#define __CMD_H

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

/* Exported define -----------------------------------------------------------*/
#define TX_TIMEOUT						((uint32_t)100)
#define RX_TIMEOUT						HAL_MAX_DELAY

#define _DEBG_MAX_LEN					100
#define _DEBUG_TX_FIFO_LENGTH			100

/* Exported typedef ----------------------------------------------------------*/
typedef struct _DEBUG_BASIC_FORMAT
{
	uint8_t Index;
	uint8_t Buf[_DEBG_MAX_LEN];
	uint8_t Complet;

	uint8_t TxFifo[_DEBUG_TX_FIFO_LENGTH][_DEBG_MAX_LEN];
	uint8_t TxPush;
	uint8_t TxPop;
	uint8_t TxSema;
}DEBUG_BASIC_FORMAT;

/* Exported functions --------------------------------------------------------*/
extern void Serial_TakePut(uint8_t param);
extern void DebugRxMsgParser(uint8_t *buf, uint8_t len);
extern void DebugRxTask(void);

#endif  /* __CMD_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
