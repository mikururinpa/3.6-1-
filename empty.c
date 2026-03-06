#include "ti_msp_dl_config.h"
#include "Delay.h"
#include "Motor.h"
#include "PWM.h"
#include "sensor.h"
#include "Encoder.h"
#include "line.h"

volatile uint32_t time = 0; 
void SysTick_Handler(void) {
    time++;  
}

int main(void) {
    // 1. 初始化底层硬件
    SYSCFG_DL_init();
    DL_SYSTICK_enable();

    // 2. 初始化核心外设
    Delay_Init();
    Motor_Init();
    
    // 🚨 给你 2 秒钟时间把小车放在赛道上，然后把手拿开！
    Delay_ms(2000); 
    
    // 3. 重置PID，准备发车
    PID_Reset();

    // 4. 纯净循迹死循环
    while (1) {
        setspeed_pid(1); // 疯狂执行循迹算法
        Delay_ms(5);     // 5ms 控制周期，刷新率极高，循迹更丝滑
    }
}