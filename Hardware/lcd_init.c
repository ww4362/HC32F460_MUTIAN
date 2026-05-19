#include "main.h"
#include "lcd_init.h"



/******************************************************************************
      函数说明：LCD串行数据写入函数
      入口数据：dat  要写入的串行数据
      返回值：  无
******************************************************************************/
//void LCD_Writ_Bus(uint8_t dat) 
//{	
////	//	LL_SPI_SetDataWidth (SPI1,LL_SPI_DATAWIDTH_8BIT );
//////		LL_GPIO_ResetOutputPin(LCD_CS_PORT, LCD_CS_PIN );

////	 while (LL_SPI_IsActiveFlag_TXE(SPI1) == RESET);
////		
////		LL_SPI_TransmitData8(SPI1,dat);

////	
////    while (!LL_SPI_IsActiveFlag_TXE(SPI1));
////	
////		while(LL_SPI_IsActiveFlag_BSY (SPI1)==SET);
////	
////	//	LL_GPIO_SetOutputPin(LCD_CS_PORT, LCD_CS_PIN );		
//}


/******************************************************************************
      函数说明：LCD写入数据
      入口数据：dat 写入的数据
      返回值：  无
******************************************************************************/
void LCD_WR_DATA8(uint8_t dat)
{
	//LCD_Writ_Bus(dat);
	MODIFY_REG32(LCD_SPI->CFG2, SPI_CFG2_DSIZE, SPI_DATA_SIZE_8BIT);
			while(SPI_GetStatus(LCD_SPI,SPI_FLAG_TX_BUF_EMPTY)==RESET)
	{
	}
	
		SPI_Trans(LCD_SPI,&dat,1,1000);
}


/******************************************************************************
      函数说明：LCD写入数据
      入口数据：dat 写入的数据
      返回值：  无
******************************************************************************/
void LCD_WR_DATA(uint16_t dat)
{
MODIFY_REG32(LCD_SPI->CFG2, SPI_CFG2_DSIZE, SPI_DATA_SIZE_16BIT);
			while(SPI_GetStatus(LCD_SPI,SPI_FLAG_TX_BUF_EMPTY)==RESET)
	{
	}
	
		SPI_Trans(LCD_SPI,&dat,1,1000);



}


/******************************************************************************
      函数说明：LCD写入命令
      入口数据：dat 写入的命令
      返回值：  无
******************************************************************************/
void LCD_WR_REG(uint8_t dat)
{
GPIO_ResetPins(LCD_RS_PORT, LCD_RS_PIN );    //拉低RS 选择为命令
	
	MODIFY_REG32(LCD_SPI->CFG2, SPI_CFG2_DSIZE, SPI_DATA_SIZE_8BIT);
			while(SPI_GetStatus(LCD_SPI,SPI_FLAG_TX_BUF_EMPTY)==RESET)
	{
	}
	
	
	SPI_Trans(LCD_SPI,&dat,1,1000);
	
	 GPIO_SetPins(LCD_RS_PORT, LCD_RS_PIN );	
}


/******************************************************************************
      函数说明：设置起始和结束地址
      入口数据：x1,x2 设置列的起始和结束地址
                y1,y2 设置行的起始和结束地址
      返回值：  无
******************************************************************************/
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
	if(USE_HORIZONTAL==0)
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1+26);
		LCD_WR_DATA(x2+26);
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1+1);
		LCD_WR_DATA(y2+1);
		LCD_WR_REG(0x2c);//储存器写
	}
	else if(USE_HORIZONTAL==1)
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1+26);
		LCD_WR_DATA(x2+26);
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1+1);
		LCD_WR_DATA(y2+1);
		LCD_WR_REG(0x2c);//储存器写
	}
	else if(USE_HORIZONTAL==2)
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1+1);
		LCD_WR_DATA(x2+1);
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1+26);
		LCD_WR_DATA(y2+26);
		LCD_WR_REG(0x2c);//储存器写
	}
	else
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA8(0);
		LCD_WR_DATA8(x1+1);
		LCD_WR_DATA8(0);
		LCD_WR_DATA8(x2+1);
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA8(0);
		LCD_WR_DATA8(y1+26);
		LCD_WR_DATA8(0);
		LCD_WR_DATA8(y2+26);
		LCD_WR_REG(0x2c);//储存器写
	}
}

void LCD_Init(void)
{
	/*LCD_PWM*/
	
	stc_tmra_init_t stcTmraInit;
    stc_tmra_pwm_init_t stcPwmInit;

      GPIO_SetFunc(GPIO_PORT_B,GPIO_PIN_14,GPIO_FUNC_4);//TIMA-3-PWM1/TIMA-3-CLKA

    /* Enable TMRA_3 peripheral clock */
    FCG_Fcg2PeriphClockCmd(FCG2_PERIPH_TMRA_1, ENABLE);

    /************************* Configure TMRA_3 counter *************************/
    (void)TMRA_StructInit(&stcTmraInit);  
    /* Config software count */
    stcTmraInit.sw_count.u8ClockDiv = TMRA_CLK_DIV8;  //时钟为100M 那pwm频率为50k 
    stcTmraInit.sw_count.u8CountMode = TMRA_MD_SAWTOOTH;
    stcTmraInit.sw_count.u8CountDir = TMRA_DIR_UP;
    stcTmraInit.u32PeriodValue = 255-1U;
    (void)TMRA_Init(CM_TMRA_1, &stcTmraInit);

    /************************* Configure TMRA_3_1 CMP ***************************/
    /* Config PWM output */
    (void)TMRA_PWM_StructInit(&stcPwmInit);
    stcPwmInit.u32CompareValue = 1-1;  //比较值
    stcPwmInit.u16StartPolarity = TMRA_PWM_HOLD;  //开始值   分频后只能设置保存不变
    stcPwmInit.u16StopPolarity = TMRA_PWM_HOLD;  //停止值   分频后只能设置保存不变
    stcPwmInit.u16CompareMatchPolarity = TMRA_PWM_HIGH;  //比较      
    stcPwmInit.u16PeriodMatchPolarity = TMRA_PWM_LOW ;   //周期     
		//TMRA_PWM_SetForcePolarity(CM_TMRA_3, TMRA_CH1,TMRA_PWM_FORCE_LOW); //设置默认输出为低电平
    (void)TMRA_PWM_Init(CM_TMRA_1, TMRA_CH6, &stcPwmInit);
    /* PWM pin function set */
    TMRA_SetFunc(CM_TMRA_1, TMRA_CH6, TMRA_FUNC_CMP);
    /* PWM output command */
    TMRA_PWM_OutputCmd(CM_TMRA_1, TMRA_CH6, ENABLE);
		





    /* Start timerA */
    TMRA_Start(CM_TMRA_1);
		
		CM_TMRA_1->CMPAR6=100;
	
	    /* GPIO initialize */
    stc_gpio_init_t stcGpioInit;
    /* PB3 set to GPIO-Output */
    GPIO_SetDebugPort(GPIO_PIN_TDO, DISABLE);
    (void)GPIO_StructInit(&stcGpioInit);
    stcGpioInit.u16PinDir = PIN_DIR_OUT;
    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
		stcGpioInit.u16PinState=PIN_STAT_SET;
    (void)GPIO_Init(LCD_RS_PORT , LCD_RS_PIN, &stcGpioInit);

    /* PA15 set to GPIO-Output */
    GPIO_SetDebugPort(GPIO_PIN_TDI, DISABLE);
    (void)GPIO_StructInit(&stcGpioInit);
		stcGpioInit.u16PinState = PIN_STAT_RST;
    stcGpioInit.u16PinDir = PIN_DIR_OUT;
    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
    (void)GPIO_Init(LCD_RESET_PORT,LCD_RESET_PIN, &stcGpioInit);

    GPIO_SetDebugPort(GPIO_PIN_TRST, DISABLE);  //把PB4 设置成了普通脚
    GPIO_SetFunc(LCD_SDA_PORT ,LCD_SDA_PIN ,LCD_SDA_FUNC);//SPI4-MISI	    
    GPIO_SetFunc(LCD_SCL_PORT,LCD_SCL_PIN, LCD_SCL_FUNC);//SPI3-SCK
    GPIO_SetFunc(	LCD_CS_PORT,LCD_CS_PIN ,LCD_CS_FUNC);//SPI3-SS0
	
//	    /* PA2 set to GPIO-Output LCD_CS-* */
//    (void)GPIO_StructInit(&stcGpioInit);
//		stcGpioInit.u16PinState=PIN_STAT_RST;
//    stcGpioInit.u16PinDir = PIN_DIR_OUT;
//    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
//	 // stcGpioInit.u16PullUp=PIN_PU_ON ;
//    (void)GPIO_Init(LCD_CS_PORT,LCD_CS_PIN, &stcGpioInit);
	
	
	    stc_spi_init_t stcSpiInit;
    stc_spi_delay_t stcSpiDelay;

    /* Enable SPI3 clock */
    FCG_Fcg1PeriphClockCmd(FCG1_PERIPH_SPI3, ENABLE);
    /************************* Configure SPI3***************************/
SPI_StructInit(&stcSpiInit);
    stcSpiInit.u32WireMode = SPI_4_WIRE;
    stcSpiInit.u32TransMode = SPI_FULL_DUPLEX;
    stcSpiInit.u32MasterSlave = SPI_MASTER;
    stcSpiInit.u32Parity = SPI_PARITY_INVD;
    stcSpiInit.u32SpiMode = SPI_MD_0;
    stcSpiInit.u32BaudRatePrescaler = SPI_BR_CLK_DIV2;
    stcSpiInit.u32DataBits = SPI_DATA_SIZE_8BIT;
    stcSpiInit.u32FirstBit = SPI_FIRST_MSB;
    stcSpiInit.u32SuspendMode = SPI_COM_SUSP_FUNC_OFF;
    stcSpiInit.u32FrameLevel = SPI_1_FRAME;
    (void)SPI_Init(CM_SPI3, &stcSpiInit);

    SPI_DelayStructInit(&stcSpiDelay);
    stcSpiDelay.u32IntervalDelay = SPI_INTERVAL_TIME_1SCK;
    stcSpiDelay.u32ReleaseDelay = SPI_RELEASE_TIME_1SCK;
    stcSpiDelay.u32SetupDelay = SPI_SETUP_TIME_1SCK;
    (void)SPI_DelayTimeConfig(CM_SPI3, &stcSpiDelay);

    /* SPI loopback function configuration */
    SPI_SetLoopbackMode(CM_SPI3, SPI_LOOPBACK_INVD);
    /* SPI parity check error self diagnosis configuration */
    SPI_ParityCheckCmd(CM_SPI3, DISABLE);
    /* SPI valid SS signal configuration */
    SPI_SSPinSelect(CM_SPI3, SPI_PIN_SS0);
    /* SPI SS signal valid level configuration */
    SPI_SetSSValidLevel(CM_SPI3, SPI_PIN_SS0, SPI_SS_VALID_LVL_LOW);
    /* Enable SPI3 */
    SPI_Cmd(CM_SPI3, ENABLE);
	
	
	
	
	
	
	
	
	


	 GPIO_SetPins(LCD_RESET_PORT, LCD_RESET_PIN);   //复位屏幕  拉高 拉低  在拉高 低电平有效
	 DDL_DelayMS (1);
	 GPIO_ResetPins(LCD_RESET_PORT, LCD_RESET_PIN);
	 DDL_DelayMS (10);
	 GPIO_SetPins(LCD_RESET_PORT, LCD_RESET_PIN);
	 DDL_DelayMS (120);

	


	
	LCD_WR_REG(0x11);     //Sleep out
	DDL_DelayMS(120);                //Delay 120ms
	LCD_WR_REG(0xB1);     //Normal mode
	LCD_WR_DATA8(0x05);    
	LCD_WR_DATA8(0x3C);   
	LCD_WR_DATA8(0x3C);   
	LCD_WR_REG(0xB2);     //Idle mode
	LCD_WR_DATA8(0x05);   
	LCD_WR_DATA8(0x3C);   
	LCD_WR_DATA8(0x3C);   
	LCD_WR_REG(0xB3);     //Partial mode
	LCD_WR_DATA8(0x05);   
	LCD_WR_DATA8(0x3C);   
	LCD_WR_DATA8(0x3C);   
	LCD_WR_DATA8(0x05);   
	LCD_WR_DATA8(0x3C);   
	LCD_WR_DATA8(0x3C);   
	LCD_WR_REG(0xB4);     //Dot inversion
	LCD_WR_DATA8(0x03);   
	LCD_WR_REG(0xC0);     //AVDD GVDD
	LCD_WR_DATA8(0xAB);   
	LCD_WR_DATA8(0x0B);   
	LCD_WR_DATA8(0x04);   
	LCD_WR_REG(0xC1);     //VGH VGL
	LCD_WR_DATA8(0xC5);   //C0
	LCD_WR_REG(0xC2);     //Normal Mode
	LCD_WR_DATA8(0x0D);   
	LCD_WR_DATA8(0x00);   
	LCD_WR_REG(0xC3);     //Idle
	LCD_WR_DATA8(0x8D);   
	LCD_WR_DATA8(0x6A);   
	LCD_WR_REG(0xC4);     //Partial+Full
	LCD_WR_DATA8(0x8D);   
	LCD_WR_DATA8(0xEE);   
	LCD_WR_REG(0xC5);     //VCOM
	LCD_WR_DATA8(0x0F);   
	LCD_WR_REG(0xE0);     //positive gamma
	LCD_WR_DATA8(0x07);   
	LCD_WR_DATA8(0x0E);   
	LCD_WR_DATA8(0x08);   
	LCD_WR_DATA8(0x07);   
	LCD_WR_DATA8(0x10);   
	LCD_WR_DATA8(0x07);   
	LCD_WR_DATA8(0x02);   
	LCD_WR_DATA8(0x07);   
	LCD_WR_DATA8(0x09);   
	LCD_WR_DATA8(0x0F);   
	LCD_WR_DATA8(0x25);   
	LCD_WR_DATA8(0x36);   
	LCD_WR_DATA8(0x00);   
	LCD_WR_DATA8(0x08);   
	LCD_WR_DATA8(0x04);   
	LCD_WR_DATA8(0x10);   
	LCD_WR_REG(0xE1);     //negative gamma
	LCD_WR_DATA8(0x0A);   
	LCD_WR_DATA8(0x0D);   
	LCD_WR_DATA8(0x08);   
	LCD_WR_DATA8(0x07);   
	LCD_WR_DATA8(0x0F);   
	LCD_WR_DATA8(0x07);   
	LCD_WR_DATA8(0x02);   
	LCD_WR_DATA8(0x07);   
	LCD_WR_DATA8(0x09);   
	LCD_WR_DATA8(0x0F);   
	LCD_WR_DATA8(0x25);   
	LCD_WR_DATA8(0x35);   
	LCD_WR_DATA8(0x00);   
	LCD_WR_DATA8(0x09);   
	LCD_WR_DATA8(0x04);   
	LCD_WR_DATA8(0x10);
		 
	LCD_WR_REG(0xFC);    
	LCD_WR_DATA8(0x80);  
		
	LCD_WR_REG(0x3A);     
	LCD_WR_DATA8(0x05);   
	LCD_WR_REG(0x36);
	if(USE_HORIZONTAL==0)LCD_WR_DATA8(0x08);
	else if(USE_HORIZONTAL==1)LCD_WR_DATA8(0xC8);
	else if(USE_HORIZONTAL==2)LCD_WR_DATA8(0x78);
	else LCD_WR_DATA8(0xA8);   
	LCD_WR_REG(0x21);     //Display inversion
	LCD_WR_REG(0x29);     //Display on
	LCD_WR_REG(0x2A);     //Set Column Address
	LCD_WR_DATA8(0x00);   
	LCD_WR_DATA8(0x1A);  //26  
	LCD_WR_DATA8(0x00);   
	LCD_WR_DATA8(0x69);   //105 
	LCD_WR_REG(0x2B);     //Set Page Address
	LCD_WR_DATA8(0x00);   
	LCD_WR_DATA8(0x01);    //1
	LCD_WR_DATA8(0x00);   
	LCD_WR_DATA8(0xA0);    //160
	LCD_WR_REG(0x2C); 
}








