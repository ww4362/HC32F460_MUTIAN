#ifndef __COULOMETER_H__
#define __COULOMETER_H__

#include "main.h"



#define FLASH_SAVE_ADDR  0x0007E000


// 需要写入到flash的数据
typedef struct{
uint32_t flash_count;	//flash写入次数
uint32_t Cycle_Percentage;  //循环百分比  没消耗百分之1 该值增加1 	
float Energy_max;     //当前最大能量
float Remaining_Energy;   //剩余能量
float efficiency;   //充放电效率 一开始为90%
}CoulombCounter_flash_t;


typedef struct
{
	uint16_t Capacity_mAh;      //电池额定容量
	uint8_t SOC;									//剩余百分比      
	float theory_Energy_max;   //理论最大能量
uint8_t healthy;     //健康度

	CoulombCounter_flash_t CoulombCounter_flash ;

} CoulombCounter_t;

enum adc_mode_t{
	none,  //无状态
	high_battery,   //充满
	Low_battery , //没电
	Charging, //充电中
	Discharging,//放电中
	
	
};




extern CoulombCounter_t CoulombCounter;




void coulometer_init(void);

void coulometer_ticks(float cur ,uint16_t vol, enum adc_mode_t mode);




#endif