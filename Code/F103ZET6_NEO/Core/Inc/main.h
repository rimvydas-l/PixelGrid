/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

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
#define R25_1_Pin GPIO_PIN_3
#define R25_1_GPIO_Port GPIOE
#define R25_2_Pin GPIO_PIN_4
#define R25_2_GPIO_Port GPIOE
#define R24_1_Pin GPIO_PIN_5
#define R24_1_GPIO_Port GPIOE
#define R24_2_Pin GPIO_PIN_6
#define R24_2_GPIO_Port GPIOE
#define LED1_Pin GPIO_PIN_13
#define LED1_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_0
#define LED2_GPIO_Port GPIOF
#define R23_1_Pin GPIO_PIN_1
#define R23_1_GPIO_Port GPIOF
#define R23_2_Pin GPIO_PIN_2
#define R23_2_GPIO_Port GPIOF
#define R22_1_Pin GPIO_PIN_3
#define R22_1_GPIO_Port GPIOF
#define R22_2_Pin GPIO_PIN_4
#define R22_2_GPIO_Port GPIOF
#define R21_1_Pin GPIO_PIN_5
#define R21_1_GPIO_Port GPIOF
#define R21_2_Pin GPIO_PIN_6
#define R21_2_GPIO_Port GPIOF
#define R17_1_Pin GPIO_PIN_7
#define R17_1_GPIO_Port GPIOF
#define R17_2_Pin GPIO_PIN_8
#define R17_2_GPIO_Port GPIOF
#define R18_1_Pin GPIO_PIN_9
#define R18_1_GPIO_Port GPIOF
#define R18_2_Pin GPIO_PIN_10
#define R18_2_GPIO_Port GPIOF
#define R19_1_Pin GPIO_PIN_0
#define R19_1_GPIO_Port GPIOC
#define R19_2_Pin GPIO_PIN_1
#define R19_2_GPIO_Port GPIOC
#define R20_1_Pin GPIO_PIN_2
#define R20_1_GPIO_Port GPIOC
#define R20_2_Pin GPIO_PIN_3
#define R20_2_GPIO_Port GPIOC
#define R14_2_Pin GPIO_PIN_4
#define R14_2_GPIO_Port GPIOA
#define R14_1_Pin GPIO_PIN_5
#define R14_1_GPIO_Port GPIOA
#define R15_1_Pin GPIO_PIN_4
#define R15_1_GPIO_Port GPIOC
#define R15_2_Pin GPIO_PIN_5
#define R15_2_GPIO_Port GPIOC
#define R13_2_Pin GPIO_PIN_2
#define R13_2_GPIO_Port GPIOB
#define R13_1_Pin GPIO_PIN_11
#define R13_1_GPIO_Port GPIOF
#define R12_2_Pin GPIO_PIN_12
#define R12_2_GPIO_Port GPIOF
#define R16_1_Pin GPIO_PIN_13
#define R16_1_GPIO_Port GPIOF
#define R16_2_Pin GPIO_PIN_14
#define R16_2_GPIO_Port GPIOF
#define R12_1_Pin GPIO_PIN_15
#define R12_1_GPIO_Port GPIOF
#define R11_2_Pin GPIO_PIN_0
#define R11_2_GPIO_Port GPIOG
#define R11_1_Pin GPIO_PIN_1
#define R11_1_GPIO_Port GPIOG
#define R10_2_Pin GPIO_PIN_7
#define R10_2_GPIO_Port GPIOE
#define R10_1_Pin GPIO_PIN_8
#define R10_1_GPIO_Port GPIOE
#define R9_2_Pin GPIO_PIN_9
#define R9_2_GPIO_Port GPIOE
#define R9_1_Pin GPIO_PIN_10
#define R9_1_GPIO_Port GPIOE
#define R8_2_Pin GPIO_PIN_11
#define R8_2_GPIO_Port GPIOE
#define R8_1_Pin GPIO_PIN_12
#define R8_1_GPIO_Port GPIOE
#define R40_1_Pin GPIO_PIN_13
#define R40_1_GPIO_Port GPIOE
#define R40_2_Pin GPIO_PIN_14
#define R40_2_GPIO_Port GPIOE
#define R7_2_Pin GPIO_PIN_15
#define R7_2_GPIO_Port GPIOE
#define R7_1_Pin GPIO_PIN_10
#define R7_1_GPIO_Port GPIOB
#define R6_2_Pin GPIO_PIN_11
#define R6_2_GPIO_Port GPIOB
#define R4_1_Pin GPIO_PIN_12
#define R4_1_GPIO_Port GPIOB
#define R4_2_Pin GPIO_PIN_13
#define R4_2_GPIO_Port GPIOB
#define R3_1_Pin GPIO_PIN_14
#define R3_1_GPIO_Port GPIOB
#define R3_2_Pin GPIO_PIN_15
#define R3_2_GPIO_Port GPIOB
#define R2_1_Pin GPIO_PIN_8
#define R2_1_GPIO_Port GPIOD
#define R2_2_Pin GPIO_PIN_9
#define R2_2_GPIO_Port GPIOD
#define R1_2_Pin GPIO_PIN_10
#define R1_2_GPIO_Port GPIOD
#define R1_1_Pin GPIO_PIN_12
#define R1_1_GPIO_Port GPIOD
#define R5_1_Pin GPIO_PIN_2
#define R5_1_GPIO_Port GPIOG
#define R5_2_Pin GPIO_PIN_3
#define R5_2_GPIO_Port GPIOG
#define R6_1_Pin GPIO_PIN_4
#define R6_1_GPIO_Port GPIOG
#define R39_2_Pin GPIO_PIN_5
#define R39_2_GPIO_Port GPIOG
#define R39_1_Pin GPIO_PIN_6
#define R39_1_GPIO_Port GPIOG
#define R38_2_Pin GPIO_PIN_7
#define R38_2_GPIO_Port GPIOG
#define R38_1_Pin GPIO_PIN_8
#define R38_1_GPIO_Port GPIOG
#define R37_2_Pin GPIO_PIN_7
#define R37_2_GPIO_Port GPIOC
#define R37_1_Pin GPIO_PIN_8
#define R37_1_GPIO_Port GPIOC
#define R36_2_Pin GPIO_PIN_9
#define R36_2_GPIO_Port GPIOA
#define R36_1_Pin GPIO_PIN_10
#define R36_1_GPIO_Port GPIOA
#define R35_2_Pin GPIO_PIN_15
#define R35_2_GPIO_Port GPIOA
#define R35_1_Pin GPIO_PIN_10
#define R35_1_GPIO_Port GPIOC
#define R34_2_Pin GPIO_PIN_11
#define R34_2_GPIO_Port GPIOC
#define R34_1_Pin GPIO_PIN_12
#define R34_1_GPIO_Port GPIOC
#define R33_2_Pin GPIO_PIN_3
#define R33_2_GPIO_Port GPIOD
#define R33_1_Pin GPIO_PIN_4
#define R33_1_GPIO_Port GPIOD
#define R32_2_Pin GPIO_PIN_5
#define R32_2_GPIO_Port GPIOD
#define R32_1_Pin GPIO_PIN_6
#define R32_1_GPIO_Port GPIOD
#define R31_2_Pin GPIO_PIN_7
#define R31_2_GPIO_Port GPIOD
#define R31_1_Pin GPIO_PIN_9
#define R31_1_GPIO_Port GPIOG
#define R30_2_Pin GPIO_PIN_10
#define R30_2_GPIO_Port GPIOG
#define R30_1_Pin GPIO_PIN_11
#define R30_1_GPIO_Port GPIOG
#define R29_2_Pin GPIO_PIN_15
#define R29_2_GPIO_Port GPIOG
#define R29_1_Pin GPIO_PIN_3
#define R29_1_GPIO_Port GPIOB
#define R28_2_Pin GPIO_PIN_4
#define R28_2_GPIO_Port GPIOB
#define R28_1_Pin GPIO_PIN_5
#define R28_1_GPIO_Port GPIOB
#define R27_2_Pin GPIO_PIN_6
#define R27_2_GPIO_Port GPIOB
#define R27_1_Pin GPIO_PIN_7
#define R27_1_GPIO_Port GPIOB
#define R26_2_Pin GPIO_PIN_8
#define R26_2_GPIO_Port GPIOB
#define R26_1_Pin GPIO_PIN_9
#define R26_1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
