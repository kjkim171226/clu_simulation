/******************************************************************************
 * @file     M24c04.c
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
#include "M24c04.h"

/* Private define ------------------------------------------------------------*/
#define Block0_ADDRESS                  0xA0
#define Block1_ADDRESS                  0xA2
#define Block0_Max                      256		// Byte
#define Block1_Max                      512		// Byte

/* Private variables ---------------------------------------------------------*/
uint16_t M24C04_addr = Block0_ADDRESS;

/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
 * Get_m24c04 Function.
 ******************************************************************************/
int Get_m24c04(uint16_t MemAddress, uint8_t *pData, uint16_t Size)
{
	HAL_I2C_Mem_Read(&hi2c2, M24C04_addr, MemAddress, I2C_MEMADD_SIZE_8BIT, pData, Size, 1000);
	
	return 1;
}

/*******************************************************************************
 * Set_m24c04 Function.
 ******************************************************************************/
int Set_m24c04(uint16_t MemAddress, uint8_t *pData, uint16_t Size)
{
	HAL_I2C_Mem_Write(&hi2c2, M24C04_addr, MemAddress, I2C_MEMADD_SIZE_8BIT, pData, Size, 1000);
	
	return 1;
}

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
