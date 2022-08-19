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

//extern int motor_flag;
//int Set_Speed_RPM_My(int speed)
//{
//    int set_speed_period;
//    set_speed_period = (1800000 / (speed * 6 *32));
//    motor_flag = set_speed_period;
//    __HAL_TIM_SET_AUTORELOAD(&htim1,set_speed_period - 1);
//    return set_speed_period;
//}

unsigned int Set_Speed_RPM(unsigned int speed)
{
    unsigned int set_speed_period;
    set_speed_period = (1800000 / (speed * 6 *32));
    __HAL_TIM_SET_AUTORELOAD(&htim1,set_speed_period - 1);
    return set_speed_period;
}

extern uint16_t dist;
uint16_t sound_flag = 0;
extern uint32_t sound_count;
void Motor_Down(uint8_t DIR){
    if (DIR == 1){
        MOTOR_DIR_POS;
        //MOTOR_DIR_NEG;
        Set_Speed_RPM(2);
        HAL_TIM_PWM_Start_IT(&htim1,TIM_CHANNEL_1);
//        while(dist < 10)
//        {
//            HAL_TIM_PWM_Stop_IT(&htim1,TIM_CHANNEL_1);
//        }
//        HAL_TIM_PWM_Start_IT(&htim1,TIM_CHANNEL_1);
    }
    else if (DIR == 0){
        MOTOR_DIR_NEG;
        //MOTOR_DIR_NEG;
        Set_Speed_RPM(2);
        HAL_TIM_PWM_Start_IT(&htim1,TIM_CHANNEL_1);
//        while(dist < 10)
//        {
//            HAL_TIM_PWM_Stop_IT(&htim1,TIM_CHANNEL_1);
//        }
//        HAL_TIM_PWM_Start_IT(&htim1,TIM_CHANNEL_1);
    }
}


extern uint8_t RED;
extern uint8_t GREEN;
extern uint8_t YELLOW;
uint8_t count = 0;
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim){
    if (htim == &htim1){

            if (RED == 1 && GREEN == 0) {
                RED = 0;
                GREEN = 1;
            }

            else if (RED == 0 && GREEN == 1 ) {
                RED = 1;
                GREEN = 0;
            }
            }
}

void General_Function(uint16_t distance){
    if (traffic_light == RED_ && RED == 1){
        if (sound_flag == 0){
            JQ8x00_Command_Data(AppointTrack, 1);
//            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
       //     HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
            sound_flag = 1;
        }
//        RED = 1;GREEN = 0;
//        Motor_Down(1);
//        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
//        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
//        HAL_TIM_PWM_PulseFinishedCallback(&htim1);
        RED = 1;GREEN = 0;YELLOW = 1;
        Motor_Down(1);

        if (distance < 30){
            HAL_TIM_PWM_Stop_IT(&htim1,TIM_CHANNEL_1);
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
        }
        else {
            HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_1);
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
            HAL_TIM_PWM_PulseFinishedCallback(&htim1);
        }
//        HAL_TIM_PWM_PulseFinishedCallback(&htim1);
//        sound_count++;
//        sound_flag = 1;
//        if (sound_flag) {
//            JQ8x00_Command_Data(AppointTrack, 1);
//            sound_flag = 0;
//        }
//        if (sound_count > 1000000000){
//            sound_flag = 1;
//            sound_count = 0;
//        }
    }
    else if(traffic_light == GREEN_ && GREEN == 1){
        if (sound_flag == 1){
            JQ8x00_Command_Data(AppointTrack, 2);
            sound_flag = 0;
        }
        RED = 0;GREEN = 1;YELLOW = 1;
        Motor_Down(0);
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
        HAL_TIM_PWM_PulseFinishedCallback(&htim1);
//        sound_count++;
//        sound_flag = 1;
//        if (sound_flag){
//            JQ8x00_Command_Data(AppointTrack, 2);
//            sound_flag = 0;
//        }
//        if (sound_count > 1000000000){
//            sound_flag = 1;
//            sound_count = 0;
//        }
    }
    else if (traffic_light == YELLOW_){
        if (YELLOW == 1){
            JQ8x00_Command_Data(AppointTrack, 3);
        }
        YELLOW = 0;
    }
}

