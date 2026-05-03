/**
 *******************************************************************************
 * @file  main.c
 * @brief Main program.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2025-06-03       CDT             First version
 @endverbatim
 *******************************************************************************
 * Copyright (C) 2022-2025, Xiaohua Semiconductor Co., Ltd. All rights reserved.
 *
 * This software component is licensed by XHSC under BSD 3-Clause license
 * (the "License"); You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                    opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "main.h"

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/
/* Configures TimerA. */
static void App_TimerACfg(void);
/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
//Clock Config
static void App_ClkCfg(void)
{
    /* Set bus clock div. */
    CLK_SetClockDiv(CLK_BUS_CLK_ALL, (CLK_HCLK_DIV1 | CLK_EXCLK_DIV2 | CLK_PCLK0_DIV1 | CLK_PCLK1_DIV2 | \
                                   CLK_PCLK2_DIV4 | CLK_PCLK3_DIV4 | CLK_PCLK4_DIV2));
    /* sram init include read/write wait cycle setting */
    SRAM_SetWaitCycle(SRAM_SRAM_ALL, SRAM_WAIT_CYCLE1, SRAM_WAIT_CYCLE1);
    SRAM_SetWaitCycle(SRAM_SRAMH, SRAM_WAIT_CYCLE0, SRAM_WAIT_CYCLE0);
    /* flash read wait cycle setting */
    EFM_SetWaitCycle(EFM_WAIT_CYCLE5);
    /* XTAL config */
    stc_clock_xtal_init_t stcXtalInit;
    (void)CLK_XtalStructInit(&stcXtalInit);
    stcXtalInit.u8State = CLK_XTAL_ON;
    stcXtalInit.u8Drv = CLK_XTAL_DRV_HIGH;
    stcXtalInit.u8Mode = CLK_XTAL_MD_OSC;
    stcXtalInit.u8StableTime = CLK_XTAL_STB_2MS;
    (void)CLK_XtalInit(&stcXtalInit);
    /* MPLL config */
    stc_clock_pll_init_t stcMPLLInit;
    (void)CLK_PLLStructInit(&stcMPLLInit);
    stcMPLLInit.PLLCFGR = 0UL;
    stcMPLLInit.PLLCFGR_f.PLLM = (1UL - 1UL);
    stcMPLLInit.PLLCFGR_f.PLLN = (50UL - 1UL);
    stcMPLLInit.PLLCFGR_f.PLLP = (2UL - 1UL);
    stcMPLLInit.PLLCFGR_f.PLLQ = (2UL - 1UL);
    stcMPLLInit.PLLCFGR_f.PLLR = (2UL - 1UL);
    stcMPLLInit.u8PLLState = CLK_PLL_ON;
    stcMPLLInit.PLLCFGR_f.PLLSRC = CLK_PLL_SRC_XTAL;
    (void)CLK_PLLInit(&stcMPLLInit);
    /* 3 cycles for 126MHz ~ 200MHz */
    GPIO_SetReadWaitCycle(GPIO_RD_WAIT3);
    /* Switch driver ability */
    PWC_HighSpeedToHighPerformance();
    /* Set the system clock source */
    CLK_SetSysClockSrc(CLK_SYSCLK_SRC_PLL);
}

//Port Config
static void App_PortCfg(void)
{
    /* GPIO initialize */
    stc_gpio_init_t stcGpioInit;
    /* PA3 set to GPIO-Output */
    (void)GPIO_StructInit(&stcGpioInit);
    stcGpioInit.u16PinDir = PIN_DIR_OUT;
    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
    (void)GPIO_Init(GPIO_PORT_A, GPIO_PIN_03, &stcGpioInit);

    /* PA4 set to GPIO-Output */
    (void)GPIO_StructInit(&stcGpioInit);
    stcGpioInit.u16PinDir = PIN_DIR_OUT;
    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
    (void)GPIO_Init(GPIO_PORT_A, GPIO_PIN_04, &stcGpioInit);

    GPIO_SetFunc(GPIO_PORT_A,GPIO_PIN_00,GPIO_FUNC_40);//SPI1-MOSI
    
    GPIO_SetFunc(GPIO_PORT_A,GPIO_PIN_01,GPIO_FUNC_43);//SPI1-SCK
    
    GPIO_SetFunc(GPIO_PORT_A,GPIO_PIN_02,GPIO_FUNC_7);//SPI1-SS3
    
    GPIO_SetFunc(GPIO_PORT_A,GPIO_PIN_05,GPIO_FUNC_5);//TIMA-3-PWM6
    
}


/**
 * @brief  Main function of the project
 * @param  None
 * @retval int32_t return value, if needed
 */
int32_t main(void)
{
    /* Register write unprotected for some required peripherals. */
    LL_PERIPH_WE(LL_PERIPH_ALL);
    //Clock Config
    App_ClkCfg();
    //Port Config
    App_PortCfg();
    //TimerA Config
    App_TimerACfg();
    /* Register write protected for some required peripherals. */
    LL_PERIPH_WP(LL_PERIPH_ALL);
    for (;;) {

    }
}


//TimerA Config
static void App_TimerACfg(void)
{
    stc_tmra_init_t stcTmraInit;
    stc_tmra_pwm_init_t stcPwmInit;

    /* Enable TMRA_3 peripheral clock */
    FCG_Fcg2PeriphClockCmd(FCG2_PERIPH_TMRA_3, ENABLE);

    /************************* Configure TMRA_3 counter *************************/
    (void)TMRA_StructInit(&stcTmraInit);
    /* Config software count */
    stcTmraInit.sw_count.u8ClockDiv = TMRA_CLK_DIV1024;
    stcTmraInit.sw_count.u8CountMode = TMRA_MD_SAWTOOTH;
    stcTmraInit.sw_count.u8CountDir = TMRA_DIR_UP;
    stcTmraInit.u32PeriodValue = 0xFFFFU;
    (void)TMRA_Init(CM_TMRA_3, &stcTmraInit);

    /************************* Configure TMRA_3_6 CMP ***************************/
    /* Config PWM output */
    (void)TMRA_PWM_StructInit(&stcPwmInit);
    stcPwmInit.u32CompareValue = 0xFFFFU;
    stcPwmInit.u16StartPolarity = TMRA_PWM_HOLD;
    stcPwmInit.u16StopPolarity = TMRA_PWM_LOW;
    stcPwmInit.u16CompareMatchPolarity = TMRA_PWM_HIGH;
    stcPwmInit.u16PeriodMatchPolarity = TMRA_PWM_LOW;
    (void)TMRA_PWM_Init(CM_TMRA_3, TMRA_CH6, &stcPwmInit);
    /* PWM pin function set */
    TMRA_SetFunc(CM_TMRA_3, TMRA_CH6, TMRA_FUNC_CMP);
    /* PWM output command */
    TMRA_PWM_OutputCmd(CM_TMRA_3, TMRA_CH6, ENABLE);

    /* Start timerA */
    TMRA_Start(CM_TMRA_3);

}

/**
 * @}
 */

/**
 * @}
 */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
