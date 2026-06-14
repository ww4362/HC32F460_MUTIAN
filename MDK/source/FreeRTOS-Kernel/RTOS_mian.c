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
#include "Coulometer.h" 


#include <math.h>
extern    struct SW6306_StatusTypedef SW6306_Status;//SW6306状态全局变量

enum adc_mode_t adc_mode;


TaskHandle_t xLVGL_timer_handler=NULL;
TaskHandle_t xLVG_Ref_screen=NULL;

 static TimerHandle_t  xbuttonTimer;
 static TimerHandle_t  xdataref;
 static TimerHandle_t  	xRef_screenTimer;
  static TimerHandle_t  x10S_Countdown;
 
  TimerHandle_t xScreen_off;
		
 
void LVGL_Tick(TimerHandle_t xTimer);
void lvgl_task(void *arg);	
void Write_flash(void);
void get_temperature(void);


 static void x10S_Countdown_func (TimerHandle_t xTimer);
static void Data_ref(TimerHandle_t xTimer);
static void cb(void);
static TimerHandle_t  xLVGL_Tick;
static void button_Callback(TimerHandle_t xTimer);
static void Ref_screen(void *arg);
static void xScreen_off_func(TimerHandle_t xTimer);

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
	
		xTimerStart(xbuttonTimer, 0);
	
	// 500ms刷新一次数据
		xdataref=xTimerCreate(
			"button",
			pdMS_TO_TICKS(500),
			pdTRUE,        // 自动重载
			NULL,
			Data_ref
	);
	
		xTimerStart(xdataref, 0);

	xScreen_off=xTimerCreate(
			"Screen",
			pdMS_TO_TICKS(60000),
			pdFALSE,        // 手动重载
			NULL,
			 xScreen_off_func
	
	);
	
		x10S_Countdown=xTimerCreate(
			"Countdown",
			pdMS_TO_TICKS(10000),
			pdFALSE,        // 手动重载
			NULL,
			 x10S_Countdown_func
	
	);
	
	
	

	
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

coulometer_init();  //把电池参数读取进内存



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
		
		/*温度获取并且传入数组中 兼容库*/
get_temperature();
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
	
	//充电管关闭 硬件过充处理
if(!BMS .Status.SwitchStatus[CHG])
{
	if(adc_flag&0x400)
	{
		
//		Batty_t.Energy_max=Batty_t.Remaining_Energy; ???????????????????????????????????????????????
		//说明出现了过充 
		if(ret==BMS_OK)
		{
			//写入8C 然后在写C
			I2C_WriteRegByte_CRC8(SH_ADDR, SH_SCONF1, (sconf1>>8)|0x80);
			I2C_WriteRegByte_CRC8(SH_ADDR, SH_SCONF1, (sconf1>>8)&~0x80);
			
		}
		
	}
}
 
//均衡处理 
cb();
static uint8_t wait=0;
//温度保护  根据报警找哪个报警了  执行不同策略 过充是内部自动关闭充电管 所以不做处理 只处理过放 
if(ret==BMS_Alarm)
{
	for(int i=0;i<Battery_Count;i++)
	{
		//过放报警
		if(	BMS .State.V_Alarm[OverDischargeAlarm][i])
		{
			//说明出现了过放 关闭放电管 放电管关闭可以经过二极管充 
			I2C_WriteRegByte_CRC8(SH_ADDR, SH_SCONF2, ((uint8_t)sconf1)&~0x02);
			 wait=20;
			break;
		}
	}
	
		//检测放电过流
	if(BMS .State.I_Alarm[ OverDischargeCurrentAlarm])
	{
		//出现了过流 关闭放电
		I2C_WriteRegByte_CRC8(SH_ADDR, SH_SCONF2, ((uint8_t)sconf1)&~0x02);
		 wait=20;
	}
	
	for(	int i=0;i<Temp_Count;i++)
	{
		//检测到高温 
		if (BMS .State.T_Alarm[ChargeHighTemperatureAlarm][i])
		{
			I2C_WriteRegByte_CRC8(SH_ADDR, SH_SCONF2, ((uint8_t)sconf1)&~0x03);  //充放电一起关闭
				break;
		}
		
	}

	
}
//在ret 返回是ok时 说明没问题 需要检查充电管和放电管是否关闭 关闭了的话打开充放电进行必要的初始化

if(ret==BMS_OK&&wait==0)
{
	//放电管 放电管重新打开需要初始6303v
	if(BMS .Status.SwitchStatus[DSG]==0)
	{
			I2C_WriteRegByte_CRC8(SH_ADDR, SH_SCONF2, ((uint8_t)sconf1)|0x03);  //充放电一起打开
			xTimerStart( x10S_Countdown, 0);
		
	}
	//充电管  只是充电管单独关闭了 
	if(BMS .Status.SwitchStatus[CHG]==0)
	{
		I2C_WriteRegByte_CRC8(SH_ADDR, SH_SCONF2, ((uint8_t)sconf1)|0x01);  //只需要打开充电即可
	}
}
wait = (wait == 0) ? 0 : (wait - 1);










static uint16_t Countdown=0; //计时  1分钟进入停止模式 当前为500ms 定时器
/*不在充放电就进行休眠*/
if(BMS .Status.SwitchStatus[CHGING]==0 && BMS .Status.SwitchStatus[DSGING]==0)
{
	
	 Countdown++;
	
}else{
	Countdown=0;
}

if( Countdown>=360)
{
		Countdown=0;
		xTimerStop(xbuttonTimer, 0);
	Run_STOP ();
	vTaskDelay(pdMS_TO_TICKS(500));
		xTimerStart(xbuttonTimer, 0);
	
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
							
			//	 状态判断 判断是否从充满
			adc_mode=none;
			for(int i=0; i<Battery_Count;i++)
			{

				if(BMS.Status .BAT_Voltage[i]<BAT_OverDischargeAlarm )
				{
				adc_mode=Low_battery;
					break;
				}
				
					if(adc_flag&0x400)
					{
						adc_mode=high_battery;
						
					}
			}
			//均衡状态不做容量结算
		for(int j=0,i=0;i<Battery_Count;i++)
{
	if(!BMS.Status.CBxStatus[i])
	{
		j++;
	}
	if(j==5)
	{
		coulometer_ticks(BMS.Status.Current,BMS.Status.Pack_Voltage,adc_mode);
	}
}

			

static uint16_t i=0;
			i++;
if(i>7200)
{
	CoulombCounter.CoulombCounter_flash.flash_count++;

	
	Write_flash();
	i=0;
}
			
			
			
refresh_flag++;
		
//	taskEXIT_CRITICAL();

	
}


/*息屏处理函数*/
static void xScreen_off_func(TimerHandle_t xTimer)
{
	
	CM_TMRA_1->CMPAR6=10;
	
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
 
 
 //10s 倒计时函数
 static void x10S_Countdown_func (TimerHandle_t xTimer)
 {
	 
	 SW6306_Init();
 }

void LVGL_Tick(TimerHandle_t xTimer)
{
	
	lv_tick_inc(1);



}
/*把电阻值转换成温度
r0 25度时阻值
beta b值
*/
uint16_t R1;
double T;
int16_t Temperature_Conversion(uint16_t R0,uint16_t BETA,uint16_t R)
{
R1=R;
	T = 1.0 / ( (1.0 / 298.15) + (1.0 / (float)BETA) * log((float)R / R0) );
	
	
	return (int16_t)((T - 273.15)*10);
}

/*获取温度
ch 通道
0 sw6306v 内部温度
1sh367303内部温度
2 sh367303 板载探头温度
3 sh367303 电池温度探头温度*/
	
void get_temperature(void)
{
	 uint16_t data;
	data=	I2C_ReadReg2Byte_CRC8(SH_ADDR, SH_TEMP1H );
	
	BMS.Status.Temperature[0]=(0.17*(float)data-270-20)*10;   //注意 芯片由于ldo温度较高 减去20度避免触发温控处理  显示温度加10度

		data=	I2C_ReadReg2Byte_CRC8(SH_ADDR, SH_TS1H );   //带线热敏电阻

   BMS.Status.Temperature[1]=  Temperature_Conversion(10000,3950,(float)data/(4096-data)*10000);

	
	
	
			data=	I2C_ReadReg2Byte_CRC8(SH_ADDR, SH_TS2H );  //板载热敏电阻
	
		   BMS.Status.Temperature[2]=  Temperature_Conversion(10000,3450,(float)data/(4096-data)*10000);
//		


}




//写flash
void Write_flash(void)
{
						EFM_FWMC_Cmd(ENABLE); //解锁
						(void)FLASH_EraseSector(0x0007E000,0);
	FLASH_WriteData(FLASH_SAVE_ADDR,(uint8_t *) &CoulombCounter.CoulombCounter_flash,sizeof(CoulombCounter_flash_t));
	
	
	EFM_FWMC_Cmd(DISABLE); //解锁
	
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
uint8_t  buff=0;
static void cb(void)
{
	uint16_t BAT_Voltage [Battery_Count];
	
	static TickType_t last_tick = 0;
	memcpy(BAT_Voltage, BMS.Status .BAT_Voltage, sizeof(BAT_Voltage));
	
	//第一步 电压排序
	sort_asc(BAT_Voltage, Battery_Count);
	if(((BAT_Voltage [Battery_Count-1]>CB_SATRT_VOL)) &&((xTaskGetTickCount() - last_tick) >= pdMS_TO_TICKS(32000)))
	{
		for(int i=0;i<Battery_Count;i++)
		{
				if((BMS.Status .BAT_Voltage[i]-BAT_Voltage[0])> CB_VD)
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
					
				sprintf(buf, "%u", CoulombCounter.SOC);
					lv_label_set_text(objects.m_per, buf);
					
					
					
														sprintf(buf, "%u", CoulombCounter.SOC);
					lv_label_set_text(objects.p_per, buf);
					
						sprintf(buf, "%u",   BMS.Status.Temperature[1]/10);
					lv_label_set_text(objects.temp_4, buf);	
											sprintf(buf, "%u",   BMS.Status.Temperature[2]/10);
					lv_label_set_text(objects.temp_3, buf);	
											sprintf(buf, "%u",   BMS.Status.Temperature[0]/10+20);
					lv_label_set_text(objects.temp_2, buf);	
					
									sprintf(buf, "%u",(int16_t)SW6306_ReadTCHIP()	);
								lv_label_set_text(objects.temp_1, buf);	
					
					
					
					
					
					
					
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
							
						
							
//														sprintf(buf, "%.2f",	(float)(SW6306_ReadIBAT()/1000));		
				lv_label_set_text(objects.eef, buf);	
							
							
						}else{
							lv_label_set_text(objects.dc_flag, "关");

				lv_label_set_text(objects.vol, "0.00");	
		
					lv_label_set_text(objects.cur, "0.00");	

					lv_label_set_text(objects.pow, "0.00");

					lv_label_set_text(objects.eef, "0.00");
					

								lv_label_set_text(objects.temp_1, "--");	
							
							
						}


						break;
					case 1:
		sprintf(buf, "%.2f",BMS.Status.Pack_Voltage /1000.0f);		
				lv_label_set_text(objects.p_vol, buf);	
					
				sprintf(buf, "%.2f",-BMS.Status.Current/1000.0f	);
								lv_label_set_text(objects.p_cou, buf);	

		sprintf(buf, "%.1f",fabs(((float)BMS.Status.Pack_Voltage /1000.0f)*((float)BMS.Status.Current/1000.0f)));		
					lv_label_set_text(objects.p_pow, buf);	
					
									sprintf(buf, "%u", CoulombCounter.SOC);
					lv_label_set_text(objects.p_per, buf);
					
						sprintf(buf, "%u",   BMS.Status.Temperature[1]/10);
					lv_label_set_text(objects.temp_7, buf);	
											sprintf(buf, "%u",   BMS.Status.Temperature[0]/10+20);
					lv_label_set_text(objects.temp_5, buf);	
											sprintf(buf, "%u",   BMS.Status.Temperature[2]/10);
					lv_label_set_text(objects.temp_6, buf);	

					
					
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
					
					sprintf(buf, "%u", CoulombCounter.CoulombCounter_flash.flash_count);   //读取flash写入次数
					lv_label_set_text(objects.wf, buf);
					
					
					if((SW6306_Status.vbus_chg&7)==SW6306_VBUS_CHG_RQST_5V)
					{
						sprintf(buf, "%u", 5);
					}else if((SW6306_Status.vbus_chg&7)==SW6306_VBUS_CHG_RQST_9V)
					{
						sprintf(buf, "%u", 9);
					}else if((SW6306_Status.vbus_chg&7)==SW6306_VBUS_CHG_RQST_12V)
					{
						sprintf(buf, "%u", 12);
					}else if((SW6306_Status.vbus_chg&7)==SW6306_VBUS_CHG_RQST_15V)
					{
						sprintf(buf, "%u", 15);
					}else if((SW6306_Status.vbus_chg&7)==SW6306_VBUS_CHG_RQST_20V)
					{
						sprintf(buf, "%u", 20);
					}
					
					lv_label_set_text(objects.iacv, buf);
					
					
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
					sprintf(buf, "%u", BAT_OverDischargeAlarm);   //过放保护电压
					lv_label_set_text(objects.prv, buf);
					
					
					
					
					sprintf(buf, "%.0f", CoulombCounter.CoulombCounter_flash.Energy_max);   //最大能量
					lv_label_set_text(objects.enm, buf);
					
					sprintf(buf, "%.0f", CoulombCounter.CoulombCounter_flash.Remaining_Energy);   //剩余能量
					lv_label_set_text(objects.ree, buf);
					sprintf(buf, "%u", CoulombCounter.CoulombCounter_flash.Cycle_Percentage);   //循环百分比
					lv_label_set_text(objects.cyp, buf);
					sprintf(buf, "%u", CoulombCounter.healthy);   //健康度
					lv_label_set_text(objects.hes, buf);
					
					
						break;
					
					
					}
			refresh_flag=0;
			}
			
			
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}
