#include "Coulometer.h"
#include <string.h>


/*
上机后可以大幅度加长flash写入间隔时间 1小时一次确实也够
*/


 CoulombCounter_t CoulombCounter;
void coulometer_init(void)
{

		CoulombCounter.theory_Energy_max=181300.0f ;
	
		memcpy(&CoulombCounter.CoulombCounter_flash, (void *)FLASH_SAVE_ADDR, sizeof(CoulombCounter_flash_t));

	if(CoulombCounter.CoulombCounter_flash.flash_count ==0xFFFFFFFF)
	{
		//说明是没初始化过的结构体 先进行初始化
		
		
		memset(&CoulombCounter.CoulombCounter_flash, 0, sizeof(CoulombCounter_flash_t));
		

//		CoulombCounter.CoulombCounter_flash.flash_count=0;
//		CoulombCounter.CoulombCounter_flash.Cycle_Percentage=0;
//		CoulombCounter.CoulombCounter_flash.Energy_max=0.0f;
//		CoulombCounter.CoulombCounter_flash.Remaining_Energy=0.0f;
	}
	
	
}

/*
500ms调用一次
cur 当前电流   单位 mA  在绝对值小于20的情况下 按20算 因为这大概率是系统功耗  大于20的叠加20的系统功耗  电流是充电正数 放电负数
vol  当前电压 单位 mV 
mode 是否充满和没电
*/

void coulometer_ticks(float cur ,uint16_t vol, enum adc_mode_t mode)
{	
		static uint8_t tmp_SOC=0; //记录上一时刻电量
	
	//大于13 说明是充电  电池计算的是放电容量  充电容量要比实际容量大 充电x98%的系数 放电不做修正
	if(cur>13)
	{
		CoulombCounter.CoulombCounter_flash.Remaining_Energy+=(vol /1000.0f*cur/7200.0f*0.98);
		
	}else if (cur<13)
	{
		
		CoulombCounter.CoulombCounter_flash.Remaining_Energy+=(vol /1000.0f*(cur-20)/7200.f);
		
	}else {
		
	//不等于充电中要计算系统功耗
		CoulombCounter.CoulombCounter_flash.Remaining_Energy+=(vol /1000.0f*(-20.0f)/7200.f);
	
		
	}
	//剩余能量小于0要等于0
	if(CoulombCounter.CoulombCounter_flash.Remaining_Energy<0)
		CoulombCounter.CoulombCounter_flash.Remaining_Energy=0;

	//当前能量大于最大能量时 最大能量等于当前能量
if(CoulombCounter.CoulombCounter_flash.Remaining_Energy>CoulombCounter.CoulombCounter_flash.Energy_max)
{
CoulombCounter.CoulombCounter_flash.Energy_max=CoulombCounter.CoulombCounter_flash.Remaining_Energy;
	
}
// 健康度计算  等于当前最大除于额定能量
CoulombCounter.healthy=CoulombCounter.CoulombCounter_flash.Energy_max/CoulombCounter.theory_Energy_max*100;

//百分比电量计算
CoulombCounter.SOC=CoulombCounter.CoulombCounter_flash.Remaining_Energy/CoulombCounter.CoulombCounter_flash.Energy_max*100;


//计算循环百分比
if(CoulombCounter.SOC<tmp_SOC)
{
	CoulombCounter.CoulombCounter_flash.Cycle_Percentage+=(tmp_SOC-CoulombCounter.SOC);	
}
tmp_SOC=CoulombCounter.SOC;

//	Batty_t.SOC=(uint8_t)((Batty_t.Remaining_Energy/Batty_t.Energy_max)*100);  //计算百分比
//	// 计算循环
//	if(Batty_t.SOC<tpm_SOC)  
//	{
//		

//			
//		
//	}
//	
//	
	









switch(mode)
{
	case 	none: //无状态
		
	break;
	case high_battery:   //充满 
		CoulombCounter.CoulombCounter_flash.Energy_max=CoulombCounter.CoulombCounter_flash.Remaining_Energy;
	break;
	case Low_battery : //没电
		CoulombCounter.CoulombCounter_flash.Remaining_Energy=0;
	break;
	case Charging: //充电中
		
		break;
	case Discharging://放电中
		
		break;
}






}