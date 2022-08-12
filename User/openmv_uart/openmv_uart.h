//
// Created by M on 2022/08/12.
//

#ifndef WAVE_OPENMV_UART_H
#define WAVE_OPENMV_UART_H

#include "main.h"

enum {
  NOT_AVAILABLE_,
  RED_,
  GREEN_,
  YELLOW_
};

HAL_StatusTypeDef openmvUartInit(void);
HAL_StatusTypeDef openmvUartStop(void);

extern uint8_t traffic_light;

#endif //WAVE_OPENMV_UART_H
