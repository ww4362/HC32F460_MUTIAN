/********************************************************************************
    * 文件名称 ：BMS_UART.h
    * 作     者：ZM
    * 版     本：V1.0
    * 编写日期 ：2024-05-08
    * 功     能：BMS模拟串口输入数据
*********************************************************************************/

#ifndef __BMS_UART_H
#define __BMS_UART_H

#include "BMS.h"
#include <stdint.h> //包含标准类型定义头文件
#include <stdio.h>

int8_t BMS_UART_Init(void);
float BMS_UART_Read_Current(void);
uint16_t BMS_UART_Read_BATT_Voltage(uint8_t num);
int16_t BMS_UART_Read_TEMP(uint8_t num);
int8_t BMS_UART_Sleep(uint8_t enable);
int8_t BMS_UART_Read_BSTATUS(void);
int8_t BMS_UART_CHG(uint8_t enable);
int8_t BMS_UART_DSG(uint8_t enable);
int8_t BMS_UART_Write_CB(uint8_t channel, uint8_t enable);
int8_t BMS_UART_Read_CBStatus(uint8_t channel);
int8_t BMS_UART_Write_CTLD(uint8_t enable);



#endif //__BMS_UART_H
