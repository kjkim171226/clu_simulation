/******************************************************************************
 * @file     Can.c
 * @brief    This file provides all the CanEvent functions.
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

/** @addtogroup 
  * @{
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
//Devices
#include "Can.h"

/* Private variables ---------------------------------------------------------*/
TxProtocol g_TxCan[255];	// Tx array

/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
 * Can1Send Function.
 ******************************************************************************/
void Can1Send(uint8_t dbc)
{
//	printf("===>> Func:%s, dbc = %d !!\r\n", __FUNCTION__, dbc);

	/* Start the Transmission process */
	if (HAL_CAN_AddTxMessage(&hcan1, &g_TxCan[dbc].TxHeader, g_TxCan[dbc].TxData, &g_TxCan[dbc].TxMailbox) != HAL_OK)
	{
		printf(" Can1Send Error dbc = %d !!\r\n", dbc);
		Error_Handler();
	}
}

/*******************************************************************************
 * Can1Receive Function.
 ******************************************************************************/
void Can1Receive(uint32_t RxFifo, CAN_RxHeaderTypeDef *pHeader, uint8_t aData[])
{
	/* Start the Receive process */
}
 
/*******************************************************************************
 * Can2Send Function.
 ******************************************************************************/
void Can2Send(uint8_t dbc)
{
//	printf("===>> Func:%s, dbc = %d !!\r\n", __FUNCTION__, dbc);

	/* Start the Transmission process */
	if (HAL_CAN_AddTxMessage(&hcan2, &g_TxCan[dbc].TxHeader, g_TxCan[dbc].TxData, &g_TxCan[dbc].TxMailbox) != HAL_OK)
	{
		printf(" Can2Send Error dbc = %d !!\r\n", dbc);
		Error_Handler();
	}
}

/*******************************************************************************
 * Can2Receive Function.
 ******************************************************************************/
void Can2Receive(uint32_t RxFifo, CAN_RxHeaderTypeDef *pHeader, uint8_t aData[])
{
	/* Start the Receive process */
}

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
