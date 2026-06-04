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

#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"
#include "lcd_init.h" 
#include "lcd.h" 
#include "SH367303.h"
#include "sw6306.h" 
#include "sw6306_IIC.h"  
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





int32_t BSP_PRINTF_Preinit(void *vpDevice, uint32_t u32Baudrate);
 extern void xPortSysTickHandler( void );
/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
 
 config_t  config={20};
 uint8_t Edit_Mode_Controls;
     void vApplicationStackOverflowHook( TaskHandle_t xTask,
                                        char * pcTaskName )
{
    /* 堆栈溢出时可以打断点、LED报警、重启等 */
    (void)xTask;
    (void)pcTaskName;

    while(1)
    {
        /* 这里你可以加断点 */
    }
}

  void SysTick_Handler(void)
{
    SysTick_IncTick();

    __DSB();  /* Arm Errata 838869 */
		
    if(xTaskGetSchedulerState()!=taskSCHEDULER_NOT_STARTED)//系统已经运行
    {
        xPortSysTickHandler();
    }
}
 
 
//Clock Config

static void App_ClkCfg(void)
{

		/*下面是外部晶振*/
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

uint8_t i;
lv_obj_t * act_scr;
void INT_SRC_GPIO_PA08_IrqCallback(void)
{

}

//Port Config
static void App_PortCfg(void)
{
		
    /* GPIO initialize */
    stc_gpio_init_t stcGpioInit;
	

		
		
		(void)GPIO_StructInit(&stcGpioInit);
    stcGpioInit.u16PinDir = PIN_DIR_IN;
		stcGpioInit.u16PullUp = PIN_PU_ON;
    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
    (void)GPIO_Init(GPIO_PORT_B, GPIO_PIN_08, &stcGpioInit);
		


		(void)GPIO_StructInit(&stcGpioInit);
    stcGpioInit.u16PinDir = PIN_DIR_IN  ;
		stcGpioInit.u16PullUp = PIN_PU_ON;
    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
    (void)GPIO_Init(GPIO_PORT_B, GPIO_PIN_11, &stcGpioInit);
		

		    /* GPIO initialize */
    /* PA8 set to GPIO-Input */
    (void)GPIO_StructInit(&stcGpioInit);
    stcGpioInit.u16PullUp = PIN_PU_ON;
    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
    (void)GPIO_Init(GPIO_PORT_A, GPIO_PIN_08, &stcGpioInit);

//		stc_extint_init_t stcExtIntInit;
//    stc_irq_signin_config_t stcIrqSignConfig;		
//		
//    /* ExtInt config */
//    (void)EXTINT_StructInit(&stcExtIntInit);
//    stcExtIntInit.u32Edge = EXTINT_TRIG_FALLING  ;  //下降沿触发  
//    (void)EXTINT_Init(EXTINT_CH08, &stcExtIntInit);

//    /* IRQ sign-in */
//    stcIrqSignConfig.enIntSrc    = INT_SRC_PORT_EIRQ8 ;
//    stcIrqSignConfig.enIRQn      = INT008_IRQn;
//    stcIrqSignConfig.pfnCallback = &INT_SRC_GPIO_PA08_IrqCallback;
//    (void)INTC_IrqSignIn(&stcIrqSignConfig);

//    /* Disable all */
//    INTC_IntCmd(INTC_INT8, ENABLE);   //启用中断 
//    /* NVIC config */
//    NVIC_ClearPendingIRQ(INT008_IRQn);  //清除下事件 
//		
//    NVIC_SetPriority(INT008_IRQn, DDL_IRQ_PRIO_00); //配置优先级 
//		NVIC_EnableIRQ(INT008_IRQn); // 

		
		GPIO_SetFunc(GPIO_PORT_B,GPIO_PIN_07,GPIO_FUNC_32);//USART3-TX
    
}

static uint8_t read_button_gpio(uint8_t button_id)
{
    switch (button_id) {

				case 1:
						return GPIO_ReadInputPins(GPIO_PORT_A, GPIO_PIN_08);
				break;
        default:
        return 0;
    }
}
 uint8_t scree_id=0;
void BTN1_SINGLE_CLICK_Callback(Button *btn)
{
			
		switch(scree_id++)
		{
			case 0:
				loadScreen(SCREEN_ID_POWER_BANK );
			break;
			case 1:
				loadScreen(SCREEN_ID_SYSTEM );
			break;
			case 2:
			loadScreen(SCREEN_ID_MAIN );
			scree_id=0;
			break;
			
		}
	
}
static Button btn1;
void  Button_init(void)
{
	
	button_init(&btn1, read_button_gpio, 0, 1);



button_attach(&btn1,BTN_SINGLE_CLICK,BTN1_SINGLE_CLICK_Callback);
	button_start(&btn1);
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
		SysTick_Init(1000);
    //Port Config
    App_PortCfg();
	
	PrintfInit();


	
    /* Register write protected for some required peripherals. */
//    LL_PERIPH_WP(LL_PERIPH_ALL);
	LCD_Init ();
//	LCD_Fill(0,0,LCD_W,LCD_H,BLACK); //灞忓箷缃负榛戣壊
//	LCD_ShowChar(56,0,'V',0xF8E3,BLACK ,16,0);
//LCD_ShowChar(56,16,'A',GRAYBLUE,BLACK ,16,0);
//LCD_ShowChar(136,0,'W',BRED,BLACK ,16,0);
//	
	 Button_init();


//	
lv_init();

lv_port_disp_init();



//lv_port_indev_init();



//lv_group_t * group = lv_group_create();  //创建组


 // lv_demo_widgets();

//lv_obj_t *square = lv_obj_create(lv_scr_act());  // 在当前屏幕上创建一个对象

//lv_obj_set_size(square, 60, 60);               // 设置为 100x100 的正方形
//lv_obj_set_style_bg_color(square, lv_color_hex(0xFF0000), 0);  // 设置背景为绿色
//lv_obj_set_style_border_width(square, 0, 0);     // 取消边框（可选）
//lv_obj_align(square, LV_ALIGN_CENTER, 0, 0);     // 居中显示（你也可以自己指定位置）





//			
ui_init(); 	



loadScreen(SCREEN_ID_MAIN );

//lv_group_add_obj(group, objects.bar);
//lv_group_add_obj(group, objects.bar2);

//lv_indev_t *indev = lv_indev_get_next(NULL); // 如果你只注册了一个输入设备就是它
//lv_indev_set_group(indev, group);
// lv_indev_set_group(indev_encoder, group);

//lv_group_focus_obj(objects.bar);



//lv_group_t *group = lv_group_create();

// 3. 把滑块加入 group
//lv_group_add_obj(group, objects.bar1);
//lv_group_add_obj(group, objects.bar2);
//lv_group_add_obj(group, slider_label);

// 4. 获取编码器输入设备并绑定 group
//lv_indev_t *indev = lv_indev_get_next(NULL);  // 获取第一个输入设备（假设是编码器）
//lv_indev_set_group(indev, groups.zu1);

//lv_group_set_editing(group, true);
//	I2C_WriteRegByte(SH_ADDR_WRITE,SH_SCONF3,0b00010100);
	


	RTOS_START();
    for (;;) {

			

		//	SysTick_Delay(15);
//		lv_obj_set_style_transform_angle(	objects.button_1,i*5,0);
//		lv_slider_set_value(objects.bar4, i, LV_ANIM_OFF);  // 设置为当前值 +1，不加动画
//     DDL_DelayMS(5);
//			i+=5;

			

			
			
    }
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
