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


unsigned int Set_Speed_RPM(unsigned int speed) {
  unsigned int set_speed_period;
  set_speed_period = (1800000 / (speed * 6 * 32));
  __HAL_TIM_SET_AUTORELOAD(&htim1, set_speed_period - 1);
  return set_speed_period;
}

extern uint16_t dist;
uint16_t sound_flag = 0;
extern uint32_t sound_count;

void Motor_Down(uint8_t DIR) {
  if (DIR == 1) {
    MOTOR_DIR_POS;
    //MOTOR_DIR_NEG;
    Set_Speed_RPM(2);
    HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_1);
  } else if (DIR == 0) {
    MOTOR_DIR_NEG;
    //MOTOR_DIR_NEG;
    Set_Speed_RPM(10);
    HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_1);
  }
}


extern uint8_t RED;
extern uint8_t GREEN;
extern uint8_t YELLOW;
extern uint8_t STOP;

void General_Function(uint16_t distance) {
  if (traffic_light == RED_) {
    if (distance < 20) {
      MotorStop();
    } else {
      MotorNeg();
      HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
      if (HAL_GPIO_ReadPin(KEY_GPIO_Port, KEY_Pin) == GPIO_PIN_SET) {
        MotorPos();
      }
    }
    if (RED == 1 && distance > 20) {
      JQ8x00_Command_Data(AppointTrack, 1);
      RED = 0;
      GREEN = 1;
      YELLOW = 1;
      STOP = 1;
    }
    if (STOP == 1 && distance <20) {
      JQ8x00_Command_Data(AppointTrack, 4);
      STOP = 0;
      RED = 1;
      GREEN = 1;
      YELLOW = 1;

    }
  } else if (traffic_light == GREEN_) {
    MotorPos();
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
    if (GREEN == 1) {
      JQ8x00_Command_Data(AppointTrack, 2);
      RED = 1;
      GREEN = 0;
      YELLOW = 1;
      STOP = 1;
    }
  } else if (traffic_light == YELLOW_) {
    if (YELLOW == 1) {
      JQ8x00_Command_Data(AppointTrack, 3);
      RED = 1;
      GREEN = 1;
      YELLOW = 0;
      STOP = 1;
    }
  }
}


extern int16_t angle;

void motorInit(void) {
//    HAL_Delay(100);
//    MotorPos();
//    HAL_Delay(1000);
//    MotorStop();
//    angle = 0;
  if (dist < 20 && angle == 0){
    JQ8x00_Command_Data(AppointTrack, 5);
    HAL_Delay(100);
    MotorPos();
    HAL_Delay(1000);
    MotorStop();
    angle = 1;
  }
}

void MotorPos(void) {
  MOTOR_DIR_POS;
  Set_Speed_RPM(12);
  if (angle < 1590)
    HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_1);
}

void MotorNeg(void) {
  MOTOR_DIR_NEG;
  Set_Speed_RPM(3);
  if (angle > 10)
    HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_1);
}

void MotorStop(void) {
  HAL_TIM_PWM_Stop_IT(&htim1, TIM_CHANNEL_1);
}
