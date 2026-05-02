#include "main.h"


int32_t BSP_PRINTF_Preinit(void *vpDevice, uint32_t u32Baudrate);

#define USART CM_USART3
#define Speed 115200


#define TX_PORT GPIO_PORT_B
#define TX_PIN  GPIO_PIN_07
#define TX_FUNC GPIO_FUNC_32

#define RX_PORT GPIO_PORT_B
#define RX_PIN  GPIO_PIN_06
#define RX_FUNC GPIO_FUNC_33
uint8_t iz;


enum cfg{
	day,
	
};




Sprintf Send;
void Usart_send(Sprintf* self)
{
	 DDL_Printf("sc\r\n");
	
}

//static void Girl_init(Girl* self) {
//	
//}




static void INTC_IrqInstalHandler(const stc_irq_signin_config_t *pstcConfig, uint32_t u32Priority)
{
    if (NULL != pstcConfig) {
        (void)INTC_IrqSignIn(pstcConfig);
        NVIC_ClearPendingIRQ(pstcConfig->enIRQn);
        NVIC_SetPriority(pstcConfig->enIRQn, u32Priority);
        NVIC_EnableIRQ(pstcConfig->enIRQn);
    }
}


static void USART_RxError_IrqCallback(void)
{
    (void)USART_ReadData(USART);

    USART_ClearStatus(USART, (USART_FLAG_PARITY_ERR | USART_FLAG_FRAME_ERR | USART_FLAG_OVERRUN));
}

static void USART_RxFull_IrqCallback(void)
{
    uint8_t u8Data = (uint8_t)USART_ReadData(USART);
//DDL_Printf("%d!!\r\n",u8Data);
Send.sendflag =u8Data;



}


void PrintfInit(void)
{

#if (LL_PRINT_ENABLE == DDL_ON)
	
	GPIO_SetFunc(TX_PORT,TX_PIN,TX_FUNC);
	GPIO_SetFunc(RX_PORT,RX_PIN,RX_FUNC);
	
	
	
  DDL_PrintfInit(USART, Speed , BSP_PRINTF_Preinit);

   DDL_Printf("OKKKK!!\r\n");

	
	
	
	stc_irq_signin_config_t stcIrqSigninConfig;
	
	    /* Register RX error IRQ handler && configure NVIC. */
    stcIrqSigninConfig.enIRQn = INT030_IRQn;
    stcIrqSigninConfig.enIntSrc = INT_SRC_USART3_EI;
    stcIrqSigninConfig.pfnCallback = &USART_RxError_IrqCallback;
    INTC_IrqInstalHandler(&stcIrqSigninConfig, DDL_IRQ_PRIO_DEFAULT);

    /* Register RX full IRQ handler && configure NVIC. */
    stcIrqSigninConfig.enIRQn = INT031_IRQn;
    stcIrqSigninConfig.enIntSrc = INT_SRC_USART3_RI;
    stcIrqSigninConfig.pfnCallback = &USART_RxFull_IrqCallback;
    INTC_IrqInstalHandler(&stcIrqSigninConfig, DDL_IRQ_PRIO_DEFAULT);

	  /* Enable RX function */
    USART_FuncCmd(USART, (USART_RX | USART_INT_RX), ENABLE);
	

Send.Usart_send=&Usart_send;
Send.Usart_send(&Send);
Send.i =&iz;

#endif





}




/*
printf
*/
int32_t BSP_PRINTF_Preinit(void *vpDevice, uint32_t u32Baudrate)
{
    uint32_t u32Div;
    float32_t f32Error;
    stc_usart_uart_init_t stcUartInit;
    int32_t i32Ret = LL_ERR_INVD_PARAM; 

    (void)vpDevice;
	
	    FCG_Fcg1PeriphClockCmd(FCG1_PERIPH_USART3, ENABLE);

    if (0UL != u32Baudrate) {
        /* Set TX port function */
     //  GPIO_SetFunc(BSP_PRINTF_PORT, BSP_PRINTF_PIN, BSP_PRINTF_PORT_FUNC);

        /* Enable clock  */
      //  FCG_Fcg1PeriphClockCmd(FCG1_PERIPH_USART3, ENABLE);

        /* Configure UART */
        (void)USART_UART_StructInit(&stcUartInit);
        stcUartInit.u32OverSampleBit = USART_OVER_SAMPLE_8BIT;
        (void)USART_UART_Init(CM_USART3, &stcUartInit, NULL);

        for (u32Div = 0UL; u32Div <= USART_CLK_DIV64; u32Div++) {
            USART_SetClockDiv(CM_USART3, u32Div);
            i32Ret = USART_SetBaudrate(CM_USART3, u32Baudrate, &f32Error);
            if ((LL_OK == i32Ret) && \
                ((-0.025F) <= f32Error) && (f32Error <= 0.025F)) {
                USART_FuncCmd(CM_USART3, USART_TX, ENABLE);
                break;
            } else {
                i32Ret = LL_ERR;
            }
        }
    }

    return i32Ret;
}

