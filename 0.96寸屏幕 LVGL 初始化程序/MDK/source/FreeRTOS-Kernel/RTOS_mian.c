#include "main.h"
#include "timers.h"

#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


TaskHandle_t xLVGL_timer_handler=NULL;

void LVGL_Tick(TimerHandle_t xTimer);
void lvgl_task(void *arg);	


static TimerHandle_t  xLVGL_Tick;


void RTOS_START(void)
{
	
	// xTaskCreate(Task, "LED",128 ,NULL ,3,  NULL);
	
	//Queue1 = xQueueCreate();//
//	xPlay_queue = xQueueCreate( 10, sizeof( flag));//创建队列
//	xTaskCreate(Task_send, "send",128 ,NULL ,15,  &xHandle);
//	xTaskCreate(Task_Receive, "receive",128 ,NULL ,15,  &xHandle);
//	
//	xSemaphore = xSemaphoreCreateBinary();  //创建信号量


	xLVGL_Tick=xTimerCreate(
			"LVGL_Tick",
			pdMS_TO_TICKS(1),
			pdTRUE,        // 自动重载
			NULL,
			LVGL_Tick
	);
	xTimerStart(xLVGL_Tick, 0);
//	
//	 xSleepTimer=xTimerCreate(
//			"Sleep",
//			pdMS_TO_TICKS(0xFFFF),
//			pdFALSE ,        //  
//			NULL,
//			Sleep
//	);

//	
//	
//	  xTaskCreate(
//                    Charge,       /* Function that implements the task. */
//                    "Charge",          /* Text name for the task. */
//                    128,      /* Stack size in words, not bytes. */
//                    NULL,    /* Parameter passed into the task. */
//                    15,/* Priority at which the task is created. */
//                    &xCharge  );      /* Used to pass out the created task's handle. */
//										
		xTaskCreate(
								lvgl_task,
								"timer_handler",
								2048,
								NULL,
								15,
								&xLVGL_timer_handler); //用于队列处理
//								
//ret=xTaskCreate(mp3Task,
//            "mp3",
//            2048,          // words = 8KB
//            NULL,
//            15,
//            &mp3TaskHandle);

    /* 4. 启动调度器 */
    vTaskStartScheduler();
	
	
	
	
}


void LVGL_Tick(TimerHandle_t xTimer)
{
	
	lv_tick_inc(1);



}
void lvgl_task(void *arg)
{
    while(1)
    {
			ui_tick();
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}
