/*lic*/
#ifndef __MAIN_H__
#define __MAIN_H__

#include "hc32_ll.h"
#include "LCD.h"


#include "ui.h"

#include "printf.h"

#include "FreeRTOS.h" 
#include "task.h" 
#include "RTOS_mian.h"
#include "queue.h"
#include "semphr.h"



//#include "lv_port_lcd_stm32_template.h"

#include <lvgl.h>
//#include "lv_port_disp_template.h"
//#include "lv_port_indev_template.h"
//#include "lv_demos.h"
//#include "lv_demo_widgets.h"

//config 保存参数结构体

typedef struct _configt {
uint8_t fan_tem;  //风扇温度
uint8_t flash_num; //flash写入次数
	
} config_t;
extern config_t  config;


extern uint8_t Edit_Mode_Controls;
//进入编辑模式的控件
//1 .风扇温度
#endif /* __MAIN_H__ */

/*eof*/
