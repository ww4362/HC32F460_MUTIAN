#ifndef __RTOS_MAIN_H
#define __RTOS_MAIN_H		



void RTOS_START(void);



typedef struct
{
	uint16_t Capacity_mAh;      //电池额定容量
	uint8_t SOC;									//剩余百分比
	uint16_t flash_count;      //flash写入次数
	float theory_Energy_max;   //理论最大能量
	float Energy_max;     //最大能量
	float Remaining_Energy;   //剩余能量
	uint32_t Cycle_Percentage;  //循环百分比  没消耗百分之1 该值增加1 
} CoulombCounter_t;





#define CB_SATRT_VOL   3400   //均衡启动电压 单位 mv
#define CB_VD          10    //均衡电压差 

#endif