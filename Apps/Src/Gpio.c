/******************************************************************************
 * @file     Gpio.c
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
#include "Gpio.h"
#include "Event.h"

/* Private variables ---------------------------------------------------------*/
uint8_t fn5_imb = 0;
uint8_t fn6_rh = 0;
uint8_t fn7_lh = 0;
uint8_t fn12_trip = 0;
uint8_t fn20_all = 0;
uint8_t fn21_c_can = 0;
uint8_t fn22_l_can = 0;
uint8_t fn23_buzzer = 0;


/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
 * Get_Gpio Function.
 ******************************************************************************/
void Get_Gpio(void)
{
	if (HAL_GPIO_ReadPin(FN1_ACC_GPIO_Port, FN1_ACC_Pin) == 0)
	{
		printf(" fn1: ACC on!! \r\n");
		HAL_GPIO_WritePin(EXT_ACC_EN_GPIO_Port, EXT_ACC_EN_Pin, GPIO_PIN_SET);
	}
	else if (HAL_GPIO_ReadPin(FN2_IGN_GPIO_Port, FN2_IGN_Pin) == 0)
	{
		printf(" fn2: IGN on!! \r\n");
		HAL_GPIO_WritePin(EXT_IGN1_EN_GPIO_Port, EXT_IGN1_EN_Pin, GPIO_PIN_SET);
	}
	else if (HAL_GPIO_ReadPin(FN3_CHARG_GPIO_Port, FN3_CHARG_Pin) == 0)
	{
		printf(" fn3: CHARG on!! \r\n");
		HAL_GPIO_WritePin(CHARGER_EN_GPIO_Port, CHARGER_EN_Pin, GPIO_PIN_SET);
	}
	else if (HAL_GPIO_ReadPin(FN4_DOOR_GPIO_Port, FN4_DOOR_Pin) == 0)
	{
		printf(" fn4: DOOR on!! \r\n");
		HAL_GPIO_WritePin(DOOR_EN_GPIO_Port, DOOR_EN_Pin, GPIO_PIN_SET);
	}
	else if (HAL_GPIO_ReadPin(FN5_IMB_GPIO_Port, FN5_IMB_Pin) == 0)
	{
		printf(" fn5: IMB on!! \r\n");
		HAL_GPIO_WritePin(IMMOBIL_EN_GPIO_Port, IMMOBIL_EN_Pin, GPIO_PIN_SET);
		fn5_imb = 1;
	}
	else if ((fn5_imb == 1) && (HAL_GPIO_ReadPin(FN5_IMB_GPIO_Port, FN5_IMB_Pin) == 1))
	{
		printf(" fn5: IMB off!! \r\n");
		HAL_GPIO_WritePin(IMMOBIL_EN_GPIO_Port, IMMOBIL_EN_Pin, GPIO_PIN_RESET);
		fn5_imb = 0;
	}
	else if (HAL_GPIO_ReadPin(FN6_RH_GPIO_Port, FN6_RH_Pin) == 0)
	{
		printf(" fn6: RH on!! \r\n");
		HAL_GPIO_WritePin(LAMP_RH_EN_GPIO_Port, LAMP_RH_EN_Pin, GPIO_PIN_SET);
		fn6_rh = 1;
	}
	else if ((fn6_rh == 1) && (HAL_GPIO_ReadPin(FN6_RH_GPIO_Port, FN6_RH_Pin) == 1))
	{
		printf(" fn6: RH off!! \r\n");
		HAL_GPIO_WritePin(LAMP_RH_EN_GPIO_Port, LAMP_RH_EN_Pin, GPIO_PIN_RESET);
		fn6_rh = 0;
	}
	else if (HAL_GPIO_ReadPin(FN7_LH_GPIO_Port, FN7_LH_Pin) == 0)
	{
		printf(" fn7: LH on!! \r\n");
		HAL_GPIO_WritePin(LAMP_LH_EN_GPIO_Port, LAMP_LH_EN_Pin, GPIO_PIN_SET);
		fn7_lh = 1;
	}
	else if ((fn7_lh == 1) && (HAL_GPIO_ReadPin(FN7_LH_GPIO_Port, FN7_LH_Pin) == 1))
	{
		printf(" fn7: LH off!! \r\n");
		HAL_GPIO_WritePin(LAMP_LH_EN_GPIO_Port, LAMP_LH_EN_Pin, GPIO_PIN_RESET);
		fn7_lh = 0;
	}
	else if (HAL_GPIO_ReadPin(FN8_HB_GPIO_Port, FN8_HB_Pin) == 0)
	{
		printf(" fn8: HB on!! \r\n");
		HAL_GPIO_WritePin(HIGH_BEAM_EN_GPIO_Port, HIGH_BEAM_EN_Pin, GPIO_PIN_SET);
	}
	else if (HAL_GPIO_ReadPin(FN9_LB_GPIO_Port, FN9_LB_Pin) == 0)
	{
		printf(" fn9: LB on!! \r\n");
		HAL_GPIO_WritePin(LOW_BEAM_EN_GPIO_Port, LOW_BEAM_EN_Pin, GPIO_PIN_SET);
	}
	else if (HAL_GPIO_ReadPin(FN10_EPS_GPIO_Port, FN10_EPS_Pin) == 0)
	{
		printf(" fn10: EPS on!! \r\n");
		HAL_GPIO_WritePin(TEST_IN_EN_GPIO_Port, TEST_IN_EN_Pin, GPIO_PIN_SET);
	}
	else if (HAL_GPIO_ReadPin(FN11_POS_GPIO_Port, FN11_POS_Pin) == 0)
	{
		printf(" fn11: POS on!! \r\n");
		HAL_GPIO_WritePin(POS_LAMP_EN_GPIO_Port, POS_LAMP_EN_Pin, GPIO_PIN_SET);
	}
	else if ((fn12_trip == 0) && HAL_GPIO_ReadPin(FN12_TRIP_GPIO_Port, FN12_TRIP_Pin) == 0)
	{
		printf(" fn12: TRIP on!! \r\n");
		HAL_GPIO_WritePin(TRIP_IN_EN_GPIO_Port, TRIP_IN_EN_Pin, GPIO_PIN_SET);
		fn12_trip = 1;
	}
	else if ((fn12_trip == 1) && (HAL_GPIO_ReadPin(FN12_TRIP_GPIO_Port, FN12_TRIP_Pin) == 1))
	{
		printf(" fn12: TRIP off!! \r\n");
		HAL_GPIO_WritePin(TRIP_IN_EN_GPIO_Port, TRIP_IN_EN_Pin, GPIO_PIN_RESET);
		fn12_trip = 0;
	}
	else if (HAL_GPIO_ReadPin(FN13_BRAKE_GPIO_Port, FN13_BRAKE_Pin) == 0)
	{
		printf(" fn13: BRAKE on!! \r\n");
		HAL_GPIO_WritePin(BRAKE_OIL_EN_GPIO_Port, BRAKE_OIL_EN_Pin, GPIO_PIN_SET);
	}
	else if (HAL_GPIO_ReadPin(FN14_PARK_GPIO_Port, FN14_PARK_Pin) == 0)
	{
		printf(" fn14: PARK on!! \r\n");
		HAL_GPIO_WritePin(PARKING_BRAKE_EN_GPIO_Port, PARKING_BRAKE_EN_Pin, GPIO_PIN_SET);
	}
	else if (HAL_GPIO_ReadPin(FN15_BELT_GPIO_Port, FN15_BELT_Pin) == 0)
	{
		printf(" fn15: BELT on!! \r\n");
		HAL_GPIO_WritePin(SEAT_BELT_EN_GPIO_Port, SEAT_BELT_EN_Pin, GPIO_PIN_RESET);
	}
	else if (HAL_GPIO_ReadPin(FN16_FL_GPIO_Port, FN16_FL_Pin) == 0)
	{
		printf(" fn16: FL on!! \r\n");
		HAL_GPIO_WritePin(FRT_FOG_LAMP_EN_GPIO_Port, FRT_FOG_LAMP_EN_Pin, GPIO_PIN_SET);
	}
	else if (HAL_GPIO_ReadPin(FN17_RL_GPIO_Port, FN17_RL_Pin) == 0)
	{
		printf(" fn17: RL on!! \r\n");
		HAL_GPIO_WritePin(RR_FOG_LAMP_EN_GPIO_Port, RR_FOG_LAMP_EN_Pin, GPIO_PIN_SET);
	}
	else if (HAL_GPIO_ReadPin(FN18_AIR_GPIO_Port, FN18_AIR_Pin) == 0)
	{
		printf(" fn18: AIR on!! \r\n");
		HAL_GPIO_WritePin(AIR_BAG_EN_GPIO_Port, AIR_BAG_EN_Pin, GPIO_PIN_SET);		//aging test on
	}
	else if (HAL_GPIO_ReadPin(FN19_GPIO_Port, FN19_Pin) == 0)
	{
		printf(" fn19: sw22 on!! \r\n");
		HAL_GPIO_WritePin(AIR_BAG_EN_GPIO_Port,			AIR_BAG_EN_Pin,			GPIO_PIN_RESET);
		HAL_GPIO_WritePin(RR_FOG_LAMP_EN_GPIO_Port,		RR_FOG_LAMP_EN_Pin,		GPIO_PIN_RESET);
		HAL_GPIO_WritePin(FRT_FOG_LAMP_EN_GPIO_Port,	FRT_FOG_LAMP_EN_Pin,	GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEAT_BELT_EN_GPIO_Port,		SEAT_BELT_EN_Pin,		GPIO_PIN_SET);		// Active Low
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
//		HAL_GPIO_WritePin(EXT_ACC_EN_GPIO_Port,			EXT_ACC_EN_Pin,			GPIO_PIN_RESET);
	}
	else if ((fn20_all == 0) && HAL_GPIO_ReadPin(FN20_ALL_GPIO_Port, FN20_ALL_Pin) == 0)
	{
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);

		Dot_Lcd_Set(0x00); 
		Dot_Lcd_Set(0x01);
		
		printf(" cluster all test: on!! \r\n");
		Clu_Test_All(1);
		fn20_all = 1;
	}
	else if ((fn20_all == 1) && (HAL_GPIO_ReadPin(FN20_ALL_GPIO_Port, FN20_ALL_Pin) == 1))
	{
		HAL_Delay(33000);

		Dot_Lcd_Set(0x00); 
		Dot_Lcd_Set(0x02);

		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
		fn20_all = 0;
	}

	else if ((fn21_c_can == 0) && HAL_GPIO_ReadPin(FN21_C_CAN_GPIO_Port, FN21_C_CAN_Pin) == 0)
	{
		printf(" fn21: C-CAN test on!! \r\n");
		Clu_Test_CCan(1);
		fn21_c_can= 1;
	}
	else if ((fn21_c_can == 1) && (HAL_GPIO_ReadPin(FN21_C_CAN_GPIO_Port, FN21_C_CAN_Pin) == 1))
	{
		printf(" fn21: C-CAN test off!! \r\n");
		Clu_Test_CCan(0);
		fn21_c_can = 0;
	}
	else if ((fn22_l_can == 0) && HAL_GPIO_ReadPin(FN22_L_CAN_GPIO_Port, FN22_L_CAN_Pin) == 0)
	{
		printf(" fn22: L-CAN test on!! \r\n");
		Clu_Test_LCan(1);
		fn22_l_can= 1;
	}
	else if ((fn22_l_can == 1) && (HAL_GPIO_ReadPin(FN22_L_CAN_GPIO_Port, FN22_L_CAN_Pin) == 1))
	{
		printf(" fn22: L-CAN test off!! \r\n");
		Clu_Test_LCan(0);
		fn22_l_can = 0;
	}
	else if ((fn23_buzzer == 0) && HAL_GPIO_ReadPin(FN23_BUZZER_GPIO_Port, FN23_BUZZER_Pin) == 0)
	{
		printf(" fn23: BUZZER test on!! \r\n");
		Clu_Test_Buzzer(1);
		fn23_buzzer= 1;
	}
	else if ((fn23_buzzer == 1) && (HAL_GPIO_ReadPin(FN23_BUZZER_GPIO_Port, FN23_BUZZER_Pin) == 1))
	{
		printf(" fn23: BUZZER test off!! \r\n");
		Clu_Test_Buzzer(0);
		fn23_buzzer = 0;
	}
	else if (HAL_GPIO_ReadPin(FN24_LCD_GPIO_Port, FN24_LCD_Pin) == 0)
	{
		printf(" fn24: sw27 on!! \r\n");
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
	else if (HAL_GPIO_ReadPin(FN25_GPIO_Port, FN25_Pin) == 0)
	{
		printf(" fn25: sw28 on!! \r\n");
		printf(" tell-tale: all reset!! \r\n");
		Clu_Test_All(0);

		Dot_Lcd_Set(0xff); 
	}
}

/*******************************************************************************
 * Set_Gpio Function.
 ******************************************************************************/
void Set_Gpio(void)
{

}

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
