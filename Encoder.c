#include "Encoder.h"
#include "ti_msp_dl_config.h" // 包含 SysConfig 自动生成的头文件

// 用于右电机的软件计数器
volatile int16_t encoder_r_count = 0;

// 原本复杂的硬件初始化函数现在全留空，因为 SysConfig 已经全部帮你做好了
void Encoder_Init_Tim2(void) { }
void Encoder_Init_Tim4(void) { }

// 读取编码器数值 (对应你 line.c 里的 10ms 速度计算)
int Read_Encoder(uint8_t TIMX) {
    int Encoder_TIM;
    if (TIMX == 4) { 
        // 左电机 (原TIM4)：直接读取硬件 QEI 的计数器
        Encoder_TIM = (int16_t)DL_TimerA_getTimerCount(ENCODER_L_INST);
        // 读取后将硬件计数器清零，为下个 10ms 周期做准备
        DL_TimerA_setTimerCount(ENCODER_L_INST, 0);
    }
    else if (TIMX == 2) { 
        // 右电机 (原TIM2)：读取我们自己写在中断里的软件计数器
        Encoder_TIM = encoder_r_count;
        // 读完立刻清零
        encoder_r_count = 0; 
    }
    else {
        Encoder_TIM = 0;
    }
    return Encoder_TIM;
}

// ==========================================
// 右电机专用GPIO 外部中断服务函数 (软件数脉冲)
// ==========================================
void GROUP1_IRQHandler(void) {
    switch (DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1)) {
        case ENCODER_R_INT_IIDX:
            switch (DL_GPIO_getPendingInterrupt(ENCODER_R_PORT)) {
                case ENCODER_R_PH_A_IIDX:
                    if (DL_GPIO_readPins(ENCODER_R_PORT, ENCODER_R_PH_B_PIN)) {
                        encoder_r_count++; 
                    } else {
                        encoder_r_count--; 
                    }
                    break;
                default: 
                    break;
            }
            break;
        default: 
            break;
    }
}