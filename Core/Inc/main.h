/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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
#define BEEP_Pin GPIO_PIN_8
#define BEEP_GPIO_Port GPIOF
#define LED0_Pin GPIO_PIN_9
#define LED0_GPIO_Port GPIOF
#define LED1_Pin GPIO_PIN_10
#define LED1_GPIO_Port GPIOF
#define DIR__Pin GPIO_PIN_0
#define DIR__GPIO_Port GPIOC
#define ECHO1_Pin GPIO_PIN_0
#define ECHO1_GPIO_Port GPIOA
#define EN__Pin GPIO_PIN_4
#define EN__GPIO_Port GPIOA
#define TRIG1_Pin GPIO_PIN_5
#define TRIG1_GPIO_Port GPIOA
#define KEY_Pin GPIO_PIN_7
#define KEY_GPIO_Port GPIOA
#define PUL__Pin GPIO_PIN_8
#define PUL__GPIO_Port GPIOA
#define link_sound_rx_Pin GPIO_PIN_9
#define link_sound_rx_GPIO_Port GPIOA
#define link_sound_tx_Pin GPIO_PIN_10
#define link_sound_tx_GPIO_Port GPIOA
#define OPENMV_LOW_Pin GPIO_PIN_6
#define OPENMV_LOW_GPIO_Port GPIOB
#define OPENMV_HIGH_Pin GPIO_PIN_7
#define OPENMV_HIGH_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
