
#include "SH367303.h"
#include "main.h"


uint8_t crc8(uint8_t *data, uint8_t len)
{
    uint8_t crc = 0x00;  // 初始值

    for (uint8_t i = 0; i < len; i++)
    {
        crc ^= data[i];

        for (uint8_t j = 0; j < 8; j++)
        {
            if (crc & 0x80)
                crc = (crc << 1) ^ 0x07;
            else
                crc <<= 1;
        }
    }
    return crc;
}
#define I2C_SCL_PROT  GPIO_PORT_A
#define I2C_SDA_PROT  GPIO_PORT_A

#define I2C_SCL_PIN  GPIO_PIN_01
#define I2C_SDA_PIN  GPIO_PIN_00




static void INT_SRC_I2C1_EEI_IrqCallback(void)
{
    //add your codes here
}
 void I2C_init()
{
	
	/*硬件i2c初始化*/
	
	
	
	 GPIO_SetFunc(GPIO_PORT_A,GPIO_PIN_00,GPIO_FUNC_48);//I2C1-SDA
    
    GPIO_SetFunc(GPIO_PORT_A,GPIO_PIN_01,GPIO_FUNC_49);//I2C1-SCL
	
	 int32_t i32Ret;
    stc_i2c_init_t stcI2cInit;
    float32_t fErr;

    /* Enable I2C1 clock */
    FCG_Fcg1PeriphClockCmd(FCG1_PERIPH_I2C1, ENABLE);
    /************************* Configure I2C1***************************/
    (void)I2C_DeInit(CM_I2C1);

    (void)I2C_StructInit(&stcI2cInit);
    stcI2cInit.u32ClockDiv = I2C_CLK_DIV32;
    stcI2cInit.u32Baudrate = 100000UL;
    stcI2cInit.u32SclTime = 0UL;
    i32Ret = I2C_Init(CM_I2C1, &stcI2cInit, &fErr);
    if (LL_OK != i32Ret) {
        //Initialized failed, add your code here.
    }
    I2C_BusWaitCmd(CM_I2C1, ENABLE);


    /* Enable interrupt function*/
    I2C_IntCmd(CM_I2C1, I2C_INT_NACK, ENABLE);

		
		    stc_irq_signin_config_t stcIrq;

    /* IRQ sign-in */
    stcIrq.enIntSrc = INT_SRC_I2C1_EEI;
    stcIrq.enIRQn = INT110_IRQn;
    stcIrq.pfnCallback = &INT_SRC_I2C1_EEI_IrqCallback;
    (void)INTC_IrqSignIn(&stcIrq);
    /* NVIC config */
    NVIC_ClearPendingIRQ(INT110_IRQn);
    NVIC_SetPriority(INT110_IRQn, DDL_IRQ_PRIO_15);
    NVIC_EnableIRQ(INT110_IRQn);

	
//    /* GPIO initialize */
//    stc_gpio_init_t stcGpioInit;
//    /* PA0 set to GPIO-Output */
//    (void)GPIO_StructInit(&stcGpioInit);
//    stcGpioInit.u16PinDir = PIN_DIR_OUT;
//    stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_NMOS;
//    stcGpioInit.u16PinState = PIN_STAT_SET;
//    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
//    (void)GPIO_Init(GPIO_PORT_A, GPIO_PIN_00, &stcGpioInit);

//    /* PA1 set to GPIO-Output */
//    (void)GPIO_StructInit(&stcGpioInit);
//    stcGpioInit.u16PinDir = PIN_DIR_OUT;
//    stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_NMOS;
//    stcGpioInit.u16PinState = PIN_STAT_SET;
//    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
//    (void)GPIO_Init(GPIO_PORT_A, GPIO_PIN_01, &stcGpioInit);

	
	
	
}


void sh_I2C_Write(uint8_t RegAddress, uint8_t ByteData)
{
uint8_t data[3];
	data[0]=SH_ADDR_WRITE;
	data[1]=RegAddress;
	data[2]= ByteData;
	    uint8_t crc = 0x00;

    for (uint8_t i = 0; i < 3; i++)
    {
        crc = crc8Table[crc ^ data[i]];
    }
		
		
	    I2C_Cmd(CM_I2C1, ENABLE);	
		
	    I2C_SWResetCmd(CM_I2C1, ENABLE);
    I2C_SWResetCmd(CM_I2C1, DISABLE);
if(I2C_Start(CM_I2C1, 0xFFFF)==LL_OK)
{
	
}
I2C_TransAddr(CM_I2C1, SH_ADDR, I2C_DIR_TX , 0xFFFF);
I2C_TransData(CM_I2C1, &RegAddress, 1, 0xFFFF);
I2C_TransData(CM_I2C1, &crc, 1, 0xFFFF);
I2C_Stop(CM_I2C1, 0xFFFF);


I2C_Cmd(CM_I2C1, DISABLE);	


	
}


void I2C_WriteRegByte(uint8_t SlaveAddress, uint8_t RegAddress, uint8_t ByteData)
{

uint8_t data[3];
	data[0]=SlaveAddress;
	data[1]=RegAddress;
	data[2]= ByteData;
	    uint8_t crc = 0x00;

    for (uint8_t i = 0; i < 3; i++)
    {
        crc = crc8Table[crc ^ data[i]];
    }
		
		
	    I2C_Cmd(CM_I2C1, ENABLE);	
		
	    I2C_SWResetCmd(CM_I2C1, ENABLE);
    I2C_SWResetCmd(CM_I2C1, DISABLE);
if(I2C_Start(CM_I2C1, 0xFFFF)==LL_OK)
{
	
}
I2C_TransAddr(CM_I2C1, SlaveAddress, I2C_DIR_TX , 0xFFFF);
I2C_TransData(CM_I2C1, &RegAddress, 1, 0xFFFF);
//I2C_TransData(CM_I2C1, &crc, 1, 0xFFFF);
I2C_Stop(CM_I2C1, 0xFFFF);


I2C_Cmd(CM_I2C1, DISABLE);	




}

uint16_t sh_I2C_Read(uint8_t RegAddress)
{
	uint8_t buf[3];
	uint16_t ret;
	
	
	    I2C_Cmd(CM_I2C1, ENABLE);	
		
	    I2C_SWResetCmd(CM_I2C1, ENABLE);
    I2C_SWResetCmd(CM_I2C1, DISABLE);
if(I2C_Start(CM_I2C1, 0xFFFF)==LL_OK)
{
}
I2C_TransAddr(CM_I2C1, SH_ADDR, I2C_DIR_TX , 0xFFFF);
I2C_TransData(CM_I2C1, &RegAddress, 1, 0xFFFF);
I2C_Restart(CM_I2C1, 0xFFFF);	
I2C_TransAddr(CM_I2C1, SH_ADDR, I2C_DIR_RX , 0xFFFF);
I2C_MasterReceiveDataAndStop(CM_I2C1,buf,3,0xFFFF);
	

	I2C_Stop(CM_I2C1, 0xFFFF);


I2C_Cmd(CM_I2C1, DISABLE);	
	return ret;
}

uint8_t I2C_ReadRegByte(uint8_t SlaveAddress, uint8_t RegAddress)
{
		uint8_t buf;
	
	
I2C_Start(CM_I2C1, 0xFFFF);
I2C_TransAddr(CM_I2C1, SlaveAddress, I2C_DIR_TX , 0xFFFF);
I2C_TransData(CM_I2C1, &RegAddress, 1, 0xFFFF);
I2C_Restart(CM_I2C1, 0xFFFF);
I2C_TransAddr(CM_I2C1, SlaveAddress+1, I2C_DIR_TX , 0xFFFF);
I2C_MasterReceiveDataAndStop(CM_I2C1,&buf,1,0xFFFF);

	
	 return buf;
	
	
}


int8_t SH36730X_Init(void)
{
	I2C_init();
	//开启电压采集
	sh_I2C_Write(SH_INT_EN  ,0b00000100);
		sh_I2C_Write(SH_SCONF3,0b11111100);  //采样周期 1s 开启全部采样
	
	
	return 0;
}

uint16_t SH36730X_Read_BATT_Voltage(uint8_t num)
{
	
	sh_I2C_Read(0x0E + (num*2));
	return 0;
	
}

