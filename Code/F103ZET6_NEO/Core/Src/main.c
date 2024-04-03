/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "can.h"
#include "dma.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "rotary.h"
#include "LED.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define ROTARY_COUNT 40

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

RotaryEnc_t rotary[ROTARY_COUNT];
Module_t modules[MODULE_COUNT];


CAN_TxHeaderTypeDef   TxHeader;
uint8_t               TxData[8];
uint32_t              TxMailbox;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

void InitRotary(uint8_t arrNr, GPIO_TypeDef *GPIO_port1, uint16_t GPIO_Pin1, GPIO_TypeDef *GPIO_port2, uint16_t GPIO_Pin2);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	for(uint8_t i = 0; i < MODULE_COUNT; i++)
	{
		if (modules[i].status==MODULE_STATUS_UPDATING)
		{
			HAL_TIM_PWM_Stop_DMA(modules[i].htim, modules[i].Channel);
			modules[i].status = MODULE_STATUS_OK;
			break;
		}
	}
}

// Callback: timer has rolled over
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  // Check which version of the timer triggered this callback and toggle LED
  if (htim == &htim7 )
  {
	  //HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);

	  for(int r=0; r < ROTARY_COUNT; r++)
	  {
		  if(HAL_GPIO_ReadPin(rotary[r].pin1.GPIO_port, rotary[r].pin1.GPIO_Pin)==GPIO_PIN_SET)
		  {
			  rotary[r].pinStatus.status.r1 = 1;
		  } else {
			  rotary[r].pinStatus.status.r1 = 0;
		  }
		  if(HAL_GPIO_ReadPin(rotary[r].pin2.GPIO_port, rotary[r].pin2.GPIO_Pin)==GPIO_PIN_SET)
		  {
			  rotary[r].pinStatus.status.r2 = 1;
		  } else {
			  rotary[r].pinStatus.status.r2 = 0;
		  }

		  if ( rotary[r].pinStatus.data != rotary[r].historyStatus.data ) {
			  RotaryProcess(&rotary[r], COLOR_COUNT-1);
		  }
	  };
  }
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */


	  int i, j, k;
	  uint16_t stepSize;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  InitRotary(0, R1_1_GPIO_Port, R1_1_Pin, R1_2_GPIO_Port, R1_2_Pin);
  InitRotary(1, R2_1_GPIO_Port, R2_1_Pin, R2_2_GPIO_Port, R2_2_Pin);
  InitRotary(2, R3_1_GPIO_Port, R3_1_Pin, R3_2_GPIO_Port, R3_2_Pin);
  InitRotary(3, R4_1_GPIO_Port, R4_1_Pin, R4_2_GPIO_Port, R4_2_Pin);
  InitRotary(4, R5_1_GPIO_Port, R5_1_Pin, R5_2_GPIO_Port, R5_2_Pin);
  InitRotary(5, R6_1_GPIO_Port, R6_1_Pin, R6_2_GPIO_Port, R6_2_Pin);
  InitRotary(6, R7_1_GPIO_Port, R7_1_Pin, R7_2_GPIO_Port, R7_2_Pin);
  InitRotary(7, R8_1_GPIO_Port, R8_1_Pin, R8_2_GPIO_Port, R8_2_Pin);
  InitRotary(8, R9_1_GPIO_Port, R9_1_Pin, R9_2_GPIO_Port, R9_2_Pin);
  InitRotary(9, R10_1_GPIO_Port, R10_1_Pin, R10_2_GPIO_Port, R10_2_Pin);
  InitRotary(10, R11_1_GPIO_Port, R11_1_Pin, R11_2_GPIO_Port, R11_2_Pin);
  InitRotary(11, R12_1_GPIO_Port, R12_1_Pin, R12_2_GPIO_Port, R12_2_Pin);
  InitRotary(12, R13_1_GPIO_Port, R13_1_Pin, R13_2_GPIO_Port, R13_2_Pin);
  InitRotary(13, R14_1_GPIO_Port, R14_1_Pin, R14_2_GPIO_Port, R14_2_Pin);
  InitRotary(14, R15_1_GPIO_Port, R15_1_Pin, R15_2_GPIO_Port, R15_2_Pin);
  InitRotary(15, R16_1_GPIO_Port, R16_1_Pin, R16_2_GPIO_Port, R16_2_Pin);
  InitRotary(16, R17_1_GPIO_Port, R17_1_Pin, R17_2_GPIO_Port, R17_2_Pin);
  InitRotary(17, R18_1_GPIO_Port, R18_1_Pin, R18_2_GPIO_Port, R18_2_Pin);
  InitRotary(18, R19_1_GPIO_Port, R19_1_Pin, R19_2_GPIO_Port, R19_2_Pin);
  InitRotary(19, R20_1_GPIO_Port, R20_1_Pin, R20_2_GPIO_Port, R20_2_Pin);
  InitRotary(20, R21_1_GPIO_Port, R21_1_Pin, R21_2_GPIO_Port, R21_2_Pin);
  InitRotary(21, R22_1_GPIO_Port, R22_1_Pin, R22_2_GPIO_Port, R22_2_Pin);
  InitRotary(22, R23_1_GPIO_Port, R23_1_Pin, R23_2_GPIO_Port, R23_2_Pin);
  InitRotary(23, R24_1_GPIO_Port, R24_1_Pin, R24_2_GPIO_Port, R24_2_Pin);
  InitRotary(24, R25_1_GPIO_Port, R25_1_Pin, R25_2_GPIO_Port, R25_2_Pin);
  InitRotary(25, R26_1_GPIO_Port, R26_1_Pin, R26_2_GPIO_Port, R26_2_Pin);
  InitRotary(26, R27_1_GPIO_Port, R27_1_Pin, R27_2_GPIO_Port, R27_2_Pin);
  InitRotary(27, R28_1_GPIO_Port, R28_1_Pin, R28_2_GPIO_Port, R28_2_Pin);
  InitRotary(28, R29_1_GPIO_Port, R29_1_Pin, R29_2_GPIO_Port, R29_2_Pin);
  InitRotary(29, R30_1_GPIO_Port, R30_1_Pin, R30_2_GPIO_Port, R30_2_Pin);
  InitRotary(30, R31_1_GPIO_Port, R31_1_Pin, R31_2_GPIO_Port, R31_2_Pin);
  InitRotary(31, R32_1_GPIO_Port, R32_1_Pin, R32_2_GPIO_Port, R32_2_Pin);
  InitRotary(32, R33_1_GPIO_Port, R33_1_Pin, R33_2_GPIO_Port, R33_2_Pin);
  InitRotary(33, R34_1_GPIO_Port, R34_1_Pin, R34_2_GPIO_Port, R34_2_Pin);
  InitRotary(34, R35_1_GPIO_Port, R35_1_Pin, R35_2_GPIO_Port, R35_2_Pin);
  InitRotary(35, R36_1_GPIO_Port, R36_1_Pin, R36_2_GPIO_Port, R36_2_Pin);
  InitRotary(36, R37_1_GPIO_Port, R37_1_Pin, R37_2_GPIO_Port, R37_2_Pin);
  InitRotary(37, R38_1_GPIO_Port, R38_1_Pin, R38_2_GPIO_Port, R38_2_Pin);
  InitRotary(38, R39_1_GPIO_Port, R39_1_Pin, R39_2_GPIO_Port, R39_2_Pin);
  InitRotary(39, R40_1_GPIO_Port, R40_1_Pin, R40_2_GPIO_Port, R40_2_Pin);


  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM4_Init();
  MX_TIM7_Init();
  MX_CAN_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM5_Init();
  MX_TIM8_Init();
  /* USER CODE BEGIN 2 */

  InitModule(&modules[0], &htim4, TIM_CHANNEL_2);
  InitModule(&modules[1], &htim2, TIM_CHANNEL_3);
  InitModule(&modules[2], &htim2, TIM_CHANNEL_2);
  InitModule(&modules[3], &htim3, TIM_CHANNEL_1);
  InitModule(&modules[4], &htim3, TIM_CHANNEL_3);
  InitModule(&modules[5], &htim3, TIM_CHANNEL_4);
  InitModule(&modules[6], &htim4, TIM_CHANNEL_3);
  InitModule(&modules[7], &htim5, TIM_CHANNEL_4);
  InitModule(&modules[8], &htim8, TIM_CHANNEL_4);
  InitModule(&modules[9], &htim8, TIM_CHANNEL_1);

  // Start timer
  HAL_TIM_Base_Start_IT(&htim7);

  //Can
  HAL_CAN_Start(&hcan);

  TxHeader.IDE = CAN_ID_STD;
  TxHeader.StdId = 0x446;
  TxHeader.RTR = CAN_RTR_DATA;
  TxHeader.DLC = 2;

  TxData[0] = 50;
  TxData[1] = 0xAA;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  k = 255;
  stepSize = 0;
  j=0;

  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
  while (1)
  {
	  if(k==0)
	  {
		  k=100;
		  HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
	  }
	  k--;//*/


	  for (int m=0; m < MODULE_COUNT; m++)
	  {
		  int changed = 0;
		  for(int r=0; r < 4; r++)
		  {
			  if(rotary[m*4 + r].changed){
				  SetPixelColorP(&modules[m].pixels[r], rotary[m*4 + r].counter % COLOR_COUNT);
				  changed = 1;
				  rotary[m*4 + r].changed=0;
			  }
		  }
		  if (changed) UpdateModule(&modules[m]);
	  }



	  for(uint8_t i = 0; i < MODULE_COUNT; i++)
	  {
		  if(modules[i].status == MODULE_STATUS_NEEDS_UPDATE)
		  {
			  UpdateModuleColor(&modules[i]);
			  //UpdateModule(&modules[i]);
			  break;
		  }
	  }
	  //if (HAL_CAN_AddTxMessage(&hcan, &TxHeader, TxData, &TxMailbox) != HAL_OK)
	  //{
	  //   Error_Handler ();
	  //}
	  //HAL_Delay(500);





    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  HAL_Delay(1);
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
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
}

/* USER CODE BEGIN 4 */

void InitRotary(uint8_t arrNr, GPIO_TypeDef *GPIO_port1, uint16_t GPIO_Pin1, GPIO_TypeDef *GPIO_port2, uint16_t GPIO_Pin2)
{
	  rotary[arrNr].pin1.GPIO_port=GPIO_port1;
	  rotary[arrNr].pin1.GPIO_Pin=GPIO_Pin1;
	  rotary[arrNr].pin2.GPIO_port=GPIO_port2;
	  rotary[arrNr].pin2.GPIO_Pin=GPIO_Pin2;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
