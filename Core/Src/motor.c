//
// Created by 24963 on 2022/8/13.
//
#include "motor.h"
#include "tim.h"
#include "openmv_uart.h"
#include "JQ8X00.h"
#include "usart.h"
#include "gpio.h"
#include "tim.h"
#include "main.h"

void Set_Speed_RPM(unsigned int speed)
{
    unsigned int set_speed_period;
    set_speed_period = (1800000 / (speed * 6 *32));

    __HAL_TIM_SET_AUTORELOAD(&htim1,set_speed_period - 1);
}

extern uint16_t dist;
extern uint16_t sound_flag;
extern uint16_t sound_count ;
void Motor_Down(uint8_t DIR){
    if (DIR == 1){
        MOTOR_DIR_POS;
        //MOTOR_DIR_NEG;
        Set_Speed_RPM(10);
        HAL_TIM_PWM_Start_IT(&htim1,TIM_CHANNEL_1);
        while(dist < 10)
        {
            HAL_TIM_PWM_Stop_IT(&htim1,TIM_CHANNEL_1);
        }
        HAL_TIM_PWM_Start_IT(&htim1,TIM_CHANNEL_1);
    }
    else if (DIR == 0){
        MOTOR_DIR_NEG;
        //MOTOR_DIR_NEG;
        Set_Speed_RPM(10);
        HAL_TIM_PWM_Start_IT(&htim1,TIM_CHANNEL_1);
        while(dist < 10)
        {
            HAL_TIM_PWM_Stop_IT(&htim1,TIM_CHANNEL_1);
        }
        HAL_TIM_PWM_Start_IT(&htim1,TIM_CHANNEL_1);
    }

}
extern uint8_t RED = 1;
extern uint8_t GREEN = 1;
extern uint8_t YELLOW = 1;

void General_Function(uint16_t distance){
    if (traffic_light == RED_){
        Motor_Down(1);
    }
}

