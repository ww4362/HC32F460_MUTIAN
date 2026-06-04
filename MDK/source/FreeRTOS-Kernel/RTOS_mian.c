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
#include "flash.h"


#include <math.h>
extern    struct SW6306_StatusTypedef SW6306_Status;//SW6306状态全局变量

static CoulombCounter_t Batty_t;

TaskHandle_t xLVGL_timer_handler=NULL;
TaskHandle_t xLVG_Ref_screen=NULL;

 static TimerHandle_t  xbuttonTimer;
 static TimerHandle_t  xdataref;
 static TimerHandle_t  	xRef_screenTimer;
 
void LVGL_Tick(TimerHandle_t xTimer);
void lvgl_task(void *arg);	
void read_struct(CoulombCounter_t *bat);
void Write_flash(void);
void Coulometer(void);

static void Data_ref(TimerHandle_t xTimer);
static void cb(void);
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
								
//								xTaskCreate(
//								Ref_screen,
//								"Ref_screen",
//								2048,
//								NULL,
//								15,
//								&xLVGL_timer_handler); //用于队列处理
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
	
	// 500ms刷新一次数据
		xdataref=xTimerCreate(
			"button",
			pdMS_TO_TICKS(500),
			pdTRUE,        // 自动重载
			NULL,
			Data_ref
	);
	
	
	
	
	
	
	xTimerStart(xbuttonTimer, 0);
		xTimerStart(xdataref, 0);
	
//	xRef_screenTimer=xTimerCreate(
//			"button",
//			pdMS_TO_TICKS(500),
//			pdTRUE,        // 自动重载
//			NULL,
//			Ref_screen
//	);
//	xTimerStart(xRef_screenTimer, 0);
DDL_DelayMS(1000);
	SH36730X_Init();
	sw6306_iic_init();
	SW6306_Init();
  SW6306_PowerLoad();

read_struct(&Batty_t);  //把电池参数读取进内存



    /* 4. 启动调度器 */
    vTaskStartScheduler();
	
	
	
	
}
uint8_t dataer[10][2];
uint8_t datareg;
/*屏幕刷新*/
uint8_t refresh_flag;
BMSTypeDef BMS;
extern struct AFE_Device AFE1;
struct AFE_Device *dev = &AFE1;
	BMS_ReturnTypeDef ret;
uint8_t databat[2];
uint16_t adc_flag,buffl;
uint16_t sconf1;
static void Data_ref(TimerHandle_t xTimer)
{
	static TickType_t OD_Time = 0;  //记录过放关闭时间
//	taskENTER_CRITICAL();
//	BMS_Read_Voltage(dev,&BMS);

	
	adc_flag=I2C_ReadReg2Byte_CRC8(SH_ADDR , SH_FLAG1 );
	sconf1=I2C_ReadReg2Byte_CRC8(SH_ADDR , SH_SCONF1 );
	if(adc_flag &0x03)
	{
		
		
			BMS_Read_Status(dev, &BMS);
		ret=BMS_Status_Cacluate(&BMS);
		
	
	}
	
	SW6306_BytesRead(0x46U, databat, 2);
	
//		 SW6306_SPAWN_ARGS(SW6306_RegsetSwitch, SW6306_CTRG_ADC_SET);
//		SW6306_ByteWrite(0x30,0x03);
//		DDL_DelayMS(2);
//		SW6306_BytesRead(0x31,databat,2);
    
////		
		   SW6306_ADCLoad();
        SW6306_PortStatusLoad();
        DDL_DelayMS(2);
        SW6306_StatusLoad();
        SW6306_PowerLoad();
		
		
		

	/*各种异常处理*/
	
	//充电管关闭
if(!BMS .Status.SwitchStatus[CHG])
{
	if(adc_flag&0x400)
	{
		//说明出现了过充 
		if(ret==BMS_OK)
		{
			//写入8C 然后在写C
			I2C_WriteRegByte_CRC8(SH_ADDR, SH_SCONF1, (sconf1>>8)|80);
			I2C_WriteRegByte_CRC8(SH_ADDR, SH_SCONF1, (sconf1>>8)&~80);
			
		}
		
	}
}
 
//均衡处理 
cb();

//库仑计处理
Coulometer();
 //写参数进内存
static uint16_t i=0;
i++;
if(i>7200)
{
	Batty_t.Capacity_mAh=9800;
	Batty_t.flash_count++;
	
	Write_flash();
	i=0;
}

//过放保护 在放电过程中才检测过放
if(BMS.Status .Current>13)
{
	for(int i=0; i<Battery_Count;i++)
	{
		if(BMS.Status .BAT_Voltage [i]<BAT_OverDischargeAlarm)
		{
			//说明出现了过放
			I2C_WriteRegByte_CRC8(SH_ADDR, SH_SCONF2, ((uint8_t)sconf1)&~0x02);
			OD_Time = xTaskGetTickCount();
			 goto EXIT;
		}
		
	}
}
EXIT:

	//放电管关闭
if(!BMS .Status.SwitchStatus[DSG]&&((xTaskGetTickCount() - OD_Time ) >= pdMS_TO_TICKS(30000)))
{
	if(ret==BMS_OK)
	{
				I2C_WriteRegByte_CRC8(SH_ADDR, SH_SCONF2, ((uint8_t)sconf1)|0x02);
			SW6306_Init();
	}
}
//在充电过程中 如果放电管关闭了 要 第一时间打开  打开放电管需要重新初始化sw6306
if(BMS.Status .Current<-13) 
{
	if(!BMS .Status.SwitchStatus[DSG])
	{
		I2C_WriteRegByte_CRC8(SH_ADDR, SH_SCONF2, ((uint8_t)sconf1)|0x02);
			SW6306_Init();
		
	}
	
}
		
//      DDL_DelayMS(2);
//        SW6306_CapacityLoad();
//      DDL_DelayMS(2);
        
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


refresh_flag++;
		
//	taskEXIT_CRITICAL();

	
}





static void Ref_screen(void *arg)
{

//	

	
	while(1)
	{
		
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
void Coulometer(void)
{
	static uint8_t tpm_SOC=0; //记录上一时刻电量
	//过充警告 出来表示充电到了100% 强制把剩余电量拉到100%
		if(!BMS .Status.SwitchStatus[CHG])
	{
		if(I2C_ReadReg2Byte_CRC8(SH_ADDR , SH_FLAG1 )&0x400)
		{
		Batty_t.SOC=100;
		Batty_t.Energy_max=	Batty_t.Remaining_Energy;
		}
	}	
	
	if(fabsf(BMS.Status .Current)>13)
	{
		//电流大于13进行统计
		Batty_t.Remaining_Energy+=(BMS.Status.Pack_Voltage /1000.0f*(-BMS.Status.Current)/7200.f);
		if(Batty_t.Remaining_Energy<0)
		{
			Batty_t.Remaining_Energy=0;
		}	
		if(Batty_t.Remaining_Energy>Batty_t.theory_Energy_max)	
		{
			Batty_t.Remaining_Energy=Batty_t.theory_Energy_max;
		}
		
		if(Batty_t.Remaining_Energy>Batty_t.Energy_max)
		{
			
			Batty_t.Energy_max=Batty_t.Remaining_Energy;
		}

			}	
		
		
	Batty_t.SOC=(uint8_t)((Batty_t.Remaining_Energy/Batty_t.Energy_max)*100);  //计算百分比
	// 计算循环
	if(Batty_t.SOC<tpm_SOC)  
	{
		Batty_t.Cycle_Percentage+=(tpm_SOC-Batty_t.SOC);

			
		
	}
	tpm_SOC=Batty_t.SOC;
	
	
}

#define FLASH_SAVE_ADDR  0x0007E000
//写flash
void Write_flash(void)
{
	uint8_t buff[1]={0xAA};
						EFM_FWMC_Cmd(ENABLE); //解锁
						(void)FLASH_EraseSector(0x0007E000,0);
	FLASH_WriteData(FLASH_SAVE_ADDR,(uint8_t *) &Batty_t,sizeof(Batty_t));
	
	
	EFM_FWMC_Cmd(DISABLE); //解锁
	
}
void read_struct(CoulombCounter_t *bat)
{
	 CoulombCounter_t *flash_data = (CoulombCounter_t*)FLASH_SAVE_ADDR;
		memcpy(bat, (void *)FLASH_SAVE_ADDR, sizeof(CoulombCounter_t));
	if(bat->flash_count ==0xFFFF)
	{
		//说明是没初始化过的结构体 先进行初始化
		
		
		bat->Capacity_mAh=3000;
		bat->theory_Energy_max=48000;
		bat->flash_count=0;
		bat->SOC=0;
		bat->Remaining_Energy=0;
		bat->Energy_max=0;
		bat->Cycle_Percentage=0;
	}
}


//冒泡排序
void sort_asc(uint16_t  *arr, int len)
{
    int i, j;
    int temp;

    for(i = 0; i < len - 1; i++)
    {
        for(j = 0; j < len - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

static void cb(void)
{
	uint16_t BAT_Voltage [Battery_Count];
	uint8_t  buff=0;
	static TickType_t last_tick = 0;
	memcpy(BAT_Voltage, BMS.Status .BAT_Voltage, sizeof(BAT_Voltage));
	
	//第一步 电压排序
	sort_asc(BAT_Voltage, Battery_Count);
	if(((BAT_Voltage [Battery_Count-1]>CB_SATRT_VOL)) &&((xTaskGetTickCount() - last_tick) >= pdMS_TO_TICKS(30000)))
	{
		for(int i=0;i<Battery_Count;i++)
		{
				if((BMS.Status .BAT_Voltage[i]-BAT_Voltage[0])>10)
				{
					buff |= (0x01 << i);
					
					
				}
			
			}
		
		 I2C_WriteRegByte_CRC8(SH_ADDR, SH_SCONF5, buff);   //写入寄存器
			//记录下时间
			  last_tick = xTaskGetTickCount();
	}
	
}
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
					
				sprintf(buf, "%u", Batty_t.SOC);
					lv_label_set_text(objects.m_per, buf);
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
					sprintf(buf, "%.1f", fabsf((((float)BMS.Status.Pack_Voltage /1000.0f)*((float)BMS.Status.Current/1000.0f))) /(((SW6306_Status.vbus*SW6306_Status.ibus)/1000000.f) )*100);	
					lv_label_set_text(objects.eef, buf);
						
						
					}else if(SW6306_IsDischarging())
						{	
							lv_label_set_text(objects.dc_flag, "放");
							sprintf(buf, "%.1f",(((SW6306_Status.vbus*SW6306_Status.ibus)/1000000.f) )/ fabsf((((float)BMS.Status.Pack_Voltage /1000.0f)*((float)BMS.Status.Current/1000.0f))) *100);	
					lv_label_set_text(objects.eef, buf);
						}else{
							lv_label_set_text(objects.dc_flag, "关");

				lv_label_set_text(objects.vol, "0.00");	
		
					lv_label_set_text(objects.cur, "0.00");	

					lv_label_set_text(objects.pow, "0.00");

					lv_label_set_text(objects.eef, "0.00");
							
							
							
							
						}


						break;
					case 1:
		sprintf(buf, "%.2f",BMS.Status.Pack_Voltage /1000.0f);		
				lv_label_set_text(objects.p_vol, buf);	
					
				sprintf(buf, "%.2f",BMS.Status.Current/1000.0f	);
								lv_label_set_text(objects.p_cou, buf);	

		sprintf(buf, "%.1f",((float)BMS.Status.Pack_Voltage /1000.0f)*((float)BMS.Status.Current/1000.0f));		
					lv_label_set_text(objects.p_pow, buf);	
					
									sprintf(buf, "%u", Batty_t.SOC);
					lv_label_set_text(objects.p_per, buf);
					
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
					if(BMS.Status.CBxStatus[0])
					{lv_obj_set_style_text_color(objects.bat1, lv_color_hex(0xFF0000),LV_PART_MAIN);;
					}else{lv_obj_set_style_text_color(objects.bat1, lv_color_hex(0xFFFFFF),LV_PART_MAIN);
					}
						
		sprintf(buf, "%u", BMS.Status .BAT_Voltage [1]);
					lv_label_set_text(objects.bat2, buf);
										if(BMS.Status.CBxStatus[1])
					{lv_obj_set_style_text_color(objects.bat2, lv_color_hex(0xFF0000),LV_PART_MAIN);;
					}else{lv_obj_set_style_text_color(objects.bat2, lv_color_hex(0xFFFFFF),LV_PART_MAIN);
					}
					
		sprintf(buf, "%u", BMS.Status .BAT_Voltage [2]);
					lv_label_set_text(objects.bat3, buf);
										if(BMS.Status.CBxStatus[2])
					{lv_obj_set_style_text_color(objects.bat3, lv_color_hex(0xFF0000),LV_PART_MAIN);;
					}else{lv_obj_set_style_text_color(objects.bat3, lv_color_hex(0xFFFFFF),LV_PART_MAIN);
					}
					
		sprintf(buf, "%u", BMS.Status .BAT_Voltage [3]);
					lv_label_set_text(objects.bat4, buf);	
										if(BMS.Status.CBxStatus[3])
					{lv_obj_set_style_text_color(objects.bat4, lv_color_hex(0xFF0000),LV_PART_MAIN);;
					}else{lv_obj_set_style_text_color(objects.bat4, lv_color_hex(0xFFFFFF),LV_PART_MAIN);
					}
					
		sprintf(buf, "%u", BMS.Status .BAT_Voltage [4]);
					lv_label_set_text(objects.bat5, buf);	
					if(BMS.Status.CBxStatus[4])
					{lv_obj_set_style_text_color(objects.bat5, lv_color_hex(0xFF0000),LV_PART_MAIN);;
					}else{lv_obj_set_style_text_color(objects.bat5, lv_color_hex(0xFFFFFF),LV_PART_MAIN);
					}
					
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
					
					sprintf(buf, "%u", Batty_t.flash_count);   //读取flash写入次数
					lv_label_set_text(objects.wf, buf);
					
					sprintf(buf, "%u", SW6306_ReadIPortLimit());   //读取实时端口限流值  单位 mA
					lv_label_set_text(objects.ibuc, buf);
										sprintf(buf, "%u", SW6306_ReadIBattLimit());   //读取实时电池限流值  单位 mA
					lv_label_set_text(objects.ibac, buf);
										sprintf(buf, "%u", SW6306_ReadMaxInputPower());   //输入最大功率
					lv_label_set_text(objects.ipm, buf);
										sprintf(buf, "%u", SW6306_ReadMaxOutputPower());   //输出最大功率
					lv_label_set_text(objects.opm, buf);
					sprintf(buf, "%u", SW6306_BAT_FCV);   //浮充限制电压
					lv_label_set_text(objects.fcv, buf);
					
					
					sprintf(buf, "%.0f", Batty_t.Energy_max);   //最大能量
					lv_label_set_text(objects.enm, buf);
					
										sprintf(buf, "%.0f", Batty_t.Remaining_Energy);   //剩余能量
					lv_label_set_text(objects.ree, buf);
										sprintf(buf, "%u", Batty_t.Cycle_Percentage);   //循环百分比
					lv_label_set_text(objects.cyp, buf);
						break;
					
					
					}
			refresh_flag=0;
			}
			
			
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}
