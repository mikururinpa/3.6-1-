#include "line.h"
#include "Motor.h"
#include "Encoder.h"
#include "sensor.h"
#include "Delay.h"

int Velocity_PWM1, Velocity_PWM2;
int encoder_A, encoder_B;
int Turn_Lock_State = 0;

float Velcity_Kp1 = 0.0001f, Velcity_Ki1 = 0.0000001f, Velcity_Kd1 = 1.06f;
float Velcity_Kp2 = 0.0001f, Velcity_Ki2 = 0.0000001f, Velcity_Kd2 = 1.06f;

// 🛡️ 极慢速发车：把基础速度直接压低到 800（满速是7200）
int PWM_BASIC = 800;

pid right = {0, 0, 0};
pid left = {0, 0, 0};
char RorL = 'S'; 

int Vel_A_ControlVelocity = 0, Vel_A_Last_bias = 0;
int Vel_B_ControlVelocity = 0, Vel_B_Last_bias = 0;

void PID_Reset(void){
    left.now = 0; left.last = 0; left.sum = 0;
    right.now = 0; right.last = 0; right.sum = 0;
    Vel_A_ControlVelocity = 0; Vel_A_Last_bias = 0;
    Vel_B_ControlVelocity = 0; Vel_B_Last_bias = 0;
    RorL = 'S';
    Turn_Lock_State = 0;
    Read_Encoder(4);
    Read_Encoder(2);
    motor(0, 0);
}

int Velocity_A(int target, int encoder) {
    int Bias = target - encoder;
    Vel_A_ControlVelocity += Velcity_Kd1 * (Bias - Vel_A_Last_bias) + Velcity_Ki1 * Bias + Velcity_Kp1 * Bias;
    Vel_A_Last_bias = Bias;
    return Vel_A_ControlVelocity;
}

int Velocity_B(int target, int encoder) {
    int Bias = target - encoder;
    Vel_B_ControlVelocity += Velcity_Kd2 * (Bias - Vel_B_Last_bias) + Velcity_Ki2 * Bias + Velcity_Kp2 * Bias;
    Vel_B_Last_bias = Bias;
    return Vel_B_ControlVelocity;
}

int whiteall(void) {
    if (L3 + L2 + L1 + M0 + M1 + R1 + R2 + R3 == 0) return 1;
    else return 0;
}

void error_get(void) {
    int error1 = 40, error2 = 150, error3 = 450;
    if (M0 == 1 || M1 == 1) { Turn_Lock_State = 0; }

    if (Turn_Lock_State != 2) { 
        if (L1 == 1) { left.now -= error1; right.now += error1; }
        if (L2 == 1) { left.now -= error2; right.now += error2; }
        if (L3 == 1) { left.now -= error3; right.now += error3; RorL = 'L'; Turn_Lock_State = 1; }
    }

    if (Turn_Lock_State != 1) {
        if (R1 == 1) { left.now += error1; right.now -= error1; }
        if (R2 == 1) { left.now += error2; right.now -= error2; }
        if (R3 == 1) { left.now += error3; right.now -= error3; RorL = 'R'; Turn_Lock_State = 2; }
    }
}

// 🛡️ 重写找线逻辑：开机没看到线就匀速直走，拐弯丢线就继续拐
void go_along_last(char RorL, int direction) {
    // 如果一开机就是全白，或者在直线上丢线了，匀速直走！
    if (RorL == 'S') {
        motor(PWM_BASIC, PWM_BASIC);
        return;
    }

    // 如果之前是往左/右拐丢的线，继续往对应方向找线
    int turn_speed = -300;  // 内侧轮轻微反转
    int forward_speed = 800; // 外侧轮加速

    // 提示：PWM1 是右轮(A)，PWM2 是左轮(B)
    if (RorL == 'L') {
        motor(forward_speed, turn_speed); // 右轮快，左轮反转 -> 原地左转
    } else if (RorL == 'R') {
        motor(turn_speed, forward_speed); // 右轮反转，左轮快 -> 原地右转
    }
}

void setspeed_pid(int direction) {
    int PWM1, PWM2;
    
    left.now = 0; 
    right.now = 0;
    error_get();
    
    if (whiteall()) {
        go_along_last(RorL, direction);
        return; 
    }
    
    left.sum += left.now;
    right.sum += right.now;
    
    int Integral_Limit = 2000; 
    if (left.sum > Integral_Limit) left.sum = Integral_Limit;
    if (left.sum < -Integral_Limit) left.sum = -Integral_Limit;
    if (right.sum > Integral_Limit) right.sum = Integral_Limit;
    if (right.sum < -Integral_Limit) right.sum = -Integral_Limit;
    
    Velocity_PWM1 = PWM_BASIC + Kp * right.now + Ki * right.sum + Kd * (right.now - right.last);
    Velocity_PWM2 = PWM_BASIC + Kp * left.now  + Ki * left.sum  + Kd * (left.now - left.last);
    
    encoder_A = Read_Encoder(4);  
    encoder_B = Read_Encoder(2);  
    
    PWM1 = Velocity_A(Velocity_PWM1, encoder_A);
    PWM2 = Velocity_B(Velocity_PWM2, encoder_B);
    
    motor(PWM1, PWM2);
    
    left.last = left.now;
    right.last = right.now;
}

void Run_Square_Map(int target_loops) {}
void Run_Normal_Map(int target_loops) {}