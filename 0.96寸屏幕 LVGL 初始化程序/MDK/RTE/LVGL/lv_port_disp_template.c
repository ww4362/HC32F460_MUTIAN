/**
 * @file lv_port_disp_templ.c
 *
 */

/*Copy this file as "lv_port_disp.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_disp_template.h"
#include <stdbool.h>
#include <main.h>
#include "lcd_init.h" 
/*********************
 *      DEFINES
 *********************/
#ifndef MY_DISP_HOR_RES
//    #warning Please define or replace the macro MY_DISP_HOR_RES with the actual screen width, default value 320 is used for now.
    #define MY_DISP_HOR_RES    160
#endif

#ifndef MY_DISP_VER_RES
//    #warning Please define or replace the macro MY_DISP_VER_RES with the actual screen height, default value 240 is used for now.
    #define MY_DISP_VER_RES    80
#endif

#define BYTE_PER_PIXEL (LV_COLOR_FORMAT_GET_SIZE(LV_COLOR_FORMAT_RGB565)) /*will be 2 for RGB565 */

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void disp_init(void);

static void disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_disp_init(void)
{
    /*-------------------------
     * Initialize your display
     * -----------------------*/
    disp_init();

    /*------------------------------------
     * Create a display and set a flush_cb
     * -----------------------------------*/
    lv_display_t * disp = lv_display_create(MY_DISP_HOR_RES, MY_DISP_VER_RES);
    lv_display_set_flush_cb(disp, disp_flush);

//    /* Example 1
//     * One buffer for partial rendering*/
//    LV_ATTRIBUTE_MEM_ALIGN
//    static uint8_t buf_1_1[MY_DISP_HOR_RES * 10 * BYTE_PER_PIXEL];            /*A buffer for 10 rows*/
//    lv_display_set_buffers(disp, buf_1_1, NULL, sizeof(buf_1_1), LV_DISPLAY_RENDER_MODE_PARTIAL);

    /* Example 2
     * Two buffers for partial rendering
     * In flush_cb DMA or similar hardware should be used to update the display in the background.*/
    LV_ATTRIBUTE_MEM_ALIGN
    static uint8_t buf_2_1[MY_DISP_HOR_RES * 40 * BYTE_PER_PIXEL];

    LV_ATTRIBUTE_MEM_ALIGN
    static uint8_t buf_2_2[MY_DISP_HOR_RES * 40* BYTE_PER_PIXEL];
    lv_display_set_buffers(disp, buf_2_1, buf_2_2, sizeof(buf_2_1), LV_DISPLAY_RENDER_MODE_PARTIAL);

    /* Example 3
     * Two buffers screen sized buffer for double buffering.
     * Both LV_DISPLAY_RENDER_MODE_DIRECT and LV_DISPLAY_RENDER_MODE_FULL works, see their comments*/
//    LV_ATTRIBUTE_MEM_ALIGN
//    static uint8_t buf_3_1[MY_DISP_HOR_RES * MY_DISP_VER_RES * BYTE_PER_PIXEL];

//    LV_ATTRIBUTE_MEM_ALIGN
//    static uint8_t buf_3_2[MY_DISP_HOR_RES * MY_DISP_VER_RES * BYTE_PER_PIXEL];
//    lv_display_set_buffers(disp, buf_3_1, buf_3_2, sizeof(buf_3_1), LV_DISPLAY_RENDER_MODE_DIRECT);

}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static lv_display_t *g_disp_flush_drv = NULL;

static void DMA_TransCompleteCallback(void)
{
   // enRxCompleteFlag = SET;
  //  DMA_ClearTransCompleteStatus(DMA_UNIT, DMA_RX_INT_CH);
// GPIO_TogglePins( GPIO_PORT_B,GPIO_PIN_09);
	    lv_display_flush_ready(g_disp_flush_drv);//写入完成调用这个
}





/*Initialize your display and the required peripherals.*/
static void disp_init(void)
{
		 stc_dma_init_t stcDmaInit;
		   /* DMA configuration */
    FCG_Fcg0PeriphClockCmd(FCG0_PERIPH_DMA1 | FCG0_PERIPH_AOS, ENABLE);

    AOS_SetTriggerEventSrc(AOS_DMA1_0, EVT_SRC_SPI3_SPTI);
		
			    /* IRQ sign-in */
		stc_irq_signin_config_t stcIrq;
    stcIrq.enIntSrc = INT_SRC_DMA1_TC0;   
    stcIrq.enIRQn = INT039_IRQn;
    stcIrq.pfnCallback = &DMA_TransCompleteCallback;
    (void)INTC_IrqSignIn(&stcIrq);
		    /* NVIC config */
    NVIC_ClearPendingIRQ(INT039_IRQn);
    NVIC_SetPriority(INT039_IRQn, DDL_IRQ_PRIO_15);
    NVIC_EnableIRQ(INT039_IRQn);
		
		

    DMA_Cmd(CM_DMA1, ENABLE);
		
//    /* DMA receive NVIC configure */
//    stcIrqSignConfig.enIntSrc    = DMA_RX_INT_SRC;
//    stcIrqSignConfig.enIRQn      = DMA_RX_IRQ_NUM;
//    stcIrqSignConfig.pfnCallback = &DMA_TransCompleteCallback;
//    (void)INTC_IrqSignIn(&stcIrqSignConfig);
//    NVIC_ClearPendingIRQ(stcIrqSignConfig.enIRQn);
//    NVIC_SetPriority(stcIrqSignConfig.enIRQn, DDL_IRQ_PRIO_DEFAULT);
//    NVIC_EnableIRQ(stcIrqSignConfig.enIRQn);

//    /* Enable DMA and channel */
//    DMA_Cmd(DMA_UNIT, ENABLE);
//    DMA_ChCmd(DMA_UNIT, DMA_TX_CH, ENABLE);
//    DMA_ChCmd(DMA_UNIT, DMA_RX_CH, ENABLE);
//		
		
	
	
    /*You code here*/
}

volatile bool disp_flush_enabled = true;

/* Enable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_enable_update(void)
{
    disp_flush_enabled = true;
}

/* Disable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_disable_update(void)
{
    disp_flush_enabled = false;
}

/*Flush the content of the internal buffer the specific area on the display.
 *`px_map` contains the rendered image as raw pixel map and it should be copied to `area` on the display.
 *You can use DMA or any hardware acceleration to do this operation in the background but
 *'lv_display_flush_ready()' has to be called when it's finished.*/
static void disp_flush(lv_display_t * disp_drv, const lv_area_t * area, uint8_t * px_map)
{
 if(disp_flush_enabled) {
//			  GPIO_TogglePins( GPIO_PORT_B,GPIO_PIN_08);
	 
			LCD_Address_Set(area->x1, area->y1, area->x2, area->y2);  //设置光标位置  

//DDL_Printf("%d\r\n",area->x1);
//	DDL_Printf("%d\r\n",area->y1);
//	DDL_Printf("%d\r\n",area->x2);
//	DDL_Printf("%d\r\n",area->y2);
	 
			MODIFY_REG32(LCD_SPI->CFG2, SPI_CFG2_DSIZE, SPI_DATA_SIZE_8BIT);
	 
	 
	 
			//uint32_t size_in_bytes = (area->x2 - area->x1 + 1) * (area->y2 - area->y1 + 1) * 2; //计算发送大小
	  g_disp_flush_drv = disp_drv;
//	 
//	 
//	 
//	 
	 		 stc_dma_init_t stcDmaInit;
		   /* DMA configuration */
    (void)DMA_StructInit(&stcDmaInit);
		stcDmaInit.u32IntEn = DMA_INT_ENABLE;
    stcDmaInit.u32BlockSize  = 1UL;
    stcDmaInit.u32TransCount = (area->x2 - area->x1 + 1) * (area->y2 - area->y1 + 1) * 2;
    stcDmaInit.u32DataWidth  = DMA_DATAWIDTH_8BIT;
    /* Configure TX */
    stcDmaInit.u32SrcAddrInc  = DMA_SRC_ADDR_INC;
    stcDmaInit.u32DestAddrInc = DMA_DEST_ADDR_FIX;
    stcDmaInit.u32SrcAddr     = (uint32_t) px_map;
    stcDmaInit.u32DestAddr    = (uint32_t)(&LCD_SPI-> DR);
    if (LL_OK != DMA_Init(CM_DMA1, DMA_CH0, &stcDmaInit)) {
        for (;;) {
        }
    }
	 
//	 
	 (void)DMA_ChCmd(CM_DMA1, DMA_CH0, ENABLE);
	 DMA_MxChSWTrigger(CM_DMA1,DMA_MX_CH0); //  软件触发一下写入
	 
			
//			for(int i=0;i<MY_DISP_HOR_RES * 10 * BYTE_PER_PIXEL;i++)
//			{		

//				
//			LCD_Writ_Bus(*px_map);
//				px_map++;
//			
//			}
//			
//        /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one*/

//        int32_t x;
//        int32_t y;
//        for(y = area->y1; y <= area->y2; y++) {
//            for(x = area->x1; x <= area->x2; x++) {
//                /*Put a pixel to the display. For example:*/
//                /*put_px(x, y, *px_map)*/
//							//这里添加画点
//							LCD_DrawPoint(x,y,*px_map);
//							
//                px_map++;
//            }
//        }

    }

    /*IMPORTANT!!!
     *Inform the graphics library that you are ready with the flushing*/
  //lv_display_flush_ready(disp_drv);
}

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
