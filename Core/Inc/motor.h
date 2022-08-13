//
// Created by 24963 on 2022/8/13.
//

#ifndef WAVE_MOTOR_H
#define WAVE_MOTOR_H

#include "main.h"

#define MOTOR_DIR_POS HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET)
#define MOTOR_DIR_NEG HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_SET)

void Set_Speed_RPM(unsigned int speed);
void Motor_Down(uint8_t DIR);

#endif //WAVE_MOTOR_H
