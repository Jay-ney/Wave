//
// Created by M on 2022/08/12.
//

#include "openmv_uart.h"
#include "usart.h"
#include "string.h"

#define OPENMV_UART_HANDLE huart5
#define DATA_LENGTH 1

uint8_t buffer[DATA_LENGTH];
uint8_t data[DATA_LENGTH];
uint8_t traffic_light = NOT_AVAILABLE_;

HAL_StatusTypeDef openmvUartInit(void){
  __HAL_UART_ENABLE_IT(&OPENMV_UART_HANDLE, UART_IT_IDLE);
  return HAL_UART_Receive_DMA(
      &OPENMV_UART_HANDLE, (uint8_t *) buffer, DATA_LENGTH);
}

void dataProcess(void){
  if (data[0]>YELLOW_) {
    traffic_light = NOT_AVAILABLE_;
  } else {
    traffic_light = data[0];
  }
}

void uart5Callback(void){
  memcpy(data, buffer, DATA_LENGTH);
  dataProcess();
  HAL_UART_Receive_DMA(
      &OPENMV_UART_HANDLE, (uint8_t *) buffer, DATA_LENGTH);
}

HAL_StatusTypeDef openmvUartStop(void){
  __HAL_UART_DISABLE_IT(&OPENMV_UART_HANDLE, UART_IT_IDLE);
  return HAL_UART_DMAStop(&OPENMV_UART_HANDLE);
}

void updateFromGPIO(void){
  uint8_t low = HAL_GPIO_ReadPin(OPENMV_LOW_GPIO_Port, OPENMV_LOW_Pin);
  uint8_t high = HAL_GPIO_ReadPin(OPENMV_HIGH_GPIO_Port, OPENMV_HIGH_Pin);
  if(low==GPIO_PIN_RESET && high==GPIO_PIN_RESET){
      traffic_light = NOT_AVAILABLE_;
  }
  else if(low==GPIO_PIN_SET && high==GPIO_PIN_RESET){
      traffic_light = RED_;
  }
  else if(low==GPIO_PIN_RESET && high==GPIO_PIN_SET){
      traffic_light = GREEN_;
  }
  else if(low==GPIO_PIN_SET && high==GPIO_PIN_SET){
      traffic_light = YELLOW_;
  }
}