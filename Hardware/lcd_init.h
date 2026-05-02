#ifndef __LCD_INIT_H
#define __LCD_INIT_H



#define USE_HORIZONTAL 3  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏


#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 80
#define LCD_H 160

#else
#define LCD_W 160
#define LCD_H 80
#endif



//-----------------LCD端口定义---------------- 

	#define LCD_SDA_PORT GPIO_PORT_B
	#define LCD_SDA_PIN  GPIO_PIN_04
	#define LCD_SDA_FUNC GPIO_FUNC_40
	
	
	#define LCD_SCL_PORT GPIO_PORT_B
	#define LCD_SCL_PIN  GPIO_PIN_05
	#define LCD_SCL_FUNC GPIO_FUNC_43
	
	#define LCD_CS_PORT  GPIO_PORT_B
	#define LCD_CS_PIN   GPIO_PIN_06
	#define LCD_CS_FUNC  GPIO_FUNC_42
	
  #define LCD_RS_PORT GPIO_PORT_B
	#define LCD_RS_PIN  GPIO_PIN_03

	
	#define LCD_RESET_PORT GPIO_PORT_A
	#define LCD_RESET_PIN  GPIO_PIN_15
	
	#define LCD_SPI CM_SPI3




void LCD_Writ_Bus(uint8_t dat);//模拟SPI时序
void LCD_WR_DATA8(uint8_t dat);//写入一个字节
void LCD_WR_DATA(uint16_t dat);//写入两个字节
void LCD_WR_REG(uint8_t dat);//写入一个指令
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);//设置坐标函数
void LCD_Init(void);//LCD初始化
#endif




