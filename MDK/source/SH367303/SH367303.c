
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
 void I2C_init()
{
	

	
    /* GPIO initialize */
    stc_gpio_init_t stcGpioInit;
    /* PA0 set to GPIO-Output */
    (void)GPIO_StructInit(&stcGpioInit);
    stcGpioInit.u16PinDir = PIN_DIR_OUT;
    stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_NMOS;
    stcGpioInit.u16PinState = PIN_STAT_SET;
    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
    (void)GPIO_Init(GPIO_PORT_A, GPIO_PIN_00, &stcGpioInit);

    /* PA1 set to GPIO-Output */
    (void)GPIO_StructInit(&stcGpioInit);
    stcGpioInit.u16PinDir = PIN_DIR_OUT;
    stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_NMOS;
    stcGpioInit.u16PinState = PIN_STAT_SET;
    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
    (void)GPIO_Init(GPIO_PORT_A, GPIO_PIN_01, &stcGpioInit);

	
	
	
}


static void I2C_START(void)
{
	while(1)
	{
	GPIO_ResetPins(I2C_SCL_PROT,I2C_SCL_PIN);
	DDL_DelayUS(1);
	GPIO_SetPins(I2C_SCL_PROT,I2C_SCL_PIN);
	DDL_DelayUS(1);
		
		GPIO_ResetPins(I2C_SDA_PROT,I2C_SDA_PIN);
	DDL_DelayUS(1);
	GPIO_SetPins(I2C_SDA_PROT,I2C_SDA_PIN);
	DDL_DelayUS(1);	
		
	}
}

void I2C_WriteRegByte(uint8_t SlaveAddress, uint8_t RegAddress, uint8_t ByteData)
{
	I2C_START();
//uint8_t data[3];
//	data[0]=SlaveAddress;
//	data[1]=RegAddress;
//	data[2]= ByteData;
//	    uint8_t crc = 0x00;

//    for (uint8_t i = 0; i < 3; i++)
//    {
//        crc = crc8Table[crc ^ data[i]];
//    }
//	    I2C_SWResetCmd(CM_I2C1, ENABLE);
//    I2C_SWResetCmd(CM_I2C1, DISABLE);
//if(I2C_Start(CM_I2C1, 0xFFFF)==LL_OK)
//{
//	
//	RTOS_START();
//}
//I2C_TransAddr(CM_I2C1, SlaveAddress, I2C_DIR_TX , 0xFFFF);
//I2C_TransData(CM_I2C1, &RegAddress, 1, 0xFFFF);
//I2C_TransData(CM_I2C1, &crc, 1, 0xFFFF);
//I2C_Stop(CM_I2C1, 0xFFFF);

}



uint8_t I2C_ReadRegByte(uint8_t SlaveAddress, uint8_t RegAddress)
{
		uint8_t buf;
	
	
//I2C_Start(CM_I2C1, 0xFFFF);
//I2C_TransAddr(CM_I2C1, SlaveAddress, I2C_DIR_TX , 0xFFFF);
//I2C_TransData(CM_I2C1, &RegAddress, 1, 0xFFFF);
//I2C_Restart(CM_I2C1, 0xFFFF);
//I2C_TransAddr(CM_I2C1, SlaveAddress+1, I2C_DIR_TX , 0xFFFF);
//I2C_MasterReceiveDataAndStop(CM_I2C1,&buf,1,0xFFFF);

	
	 return buf;
	
	
}
