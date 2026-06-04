
#ifndef __6306_sw6306_iic_H
#define __6306_sw6306_iic_H

/* IO操作 */
#define sw6306_iic_SCL(x)        do{ x ? \
                               GPIO_SetPins(GPIO_PORT_B, GPIO_PIN_09) : \
                              GPIO_ResetPins(GPIO_PORT_B, GPIO_PIN_09); \
                          }while(0)       /* SCL */

#define sw6306_iic_SDA(x)        do{ x ? \
                            	GPIO_SetPins(GPIO_PORT_B, GPIO_PIN_08) : \
                              GPIO_ResetPins(GPIO_PORT_B, GPIO_PIN_08); \
                          }while(0)       /* SDA */

#define sw6306_iic_READ_SDA     GPIO_ReadInputPins(GPIO_PORT_B, GPIO_PIN_08) /* 读取SDA */
													
#define sw6306_iic_Delay     2


													
/* sw6306_iic所有操作函数 */
void sw6306_iic_init(void);                        /* 初始化sw6306_iic的IO */
void sw6306_iic_start(void);                       /* 发送sw6306_iic开始信号 */
void sw6306_iic_restart(void);                     /* 发送sw6306_iic开始信号 */
void sw6306_iic_stop(void);                        /* 发送sw6306_iic停止信号 */
void sw6306_iic_ack(void);                         /* sw6306_iic发送ACK信号 */
void sw6306_iic_nack(void);                        /* sw6306_iic不发送ACK信号 */
uint8_t sw6306_iic_wait_ack(void);                 /* sw6306_iic等待ACK信号 */
void sw6306_iic_send_byte(uint8_t txd);            /* sw6306_iic发送一个字节 */
uint8_t sw6306_iic_read_byte(unsigned char ack);   /* sw6306_iic读取一个字节 */
//void I2C_WriteRegByte(uint8_t SlaveAddress, uint8_t RegAddress, uint8_t ByteData); //通过I2C向设备寄存器写一个字节
//uint8_t I2C_ReadRegByte(uint8_t SlaveAddress, uint8_t RegAddress); //通过I2C从设备寄存器读一个字节

												
#endif
