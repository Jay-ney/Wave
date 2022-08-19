//
// Created by 24963 on 2022/8/13.
//

#ifndef WAVE_MOTOR_H
#define WAVE_MOTOR_H

#include "main.h"

#define MOTOR_DIR_POS HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,RESET)
#define MOTOR_DIR_NEG HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,SET)

unsigned int Set_Speed_RPM(unsigned int speed);
void Motor_Down(uint8_t DIR);
void General_Function(uint16_t distance);

#endif //WAVE_MOTOR_H
