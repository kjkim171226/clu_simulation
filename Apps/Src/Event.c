/******************************************************************************
 * @file     Event.c
 * @brief    This file provides all the Event functions.
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
//Apps
#include "Event.h"
//Devices
#include "Can.h"
#include "Pcf8574a.h"

/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
 * SystemReset Function.
 ******************************************************************************/
void SystemReset(void)
{
	NVIC_SystemReset();
}

/*******************************************************************************
 * Lcan_deepsleepmode_l Function.
 ******************************************************************************/
void Lcan_deepsleepmode_l(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8)
{
//	printf("===>> Func:%s, dbc = %d !!\r\n", __FUNCTION__, dbc);

	if (dbc)
	{
		g_TxCan[dbc].TxHeader.ExtId = CAN_29B_DEEP_SLEEP_MODE_L;
		g_TxCan[dbc].TxHeader.IDE = CAN_ID_EXT;
		g_TxCan[dbc].TxHeader.RTR = CAN_RTR_DATA;
		g_TxCan[dbc].TxHeader.DLC = 8;
		g_TxCan[dbc].TxHeader.TransmitGlobalTime = DISABLE;
		g_TxCan[dbc].TxData[0] = byte1;
		g_TxCan[dbc].TxData[1] = byte2;
		g_TxCan[dbc].TxData[2] = byte3;
		g_TxCan[dbc].TxData[3] = byte4;
		g_TxCan[dbc].TxData[4] = byte5;
		g_TxCan[dbc].TxData[5] = byte6;
		g_TxCan[dbc].TxData[6] = byte7;
		g_TxCan[dbc].TxData[7] = byte8;
	}
	//DEEP_SLEEP_MODE_L=enable
	//	g_TxCan[dbc].TxData[0] = 0x08;
}

/*******************************************************************************
 * Lcan_mcwarn Function.
 ******************************************************************************/
void Lcan_mcwarn(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8)
{
//	printf("===>> Func:%s, dbc = %d !!\r\n", __FUNCTION__, dbc);

	if (dbc)
	{
		g_TxCan[dbc].TxHeader.ExtId = CAN_29B_MC_WARN;
		g_TxCan[dbc].TxHeader.IDE = CAN_ID_EXT;
		g_TxCan[dbc].TxHeader.RTR = CAN_RTR_DATA;
		g_TxCan[dbc].TxHeader.DLC = 8;
		g_TxCan[dbc].TxHeader.TransmitGlobalTime = DISABLE;
		g_TxCan[dbc].TxData[0] = byte1;
		g_TxCan[dbc].TxData[1] = byte2;
		g_TxCan[dbc].TxData[2] = byte3;
		g_TxCan[dbc].TxData[3] = byte4;
		g_TxCan[dbc].TxData[4] = byte5;
		g_TxCan[dbc].TxData[5] = byte6;
		g_TxCan[dbc].TxData[6] = byte7;
		g_TxCan[dbc].TxData[7] = byte8;
	}
	//BAT_TEMP_W=Low
	//	g_TxCan[dbc].TxData[0] = 0x01;

	//BAT_TEMP_W=Overheat
	//	g_TxCan[dbc].TxData[0] = 0x02;
}

/*******************************************************************************
 * Lcan_mcind Function.
 ******************************************************************************/
void Lcan_mcind(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8)
{
//	printf("===>> Func:%s, dbc = %d !!\r\n", __FUNCTION__, dbc);

	if (dbc)
	{
		g_TxCan[dbc].TxHeader.ExtId = CAN_29B_MC_IND;
		g_TxCan[dbc].TxHeader.IDE = CAN_ID_EXT;
		g_TxCan[dbc].TxHeader.RTR = CAN_RTR_DATA;
		g_TxCan[dbc].TxHeader.DLC = 8;
		g_TxCan[dbc].TxHeader.TransmitGlobalTime = DISABLE;
		g_TxCan[dbc].TxData[0] = byte1;
		g_TxCan[dbc].TxData[1] = byte2;
		g_TxCan[dbc].TxData[2] = byte3;
		g_TxCan[dbc].TxData[3] = byte4;
		g_TxCan[dbc].TxData[4] = byte5;
		g_TxCan[dbc].TxData[5] = byte6;
		g_TxCan[dbc].TxData[6] = byte7;
		g_TxCan[dbc].TxData[7] = byte8;
	}
	//Ready=1, RND=R
	//	g_TxCan[dbc].TxData[0] = 0x04;
	//Ready=1, RND=N
	//	g_TxCan[dbc].TxData[0] = 0x07;
	//Ready=1, RND=D
	//	g_TxCan[dbc].TxData[0] = 0x06;
}

/*******************************************************************************
 * Lcan_mcind1 Function.
 ******************************************************************************/
void Lcan_mcind1(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8)
{
//	printf("===>> Func:%s, dbc = %d !!\r\n", __FUNCTION__, dbc);

	if (dbc)
	{
		g_TxCan[dbc].TxHeader.ExtId = CAN_29B_MC_IND1;
		g_TxCan[dbc].TxHeader.IDE = CAN_ID_EXT;
		g_TxCan[dbc].TxHeader.RTR = CAN_RTR_DATA;
		g_TxCan[dbc].TxHeader.DLC = 8;
		g_TxCan[dbc].TxHeader.TransmitGlobalTime = DISABLE;
		g_TxCan[dbc].TxData[0] = byte1;
		g_TxCan[dbc].TxData[1] = byte2;
		g_TxCan[dbc].TxData[2] = byte3;
		g_TxCan[dbc].TxData[3] = byte4;
		g_TxCan[dbc].TxData[4] = byte5;
		g_TxCan[dbc].TxData[5] = byte6;
		g_TxCan[dbc].TxData[6] = byte7;
		g_TxCan[dbc].TxData[7] = byte8;
	}
}

/*******************************************************************************
 * Lcan_acbh Function.
 ******************************************************************************/
void Lcan_acbh(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8)
{
//	printf("===>> Func:%s, dbc = %d !!\r\n", __FUNCTION__, dbc);

	if (dbc)
	{
		g_TxCan[dbc].TxHeader.ExtId = CAN_29B_AC_B_H;
		g_TxCan[dbc].TxHeader.IDE = CAN_ID_EXT;
		g_TxCan[dbc].TxHeader.RTR = CAN_RTR_DATA;
		g_TxCan[dbc].TxHeader.DLC = 8;
		g_TxCan[dbc].TxHeader.TransmitGlobalTime = DISABLE;
		g_TxCan[dbc].TxData[0] = byte1;
		g_TxCan[dbc].TxData[1] = byte2;
		g_TxCan[dbc].TxData[2] = byte3;
		g_TxCan[dbc].TxData[3] = byte4;
		g_TxCan[dbc].TxData[4] = byte5;
		g_TxCan[dbc].TxData[5] = byte6;
		g_TxCan[dbc].TxData[6] = byte7;
		g_TxCan[dbc].TxData[7] = byte8;
	}
	//ac_b=enable
	//	g_TxCan[dbc].TxData[0] = 0x01;
}

/*******************************************************************************
 * Lcan_clutest_l Function.
 ******************************************************************************/
void Lcan_clutest_l(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8)
{
//	printf("===>> Func:%s, dbc = %d !!\r\n", __FUNCTION__, dbc);

	if (dbc)
	{
		g_TxCan[dbc].TxHeader.ExtId = CAN_29B_CLU_TEST;
		g_TxCan[dbc].TxHeader.IDE = CAN_ID_EXT;
		g_TxCan[dbc].TxHeader.RTR = CAN_RTR_DATA;
		g_TxCan[dbc].TxHeader.DLC = 8;
		g_TxCan[dbc].TxHeader.TransmitGlobalTime = DISABLE;
		g_TxCan[dbc].TxData[0] = byte1;
		g_TxCan[dbc].TxData[1] = byte2;
		g_TxCan[dbc].TxData[2] = byte3;
		g_TxCan[dbc].TxData[3] = byte4;
		g_TxCan[dbc].TxData[4] = byte5;
		g_TxCan[dbc].TxData[5] = byte6;
		g_TxCan[dbc].TxData[6] = byte7;
		g_TxCan[dbc].TxData[7] = byte8;
	}
	//CLUSTER_TEST=CLU_SOC_RESET
	//	g_TxCan[dbc].TxData[2] = 0x03;
	//CLUSTER_TEST=CLU_MCU_RESET
	//	g_TxCan[dbc].TxData[3] = 0x03;
}

/*******************************************************************************
 * Ccan_bmsatat0 Function.
 ******************************************************************************/
void Ccan_bmsatat0(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8)
{
//	printf("===>> Func:%s, dbc = %d !!\r\n", __FUNCTION__, dbc);

	if (dbc)
	{
		g_TxCan[dbc].TxHeader.ExtId = CAN_29B_BMS_STAT0;
		g_TxCan[dbc].TxHeader.IDE = CAN_ID_EXT;
		g_TxCan[dbc].TxHeader.RTR = CAN_RTR_DATA;
		g_TxCan[dbc].TxHeader.DLC = 8;
		g_TxCan[dbc].TxHeader.TransmitGlobalTime = DISABLE;
		g_TxCan[dbc].TxData[0] = byte1;
		g_TxCan[dbc].TxData[1] = byte2;
		g_TxCan[dbc].TxData[2] = byte3;
		g_TxCan[dbc].TxData[3] = byte4;
		g_TxCan[dbc].TxData[4] = byte5;
		g_TxCan[dbc].TxData[5] = byte6;
		g_TxCan[dbc].TxData[6] = byte7;
		g_TxCan[dbc].TxData[7] = byte8;
	}
}

/*******************************************************************************
 * Ccan_bmsatat1 Function.
 ******************************************************************************/
void Ccan_bmsatat1(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8)
{
//	printf("===>> Func:%s, dbc = %d !!\r\n", __FUNCTION__, dbc);

	if (dbc)
	{
		g_TxCan[dbc].TxHeader.ExtId = CAN_29B_BMS_STAT1;
		g_TxCan[dbc].TxHeader.IDE = CAN_ID_EXT;
		g_TxCan[dbc].TxHeader.RTR = CAN_RTR_DATA;
		g_TxCan[dbc].TxHeader.DLC = 8;
		g_TxCan[dbc].TxHeader.TransmitGlobalTime = DISABLE;
		g_TxCan[dbc].TxData[0] = byte1;
		g_TxCan[dbc].TxData[1] = byte2;
		g_TxCan[dbc].TxData[2] = byte3;
		g_TxCan[dbc].TxData[3] = byte4;
		g_TxCan[dbc].TxData[4] = byte5;
		g_TxCan[dbc].TxData[5] = byte6;
		g_TxCan[dbc].TxData[6] = byte7;
		g_TxCan[dbc].TxData[7] = byte8;
	}
}

/*******************************************************************************
 * Ccan_bmsatat3 Function.
 ******************************************************************************/
void Ccan_bmsatat3(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8)
{
//	printf("===>> Func:%s, dbc = %d !!\r\n", __FUNCTION__, dbc);

	if (dbc)
	{
		g_TxCan[dbc].TxHeader.ExtId = CAN_29B_BMS_STAT3;
		g_TxCan[dbc].TxHeader.IDE = CAN_ID_EXT;
		g_TxCan[dbc].TxHeader.RTR = CAN_RTR_DATA;
		g_TxCan[dbc].TxHeader.DLC = 8;
		g_TxCan[dbc].TxHeader.TransmitGlobalTime = DISABLE;
		g_TxCan[dbc].TxData[0] = byte1;
		g_TxCan[dbc].TxData[1] = byte2;
		g_TxCan[dbc].TxData[2] = byte3;
		g_TxCan[dbc].TxData[3] = byte4;
		g_TxCan[dbc].TxData[4] = byte5;
		g_TxCan[dbc].TxData[5] = byte6;
		g_TxCan[dbc].TxData[6] = byte7;
		g_TxCan[dbc].TxData[7] = byte8;
	}
}

/*******************************************************************************
 * Ccan_bmsatat3 Function.
 ******************************************************************************/
void Ccan_speedpower(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8)
{
//	printf("===>> Func:%s, dbc = %d !!\r\n", __FUNCTION__, dbc);

	if (dbc)
	{
		g_TxCan[dbc].TxHeader.ExtId = CAN_29B_SPEED_POWER;
		g_TxCan[dbc].TxHeader.IDE = CAN_ID_EXT;
		g_TxCan[dbc].TxHeader.RTR = CAN_RTR_DATA;
		g_TxCan[dbc].TxHeader.DLC = 8;
		g_TxCan[dbc].TxHeader.TransmitGlobalTime = DISABLE;
		g_TxCan[dbc].TxData[0] = byte1;
		g_TxCan[dbc].TxData[1] = byte2;
		g_TxCan[dbc].TxData[2] = byte3;
		g_TxCan[dbc].TxData[3] = byte4;
		g_TxCan[dbc].TxData[4] = byte5;
		g_TxCan[dbc].TxData[5] = byte6;
		g_TxCan[dbc].TxData[6] = byte7;
		g_TxCan[dbc].TxData[7] = byte8;
	}
	
	//Speed_Power:Vh=50
	//	g_TxCan[dbc].TxData[1] = 0xF4;
	//	g_TxCan[dbc].TxData[2] = 0x01;
}

/*******************************************************************************
 * Lcan_clutest_c Function.
 ******************************************************************************/
void Ccan_clutest_c(uint8_t dbc, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7, uint8_t byte8)
{
//	printf("===>> Func:%s, dbc = %d !!\r\n", __FUNCTION__, dbc);

	if (dbc)
	{
		g_TxCan[dbc].TxHeader.ExtId = CAN_29B_CLU_TEST;
		g_TxCan[dbc].TxHeader.IDE = CAN_ID_EXT;
		g_TxCan[dbc].TxHeader.RTR = CAN_RTR_DATA;
		g_TxCan[dbc].TxHeader.DLC = 8;
		g_TxCan[dbc].TxHeader.TransmitGlobalTime = DISABLE;
		g_TxCan[dbc].TxData[0] = byte1;
		g_TxCan[dbc].TxData[1] = byte2;
		g_TxCan[dbc].TxData[2] = byte3;
		g_TxCan[dbc].TxData[3] = byte4;
		g_TxCan[dbc].TxData[4] = byte5;
		g_TxCan[dbc].TxData[5] = byte6;
		g_TxCan[dbc].TxData[6] = byte7;
		g_TxCan[dbc].TxData[7] = byte8;
	}
	
	//CLUSTER_TEST=CLU_SOC_RESET
	//	g_TxCan[dbc].TxData[2] = 0x03;

	//CLUSTER_TEST=CLU_MCU_RESET
	//	g_TxCan[dbc].TxData[3] = 0x03;
}

/*******************************************************************************
 * Clu_Test_CCan Function.
 ******************************************************************************/
void Clu_Test_CCan(uint8_t true)
{
	if (true)
	{
		printf("  C-CAN test: set!! \r\n");
		
		HAL_GPIO_WritePin(EXT_ACC_EN_GPIO_Port, EXT_ACC_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(4500);
		
#if WS_BS0
		printf("  => BMS_STAT0: SOC = 00%!! \r\n");
		Ccan_bmsatat0(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(1);
		HAL_Delay(500);
		
		printf("  => BMS_STAT0: SOC = 25%!! \r\n");
		Ccan_bmsatat0(1, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(1);
		HAL_Delay(500);
		
		printf("  => BMS_STAT0: SOC = 50%!! \r\n");
		Ccan_bmsatat0(1, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(1);
		HAL_Delay(500);
		
		printf("  => BMS_STAT0: SOC = 75%!! \r\n");
		Ccan_bmsatat0(1, 0x4B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(1);
		HAL_Delay(500);
		
		printf("  => BMS_STAT0: SOC = 100%!! \r\n");
		Ccan_bmsatat0(1, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(1);
		HAL_Delay(1000);
		
#endif
#if DV_BS1
		printf("  => BMS_STAT1: BMS_SOC_EXT = 00%!! \r\n");
		Ccan_bmsatat1(7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78);		//12.0
		Can2Send(7);
		HAL_Delay(500);
		
		printf("  => BMS_STAT1: BMS_SOC_EXT = 25%!! \r\n");
		Ccan_bmsatat1(7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x5E);		//35.0
		Can2Send(7);
		HAL_Delay(500);
		
		printf("  => BMS_STAT1: BMS_SOC_EXT = 50%!! \r\n");
		Ccan_bmsatat1(7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x26);		//55.0
		Can2Send(7);
		HAL_Delay(500);
		
		printf("  => BMS_STAT1: BMS_SOC_EXT = 75%!! \r\n");
		Ccan_bmsatat1(7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xEE);		//75.0
		Can2Send(7);
		HAL_Delay(500);
		
		printf("  => BMS_STAT1: BMS_SOC_EXT = 100%!! \r\n");
		Ccan_bmsatat1(7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xB6);		//95.0
		Can2Send(7);
		HAL_Delay(1000);
#endif
		printf("  => BMS_STAT3: CHARGE_TIME_REMAIN = 0!! \r\n");
		Ccan_bmsatat3(2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(500);
		
		printf("  => BMS_STAT3: CHARGE_TIME_REMAIN = 32767!! \r\n");
		Ccan_bmsatat3(2, 0x00, 0x7F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(500);
		
		printf("  => BMS_STAT3: CHARGE_TIME_REMAIN = 65535!! \r\n");
		Ccan_bmsatat3(2, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(1000);
		
		printf("  => Speed_Power: Vh = 00!! \r\n");
		Ccan_speedpower(2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(1000);
		
		printf("  => Speed_Power: Vh = 20!! \r\n");
		Ccan_speedpower(2, 0x00, 0xC8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(1000);
		
		printf("  => Speed_Power: Vh = 40!! \r\n");
		Ccan_speedpower(2, 0x00, 0x90, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(1000);
		
		printf("  => Speed_Power: Vh = 60!! \r\n");
		Ccan_speedpower(2, 0x00, 0x58, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(1000);
		
		printf("  => Speed_Power: Vh = 80!! \r\n");
		Ccan_speedpower(2, 0x00, 0x20, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = 00!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = 30!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0xB8, 0x0B, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = 60!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x70, 0x17, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = 90!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x28, 0x23, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = 120!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x2E, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = 150!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x98, 0x3A, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = 00!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = -10!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0xF6, 0xFF, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = -20!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0xEC, 0xFF, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = -30!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0xE2, 0xFF, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = -100!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x9C, 0xFF, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = -150!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xFF, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);
	}
	else
	{
		printf("  C-CAN test: reset!! \r\n");

		printf("  => BMS_STAT0: SOC = 00%!! \r\n");
		Ccan_bmsatat0(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(1);
		HAL_Delay(500);
		
		printf("  => BMS_STAT1: BMS_SOC_EXT = 00%!! \r\n");
		Ccan_bmsatat1(7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(7);
		HAL_Delay(500);

		printf("  => BMS_STAT3: CHARGE_TIME_REMAIN = 0!! \r\n");
		Ccan_bmsatat3(2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(500);

		printf("  => Speed_Power: Vh = 00!! \r\n");
		Ccan_speedpower(2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(500);

		printf("  => Speed_Power: Pw_MOT = 00! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(3000);
		
		HAL_GPIO_WritePin(EXT_ACC_EN_GPIO_Port, EXT_ACC_EN_Pin, GPIO_PIN_RESET);
	}

}


/*******************************************************************************
 * Clu_Test_LCan Function.
 ******************************************************************************/
void Clu_Test_LCan(uint8_t true)
{
	if (true)
	{
		printf("  L-CAN test: set!! \r\n");
		
		HAL_GPIO_WritePin(EXT_ACC_EN_GPIO_Port, EXT_ACC_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(4500);

		
		printf("  => MC_WARN: BAT_TEMP_W = Low!! \r\n");
		Lcan_mcwarn(1, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(4500);
		
		printf("  => MC_WARN: BAT_TEMP_W = Overheated!! \r\n");
		Lcan_mcwarn(1, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(1000);

		
		printf("  => MC_IND: READY_D = 1, GEAR_STATUS = R!! \r\n");
		Lcan_mcind(1, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);
		
		printf("  => MC_IND: READY_D = 1, GEAR_STATUS = N(P)!! \r\n");
		Lcan_mcind(1, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);
		
		printf("  => MC_IND: READY_D = 1, GEAR_STATUS = D!! \r\n");
		Lcan_mcind(1, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(1000);

		
		printf("  => AC_B_H: AC_BAT_HEAT = enable!! \r\n");
		Lcan_acbh(1, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(1000);

		
		printf("  => Deep_Sleep_L: DEEP_SLEEP_MODE_L = enable!! \r\n");
		for (int i = 0; i < 100; i++) {
			Lcan_deepsleepmode_l(1, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
			Can1Send(1);
			HAL_Delay(100);
		}
		HAL_Delay(1000);

		
		printf("  => ACC: reset!! \r\n");
		HAL_GPIO_WritePin(EXT_ACC_EN_GPIO_Port, EXT_ACC_EN_Pin, GPIO_PIN_RESET);
		HAL_Delay(500);
		HAL_GPIO_WritePin(EXT_ACC_EN_GPIO_Port, EXT_ACC_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(5000);

		
		printf("  => CLU_TEST: MCU_RESET = enable!! \r\n");
		Lcan_clutest_l(4, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00);
		Can1Send(4);
		HAL_Delay(5000);
		
		printf("  => CLU_TEST: SOC_RESET = enable!! \r\n");
		Lcan_clutest_l(3, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(3);
		HAL_Delay(1000);
		
	}
	else
	{
		printf("  L-CAN test: reset!! \r\n");

		printf("  => MC_WARN: disable!! \r\n");
		Lcan_mcwarn(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);
		
		printf("  => MC_IND: disable!! \r\n");
		Lcan_mcind(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);

		printf("  => AC_B_H: disable!! \r\n");
		Lcan_acbh(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);

		printf("  => Deep_Sleep_L: disable!! \r\n");
		Lcan_deepsleepmode_l(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);

		printf("  => CLU_TEST: MCU_RESET = disable!! \r\n");
		Lcan_clutest_l(4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(4);
		HAL_Delay(500);

		printf("  => CLU_TEST: SOC_RESET = disable!! \r\n");
		Lcan_clutest_l(3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(3);
		HAL_Delay(3000);
		
		HAL_GPIO_WritePin(EXT_ACC_EN_GPIO_Port, EXT_ACC_EN_Pin, GPIO_PIN_RESET);
	}
}

/*******************************************************************************
 * Clu_Test_Buzzer Function.
 ******************************************************************************/
void Clu_Test_Buzzer(uint8_t true)
{
	if (true)
	{
		printf("  BUZZER test: set!! \r\n");
		
		HAL_GPIO_WritePin(EXT_ACC_EN_GPIO_Port, EXT_ACC_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(4500);

		HAL_GPIO_WritePin(EXT_IGN1_EN_GPIO_Port, EXT_IGN1_EN_Pin, GPIO_PIN_SET);

		printf("  1. Door Ajar Warning Buzzer!! \r\n");
		printf("  => MC_IND: READY_D = 1, GEAR_STATUS = D!! \r\n");
		Lcan_mcind(1, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);
		
		printf("  => Speed_Power: Vh = 20!! \r\n");
		Ccan_speedpower(2, 0x00, 0xC8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(500);
		
		HAL_GPIO_WritePin(DOOR_EN_GPIO_Port, DOOR_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(61000);
		
		HAL_GPIO_WritePin(DOOR_EN_GPIO_Port, DOOR_EN_Pin, GPIO_PIN_RESET);
		HAL_Delay(1000);

		printf("  2. Parking Brake Warning Buzzer!! \r\n");
		HAL_GPIO_WritePin(PARKING_BRAKE_EN_GPIO_Port, PARKING_BRAKE_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(61000);
		
		HAL_GPIO_WritePin(PARKING_BRAKE_EN_GPIO_Port, PARKING_BRAKE_EN_Pin, GPIO_PIN_RESET);
		HAL_Delay(1000);

		printf("  3. Seat Belt Warning Buzzer!! \r\n");
		HAL_GPIO_WritePin(SEAT_BELT_EN_GPIO_Port, SEAT_BELT_EN_Pin, GPIO_PIN_RESET);
		HAL_Delay(61000);
		
		HAL_GPIO_WritePin(SEAT_BELT_EN_GPIO_Port, SEAT_BELT_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(1000);

		printf("  => MC_IND: disable!! \r\n");
		Lcan_mcind(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);
		
		printf("  => Speed_Power: disable!! \r\n");
		Ccan_speedpower(2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(500);
		
		HAL_GPIO_WritePin(EXT_IGN1_EN_GPIO_Port, EXT_IGN1_EN_Pin, GPIO_PIN_RESET);
		HAL_Delay(1000);

		printf("  4. SSB Warning Buzzer!! \r\n");
		printf("  => MC_IND: GEAR_STATUS = D!! \r\n");
		Lcan_mcind(1, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);
		
		printf("  => MC_WARN: GEAR_POSITION_W!! \r\n");
		Lcan_mcwarn(2, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(2);
		HAL_Delay(61000);
		
		printf("  => MC_IND: GEAR_STATUS = N(P)!! \r\n");
		Lcan_mcind(1, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);
		
		printf("  => MC_WARN: disable!! \r\n");
		Lcan_mcwarn(2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(2);
		HAL_Delay(1000);

		HAL_GPIO_WritePin(EXT_IGN1_EN_GPIO_Port, EXT_IGN1_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(1000);
		
		printf("  5. Gear Warning Buzzer!! \r\n");
		printf("  => MC_IND: READY_D = 1, GEAR_STATUS = D!! \r\n");
		Lcan_mcind(1, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);
		
		printf("  => Speed_Power: Vh = 20!! \r\n");
		Ccan_speedpower(2, 0x00, 0xC8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(500);
		
		printf("  => MC_WARN: gear_text!! \r\n");
		Lcan_mcwarn(1, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(61000);
		
		printf("  => Speed_Power: disable!! \r\n");
		Ccan_speedpower(2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(500);
		
		printf("  => MC_IND: disable!! \r\n");
		Lcan_mcind(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);
		
		printf("  => MC_WARN: disable!! \r\n");
		Lcan_mcwarn(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(1000);

		HAL_GPIO_WritePin(EXT_IGN1_EN_GPIO_Port, EXT_IGN1_EN_Pin, GPIO_PIN_RESET);
		HAL_Delay(1000);

		printf("  6. Turn Off Warning Buzzer!! \r\n");
		printf("  => Speed_Power: Vh = 00!! \r\n");
		Ccan_speedpower(2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(500);
		
		HAL_GPIO_WritePin(PARKING_BRAKE_EN_GPIO_Port, PARKING_BRAKE_EN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(DOOR_EN_GPIO_Port, DOOR_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(61000);
		
		HAL_GPIO_WritePin(PARKING_BRAKE_EN_GPIO_Port, PARKING_BRAKE_EN_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(DOOR_EN_GPIO_Port, DOOR_EN_Pin, GPIO_PIN_RESET);
		HAL_Delay(1000);
	}
	else
	{
		printf("  BUZZER test: reset!! \r\n");

		HAL_Delay(3000);
		HAL_GPIO_WritePin(EXT_ACC_EN_GPIO_Port, EXT_ACC_EN_Pin, GPIO_PIN_RESET);
	}
}


/*******************************************************************************
 * Clu_Test_All Function.
 ******************************************************************************/
void Clu_Test_All(uint8_t true)
{
	if (true)
	{
		printf("  ALL: set!! \r\n");
		HAL_GPIO_WritePin(CHARGER_EN_GPIO_Port, CHARGER_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(EXT_ACC_EN_GPIO_Port, EXT_ACC_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(3000);


		//Left gauge
		printf("  Left gauge: on!! \r\n");
		printf("  => Speed_Power: Pw_MOT = 00!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = -10!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0xF6, 0xFF, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = -20!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0xEC, 0xFF, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = -30!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0xE2, 0xFF, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = -100!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x9C, 0xFF, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = -150!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xFF, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = 00!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = 30!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0xB8, 0x0B, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = 60!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x70, 0x17, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = 90!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x28, 0x23, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = 120!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x2E, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => Speed_Power: Pw_MOT = 150!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x98, 0x3A, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(1000);

		printf("  => MC_IND: GEAR_STATUS = R!! \r\n");
		Lcan_mcind(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(1000);

		printf("  => MC_IND: GEAR_STATUS = N(P)!! \r\n");
		Lcan_mcind(1, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(1000);				

		printf("  => MC_IND: GEAR_STATUS = D!! \r\n");
		Lcan_mcind(1, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(1000);
		
		HAL_GPIO_WritePin(EXT_IGN1_EN_GPIO_Port, EXT_IGN1_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(1000);


		//Left tell-tale
		printf("\r\n  Left tell-tale: on!! \r\n");
#if WS_BS0
		printf("  => BMS_STAT0: SOC = 04%!! \r\n");
		Ccan_bmsatat0(1, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(1);
		HAL_Delay(1000);
#endif
#if DV_BS1
		printf("  => BMS_STAT1: BMS_SOC_EXT = 04%!! \r\n");
		Ccan_bmsatat1(7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB8);		//18.4
		Can2Send(7);
		HAL_Delay(1000);
#endif
		printf("  => MC_WARN: SERVICE_W = 4:OBC error!! \r\n");
		Lcan_mcwarn(2, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(2);
		HAL_Delay(1000);

		printf("  => MC_WARN: COOLANT_W = 2!! \r\n");
		Lcan_mcwarn(1, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(1000);
		
		printf("  => MC_IND: READY_D = 1, GEAR_STATUS = D!! \r\n");
		Lcan_mcind(1, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(1000);

		printf("  => MC_WARN: LV_BAT_W = 1!! \r\n");
		Lcan_mcwarn(1, 0x08, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(1000);

		HAL_GPIO_WritePin(BRAKE_OIL_EN_GPIO_Port, BRAKE_OIL_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(1000);

		HAL_GPIO_WritePin(PARKING_BRAKE_EN_GPIO_Port, PARKING_BRAKE_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(1000);


		//Speed
		printf("\r\n  Center Speed: on!! \r\n");
		printf("  => Speed_Power: Vh = 60, Pw_MOT = 90!! \r\n");
		Ccan_speedpower(2, 0x00, 0x58, 0x02, 0x00, 0x28, 0x23, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(1000);


		//Right tell-tale
		printf("\r\n  Right tell-tale: on!! \r\n");
		HAL_GPIO_WritePin(SEAT_BELT_EN_GPIO_Port, SEAT_BELT_EN_Pin, GPIO_PIN_RESET);
		HAL_Delay(1000);
		
		HAL_GPIO_WritePin(DOOR_EN_GPIO_Port, DOOR_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(1000);
		
		HAL_GPIO_WritePin(IMMOBIL_EN_GPIO_Port, IMMOBIL_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(1000);
		
		printf("  => MC_WARN: charge_state = 2!! \r\n");
		Lcan_mcwarn(1, 0x88, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(1000);
		
		HAL_GPIO_WritePin(TEST_IN_EN_GPIO_Port, TEST_IN_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(1000);


		//Right gauge
		printf("\r\n  Right gauge: on!! \r\n");
#if WS_BS0
		printf("  => BMS_STAT0: SOC = 50%!! \r\n");
		Ccan_bmsatat0(1, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(1);
		HAL_Delay(1000);

		printf("  => BMS_STAT0: SOC = 100%!! \r\n");
		Ccan_bmsatat0(1, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(1);
		HAL_Delay(1000);
#endif
#if DV_BS1
		printf("  => BMS_STAT1: BMS_SOC_EXT = 50%!! \r\n");
		Ccan_bmsatat1(7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x26);		//55.0
		Can2Send(7);
		HAL_Delay(1000);

		printf("  => BMS_STAT1: BMS_SOC_EXT = 100%!! \r\n");
		Ccan_bmsatat1(7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xE0);		//99.2 > 95.2
		Can2Send(7);
		HAL_Delay(1000);
#endif


		//Down tell-tale
		printf("\r\n  Down tell-tale: on!! \r\n");
		printf("  => MC_WARN: BAT_TEMP_STEP = 13!! \r\n");
		Lcan_mcwarn(3, 0x88, 0x09, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(3);
		HAL_Delay(1000);
		printf("  => MC_WARN: BAT_TEMP_W = 1:Low!! \r\n");
		Lcan_mcwarn(1, 0x89, 0x09, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(1000);
		printf("  => MC_WARN: BAT_TEMP_W = 2:Overheated!! \r\n");
		Lcan_mcwarn(1, 0x8A, 0x09, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(TRIP_IN_EN_GPIO_Port, TRIP_IN_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(2000);
		HAL_GPIO_WritePin(TRIP_IN_EN_GPIO_Port, TRIP_IN_EN_Pin, GPIO_PIN_RESET);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(TRIP_IN_EN_GPIO_Port, TRIP_IN_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(2000);
		HAL_GPIO_WritePin(TRIP_IN_EN_GPIO_Port, TRIP_IN_EN_Pin, GPIO_PIN_RESET);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(TRIP_IN_EN_GPIO_Port, TRIP_IN_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(2000);
		HAL_GPIO_WritePin(TRIP_IN_EN_GPIO_Port, TRIP_IN_EN_Pin, GPIO_PIN_RESET);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(TRIP_IN_EN_GPIO_Port, TRIP_IN_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(2000);
		HAL_GPIO_WritePin(TRIP_IN_EN_GPIO_Port, TRIP_IN_EN_Pin, GPIO_PIN_RESET);
		HAL_Delay(1000);
//		HAL_GPIO_WritePin(TRIP_IN_EN_GPIO_Port, TRIP_IN_EN_Pin, GPIO_PIN_SET);
//		HAL_Delay(5000);
//		HAL_GPIO_WritePin(TRIP_IN_EN_GPIO_Port, TRIP_IN_EN_Pin, GPIO_PIN_RESET);
//		HAL_Delay(1000);
		printf("  => MC_IND: drivingmileage = 50km!! \r\n");
		Lcan_mcind(2, 0x96, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(2);
		HAL_Delay(1000);

		
		//Upper tell-tale
		printf("\r\n  Upper tell-tale: on!! \r\n");
		HAL_GPIO_WritePin(LAMP_LH_EN_GPIO_Port, LAMP_LH_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(FRT_FOG_LAMP_EN_GPIO_Port, FRT_FOG_LAMP_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(POS_LAMP_EN_GPIO_Port, POS_LAMP_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(HIGH_BEAM_EN_GPIO_Port, HIGH_BEAM_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(LOW_BEAM_EN_GPIO_Port, LOW_BEAM_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(LAMP_RH_EN_GPIO_Port, LAMP_RH_EN_Pin, GPIO_PIN_SET);
		HAL_Delay(1000);
	}
	else
	{
		printf("  ALL: reset!! \r\n");

#if WS_BS0
		printf("  => BMS_STAT0: SOC = 00%!! \r\n");
		Ccan_bmsatat0(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(1);
		HAL_Delay(500);
#endif
#if DV_BS1
		printf("  => BMS_STAT1: BMS_SOC_EXT = 00%!! \r\n");
		Ccan_bmsatat1(7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(7);
		HAL_Delay(500);
#endif
		printf("  => BMS_STAT3: Disable!! \r\n");
		Ccan_bmsatat3(2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(500);

		printf("  => Speed_Power: Disable!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(5);
		HAL_Delay(500);


		printf("  => MC_WARN: Disable!! \r\n");
		Lcan_mcwarn(2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(2);
		HAL_Delay(500);
		
		printf("  => MC_IND: disable!! \r\n");
		Lcan_mcind(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);

		printf("  => AC_B_H: disable!! \r\n");
		Lcan_acbh(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);

		printf("  => Deep_Sleep_L: disable!! \r\n");
		Lcan_deepsleepmode_l(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);

		printf("  => CLU_TEST: disable!! \r\n");
		Lcan_clutest_l(4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(4);
		HAL_Delay(500);

		printf("  => tell-tale: off!! \r\n");
		
		HAL_GPIO_WritePin(AIR_BAG_EN_GPIO_Port,			AIR_BAG_EN_Pin,			GPIO_PIN_RESET);
		HAL_GPIO_WritePin(RR_FOG_LAMP_EN_GPIO_Port,		RR_FOG_LAMP_EN_Pin,		GPIO_PIN_RESET);
		HAL_GPIO_WritePin(FRT_FOG_LAMP_EN_GPIO_Port,	FRT_FOG_LAMP_EN_Pin,	GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEAT_BELT_EN_GPIO_Port,		SEAT_BELT_EN_Pin,		GPIO_PIN_SET);
		HAL_GPIO_WritePin(PARKING_BRAKE_EN_GPIO_Port,	PARKING_BRAKE_EN_Pin,	GPIO_PIN_RESET);
		HAL_GPIO_WritePin(BRAKE_OIL_EN_GPIO_Port,		BRAKE_OIL_EN_Pin,		GPIO_PIN_RESET);

		HAL_GPIO_WritePin(TRIP_IN_EN_GPIO_Port,			TRIP_IN_EN_Pin,			GPIO_PIN_RESET);
		HAL_GPIO_WritePin(POS_LAMP_EN_GPIO_Port,		POS_LAMP_EN_Pin,		GPIO_PIN_RESET);
		HAL_GPIO_WritePin(TEST_IN_EN_GPIO_Port,			TEST_IN_EN_Pin,			GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LOW_BEAM_EN_GPIO_Port,		LOW_BEAM_EN_Pin,		GPIO_PIN_RESET);
		HAL_GPIO_WritePin(HIGH_BEAM_EN_GPIO_Port,		HIGH_BEAM_EN_Pin,		GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LAMP_LH_EN_GPIO_Port,			LAMP_LH_EN_Pin,			GPIO_PIN_RESET);

		HAL_GPIO_WritePin(LAMP_RH_EN_GPIO_Port,			LAMP_RH_EN_Pin,			GPIO_PIN_RESET);
		HAL_GPIO_WritePin(IMMOBIL_EN_GPIO_Port,			IMMOBIL_EN_Pin,			GPIO_PIN_RESET);
		HAL_GPIO_WritePin(DOOR_EN_GPIO_Port,			DOOR_EN_Pin,			GPIO_PIN_RESET);
		HAL_GPIO_WritePin(CHARGER_EN_GPIO_Port,			CHARGER_EN_Pin,			GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EXT_IGN1_EN_GPIO_Port,		EXT_IGN1_EN_Pin,		GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EXT_ACC_EN_GPIO_Port,			EXT_ACC_EN_Pin,			GPIO_PIN_RESET);
	}
}


/*******************************************************************************
 * Dot_Lcd_Set Function.
 ******************************************************************************/
void Dot_Lcd_Set(uint8_t option)
{
	switch(option)
	{
		case 0x00:		// Dot Lcd Clear
			lcd_gotoxy(0,0);
			lcd_send_string ("                    ");
			lcd_gotoxy(0,1);
			lcd_send_string ("                    ");
			lcd_gotoxy(0,2);
			lcd_send_string ("                    ");
			lcd_gotoxy(0,3);
			lcd_send_string ("                    ");
			break;
		case 0x01:		// Cluster ALL Test - Start
			lcd_gotoxy(0,0);
			lcd_send_string ("Cluster ALL Test !! ");
			lcd_gotoxy(0,1);
			lcd_send_string ("                    ");
			lcd_gotoxy(0,2);
			lcd_send_string (" Start !!           ");
			lcd_gotoxy(0,3);
			lcd_send_string ("                    ");
			break;
		case 0x02:		// Cluster ALL Test - End
			lcd_gotoxy(0,0);
			lcd_send_string ("Cluster ALL Test !! ");
			lcd_gotoxy(0,1);
			lcd_send_string ("                    ");
			lcd_gotoxy(0,2);
			lcd_send_string (" End !!             ");
			lcd_gotoxy(0,3);
			lcd_send_string ("                    ");
			break;

		case 0xff:
			lcd_gotoxy(0,0);
			lcd_send_string(_OFFICE_NAME_);lcd_send_string("   ");
			lcd_gotoxy(0,1);
            lcd_send_string(__DATE__);lcd_send_string("         ");
			lcd_gotoxy(0,2);
			lcd_send_string(__TIME__);lcd_send_string("            ");
			lcd_gotoxy(0,3);
			lcd_send_string("App Ver ");lcd_send_string(_FIRMWARE_VERSION_);lcd_send_string("       ");
			break;

		default:
			break;
    }

}

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
