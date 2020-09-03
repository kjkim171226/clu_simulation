/******************************************************************************
 * @file     Can.h
 * @brief    Can header file
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
#ifndef __CAN_H
#define __CAN_H

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

/* Private define ------------------------------------------------------------*/
/* CAN_ID define 29bit*/
//------------------------------------------------------------------------------
//L-CAN
#define CAN_29B_DEEP_SLEEP_MODE_L	0x00C5D22E		//100ms
#define CAN_29B_MC_WARN				0x00C601E8		//100ms
#define CAN_29B_MC_IND				0x00CC60AB		//100ms
#define CAN_29B_MC_IND1				0x00CD77AE		//100ms
#define CAN_29B_AC_B_H				0x0CEEC09C		//100ms
#define CAN_29B_CLU_TEST			0x014A5943		//100ms
//C-CAN
#define CAN_29B_BMS_STAT0			0x004B04C6		//20ms
#define CAN_29B_BMS_STAT1			0x004B770C		//20ms
#define CAN_29B_BMS_STAT3			0x004B995E		//20ms
#define CAN_29B_SPEED_POWER			0x007C707C		//20ms

/* Private typedef -----------------------------------------------------------*/
typedef struct __TxProtocol
{
  CAN_TxHeaderTypeDef TxHeader;
  uint8_t TxData[8];
  uint32_t TxMailbox;
} TxProtocol;

typedef struct __RxProtocol
{
  CAN_RxHeaderTypeDef RxHeader;
  uint8_t RxData[8];
} RxProtocol;


/* Private variables ---------------------------------------------------------*/
extern TxProtocol g_TxCan[255];	// Tx array
extern RxProtocol g_RxCan[2];	// Rx array

/* Exported functions --------------------------------------------------------*/
extern void Can1Send(uint8_t dbc);
extern void Can1Receive(uint32_t RxFifo, CAN_RxHeaderTypeDef *pHeader, uint8_t aData[]);

extern void Can2Send(uint8_t dbc);
extern void Can2Receive(uint32_t RxFifo, CAN_RxHeaderTypeDef *pHeader, uint8_t aData[]);

#endif  /* __CAN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
