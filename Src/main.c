/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
//Apps
#include "Cmd.h"
#include "Event.h"
#include "Gpio.h"
//Devices
#include "Can.h"
#include "Pcf8574a.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
CAN_HandleTypeDef hcan1;
CAN_HandleTypeDef hcan2;

I2C_HandleTypeDef hi2c2;

TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart4;
UART_HandleTypeDef huart5;
UART_HandleTypeDef huart2;

/* Definitions for CmdTask */
osThreadId_t CmdTaskHandle;
const osThreadAttr_t CmdTask_attributes = {
  .name = "CmdTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for GPinTask */
osThreadId_t GPinTaskHandle;
const osThreadAttr_t GPinTask_attributes = {
  .name = "GPinTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for GPoutTask */
osThreadId_t GPoutTaskHandle;
const osThreadAttr_t GPoutTask_attributes = {
  .name = "GPoutTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* USER CODE BEGIN PV */
uint32_t TimeTick = 0;
uint8_t uart4_rx_data;

RxProtocol g_RxCan[2];		// Rx array

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN1_Init(void);
static void MX_CAN2_Init(void);
static void MX_I2C2_Init(void);
static void MX_TIM2_Init(void);
static void MX_UART4_Init(void);
static void MX_UART5_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USB_OTG_FS_USB_Init(void);
void StartCmdTask(void *argument);
void StartGPinTask(void *argument);
void StartGPoutTask(void *argument);

/* USER CODE BEGIN PFP */
#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART2 and Loop until the end of transmission */
  HAL_UART_Transmit(&huart4, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}

/*******************************************************************************
 * HAL_TIM_PeriodElapsedCallback Function.
 ******************************************************************************/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	TimeTick++;

	//printf(" TimeTick = %d ms\r\n", TimeTick);
}

/*******************************************************************************
 * HAL_UART_RxCpltCallback Function.
 ******************************************************************************/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == UART4)
	{
		HAL_UART_Receive_IT(&huart4, &uart4_rx_data, 1);
		Serial_TakePut(uart4_rx_data);
	}
}

/*******************************************************************************
 * GetTimeTick Function.
 ******************************************************************************/
uint32_t GetTimeTick(void)
{
	return TimeTick;
}

/*******************************************************************************
 * HAL_CAN_RxFifo0MsgPendingCallback Function.
 ******************************************************************************/
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
  /* Get CAN1 RX message */
  if (HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &g_RxCan[0].RxHeader, g_RxCan[0].RxData) != HAL_OK)
  {
    printf(" Error HAL_CAN_GetRxMessage hcan1 !!\r\n");
    Error_Handler();
  }

  //Can1Receive(CAN_RX_FIFO0, &g_RxCan[0].RxHeader, g_RxCan[0].RxData);

  /* Get CAN1 RX message */
  if (HAL_CAN_GetRxMessage(&hcan2, CAN_RX_FIFO1, &g_RxCan[1].RxHeader, g_RxCan[1].RxData) != HAL_OK)
  {
    printf(" Error HAL_CAN_GetRxMessage hcan2 !!\r\n");
    Error_Handler();
  }

  //Can2Receive(CAN_RX_FIFO1, &g_RxCan[1].RxHeader, g_RxCan[1].RxData);
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CAN1_Init();		//L-CAN
  MX_CAN2_Init();		//C-CAN
  MX_I2C2_Init();
  MX_TIM2_Init();
  MX_UART4_Init();
  MX_UART5_Init();
  MX_USART2_UART_Init();
  MX_USB_OTG_FS_USB_Init();
  /* USER CODE BEGIN 2 */
  printf("\r\n");
  printf("========================== ==========================\r\n");
  printf(" %s \r\n", _OFFICE_NAME_);
  printf(" App Build Data&Time: %s \r\n", _BUILD_DATE_TIME_);
  printf(" App Ver %s \r\n", _FIRMWARE_VERSION_);
  printf(" \"cmd\" shows the dibugging console command. \r\n");
  printf("========================== ==========================\r\n");

  lcd_init();

  Dot_Lcd_Set(0xff);

  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
	Error_Handler();

  if (HAL_TIM_Base_Start_IT(&htim2) != HAL_OK)
	Error_Handler();
  
  HAL_UART_Receive_IT(&huart4, &uart4_rx_data, 1);

  /* Start the CAN peripheral */
  if (HAL_CAN_Start(&hcan1) != HAL_OK)
    Error_Handler();

  /* Activate CAN RX notification */
  if (HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
    Error_Handler();

  if (HAL_CAN_Start(&hcan2) != HAL_OK)
    Error_Handler();

  /* Activate CAN RX notification */
  if (HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
    Error_Handler();

  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of CmdTask */
  CmdTaskHandle = osThreadNew(StartCmdTask, NULL, &CmdTask_attributes);

  /* creation of GPinTask */
  GPinTaskHandle = osThreadNew(StartGPinTask, NULL, &GPinTask_attributes);

  /* creation of GPoutTask */
  GPoutTaskHandle = osThreadNew(StartGPoutTask, NULL, &GPoutTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV5;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.Prediv1Source = RCC_PREDIV1_SOURCE_PLL2;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL2.PLL2State = RCC_PLL2_ON;
  RCC_OscInitStruct.PLL2.PLL2MUL = RCC_PLL2_MUL8;
  RCC_OscInitStruct.PLL2.HSEPrediv2Value = RCC_HSE_PREDIV2_DIV5;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV3;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the Systick interrupt time 
  */
  __HAL_RCC_PLLI2S_ENABLE();
}

/**
  * @brief CAN1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN1_Init(void)
{

  /* USER CODE BEGIN CAN1_Init 0 */

  /* USER CODE END CAN1_Init 0 */

  /* USER CODE BEGIN CAN1_Init 1 */

  /* USER CODE END CAN1_Init 1 */
  hcan1.Instance = CAN1;
#if 0
  hcan1.Init.Prescaler = 16;
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_1TQ;
  hcan1.Init.TimeSeg2 = CAN_BS2_1TQ;
#endif
  //Baudrate = 125kbps(36M/32/(1+3+5))
  hcan1.Init.Prescaler = 32;
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_3TQ;
  hcan1.Init.TimeSeg2 = CAN_BS2_5TQ;
  hcan1.Init.TimeTriggeredMode = DISABLE;
  hcan1.Init.AutoBusOff = DISABLE;
  hcan1.Init.AutoWakeUp = DISABLE;
  hcan1.Init.AutoRetransmission = DISABLE;
  hcan1.Init.ReceiveFifoLocked = DISABLE;
  hcan1.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN1_Init 2 */

  /* USER CODE END CAN1_Init 2 */

}

/**
  * @brief CAN2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN2_Init(void)
{

  /* USER CODE BEGIN CAN2_Init 0 */

  /* USER CODE END CAN2_Init 0 */

  /* USER CODE BEGIN CAN2_Init 1 */

  /* USER CODE END CAN2_Init 1 */
  hcan2.Instance = CAN2;
#if 0
  hcan2.Init.Prescaler = 16;
  hcan2.Init.Mode = CAN_MODE_NORMAL;
  hcan2.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan2.Init.TimeSeg1 = CAN_BS1_1TQ;
  hcan2.Init.TimeSeg2 = CAN_BS2_1TQ;
#endif
  //Baudrate = 500kbps(36M/8/(1+3+5))
  hcan2.Init.Prescaler = 8;
  hcan2.Init.Mode = CAN_MODE_NORMAL;
  hcan2.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan2.Init.TimeSeg1 = CAN_BS1_3TQ;
  hcan2.Init.TimeSeg2 = CAN_BS2_5TQ;
  hcan2.Init.TimeTriggeredMode = DISABLE;
  hcan2.Init.AutoBusOff = DISABLE;
  hcan2.Init.AutoWakeUp = DISABLE;
  hcan2.Init.AutoRetransmission = DISABLE;
  hcan2.Init.ReceiveFifoLocked = DISABLE;
  hcan2.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN2_Init 2 */

  /* USER CODE END CAN2_Init 2 */

}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 72-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1000;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief UART4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART4_Init(void)
{

  /* USER CODE BEGIN UART4_Init 0 */

  /* USER CODE END UART4_Init 0 */

  /* USER CODE BEGIN UART4_Init 1 */

  /* USER CODE END UART4_Init 1 */
  huart4.Instance = UART4;
  huart4.Init.BaudRate = 500000;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART4_Init 2 */

  /* USER CODE END UART4_Init 2 */

}

/**
  * @brief UART5 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART5_Init(void)
{

  /* USER CODE BEGIN UART5_Init 0 */

  /* USER CODE END UART5_Init 0 */

  /* USER CODE BEGIN UART5_Init 1 */

  /* USER CODE END UART5_Init 1 */
  huart5.Instance = UART5;
  huart5.Init.BaudRate = 115200;
  huart5.Init.WordLength = UART_WORDLENGTH_8B;
  huart5.Init.StopBits = UART_STOPBITS_1;
  huart5.Init.Parity = UART_PARITY_NONE;
  huart5.Init.Mode = UART_MODE_TX_RX;
  huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart5.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart5) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART5_Init 2 */

  /* USER CODE END UART5_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief USB_OTG_FS Initialization Function
  * @param None
  * @retval None
  */
static void MX_USB_OTG_FS_USB_Init(void)
{

  /* USER CODE BEGIN USB_OTG_FS_Init 0 */

  /* USER CODE END USB_OTG_FS_Init 0 */

  /* USER CODE BEGIN USB_OTG_FS_Init 1 */

  /* USER CODE END USB_OTG_FS_Init 1 */
  /* USER CODE BEGIN USB_OTG_FS_Init 2 */

  /* USER CODE END USB_OTG_FS_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, EPS_EN_Pin|AIR_BAG_EN_Pin|EXT_IGN1_EN_Pin|BRAKE_OIL_EN_Pin 
                          |TRIP_IN_EN_Pin|PARKING_BRAKE_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SEAT_BELT_EN_GPIO_Port, SEAT_BELT_EN_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED4_Pin|LED5_Pin|LED6_Pin|LED7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED8_Pin|LED11_Pin|IMMOBIL_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, LAMP_LH_EN_Pin|HIGH_BEAM_EN_Pin|LOW_BEAM_EN_Pin|FRT_FOG_LAMP_EN_Pin 
                          |RR_FOG_LAMP_EN_Pin|DOOR_EN_Pin|TEST_IN_EN_Pin|EXT_ACC_EN_Pin 
                          |CHARGER_EN_Pin|POS_LAMP_EN_Pin|LAMP_RH_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : FN3_CHARG_Pin FN4_DOOR_Pin FN5_IMB_Pin FN6_RH_Pin 
                           FN7_LH_Pin FN8_HB_Pin FN9_LB_Pin FN10_EPS_Pin 
                           FN11_POS_Pin FN12_TRIP_Pin FN13_BRAKE_Pin FN14_PARK_Pin 
                           FN15_BELT_Pin FN16_FL_Pin FN1_ACC_Pin FN2_IGN_Pin */
  GPIO_InitStruct.Pin = FN3_CHARG_Pin|FN4_DOOR_Pin|FN5_IMB_Pin|FN6_RH_Pin 
                          |FN7_LH_Pin|FN8_HB_Pin|FN9_LB_Pin|FN10_EPS_Pin 
                          |FN11_POS_Pin|FN12_TRIP_Pin|FN13_BRAKE_Pin|FN14_PARK_Pin 
                          |FN15_BELT_Pin|FN16_FL_Pin|FN1_ACC_Pin|FN2_IGN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : EPS_EN_Pin AIR_BAG_EN_Pin EXT_IGN1_EN_Pin SEAT_BELT_EN_Pin 
                           BRAKE_OIL_EN_Pin TRIP_IN_EN_Pin PARKING_BRAKE_EN_Pin */
  GPIO_InitStruct.Pin = EPS_EN_Pin|AIR_BAG_EN_Pin|EXT_IGN1_EN_Pin|SEAT_BELT_EN_Pin 
                          |BRAKE_OIL_EN_Pin|TRIP_IN_EN_Pin|PARKING_BRAKE_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : DJ_1000_DECT_Pin */
  GPIO_InitStruct.Pin = DJ_1000_DECT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(DJ_1000_DECT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED4_Pin LED5_Pin LED6_Pin LED7_Pin */
  GPIO_InitStruct.Pin = LED4_Pin|LED5_Pin|LED6_Pin|LED7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED8_Pin LED11_Pin IMMOBIL_EN_Pin */
  GPIO_InitStruct.Pin = LED8_Pin|LED11_Pin|IMMOBIL_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : BOOT1_Pin FN24_LCD_Pin FN25_Pin FN22_L_CAN_Pin 
                           FN23_BUZZER_Pin */
  GPIO_InitStruct.Pin = BOOT1_Pin|FN24_LCD_Pin|FN25_Pin|FN22_L_CAN_Pin 
                          |FN23_BUZZER_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : LAMP_LH_EN_Pin HIGH_BEAM_EN_Pin LOW_BEAM_EN_Pin FRT_FOG_LAMP_EN_Pin 
                           RR_FOG_LAMP_EN_Pin DOOR_EN_Pin TEST_IN_EN_Pin EXT_ACC_EN_Pin 
                           CHARGER_EN_Pin POS_LAMP_EN_Pin LAMP_RH_EN_Pin */
  GPIO_InitStruct.Pin = LAMP_LH_EN_Pin|HIGH_BEAM_EN_Pin|LOW_BEAM_EN_Pin|FRT_FOG_LAMP_EN_Pin 
                          |RR_FOG_LAMP_EN_Pin|DOOR_EN_Pin|TEST_IN_EN_Pin|EXT_ACC_EN_Pin 
                          |CHARGER_EN_Pin|POS_LAMP_EN_Pin|LAMP_RH_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : FN17_RL_Pin FN18_AIR_Pin */
  GPIO_InitStruct.Pin = FN17_RL_Pin|FN18_AIR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : FN19_Pin FN20_ALL_Pin FN21_C_CAN_Pin */
  GPIO_InitStruct.Pin = FN19_Pin|FN20_ALL_Pin|FN21_C_CAN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_VBUS_Pin */
  GPIO_InitStruct.Pin = USB_VBUS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USB_VBUS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : OTG_ID_Pin */
  GPIO_InitStruct.Pin = OTG_ID_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(OTG_ID_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartCmdTask */
/**
  * @brief  Function implementing the CmdTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartCmdTask */
void StartCmdTask(void *argument)
{
  /* USER CODE BEGIN 5 */
  printf("===>> Func:%s !!\r\n", __FUNCTION__);
  printf("===>> osThreadGetCount = %d \r\n", osThreadGetCount());
  /* Infinite loop */
  for(;;)
  {
    DebugRxTask();
    osDelay(1);
  }
  /* USER CODE END 5 */ 
}

/* USER CODE BEGIN Header_StartGPinTask */
/**
* @brief Function implementing the GPinTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartGPinTask */
void StartGPinTask(void *argument)
{
  /* USER CODE BEGIN StartGPinTask */
  printf("===>> Func:%s !!\r\n", __FUNCTION__);
  printf("===>> osThreadGetCount = %d \r\n", osThreadGetCount());
  /* Infinite loop */
  for(;;)
  {
	Get_Gpio();
	osDelay(1);
  }
  /* USER CODE END StartGPinTask */
}

/* USER CODE BEGIN Header_StartGPoutTask */
/**
* @brief Function implementing the GPoutTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartGPoutTask */
void StartGPoutTask(void *argument)
{
  /* USER CODE BEGIN StartGPoutTask */
  printf("===>> Func:%s !!\r\n", __FUNCTION__);
  printf("===>> osThreadGetCount = %d \r\n", osThreadGetCount());
  /* Infinite loop */
  for(;;)
  {
  	Set_Gpio();
    osDelay(1);
  }
  /* USER CODE END StartGPoutTask */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
