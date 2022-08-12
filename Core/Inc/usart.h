/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
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
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#define UART1                                 USART1
#define UART1_BAUDRATE                        9600
#define UART_RCC_CLK_ENABLE()                 __HAL_RCC_USART1_CLK_ENABLE()
#define UART_RCC_CLK_DISABLE()                __HAL_RCC_USART1_CLK_DISABLE()

#define UART1_GPIO_ClK_ENABLE()               __HAL_RCC_GPIOA_CLK_ENABLE()
#define UART1_Tx_GPIO_PIN                     GPIO_PIN_9
#define UART1_Tx_GPIO                         GPIOA
#define UART1_Rx_GPIO_PIN                     GPIO_PIN_10
#define UART1_Rx_GPIO                         GPIOA

#define UART1_IRQHANDLER                      UART1_IRQHandler
#define UART1_IRQn                            USART1_IRQn
/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;

extern UART_HandleTypeDef huart2;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);
void MX_USART2_UART_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

