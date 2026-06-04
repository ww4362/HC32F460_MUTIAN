/********************************************************************************
    * 文件名称 ：IIC.c
    * 作     者：ZM
    * 版     本：V1.0
    * 编写日期 ：2024-01-30
    * 功     能：IIC驱动
*********************************************************************************/
#include "IIC.h"
#include "main.h"



/**
 * @brief       IIC写入一个字节
 * @param       无
 * @retval      无
 */
void I2C_WriteRegByte(uint8_t SlaveAddress, uint8_t RegAddress, uint8_t ByteData)
{
	iic_start();
	iic_send_byte(SlaveAddress);
	iic_wait_ack();
	iic_send_byte(RegAddress);
	iic_wait_ack();
	iic_send_byte(ByteData);
	iic_wait_ack();
	iic_stop();
}
/**
 * @brief       IIC读出一个字节
 * @param       无
 * @retval      无
 */
uint8_t I2C_ReadRegByte(uint8_t SlaveAddress, uint8_t RegAddress)
{
	uint8_t data;
	iic_start();
	iic_send_byte(SlaveAddress);
	iic_wait_ack();
	iic_send_byte(RegAddress);
	iic_wait_ack();
	iic_start();
	iic_send_byte(SlaveAddress + 1);
	iic_wait_ack();
	data = iic_read_byte(0);
	iic_nack();
	iic_stop();
	return data;
}

/**
 * @brief       us延时函数
 * @param       无
 * @retval      无
 */
void delay_us(uint32_t nus)
{
    uint32_t Delay = nus * 168/4;
    do
    {
        __NOP();
    }
    while (Delay --);
}

/**
 * @brief       IIC延时函数,用于控制IIC读写速度
 * @param       无
 * @retval      无
 */
void iic_delay(int delay)
{
//	AL_Delay(1);    /* 2us的延时, 读写速度在250Khz以内 */
	delay_us(delay);
//	DDL_DelayUS (delay);
}

/**
 * @brief       产生IIC起始信号
 * @param       无
 * @retval      无
 */
void iic_start(void)
{
    IIC_SDA(1);
    IIC_SCL(1);
    iic_delay(IIC_Delay);
    IIC_SDA(0);     /* START信号: 当SCL为高时, SDA从高变成低, 表示起始信号 */
    iic_delay(IIC_Delay);
    IIC_SCL(0);     /* 钳住I2C总线，准备发送或接收数据 */
    iic_delay(IIC_Delay);
}

/**
 * @brief       产生IIC起始信号
 * @param       无
 * @retval      无
 */
void iic_restart(void)
{
    IIC_SDA(1);
    IIC_SCL(1);
    iic_delay(IIC_Delay+2);
    IIC_SDA(0);     /* START信号: 当SCL为高时, SDA从高变成低, 表示起始信号 */
    iic_delay(IIC_Delay+2);
    IIC_SCL(0);     /* 钳住I2C总线，准备发送或接收数据 */
    iic_delay(IIC_Delay);
}

/**
 * @brief       产生IIC停止信号
 * @param       无
 * @retval      无
 */
void iic_stop(void)
{
	IIC_SDA(0);
    IIC_SCL(1);
		iic_delay(IIC_Delay);
     /* STOP信号: 当SCL为高时, SDA从低变成高, 表示停止信号 */
    iic_delay(IIC_Delay);
    IIC_SDA(1);     /* 发送I2C总线结束信号 */
    iic_delay(IIC_Delay);
}

void iic_init(void)
{
	IIC_SDA(1);
    IIC_SCL(1);
}

/**
 * @brief       等待应答信号到来
 * @param       无
 * @retval      1，接收应答失败
 *              0，接收应答成功
 */
uint8_t iic_wait_ack(void)
{
    uint8_t waittime = 0;
    uint8_t rack = 0;

    IIC_SDA(1);     /* 主机释放SDA线(此时外部器件可以拉低SDA线) */
    iic_delay(IIC_Delay);
    IIC_SCL(1);     /* SCL=1, 此时从机可以返回ACK */
    iic_delay(IIC_Delay);

    while (IIC_READ_SDA)    /* 等待应答 */
    {
        waittime++;

        if (waittime > 250)
        {
            iic_stop();
            rack = 1;
            break;
        }
    }

    IIC_SCL(0);     /* SCL=0, 结束ACK检查 */
    iic_delay(IIC_Delay);
    return rack;
}

/**
 * @brief       产生ACK应答
 * @param       无
 * @retval      无
 */
void iic_ack(void)
{
    IIC_SDA(0);     /* SCL 0 -> 1  时 SDA = 0,表示应答 */
    iic_delay(IIC_Delay);
    IIC_SCL(1);     /* 产生一个时钟 */
    iic_delay(IIC_Delay);
    IIC_SCL(0);
    iic_delay(IIC_Delay);
    IIC_SDA(1);     /* 主机释放SDA线 */
    iic_delay(IIC_Delay);
}

/**
 * @brief       不产生ACK应答
 * @param       无
 * @retval      无
 */
void iic_nack(void)
{
    IIC_SDA(1);     /* SCL 0 -> 1  时 SDA = 1,表示不应答 */
    iic_delay(IIC_Delay);
    IIC_SCL(1);     /* 产生一个时钟 */
    iic_delay(IIC_Delay);
    IIC_SCL(0);
    iic_delay(IIC_Delay);
}

/**
 * @brief       IIC发送一个字节
 * @param       data: 要发送的数据
 * @retval      无
 */
void iic_send_byte(uint8_t data)
{
    uint8_t t;
    
    for (t = 0; t < 8; t++)
    {
        IIC_SDA((data & 0x80) >> 7);    /* 高位先发送 */
        iic_delay(IIC_Delay);
        IIC_SCL(1);
        iic_delay(IIC_Delay);
        IIC_SCL(0);
				iic_delay(IIC_Delay);
        data <<= 1;     /* 左移1位,用于下一次发送 */
    }
    IIC_SDA(1);         /* 发送完成, 主机释放SDA线 */
}

/**
 * @brief       IIC读取一个字节
 * @param       ack:  ack=1时，发送ack; ack=0时，发送nack
 * @retval      接收到的数据
 */
uint8_t iic_read_byte(uint8_t ack)
{
    uint8_t i, receive = 0;

    for (i = 0; i < 8; i++ )    /* 接收1个字节数据 */
    {
        receive <<= 1;  /* 高位先输出,所以先收到的数据位要左移 */
        IIC_SCL(1);
        iic_delay(IIC_Delay);

        if (IIC_READ_SDA)
        {
            receive++;
        }
        
        IIC_SCL(0);
        iic_delay(IIC_Delay);
    }

    if (!ack)
    {
        iic_nack();     /* 发送nACK */
    }
    else
    {
        iic_ack();      /* 发送ACK */
    }

    return receive;
}

void I2C_WriteRegByte_CRC8(uint8_t SlaveAddress, uint8_t RegAddress, uint8_t ByteData) //通过I2C向设备寄存器写一个字节(CRC校验)
{
    uint8_t CRC_buf[3];
    CRC_buf[0] = (SlaveAddress<<1 | 0);
    CRC_buf[1] = RegAddress;
    CRC_buf[2] = ByteData;
	iic_start();
	iic_send_byte((SlaveAddress<<1) | 0);
	iic_wait_ack();
	iic_send_byte(RegAddress);
	iic_wait_ack();
	iic_send_byte(ByteData);
	iic_wait_ack();
	iic_send_byte(CRC8(CRC_buf,3));
	iic_wait_ack();
	iic_stop();
}


uint8_t CRC8(uint8_t *data , uint8_t len)
{
    
	uint8_t crc8 = 0;

    while (len --)
    {
        crc8 = crc8 ^ (*data++);
        crc8 = crc8Table[crc8];
    }

    return crc8;
}


uint8_t CRC_buf[6];
uint16_t I2C_ReadReg2Byte_CRC8(uint8_t SlaveAddress, uint8_t RegAddress) //通过I2C从设备寄存器读两个字节(CRC校验)
{
    
    uint16_t data;
    CRC_buf[0] = (SlaveAddress<<1);
    CRC_buf[1] = RegAddress;
    CRC_buf[2] = (SlaveAddress<<1)+1;
	
    iic_start();
	iic_send_byte((SlaveAddress<<1));
	iic_wait_ack();
	iic_send_byte(RegAddress);
	iic_wait_ack();	
	iic_start();		
    iic_send_byte((SlaveAddress<<1)+1);
	iic_wait_ack();
    CRC_buf[3] = iic_read_byte(1);      //高8位
    CRC_buf[4] = iic_read_byte(1);      //低八位
	CRC_buf[5] = iic_read_byte(0);      //CRC
    iic_stop();

if( CRC8(CRC_buf,5) == CRC_buf[5])
{
data = (CRC_buf[3] <<8 )| CRC_buf[4];
}
else 
   {
       data = 0xffff;
        #ifdef LOG_OUTPUT
        printf("IIC CRC Failed\n");
         #endif
   }
return data;
}


uint8_t I2C_ReadRegByte_CRC8(uint8_t SlaveAddress, uint8_t RegAddress) //通过I2C从设备寄存器读一个字节
{
    
    uint8_t data;
    CRC_buf[0] = (SlaveAddress<<1);
    CRC_buf[1] = RegAddress;
    CRC_buf[2] = (SlaveAddress<<1)+1;
    iic_start();
	iic_send_byte((SlaveAddress<<1));
	iic_wait_ack();
	iic_send_byte(RegAddress);
	iic_wait_ack();	
	iic_start();
  iic_send_byte((SlaveAddress<<1)+1);
	iic_wait_ack();
   CRC_buf[3] = iic_read_byte(1);      //高8位
   CRC_buf[4] = iic_read_byte(1);      //低八位
	CRC_buf[5] = iic_read_byte(0);      //CRC
    iic_stop();
   if( CRC8(CRC_buf,5) == CRC_buf[5])
   {
       data = CRC_buf[3];
   }
   else 
   {
       data = 0xff;
        #ifdef LOG_OUTPUT
        printf("IIC CRC Failed\n");
         #endif
   }
    return data;
}





