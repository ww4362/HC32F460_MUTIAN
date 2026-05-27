#include "main.h"
#include "timers.h"

#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "BMS.h"
#include "SH367303.h"
#include "sw6306.h"
#include "sw6306_IIC.h"  


extern    struct SW6306_StatusTypedef SW6306_Status;//SW6306状态全局变量

TaskHandle_t xLVGL_timer_handler=NULL;
TaskHandle_t xLVG_Ref_screen=NULL;

 static TimerHandle_t  xbuttonTimer;
 static TimerHandle_t  	xRef_screenTimer;
 
void LVGL_Tick(TimerHandle_t xTimer);
void lvgl_task(void *arg);	


static TimerHandle_t  xLVGL_Tick;
static void button_Callback(TimerHandle_t xTimer);
static void Ref_screen(void *arg);
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
								
								xTaskCreate(
								Ref_screen,
								"Ref_screen",
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

	xbuttonTimer=xTimerCreate(
			"button",
			pdMS_TO_TICKS(5),
			pdTRUE,        // 自动重载
			NULL,
			button_Callback
	);
	xTimerStart(xbuttonTimer, 0);
	
//	xRef_screenTimer=xTimerCreate(
//			"button",
//			pdMS_TO_TICKS(500),
//			pdTRUE,        // 自动重载
//			NULL,
//			Ref_screen
//	);
//	xTimerStart(xRef_screenTimer, 0);



    /* 4. 启动调度器 */
    vTaskStartScheduler();
	
	
	
	
}
/*屏幕刷新*/
uint8_t refresh_flag;
BMSTypeDef BMS;
extern struct AFE_Device AFE1;
struct AFE_Device *dev = &AFE1;
	BMS_ReturnTypeDef ret;
uint8_t databat[2];
static void Ref_screen(void *arg)
{

//	
	SH36730X_Init();
	sw6306_iic_init();
	SW6306_Init();
	SW6306_PowerLoad();
	SW6306_IsInitialized();
	while(1)
	{
		taskENTER_CRITICAL();
	//BMS_Read_Voltage(&AFE_t,&BMS);
	BMS_Read_Status(dev, &BMS);
		ret=BMS_Status_Cacluate(&BMS);
		
//		 SW6306_SPAWN_ARGS(SW6306_RegsetSwitch, SW6306_CTRG_ADC_SET);
//		SW6306_ByteWrite(0x30,0x03);
//		DDL_DelayMS(2);
//		SW6306_BytesRead(0x31,databat,2);
    
//		
		   SW6306_ADCLoad();
        SW6306_PortStatusLoad();
        DDL_DelayMS(2);
        SW6306_StatusLoad();
        SW6306_PowerLoad();
      DDL_DelayMS(2);
        SW6306_CapacityLoad();
      DDL_DelayMS(2);
        
//  
		
		
//		if(BMS.Control.DSG==0 &&ret==BMS_OK)
//		{
//					//放电关闭 没警告就打开放电
//			BMS_DSG(dev, &BMS,ON);
//			BMS_Control_Update(dev, &BMS);
//		}
//		
//		if(BMS.Control.CHG==0 &&ret==BMS_OK)
//		{
//			BMS_CHG(dev, &BMS,ON);
//			BMS_Control_Update(dev, &BMS);
//		}
							
			//	



		
	taskEXIT_CRITICAL();
refresh_flag++;
	 vTaskDelay(pdMS_TO_TICKS(500));
	}
}

static void button_Callback(TimerHandle_t xTimer)
{

	 
	  button_ticks();
 }
 

void LVGL_Tick(TimerHandle_t xTimer)
{
	
	lv_tick_inc(1);



}
float pbat,pout;
extern SH367303_SCONF_TypeDef SH367303_SCONF_Struct;
void lvgl_task(void *arg)
{
	char buf[255];
    while(1)
    {
		//	ui_tick();
        lv_timer_handler();
			if(refresh_flag!=0)
			{
			
				switch(scree_id)
				{
					case 0:
							sprintf(buf, "%.2f",SW6306_Status.vbus/1000.0f);		
				lv_label_set_text(objects.vol, buf);	
								sprintf(buf, "%.2f",SW6306_Status.ibus/1000.0f);				
					lv_label_set_text(objects.cur, buf);	
					sprintf(buf, "%.2f",(SW6306_Status.vbus*SW6306_Status.ibus)/1000000.f);	
					lv_label_set_text(objects.pow, buf);
					
//					pbat=SW6306_Status.vbus*SW6306_Status.ibus;
//					pout=SW6306_Status.ibat*SW6306_Status.vbat;
//					
//					sprintf(buf, "%.2f",pout/pbat*100.0f);	
//					lv_label_set_text(objects.eef, buf);
					
										sprintf(buf, "%.2f",SW6306_Status.ibat/1000.f);	
					lv_label_set_text(objects.eef, buf);
					//快充协议显示
					if(!(SW6306_Status.qcstat & SW6306_QCSTAT_PQC))
					{
						lv_label_set_text(objects.fc, "none");
					}else{
						switch(SW6306_Status.qcstat & 0x0FU)
						{
							case 0:
								lv_label_set_text(objects.fc, "none");
						break ;
						case 1:
							lv_label_set_text(objects.fc, "qc2");
						break ;	
							case 2:
								lv_label_set_text(objects.fc, "qc3");
							break ;
						case 3:
							lv_label_set_text(objects.fc, "qc3+");
						break ;
							case 4:
								lv_label_set_text(objects.fc, "fcp");
							break ;
						case 5:
							lv_label_set_text(objects.fc, "scp");
						break ;
							case 6:
								lv_label_set_text(objects.fc, "pd\nfix");
							break ;
							case 7:
								lv_label_set_text(objects.fc, "pd\npps");
							break ;
							case 8:
								lv_label_set_text(objects.fc, "pe\n1.1");
							break ;
							case 9:
								lv_label_set_text(objects.fc, "pe\n2.0");
							break ;
							case 10:
								lv_label_set_text(objects.fc, "vooc\n1.0");
							break ;
							case 11:
								lv_label_set_text(objects.fc, "vooc\n2.0");
							break ;
							case 12:
								lv_label_set_text(objects.fc, "s\nvooc");
							break ;
							case 13:
								lv_label_set_text(objects.fc, "pe\n2.0");
							break ;
							case 14:
								lv_label_set_text(objects.fc, "sfcp");
							break ;
							case 15:
								lv_label_set_text(objects.fc, "afc");
							break ;
							case 16:
								lv_label_set_text(objects.fc, "ufcs");
							break ;
							
						}
					}
					
					if(SW6306_IsCharging())
					{
						lv_label_set_text(objects.dc_flag, "充");
					}else if(SW6306_IsDischarging())
						{	
							lv_label_set_text(objects.dc_flag, "放");
						}else{
							lv_label_set_text(objects.dc_flag, "关");

				lv_label_set_text(objects.vol, "0.00");	
		
					lv_label_set_text(objects.cur, "0.00");	

					lv_label_set_text(objects.pow, "0.00");

					lv_label_set_text(objects.eef, "0.00");
							
							
							
							
						}

					uint8_t SW6306_IsMPPTCharging(void);            //SW6306是否处于MPPT充电模式
uint8_t SW6306_IsCharging(void);                //SW6306是否正在充电
					
						break;
					case 1:
		sprintf(buf, "%.2f",BMS.Status.Pack_Voltage /1000.0f);		
				lv_label_set_text(objects.p_vol, buf);	
					
				sprintf(buf, "%.2f",BMS.Status.Current/1000.0f	);
								lv_label_set_text(objects.p_cou, buf);		
					if(BMS.Status.SwitchStatus[CHG]==0)
					{
						lv_obj_set_style_bg_color(objects.p_chg , lv_color_hex(0xF01D1D), LV_PART_MAIN | LV_STATE_DEFAULT);
					}else{lv_obj_set_style_bg_color(objects.p_chg, lv_color_hex(0x00a227), LV_PART_MAIN | LV_STATE_DEFAULT);
					}
					if(BMS.Status.SwitchStatus[DSG]==0)
					{
						lv_obj_set_style_bg_color(objects.p_dsg , lv_color_hex(0xF01D1D), LV_PART_MAIN | LV_STATE_DEFAULT);
					}else{lv_obj_set_style_bg_color(objects.p_dsg, lv_color_hex(0x00a227), LV_PART_MAIN | LV_STATE_DEFAULT);
					}
					
						break;
					case 2:
		sprintf(buf, "%u", BMS.Status .BAT_Voltage [0]);
					lv_label_set_text(objects.bat1, buf);
		sprintf(buf, "%u", BMS.Status .BAT_Voltage [1]);
					lv_label_set_text(objects.bat2, buf);
		sprintf(buf, "%u", BMS.Status .BAT_Voltage [2]);
					lv_label_set_text(objects.bat3, buf);
		sprintf(buf, "%u", BMS.Status .BAT_Voltage [3]);
					lv_label_set_text(objects.bat4, buf);	
		sprintf(buf, "%u", BMS.Status .BAT_Voltage [4]);
					lv_label_set_text(objects.bat5, buf);	
					snprintf(buf,
         sizeof(buf),"%.0f",(SH367303_SCONF_Struct.OVD*5.86));
					lv_label_set_text(objects.cpv, buf);	
					if(ret==BMS_OK)
					{
					lv_label_set_text(objects.err,"o k");	
					}else if(ret != BMS_OK)
					{
						lv_label_set_text(objects.err,"err");
					}
					
					
						break;
					
					
					}
			refresh_flag=0;
			}
			
			
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}
