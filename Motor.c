#include "Motor.h"
#include "PWM.h"
#include "ti_msp_dl_config.h"
#include <math.h>
#include <stdlib.h>
void Motor_Init(void) {
    Motor_SetDirA(MOTOR_STOP);
    Motor_SetDirB(MOTOR_STOP);
    PWM_Init();
    
    PWM_SetMotorA(0);
    PWM_SetMotorB(0);
}

void Motor_SetDirA(Motor_Dir dir) {
    switch (dir) {
        case MOTOR_STOP:      DL_GPIO_clearPins(MOTOR_DIR_PORT, MOTOR_DIR_AIN1_PIN | MOTOR_DIR_AIN2_PIN); break;
        case MOTOR_FORWARD:   DL_GPIO_setPins(MOTOR_DIR_PORT, MOTOR_DIR_AIN1_PIN); DL_GPIO_clearPins(MOTOR_DIR_PORT, MOTOR_DIR_AIN2_PIN); break;
        case MOTOR_BACKWARD:  DL_GPIO_clearPins(MOTOR_DIR_PORT, MOTOR_DIR_AIN1_PIN); DL_GPIO_setPins(MOTOR_DIR_PORT, MOTOR_DIR_AIN2_PIN); break;
        case MOTOR_BRAKE:     DL_GPIO_setPins(MOTOR_DIR_PORT, MOTOR_DIR_AIN1_PIN | MOTOR_DIR_AIN2_PIN); break;
    }
}

void Motor_SetDirB(Motor_Dir dir) {
    switch (dir) {
        case MOTOR_STOP:      DL_GPIO_clearPins(MOTOR_DIR_PORT, MOTOR_DIR_BIN1_PIN | MOTOR_DIR_BIN2_PIN); break;
        case MOTOR_FORWARD:   DL_GPIO_setPins(MOTOR_DIR_PORT, MOTOR_DIR_BIN1_PIN); DL_GPIO_clearPins(MOTOR_DIR_PORT, MOTOR_DIR_BIN2_PIN); break;
        case MOTOR_BACKWARD:  DL_GPIO_clearPins(MOTOR_DIR_PORT, MOTOR_DIR_BIN1_PIN); DL_GPIO_setPins(MOTOR_DIR_PORT, MOTOR_DIR_BIN2_PIN); break;
        case MOTOR_BRAKE:     DL_GPIO_setPins(MOTOR_DIR_PORT, MOTOR_DIR_BIN1_PIN | MOTOR_DIR_BIN2_PIN); break;
    }
}

void Motor_ControlA(Motor_Dir dir, uint16_t speed) { Motor_SetDirA(dir); PWM_SetMotorA(speed); }
void Motor_ControlB(Motor_Dir dir, uint16_t speed) { Motor_SetDirB(dir); PWM_SetMotorB(speed); }

void motor(int Motor_1, int Motor_2) {
    if (Motor_1 == 0) { Motor_SetDirA(MOTOR_STOP); PWM_SetMotorA(0); } 
    else {
        uint16_t pwmA = (uint16_t)abs(Motor_1);
        if (pwmA > 7200) pwmA = 7200;
        if (Motor_1 > 0) Motor_ControlA(MOTOR_FORWARD, pwmA);
        else Motor_ControlA(MOTOR_BACKWARD, pwmA);
    }
    if (Motor_2 == 0) { Motor_SetDirB(MOTOR_STOP); PWM_SetMotorB(0); } 
    else {
        uint16_t pwmB = (uint16_t)abs(Motor_2);
        if (pwmB > 7200) pwmB = 7200;
        if (Motor_2 > 0) Motor_ControlB(MOTOR_FORWARD, pwmB);
        else Motor_ControlB(MOTOR_BACKWARD, pwmB);
    }
}