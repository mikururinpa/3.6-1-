#include "PWM.h"
#include "ti_msp_dl_config.h"

void PWM_Init(void) {
    // 必须手动开启定时器计数！否则没有PWM输出
    DL_TimerA_startCounter(PWM_MOTOR_INST);
}

void PWM_SetMotorA(uint16_t duty) {
    if (duty > 7200) duty = 7200;
    // 修复底层API：电机定时器是TIMA0，必须用 DL_TimerA_ 开头
    DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, duty, DL_TIMER_CC_0_INDEX);
}

void PWM_SetMotorB(uint16_t duty) {
    if (duty > 7200) duty = 7200;
    // 修复底层API：电机定时器是TIMA0，必须用 DL_TimerA_ 开头
    DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, duty, DL_TIMER_CC_1_INDEX);
}