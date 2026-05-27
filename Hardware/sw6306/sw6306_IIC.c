#include "main.h" 
#include "sw6306_IIC.h" 
/**
 * @brief       sw6306_iic写入一个字节
 * @param       无
 * @retval      无
 */
//void I2C_WriteRegByte(uint8_t SlaveAddress, uint8_t RegAddress, uint8_t ByteData)
//{
//	sw6306_iic_start();
//	sw6306_iic_send_byte(SlaveAddress);
//	sw6306_iic_wait_ack();
//	sw6306_iic_send_byte(RegAddress);
//	sw6306_iic_wait_ack();
//	sw6306_iic_send_byte(ByteData);
//	sw6306_iic_wait_ack();
//	sw6306_iic_stop();
//}
///**
// * @brief       sw6306_iic读出一个字节
// * @param       无
// * @retval      无
// */
//uint8_t I2C_ReadRegByte(uint8_t SlaveAddress, uint8_t RegAddress)
//{
//	uint8_t data;
//	sw6306_iic_start();
//	sw6306_iic_send_byte(SlaveAddress);
//	sw6306_iic_wait_ack();
//	sw6306_iic_send_byte(RegAddress);
//	sw6306_iic_wait_ack();
//	sw6306_iic_start();
//	sw6306_iic_send_byte(SlaveAddress + 1);
//	sw6306_iic_wait_ack();
//	data = sw6306_iic_read_byte(0);
//	sw6306_iic_nack();
//	sw6306_iic_stop();
//	return data;
//}

/**
 * @brief       us延时函数
 * @param       无
 * @retval      无
 */
void sw6306_delay_us(uint32_t nus)
{
    uint32_t Delay = nus * 168/4;
    do
    {
        __NOP();
    }
    while (Delay --);
}

/**
 * @brief       sw6306_iic延时函数,用于控制sw6306_iic读写速度
 * @param       无
 * @retval      无
 */
void sw6306_iic_delay(int delay)
{
//	AL_Delay(1);    /* 2us的延时, 读写速度在250Khz以内 */
	sw6306_delay_us(delay);
//	DDL_DelayUS (delay);
}

/**
 * @brief       产生sw6306_iic起始信号
 * @param       无
 * @retval      无
 */
void sw6306_iic_start(void)
{
    sw6306_iic_SDA(1);
    sw6306_iic_SCL(1);
    sw6306_iic_delay(sw6306_iic_Delay);
    sw6306_iic_SDA(0);     /* START信号: 当SCL为高时, SDA从高变成低, 表示起始信号 */
    sw6306_iic_delay(sw6306_iic_Delay);
    sw6306_iic_SCL(0);     /* 钳住I2C总线，准备发送或接收数据 */
    sw6306_iic_delay(sw6306_iic_Delay);
}

/**
 * @brief       产生sw6306_iic起始信号
 * @param       无
 * @retval      无
 */
void sw6306_iic_restart(void)
{
    sw6306_iic_SDA(1);
    sw6306_iic_SCL(1);
    sw6306_iic_delay(sw6306_iic_Delay+2);
    sw6306_iic_SDA(0);     /* START信号: 当SCL为高时, SDA从高变成低, 表示起始信号 */
    sw6306_iic_delay(sw6306_iic_Delay+2);
    sw6306_iic_SCL(0);     /* 钳住I2C总线，准备发送或接收数据 */
    sw6306_iic_delay(sw6306_iic_Delay);
}

/**
 * @brief       产生sw6306_iic停止信号
 * @param       无
 * @retval      无
 */
void sw6306_iic_stop(void)
{
	sw6306_iic_SDA(0);
    sw6306_iic_SCL(1);
		sw6306_iic_delay(sw6306_iic_Delay);
     /* STOP信号: 当SCL为高时, SDA从低变成高, 表示停止信号 */
    sw6306_iic_delay(sw6306_iic_Delay);
    sw6306_iic_SDA(1);     /* 发送I2C总线结束信号 */
    sw6306_iic_delay(sw6306_iic_Delay);
}

void sw6306_iic_init(void)
{
	    stc_gpio_init_t stcGpioInit;

    /* PA0 set to GPIO-Output SCL */
    (void)GPIO_StructInit(&stcGpioInit);
    stcGpioInit.u16PinDir = PIN_DIR_OUT;
    stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_NMOS;
    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
		stcGpioInit.u16PinState = PIN_STAT_SET ;
		stcGpioInit.u16PinDrv= PIN_HIGH_DRV;
    (void)GPIO_Init(GPIO_PORT_B, GPIO_PIN_09, &stcGpioInit);

    /* PA1 set to GPIO-Output SDA */
    (void)GPIO_StructInit(&stcGpioInit);
    stcGpioInit.u16PinDir = PIN_DIR_OUT;
    stcGpioInit.u16PinOutputType = PIN_OUT_TYPE_NMOS;
    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
		stcGpioInit.u16PinState = PIN_STAT_SET ;
		stcGpioInit.u16PinDrv= PIN_HIGH_DRV;
    (void)GPIO_Init(GPIO_PORT_B, GPIO_PIN_08, &stcGpioInit);
	
	
	
}

/**
 * @brief       等待应答信号到来
 * @param       无
 * @retval      1，接收应答失败
 *              0，接收应答成功
 */
uint8_t sw6306_iic_wait_ack(void)
{
    uint8_t waittime = 0;
    uint8_t rack = 0;

    sw6306_iic_SDA(1);     /* 主机释放SDA线(此时外部器件可以拉低SDA线) */
    sw6306_iic_delay(sw6306_iic_Delay);
    sw6306_iic_SCL(1);     /* SCL=1, 此时从机可以返回ACK */
    sw6306_iic_delay(sw6306_iic_Delay);

    while (sw6306_iic_READ_SDA)    /* 等待应答 */
    {
        waittime++;

        if (waittime > 250)
        {
            sw6306_iic_stop();
            rack = 1;
            break;
        }
    }

    sw6306_iic_SCL(0);     /* SCL=0, 结束ACK检查 */
    sw6306_iic_delay(sw6306_iic_Delay);
    return rack;
}

/**
 * @brief       产生ACK应答
 * @param       无
 * @retval      无
 */
void sw6306_iic_ack(void)
{
    sw6306_iic_SDA(0);     /* SCL 0 -> 1  时 SDA = 0,表示应答 */
    sw6306_iic_delay(sw6306_iic_Delay);
    sw6306_iic_SCL(1);     /* 产生一个时钟 */
    sw6306_iic_delay(sw6306_iic_Delay);
    sw6306_iic_SCL(0);
    sw6306_iic_delay(sw6306_iic_Delay);
    sw6306_iic_SDA(1);     /* 主机释放SDA线 */
    sw6306_iic_delay(sw6306_iic_Delay);
}

/**
 * @brief       不产生ACK应答
 * @param       无
 * @retval      无
 */
void sw6306_iic_nack(void)
{
    sw6306_iic_SDA(1);     /* SCL 0 -> 1  时 SDA = 1,表示不应答 */
    sw6306_iic_delay(sw6306_iic_Delay);
    sw6306_iic_SCL(1);     /* 产生一个时钟 */
    sw6306_iic_delay(sw6306_iic_Delay);
    sw6306_iic_SCL(0);
    sw6306_iic_delay(sw6306_iic_Delay);
}

/**
 * @brief       sw6306_iic发送一个字节
 * @param       data: 要发送的数据
 * @retval      无
 */
void sw6306_iic_send_byte(uint8_t data)
{
    uint8_t t;
    
    for (t = 0; t < 8; t++)
    {
        sw6306_iic_SDA((data & 0x80) >> 7);    /* 高位先发送 */
        sw6306_iic_delay(sw6306_iic_Delay);
        sw6306_iic_SCL(1);
        sw6306_iic_delay(sw6306_iic_Delay);
        sw6306_iic_SCL(0);
        data <<= 1;     /* 左移1位,用于下一次发送 */
    }
    sw6306_iic_SDA(1);         /* 发送完成, 主机释放SDA线 */
}

/**
 * @brief       sw6306_iic读取一个字节
 * @param       ack:  ack=1时，发送ack; ack=0时，发送nack
 * @retval      接收到的数据
 */
uint8_t sw6306_iic_read_byte(uint8_t ack)
{
    uint8_t i, receive = 0;

    for (i = 0; i < 8; i++ )    /* 接收1个字节数据 */
    {
        receive <<= 1;  /* 高位先输出,所以先收到的数据位要左移 */
        sw6306_iic_SCL(1);
        sw6306_iic_delay(sw6306_iic_Delay);

        if (sw6306_iic_READ_SDA)
        {
            receive++;
        }
        
        sw6306_iic_SCL(0);
        sw6306_iic_delay(sw6306_iic_Delay);
    }

    if (!ack)
    {
        sw6306_iic_nack();     /* 发送nACK */
    }
    else
    {
        sw6306_iic_ack();      /* 发送ACK */
    }

    return receive;
}