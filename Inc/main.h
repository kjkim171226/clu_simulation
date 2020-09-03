/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  * Description : 
  *
  *
  * Compiler    : IAR (Ver 8.40.2.22891)
  * CPU         : STM32F105VC
  * Flash       : 256KByte
  * Ram         : 64KByte
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "stdio.h"
#include "string.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define FN3_CHARG_Pin GPIO_PIN_2
#define FN3_CHARG_GPIO_Port GPIOE
#define FN4_DOOR_Pin GPIO_PIN_3
#define FN4_DOOR_GPIO_Port GPIOE
#define FN5_IMB_Pin GPIO_PIN_4
#define FN5_IMB_GPIO_Port GPIOE
#define FN6_RH_Pin GPIO_PIN_5
#define FN6_RH_GPIO_Port GPIOE
#define FN7_LH_Pin GPIO_PIN_6
#define FN7_LH_GPIO_Port GPIOE
#define MCU_RTC_X1_Pin GPIO_PIN_14
#define MCU_RTC_X1_GPIO_Port GPIOC
#define MCU_RTC_X2_Pin GPIO_PIN_15
#define MCU_RTC_X2_GPIO_Port GPIOC
#define EPS_EN_Pin GPIO_PIN_0
#define EPS_EN_GPIO_Port GPIOC
#define AIR_BAG_EN_Pin GPIO_PIN_1
#define AIR_BAG_EN_GPIO_Port GPIOC
#define EXT_IGN1_EN_Pin GPIO_PIN_2
#define EXT_IGN1_EN_GPIO_Port GPIOC
#define SEAT_BELT_EN_Pin GPIO_PIN_3
#define SEAT_BELT_EN_GPIO_Port GPIOC
#define DJ_1000_DECT_Pin GPIO_PIN_4
#define DJ_1000_DECT_GPIO_Port GPIOA
#define LED4_Pin GPIO_PIN_5
#define LED4_GPIO_Port GPIOA
#define LED5_Pin GPIO_PIN_6
#define LED5_GPIO_Port GPIOA
#define LED6_Pin GPIO_PIN_7
#define LED6_GPIO_Port GPIOA
#define BRAKE_OIL_EN_Pin GPIO_PIN_4
#define BRAKE_OIL_EN_GPIO_Port GPIOC
#define TRIP_IN_EN_Pin GPIO_PIN_5
#define TRIP_IN_EN_GPIO_Port GPIOC
#define LED8_Pin GPIO_PIN_0
#define LED8_GPIO_Port GPIOB
#define LED11_Pin GPIO_PIN_1
#define LED11_GPIO_Port GPIOB
#define BOOT1_Pin GPIO_PIN_2
#define BOOT1_GPIO_Port GPIOB
#define FN8_HB_Pin GPIO_PIN_7
#define FN8_HB_GPIO_Port GPIOE
#define FN9_LB_Pin GPIO_PIN_8
#define FN9_LB_GPIO_Port GPIOE
#define FN10_EPS_Pin GPIO_PIN_9
#define FN10_EPS_GPIO_Port GPIOE
#define FN11_POS_Pin GPIO_PIN_10
#define FN11_POS_GPIO_Port GPIOE
#define FN12_TRIP_Pin GPIO_PIN_11
#define FN12_TRIP_GPIO_Port GPIOE
#define FN13_BRAKE_Pin GPIO_PIN_12
#define FN13_BRAKE_GPIO_Port GPIOE
#define FN14_PARK_Pin GPIO_PIN_13
#define FN14_PARK_GPIO_Port GPIOE
#define FN15_BELT_Pin GPIO_PIN_14
#define FN15_BELT_GPIO_Port GPIOE
#define FN16_FL_Pin GPIO_PIN_15
#define FN16_FL_GPIO_Port GPIOE
#define I2C2_SCL_EEPROM_Pin GPIO_PIN_10
#define I2C2_SCL_EEPROM_GPIO_Port GPIOB
#define I2C2_SDA_EEPROM_Pin GPIO_PIN_11
#define I2C2_SDA_EEPROM_GPIO_Port GPIOB
#define MCU_CAN2_RXD_Pin GPIO_PIN_12
#define MCU_CAN2_RXD_GPIO_Port GPIOB
#define MCU_CAN2_TXD_Pin GPIO_PIN_13
#define MCU_CAN2_TXD_GPIO_Port GPIOB
#define FN24_LCD_Pin GPIO_PIN_14
#define FN24_LCD_GPIO_Port GPIOB
#define FN25_Pin GPIO_PIN_15
#define FN25_GPIO_Port GPIOB
#define LAMP_LH_EN_Pin GPIO_PIN_8
#define LAMP_LH_EN_GPIO_Port GPIOD
#define HIGH_BEAM_EN_Pin GPIO_PIN_9
#define HIGH_BEAM_EN_GPIO_Port GPIOD
#define LOW_BEAM_EN_Pin GPIO_PIN_10
#define LOW_BEAM_EN_GPIO_Port GPIOD
#define FRT_FOG_LAMP_EN_Pin GPIO_PIN_11
#define FRT_FOG_LAMP_EN_GPIO_Port GPIOD
#define RR_FOG_LAMP_EN_Pin GPIO_PIN_12
#define RR_FOG_LAMP_EN_GPIO_Port GPIOD
#define FN17_RL_Pin GPIO_PIN_13
#define FN17_RL_GPIO_Port GPIOD
#define FN18_AIR_Pin GPIO_PIN_14
#define FN18_AIR_GPIO_Port GPIOD
#define DOOR_EN_Pin GPIO_PIN_15
#define DOOR_EN_GPIO_Port GPIOD
#define FN19_Pin GPIO_PIN_6
#define FN19_GPIO_Port GPIOC
#define FN20_ALL_Pin GPIO_PIN_7
#define FN20_ALL_GPIO_Port GPIOC
#define FN21_C_CAN_Pin GPIO_PIN_8
#define FN21_C_CAN_GPIO_Port GPIOC
#define PARKING_BRAKE_EN_Pin GPIO_PIN_9
#define PARKING_BRAKE_EN_GPIO_Port GPIOC
#define LED7_Pin GPIO_PIN_8
#define LED7_GPIO_Port GPIOA
#define USB_VBUS_Pin GPIO_PIN_9
#define USB_VBUS_GPIO_Port GPIOA
#define OTG_ID_Pin GPIO_PIN_10
#define OTG_ID_GPIO_Port GPIOA
#define USB_DM_Pin GPIO_PIN_11
#define USB_DM_GPIO_Port GPIOA
#define USB_DP_Pin GPIO_PIN_12
#define USB_DP_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define MCU_DBG_TXD_Pin GPIO_PIN_10
#define MCU_DBG_TXD_GPIO_Port GPIOC
#define MCU_DBG_RXD_Pin GPIO_PIN_11
#define MCU_DBG_RXD_GPIO_Port GPIOC
#define TXD_2_Pin GPIO_PIN_12
#define TXD_2_GPIO_Port GPIOC
#define TEST_IN_EN_Pin GPIO_PIN_0
#define TEST_IN_EN_GPIO_Port GPIOD
#define EXT_ACC_EN_Pin GPIO_PIN_1
#define EXT_ACC_EN_GPIO_Port GPIOD
#define RXD_2_Pin GPIO_PIN_2
#define RXD_2_GPIO_Port GPIOD
#define CHARGER_EN_Pin GPIO_PIN_3
#define CHARGER_EN_GPIO_Port GPIOD
#define POS_LAMP_EN_Pin GPIO_PIN_4
#define POS_LAMP_EN_GPIO_Port GPIOD
#define TXD_1_Pin GPIO_PIN_5
#define TXD_1_GPIO_Port GPIOD
#define RXD_1_Pin GPIO_PIN_6
#define RXD_1_GPIO_Port GPIOD
#define LAMP_RH_EN_Pin GPIO_PIN_7
#define LAMP_RH_EN_GPIO_Port GPIOD
#define IMMOBIL_EN_Pin GPIO_PIN_5
#define IMMOBIL_EN_GPIO_Port GPIOB
#define FN22_L_CAN_Pin GPIO_PIN_6
#define FN22_L_CAN_GPIO_Port GPIOB
#define FN23_BUZZER_Pin GPIO_PIN_7
#define FN23_BUZZER_GPIO_Port GPIOB
#define MCU_CAN1_RXD_Pin GPIO_PIN_8
#define MCU_CAN1_RXD_GPIO_Port GPIOB
#define MCU_CAN1_TXD_Pin GPIO_PIN_9
#define MCU_CAN1_TXD_GPIO_Port GPIOB
#define FN1_ACC_Pin GPIO_PIN_0
#define FN1_ACC_GPIO_Port GPIOE
#define FN2_IGN_Pin GPIO_PIN_1
#define FN2_IGN_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */
#define _OFFICE_NAME_			"2020 by JY CUSTOM"
#define _BUILD_DATE_TIME_		"2020.07.07-14:07:00"
#define _FIRMWARE_VERSION_		"V0.04"

#define WS_BS0					0	// WS
#define DV_BS1					1	// ES, DV

/* USER CODE END Private defines */

/* Exported typedef ----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/
extern CAN_HandleTypeDef hcan1;
extern CAN_HandleTypeDef hcan2;

extern I2C_HandleTypeDef hi2c2;

extern UART_HandleTypeDef huart4;

/* Exported functions --------------------------------------------------------*/
extern uint32_t GetTimeTick(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
