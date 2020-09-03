/******************************************************************************
 * @file     Cmd.c
 * @brief    This file provides all the Command functions.
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

/** @addtogroup 
  * @{
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
//Apps
#include "Cmd.h"
#include "Event.h"
//Devices
#include "Can.h"
#include "M24c04.h"

/* Private typedef -----------------------------------------------------------*/
DEBUG_BASIC_FORMAT Debug;

/* Private variables ---------------------------------------------------------*/
uint8_t E2p_Tx_buffer[65];
uint8_t E2p_Rx_buffer[65];


/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
 * Serial_TakePut Function.
 ******************************************************************************/
void Serial_TakePut(uint8_t param)
{
	if (param == 0x0d)
	{
		Debug.Complet = 1;
		printf("\r\n");
	}
	else if ((param == 0x20) || (param == 0x03))
	{
		Debug.Complet = 1;
		printf("\r\n");
	}
	else
	{
		if (Debug.Index < _DEBG_MAX_LEN-1)
		{
			if (param == 0x08)
			{
				if (Debug.Index > 0)
					Debug.Index -= 1;
			}
			else
				Debug.Buf[Debug.Index++] = param;
		}

		HAL_UART_Transmit(&huart4, &param, 1, TX_TIMEOUT);
	}
}

/*******************************************************************************
 * DebugMsgParser Function.
 ******************************************************************************/
void DebugRxMsgParser(uint8_t *buf, uint8_t len)
{
	if (!memcmp((uint8_t *)buf, (uint8_t *)"CMD", 3))
	{
		printf("===================================================\r\n");
		printf(" ?          : show system status \r\n");
		printf(" HALT       : system enters low power mode \r\n");
		printf(" RESET      : excute system reset \r\n");

		printf("===================================================\r\n");
		printf(" ACC_1/0    : fn1 acc on/off \r\n");
		printf(" IGN_1/0    : fn2 ign on/off \r\n");
		printf(" CHA_1/0    : fn3 charger on/off \r\n");
		printf(" DOO_1/0    : fn4 door on/off \r\n");
		printf(" IMB_1/0    : fn5 immobil on/off \r\n");
		printf(" RH_1/0     : fn6 rh on/off \r\n");
		printf(" LH_1/0     : fn7 lh on/off \r\n");
		printf(" HB_1/0     : fn8 hb on/off \r\n");
		printf(" LB_1/0     : fn9 lb on/off \r\n");
		printf(" EPS_1/0    : fn10 eps on/off \r\n");
		printf(" POS_1/0    : fn11 pos on/off \r\n");
		printf(" TRI_1/0    : fn12 trip on/off \r\n");
		printf(" BRA_1/0    : fn13 brake on/off \r\n");
		printf(" PAR_1/0    : fn14 park on/off \r\n");
		printf(" BEL_1/0    : fn15 belt on/off \r\n");
		printf(" FL_1/0     : fn16 fl on/off \r\n");
		printf(" RL_1/0     : fn17 rl on/off \r\n");
		printf(" AIR_1/0    : fn18 air on/off \r\n");

		printf(" ALL_1/0    : fn20 all on/off \r\n");
		printf(" CCAN_1/0   : fn21 c-can on/off \r\n");
		printf(" LCAN_1/0   : fn22 l-can on/off \r\n");
		printf(" BUZ_1/0    : fn23 buzzer on/off \r\n");
		

		printf("===================================================\r\n");
		printf(" DSM_0~1    : send Lcan Deep Sleep Mode \r\n");
		printf(" MWN_0~9    : send Lcan Mc Warn \r\n");
		printf(" MID_0~9    : send Lcan Mc Ind \r\n");
		printf(" MI1_0~9    : send Lcan Mc Ind1 \r\n");
		printf(" ABH_0~9    : send Lcan AC_B_H \r\n");
		printf(" CTL_0~9    : send Lcan Cluster Test \r\n");

		printf(" BS0_0~9    : send Ccan Bms Stat0 \r\n");
		printf(" BS1_0~9    : send Ccan Bms Stat1 \r\n");
		printf(" BS3_0~9    : send Ccan Bms Stat3 \r\n");
		printf(" SPM_0~9    : send Ccan Speed Power \r\n");
		printf(" CTC_0~9    : send Ccan Cluster Test \r\n");	
#if 0
		printf(" TGC        : excute Get Tasks Count \r\n");
		
		printf(" TN1        : create New Task1 \r\n");
		printf(" TT1        : excute Terminate Task1 \r\n");
		printf(" TN2        : create New Task2 \r\n");
		printf(" TT2        : excute Terminate Task2 \r\n");
#endif
	}
	
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"?", 1))
	{
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"HALT", 4))
	{
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"RESET", 5))
	{
		SystemReset();
	}

	//tell-tale test
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"ACC_1", 5))
	{
		printf(" ACC: on!! \r\n");
		HAL_GPIO_WritePin(EXT_ACC_EN_GPIO_Port, EXT_ACC_EN_Pin, GPIO_PIN_SET);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"ACC_0", 5))
	{
		printf(" ACC: off!! \r\n");
		HAL_GPIO_WritePin(EXT_ACC_EN_GPIO_Port, EXT_ACC_EN_Pin, GPIO_PIN_RESET);
	}
   	else if (!memcmp((uint8_t *)buf, (uint8_t *)"IGN_1", 5))
	{
		printf(" IGN: on!! \r\n");
		HAL_GPIO_WritePin(EXT_IGN1_EN_GPIO_Port, EXT_IGN1_EN_Pin, GPIO_PIN_SET);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"IGN_0", 5))
	{
		printf(" IGN: off!! \r\n");
		HAL_GPIO_WritePin(EXT_IGN1_EN_GPIO_Port, EXT_IGN1_EN_Pin, GPIO_PIN_RESET);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"CHA_1", 5))
	{
		printf(" CHA: on!! \r\n");
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"CHA_0", 5))
	{
		printf(" CHA: off!! \r\n");
	}
   	else if (!memcmp((uint8_t *)buf, (uint8_t *)"DOO_1", 5))
	{
		printf(" DOO: on!! \r\n");
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"DOO_0", 5))
	{
		printf(" DOO: off!! \r\n");
	}
	
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"ALL_1", 5))
	{
		printf(" ALL: on!! \r\n");
		Clu_Test_All(1);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"ALL_0", 5))
	{
		printf(" ALL: off!! \r\n");
		Clu_Test_All(0);
	}

	//c-can test
#if WS_BS0
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"BS0_00", 6))
	{
		printf(" BMS_STAT0:SOC = 00%!! \r\n");
		Ccan_bmsatat0(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(1);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"BS0_50", 6))
	{
		printf(" BMS_STAT0:SOC = 50%!! \r\n");
		Ccan_bmsatat0(1, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(1);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"BS0_100", 7))
	{
		printf(" BMS_STAT0:SOC = 100%!! \r\n");
		Ccan_bmsatat0(1, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(1);
	}
#endif

#if DV_BS1
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"BS1_120", 7))
	{
		printf(" BMS_STAT1:BMS_SOC_EXT = 00%!! \r\n");
		Ccan_bmsatat1(7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78);		//12.0 = 0%
		Can2Send(7);
	}
    else if (!memcmp((uint8_t *)buf, (uint8_t *)"BS1_155", 7))
	{
		printf(" BMS_STAT1:BMS_SOC_EXT = 00%!! \r\n");
		Ccan_bmsatat1(7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9B);		//15.5 = 1%
		Can2Send(7);
	}
    else if (!memcmp((uint8_t *)buf, (uint8_t *)"BS1_230", 7))
	{
		printf(" BMS_STAT1:BMS_SOC_EXT = 10%!! \r\n");
		Ccan_bmsatat1(7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE6);		//23.0 = 10%
		Can2Send(7);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"BS1_550", 7))
	{
		printf(" BMS_STAT1:BMS_SOC_EXT = 50%!! \r\n");
		Ccan_bmsatat1(7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x26);		//55.0 = 50%
		Can2Send(7);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"BS1_870", 7))
	{
		printf(" BMS_STAT1:BMS_SOC_EXT = 90%!! \r\n");
		Ccan_bmsatat1(7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x66);		//87.0 = 90%
		Can2Send(7);
	}
    else if (!memcmp((uint8_t *)buf, (uint8_t *)"BS1_940", 7))
	{
		printf(" BMS_STAT1:BMS_SOC_EXT = 99%!! \r\n");
		Ccan_bmsatat1(7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xAC);		//94.0 = 99%
		Can2Send(7);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"BS1_950", 7))
	{
		printf(" BMS_STAT1:BMS_SOC_EXT = 100%!! \r\n");
		Ccan_bmsatat1(7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xB6);		//95.0 = 100%
		Can2Send(7);
	}
#endif
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"BS3_00", 6))
	{
		printf(" BMS_STAT3:CHARGE_TIME_REMAIN = 0!! \r\n");
		Ccan_bmsatat3(2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"BS3_7F", 6))
	{
		printf("     BMS_STAT3:CHARGE_TIME_REMAIN = 32767!! \r\n");
		Ccan_bmsatat3(2, 0x00, 0x7F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"BS3_FF", 6))
	{
		printf(" BMS_STAT3: CHARGE_TIME_REMAIN = 65535!! \r\n");
		Ccan_bmsatat3(2, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"SPV_00", 6))
	{
		printf(" Speed_Power: Vh = 00!! \r\n");
		Ccan_speedpower(2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"SPV_40", 6))
	{
		printf(" Speed_Power: Vh = 40!! \r\n");
		Ccan_speedpower(2, 0x00, 0x90, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"SPV_80", 6))
	{
		printf(" Speed_Power: Vh = 80!! \r\n");
		Ccan_speedpower(2, 0x00, 0x20, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"SPM_00", 6))
	{
		printf(" Speed_Power: Pw_MOT = 00!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(5);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"SPM_30", 6))
	{
		printf(" Speed_Power: Pw_MOT = 30!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0xB8, 0x0B, 0x00, 0x00);
		Can2Send(5);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"SPM_60", 6))
	{
		printf(" Speed_Power: Pw_MOT = 60!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x70, 0x17, 0x00, 0x00);
		Can2Send(5);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"SPM_90", 6))
	{
		printf(" Speed_Power: Pw_MOT = 90!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x28, 0x23, 0x00, 0x00);
		Can2Send(5);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"SPM_120", 7))					//max
	{
		printf(" Speed_Power: Pw_MOT = 120!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x2E, 0x00, 0x00);
		Can2Send(5);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"SPM_150", 7))
	{
		printf(" Speed_Power: Pw_MOT = 150!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x98, 0x3A, 0x00, 0x00);
		Can2Send(5);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"SPM_00", 6))
	{
		printf(" Speed_Power: Pw_MOT = 00!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(5);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"SPM-10", 6))
	{
		printf(" Speed_Power: Pw_MOT = -10!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0xF6, 0xFF, 0x00, 0x00);
		Can2Send(5);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"SPM-20", 6))
	{
		printf(" Speed_Power: Pw_MOT = -20!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0xEC, 0xFF, 0x00, 0x00);
		Can2Send(5);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"SPM-30", 6))					//min
	{
		printf(" Speed_Power: Pw_MOT = -30!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0xE2, 0xFF, 0x00, 0x00);
		Can2Send(5);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"SPM-100", 7))
	{
		printf(" Speed_Power: Pw_MOT = -100!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x9C, 0xFF, 0x00, 0x00);
		Can2Send(5);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"SPM-150", 7))
	{
		printf(" Speed_Power: Pw_MOT = -150!! \r\n");
		Ccan_speedpower(5, 0x00, 0x00, 0x00, 0x00, 0x6A, 0xFF, 0x00, 0x00);
		Can2Send(5);
	}

	//l-can test
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"DSM_1", 5))
	{
		printf(" Deep_Sleep_L: DEEP_SLEEP_MODE_L = enable!! \r\n");
		for (int i = 0; i < 100; i++) {
			Lcan_deepsleepmode_l(1, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
			Can1Send(1);
			HAL_Delay(100);
		}
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"MWN_0", 4))
	{
		printf(" MC_WARN: Disable!! \r\n");
		Lcan_mcwarn(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"MWN_1", 4))
	{
		printf(" MC_WARN: BAT_TEMP_W = Low!! \r\n");
		Lcan_mcwarn(1, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"MWN_2", 4))
	{
		printf(" MC_WARN: BAT_TEMP_W = Overheated!! \r\n");
		Lcan_mcwarn(1, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"MID_0", 4))
	{
		printf(" MC_IND: Disable!! \r\n");
		Lcan_mcind(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"MID_1", 4))
	{
		printf(" MC_IND: READY_D = 1, GEAR_STATUS = R!! \r\n");
		Lcan_mcind(1, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"MID_2", 4))
	{
		printf(" MC_IND: READY_D = 1, GEAR_STATUS = N(P)!! \r\n");
		Lcan_mcind(1, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"MID_3", 4))
	{
		printf(" MC_IND: READY_D = 1, GEAR_STATUS = D!! \r\n");
		Lcan_mcind(1, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"ABH_0", 4))
	{
		printf(" AC_B_H: AC_BAT_HEAT = Disable!! \r\n");
		Lcan_acbh(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"ABH_1", 4))
	{
		printf("     AC_B_H: AC_BAT_HEAT = enable!! \r\n");
		Lcan_acbh(1, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"CTL_3", 4))
	{
		printf(" CLU_TEST: SOC_RESET = enable!! \r\n");
		Lcan_clutest_l(3, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(3);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"CTL_4", 4))
	{
		printf(" CLU_TEST: MCU_RESET = enable!! \r\n");
		Lcan_clutest_l(4, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00);
		Can1Send(4);
	}

	//buzzer test
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"BUZ_1", 5))
	{
		HAL_GPIO_WritePin(EXT_IGN1_EN_GPIO_Port, EXT_IGN1_EN_Pin, GPIO_PIN_SET);

		printf(" 1. Door Ajar Warning Buzzer!! \r\n");
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
		
		printf("  => MC_IND: disable!! \r\n");
		Lcan_mcind(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);
		printf("  => Speed_Power: disable!! \r\n");
		Ccan_speedpower(2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(500);
		HAL_GPIO_WritePin(DOOR_EN_GPIO_Port, DOOR_EN_Pin, GPIO_PIN_RESET);
		
		HAL_GPIO_WritePin(EXT_IGN1_EN_GPIO_Port, EXT_IGN1_EN_Pin, GPIO_PIN_RESET);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"BUZ_2", 5))
	{
		HAL_GPIO_WritePin(EXT_IGN1_EN_GPIO_Port, EXT_IGN1_EN_Pin, GPIO_PIN_SET);

		printf(" 2. Parking Brake Warning Buzzer!! \r\n");
		printf("  => MC_IND: READY_D = 1, GEAR_STATUS = D!! \r\n");
		Lcan_mcind(1, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);
		printf("  => Speed_Power: Vh = 20!! \r\n");
		Ccan_speedpower(2, 0x00, 0xC8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(500);
		HAL_GPIO_WritePin(PARKING_BRAKE_EN_GPIO_Port, PARKING_BRAKE_EN_Pin, GPIO_PIN_SET);
		
		HAL_Delay(61000);

		printf("  => MC_IND: disable!! \r\n");
		Lcan_mcind(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);
		printf("  => Speed_Power: disable!! \r\n");
		Ccan_speedpower(2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(500);
		HAL_GPIO_WritePin(PARKING_BRAKE_EN_GPIO_Port, PARKING_BRAKE_EN_Pin, GPIO_PIN_RESET);
		
		HAL_GPIO_WritePin(EXT_IGN1_EN_GPIO_Port, EXT_IGN1_EN_Pin, GPIO_PIN_RESET);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"BUZ_3", 5))
	{
		HAL_GPIO_WritePin(EXT_IGN1_EN_GPIO_Port, EXT_IGN1_EN_Pin, GPIO_PIN_SET);

		printf(" 3. Seat Belt Warning Buzzer!! \r\n");
		printf("  => MC_IND: READY_D = 1, GEAR_STATUS = D!! \r\n");
		Lcan_mcind(1, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);
		printf("  => Speed_Power: Vh = 20!! \r\n");
		Ccan_speedpower(2, 0x00, 0xC8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(500);
		HAL_GPIO_WritePin(SEAT_BELT_EN_GPIO_Port, SEAT_BELT_EN_Pin, GPIO_PIN_RESET);
		
		HAL_Delay(61000);

		printf("  => MC_IND: disable!! \r\n");
		Lcan_mcind(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);
		printf("  => Speed_Power: disable!! \r\n");
		Ccan_speedpower(2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(500);
		HAL_GPIO_WritePin(SEAT_BELT_EN_GPIO_Port, SEAT_BELT_EN_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(EXT_IGN1_EN_GPIO_Port, EXT_IGN1_EN_Pin, GPIO_PIN_RESET);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"BUZ_4", 5))
	{
		printf(" 4. SSB Warning Buzzer!! \r\n");
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
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"BUZ_5", 5))
	{
		HAL_GPIO_WritePin(EXT_IGN1_EN_GPIO_Port, EXT_IGN1_EN_Pin, GPIO_PIN_SET);

		printf(" 5. Gear Warning Buzzer!! \r\n");
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
		
		printf("  => MC_IND: disable!! \r\n");
		Lcan_mcind(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);
		HAL_Delay(500);
		printf("  => Speed_Power: disable!! \r\n");
		Ccan_speedpower(2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(500);
		printf("  => MC_WARN: disable!! \r\n");
		Lcan_mcwarn(1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can1Send(1);

		HAL_GPIO_WritePin(EXT_IGN1_EN_GPIO_Port, EXT_IGN1_EN_Pin, GPIO_PIN_RESET);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"BUZ_6", 5))
	{
		printf(" 6. Turn Off Warning Buzzer!! \r\n");
		printf("  => Speed_Power: Vh = 00!! \r\n");
		Ccan_speedpower(2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		Can2Send(2);
		HAL_Delay(500);
		HAL_GPIO_WritePin(PARKING_BRAKE_EN_GPIO_Port, PARKING_BRAKE_EN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(DOOR_EN_GPIO_Port, DOOR_EN_Pin, GPIO_PIN_SET);

		HAL_Delay(61000);

		HAL_GPIO_WritePin(PARKING_BRAKE_EN_GPIO_Port, PARKING_BRAKE_EN_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(DOOR_EN_GPIO_Port, DOOR_EN_Pin, GPIO_PIN_RESET);
	}

	else if (!memcmp((uint8_t *)buf, (uint8_t *)"E2P_W0", 6))
	{
		E2p_Tx_buffer[0] = 0x00;
		
		printf(" E2P M24c04 Write 0!! \r\n");
		Set_m24c04(0x00, E2p_Tx_buffer, 1);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"E2P_W1", 6))
	{
		E2p_Tx_buffer[0] = 0x07;
		
		printf(" E2P M24c04 Write 1!! \r\n");
		Set_m24c04(0x00, E2p_Tx_buffer, 1);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"E2P_RE", 6))
	{
		printf(" E2P M24c04 Read!! \r\n");
		Get_m24c04(0x00, E2p_Rx_buffer, 1);

		printf(" E2P M24c04 Read = %d!! \r\n", E2p_Rx_buffer[0]);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"LCD_00", 6))
	{
		printf(" LCD Clear Set!! \r\n");

		Dot_Lcd_Set(0x00);
	}
	else if (!memcmp((uint8_t *)buf, (uint8_t *)"LCD_FF", 6))
	{
		Dot_Lcd_Set(0xff);
	}


	printf("\r\n");
}

/*******************************************************************************
 * DebugRxTask Function.
 ******************************************************************************/
void DebugRxTask(void)
{
	uint8_t i;
	uint8_t buf[_DEBG_MAX_LEN];
	uint8_t ch = 0;

	if (Debug.Complet == 1)
	{
		memset(buf, 0, sizeof(buf));
		Debug.Complet = 0;

		for (i = 0; i < Debug.Index; i++)
		{
			ch = Debug.Buf[i];

			if((ch >= 'a') && (ch <= 'z'))
			{
				buf[i] = ch -'a' + 'A';
			}
			else
			{
				buf[i] = ch;
			}
		}

		DebugRxMsgParser((uint8_t *)buf, Debug.Index);
		memset(Debug.Buf, 0, Debug.Index);
		Debug.Index = 0;
		
		//printf("\r\n");
	}
}

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
