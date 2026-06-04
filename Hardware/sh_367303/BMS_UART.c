/********************************************************************************
    * 文件名称 ：BMS_UART.c
    * 作     者：ZM
    * 版     本：V1.0
    * 编写日期 ：2024-05-08
    * 功     能：BMS模拟串口输入数据
*********************************************************************************/
#include "BMS_UART.h"

/**
 * @brief   初始化 UART_Init
 *
 * @return  0   初始化成功
 *          -1   初始化失败
 */
int8_t BMS_UART_Init(void)
{
    return 0;
}

/**
 * @brief   读取电流 UART_Read_Current
 *
 * @return  电流值
 */
float BMS_UART_Read_Current(void)
{
    float current = 0;
    return current;
}

/**
 * @brief   读取电压 UART_Read_Voltage
 *
 * @return  电压值
 */
uint16_t BMS_UART_Read_BATT_Voltage(uint8_t num)
{
    uint16_t voltage = 6666;
    return voltage;
}

/**
 * @brief   读取温度 UART_Read_TEMP
 *
 * @return  温度值
 */
int16_t BMS_UART_Read_TEMP(uint8_t num)
{
    int16_t temp = 666;
    return temp;
}

/**
 * @brief   睡眠模式 UART_Sleep
 *
 * @return  0   初始化成功
 *          -1   初始化失败
 */
int8_t BMS_UART_Sleep(uint8_t enable)
{
    return 0;
}

/**
 * @brief   读取电池状态 UART_Read_BSTATUS
 *
 * @return  电池状态
 */
int8_t BMS_UART_Read_BSTATUS(void)
{
    int8_t status = 0;
    return status;
}

/**
 * @brief   设置充电 UART_CHG
 *
 * @return  电池状态
 */
int8_t BMS_UART_CHG(uint8_t enable)
{
    return 0;
}

/**
 * @brief   设置放电 UART_DSG
 *
 * @return  电池状态
 */
int8_t BMS_UART_DSG(uint8_t enable)
{
    return 0;
}

/**
 * @brief   设置电池状态 UART_Write_BSTATUS
 *
 * @return  电池状态
 */
int8_t BMS_UART_Write_CB(uint8_t channel, uint8_t enable)
{
    return 0;
}

/**
 * @brief   读取电池状态 UART_Read_BSTATUS
 *
 * @return  电池状态
 */
uint16_t BMS_UART_Read_CBStatus(void)
{
    int8_t status = 0;
    return status;
}

/**
 * @brief   设置电池状态 UART_Write_BSTATUS
 *
 * @return  电池状态
 */
int8_t BMS_UART_Write_CTLD(uint8_t enable)
{
    return 0;
}



