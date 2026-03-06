#ifndef __LINE_H__
#define __LINE_H__

#include <stdint.h>
#include "Encoder.h"

extern volatile uint32_t time;

#define ADC_N 8
extern int PWM_BASIC;
#define PWM_MAX 7200

// 🛡️ 转向PID参数 (大幅调柔和，匹配降低后的基础速度)
#define Kp 3.0f
#define Ki 0.0f
#define Kd 10.0f

typedef struct {
    int now;   
    int last;  
    int sum;   
} pid;

extern pid left;
extern pid right;

extern float Velcity_Kp1;
extern float Velcity_Ki1;
extern float Velcity_Kd1;
extern float Velcity_Kp2;
extern float Velcity_Ki2;
extern float Velcity_Kd2;

int Velocity_A(int target, int encoder);
int Velocity_B(int target, int encoder);
int whiteall(void);
void error_get(void);
void setspeed_pid(int direction);
void go_along_last(char RorL, int direction);

void Run_Square_Map(int target_loops); 
void Run_Normal_Map(int target_loops); 
void PID_Reset(void);

#endif