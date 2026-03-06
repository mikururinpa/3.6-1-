/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_MOTOR */
#define PWM_MOTOR_INST                                                     TIMA0
#define PWM_MOTOR_INST_IRQHandler                               TIMA0_IRQHandler
#define PWM_MOTOR_INST_INT_IRQN                                 (TIMA0_INT_IRQn)
#define PWM_MOTOR_INST_CLK_FREQ                                         32000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_MOTOR_C0_PORT                                             GPIOB
#define GPIO_PWM_MOTOR_C0_PIN                                      DL_GPIO_PIN_8
#define GPIO_PWM_MOTOR_C0_IOMUX                                  (IOMUX_PINCM25)
#define GPIO_PWM_MOTOR_C0_IOMUX_FUNC                 IOMUX_PINCM25_PF_TIMA0_CCP0
#define GPIO_PWM_MOTOR_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_MOTOR_C1_PORT                                             GPIOB
#define GPIO_PWM_MOTOR_C1_PIN                                     DL_GPIO_PIN_20
#define GPIO_PWM_MOTOR_C1_IOMUX                                  (IOMUX_PINCM48)
#define GPIO_PWM_MOTOR_C1_IOMUX_FUNC                 IOMUX_PINCM48_PF_TIMA0_CCP1
#define GPIO_PWM_MOTOR_C1_IDX                                DL_TIMER_CC_1_INDEX




/* Defines for ENCODER_L */
#define ENCODER_L_INST                                                     TIMG8
#define ENCODER_L_INST_IRQHandler                               TIMG8_IRQHandler
#define ENCODER_L_INST_INT_IRQN                                 (TIMG8_INT_IRQn)
/* Pin configuration defines for ENCODER_L PHA Pin */
#define GPIO_ENCODER_L_PHA_PORT                                            GPIOA
#define GPIO_ENCODER_L_PHA_PIN                                    DL_GPIO_PIN_23
#define GPIO_ENCODER_L_PHA_IOMUX                                 (IOMUX_PINCM53)
#define GPIO_ENCODER_L_PHA_IOMUX_FUNC                IOMUX_PINCM53_PF_TIMG8_CCP0
/* Pin configuration defines for ENCODER_L PHB Pin */
#define GPIO_ENCODER_L_PHB_PORT                                            GPIOA
#define GPIO_ENCODER_L_PHB_PIN                                    DL_GPIO_PIN_22
#define GPIO_ENCODER_L_PHB_IOMUX                                 (IOMUX_PINCM47)
#define GPIO_ENCODER_L_PHB_IOMUX_FUNC                IOMUX_PINCM47_PF_TIMG8_CCP1


/* Defines for TIMER_10MS */
#define TIMER_10MS_INST                                                  (TIMA1)
#define TIMER_10MS_INST_IRQHandler                              TIMA1_IRQHandler
#define TIMER_10MS_INST_INT_IRQN                                (TIMA1_INT_IRQn)
#define TIMER_10MS_INST_LOAD_VALUE                                          (0U)




/* Defines for I2C_OLED */
#define I2C_OLED_INST                                                       I2C0
#define I2C_OLED_INST_IRQHandler                                 I2C0_IRQHandler
#define I2C_OLED_INST_INT_IRQN                                     I2C0_INT_IRQn
#define I2C_OLED_BUS_SPEED_HZ                                             100000
#define GPIO_I2C_OLED_SDA_PORT                                             GPIOA
#define GPIO_I2C_OLED_SDA_PIN                                     DL_GPIO_PIN_28
#define GPIO_I2C_OLED_IOMUX_SDA                                   (IOMUX_PINCM3)
#define GPIO_I2C_OLED_IOMUX_SDA_FUNC                    IOMUX_PINCM3_PF_I2C0_SDA
#define GPIO_I2C_OLED_SCL_PORT                                             GPIOA
#define GPIO_I2C_OLED_SCL_PIN                                     DL_GPIO_PIN_31
#define GPIO_I2C_OLED_IOMUX_SCL                                   (IOMUX_PINCM6)
#define GPIO_I2C_OLED_IOMUX_SCL_FUNC                    IOMUX_PINCM6_PF_I2C0_SCL



/* Defines for S1: GPIOA.2 with pinCMx 7 on package pin 42 */
#define SENSOR_PORT_S1_PORT                                              (GPIOA)
#define SENSOR_PORT_S1_PIN                                       (DL_GPIO_PIN_2)
#define SENSOR_PORT_S1_IOMUX                                      (IOMUX_PINCM7)
/* Defines for S2: GPIOA.3 with pinCMx 8 on package pin 43 */
#define SENSOR_PORT_S2_PORT                                              (GPIOA)
#define SENSOR_PORT_S2_PIN                                       (DL_GPIO_PIN_3)
#define SENSOR_PORT_S2_IOMUX                                      (IOMUX_PINCM8)
/* Defines for S3: GPIOA.4 with pinCMx 9 on package pin 44 */
#define SENSOR_PORT_S3_PORT                                              (GPIOA)
#define SENSOR_PORT_S3_PIN                                       (DL_GPIO_PIN_4)
#define SENSOR_PORT_S3_IOMUX                                      (IOMUX_PINCM9)
/* Defines for S4: GPIOA.5 with pinCMx 10 on package pin 45 */
#define SENSOR_PORT_S4_PORT                                              (GPIOA)
#define SENSOR_PORT_S4_PIN                                       (DL_GPIO_PIN_5)
#define SENSOR_PORT_S4_IOMUX                                     (IOMUX_PINCM10)
/* Defines for S5: GPIOA.6 with pinCMx 11 on package pin 46 */
#define SENSOR_PORT_S5_PORT                                              (GPIOA)
#define SENSOR_PORT_S5_PIN                                       (DL_GPIO_PIN_6)
#define SENSOR_PORT_S5_IOMUX                                     (IOMUX_PINCM11)
/* Defines for S6: GPIOB.0 with pinCMx 12 on package pin 47 */
#define SENSOR_PORT_S6_PORT                                              (GPIOB)
#define SENSOR_PORT_S6_PIN                                       (DL_GPIO_PIN_0)
#define SENSOR_PORT_S6_IOMUX                                     (IOMUX_PINCM12)
/* Defines for S7: GPIOB.1 with pinCMx 13 on package pin 48 */
#define SENSOR_PORT_S7_PORT                                              (GPIOB)
#define SENSOR_PORT_S7_PIN                                       (DL_GPIO_PIN_1)
#define SENSOR_PORT_S7_IOMUX                                     (IOMUX_PINCM13)
/* Defines for S8: GPIOA.7 with pinCMx 14 on package pin 49 */
#define SENSOR_PORT_S8_PORT                                              (GPIOA)
#define SENSOR_PORT_S8_PIN                                       (DL_GPIO_PIN_7)
#define SENSOR_PORT_S8_IOMUX                                     (IOMUX_PINCM14)
/* Port definition for Pin Group MOTOR_DIR */
#define MOTOR_DIR_PORT                                                   (GPIOB)

/* Defines for AIN1: GPIOB.2 with pinCMx 15 on package pin 50 */
#define MOTOR_DIR_AIN1_PIN                                       (DL_GPIO_PIN_2)
#define MOTOR_DIR_AIN1_IOMUX                                     (IOMUX_PINCM15)
/* Defines for AIN2: GPIOB.3 with pinCMx 16 on package pin 51 */
#define MOTOR_DIR_AIN2_PIN                                       (DL_GPIO_PIN_3)
#define MOTOR_DIR_AIN2_IOMUX                                     (IOMUX_PINCM16)
/* Defines for BIN1: GPIOB.4 with pinCMx 17 on package pin 52 */
#define MOTOR_DIR_BIN1_PIN                                       (DL_GPIO_PIN_4)
#define MOTOR_DIR_BIN1_IOMUX                                     (IOMUX_PINCM17)
/* Defines for BIN2: GPIOB.5 with pinCMx 18 on package pin 53 */
#define MOTOR_DIR_BIN2_PIN                                       (DL_GPIO_PIN_5)
#define MOTOR_DIR_BIN2_IOMUX                                     (IOMUX_PINCM18)
/* Port definition for Pin Group KEY_PORT */
#define KEY_PORT_PORT                                                    (GPIOA)

/* Defines for K0: GPIOA.15 with pinCMx 37 on package pin 8 */
#define KEY_PORT_K0_PIN                                         (DL_GPIO_PIN_15)
#define KEY_PORT_K0_IOMUX                                        (IOMUX_PINCM37)
/* Defines for K1: GPIOA.16 with pinCMx 38 on package pin 9 */
#define KEY_PORT_K1_PIN                                         (DL_GPIO_PIN_16)
#define KEY_PORT_K1_IOMUX                                        (IOMUX_PINCM38)
/* Defines for K2: GPIOA.17 with pinCMx 39 on package pin 10 */
#define KEY_PORT_K2_PIN                                         (DL_GPIO_PIN_17)
#define KEY_PORT_K2_IOMUX                                        (IOMUX_PINCM39)
/* Defines for K3: GPIOA.18 with pinCMx 40 on package pin 11 */
#define KEY_PORT_K3_PIN                                         (DL_GPIO_PIN_18)
#define KEY_PORT_K3_IOMUX                                        (IOMUX_PINCM40)
/* Port definition for Pin Group ENCODER_R */
#define ENCODER_R_PORT                                                   (GPIOB)

/* Defines for PH_A: GPIOB.14 with pinCMx 31 on package pin 2 */
// pins affected by this interrupt request:["PH_A"]
#define ENCODER_R_INT_IRQN                                      (GPIOB_INT_IRQn)
#define ENCODER_R_INT_IIDX                      (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define ENCODER_R_PH_A_IIDX                                 (DL_GPIO_IIDX_DIO14)
#define ENCODER_R_PH_A_PIN                                      (DL_GPIO_PIN_14)
#define ENCODER_R_PH_A_IOMUX                                     (IOMUX_PINCM31)
/* Defines for PH_B: GPIOB.13 with pinCMx 30 on package pin 1 */
#define ENCODER_R_PH_B_PIN                                      (DL_GPIO_PIN_13)
#define ENCODER_R_PH_B_IOMUX                                     (IOMUX_PINCM30)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_MOTOR_init(void);
void SYSCFG_DL_ENCODER_L_init(void);
void SYSCFG_DL_TIMER_10MS_init(void);
void SYSCFG_DL_I2C_OLED_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
