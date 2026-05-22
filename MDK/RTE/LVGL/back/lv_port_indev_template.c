/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_indev_template.h"
#include "main.h"
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void touchpad_init(void);
static void touchpad_read(lv_indev_t * indev, lv_indev_data_t * data);
static bool touchpad_is_pressed(void);
static void touchpad_get_xy(int32_t * x, int32_t * y);

static void mouse_init(void);
static void mouse_read(lv_indev_t * indev, lv_indev_data_t * data);
static bool mouse_is_pressed(void);
static void mouse_get_xy(int32_t * x, int32_t * y);

static void keypad_init(void);
static void keypad_read(lv_indev_t * indev, lv_indev_data_t * data);
static uint32_t keypad_get_key(void);

static void encoder_init(void);
static void encoder_read(lv_indev_t * indev, lv_indev_data_t * data);
static void encoder_handler(void);

static void button_init(void);
static void button_read(lv_indev_t * indev, lv_indev_data_t * data);
static int8_t button_get_pressed_id(void);
static bool button_is_pressed(uint8_t id);

/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t * indev_touchpad;
lv_indev_t * indev_mouse;
lv_indev_t * indev_keypad;
lv_indev_t * indev_encoder;
lv_indev_t * indev_button;

static int32_t encoder_diff;
static lv_indev_state_t encoder_state;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_indev_init(void)
{
//    /**
//     * Here you will find example implementation of input devices supported by LittelvGL:
//     *  - Touchpad
//     *  - Mouse (with cursor support)
//     *  - Keypad (supports GUI usage only with key)
//     *  - Encoder (supports GUI usage only with: left, right, push)
//     *  - Button (external buttons to press points on the screen)
//     *
//     *  The `..._read()` function are only examples.
//     *  You should shape them according to your hardware
//     */

//    /*------------------
//     * Touchpad
//     * -----------------*/

//    /*Initialize your touchpad if you have*/
//    touchpad_init();

//    /*Register a touchpad input device*/
//    indev_touchpad = lv_indev_create();
//    lv_indev_set_type(indev_touchpad, LV_INDEV_TYPE_POINTER);
//    lv_indev_set_read_cb(indev_touchpad, touchpad_read);

//    /*------------------
//     * Mouse
//     * -----------------*/

//    /*Initialize your mouse if you have*/
//    mouse_init();

//    /*Register a mouse input device*/
//    indev_mouse = lv_indev_create();
//    lv_indev_set_type(indev_mouse, LV_INDEV_TYPE_POINTER);
//    lv_indev_set_read_cb(indev_mouse, mouse_read);

//    /*Set cursor. For simplicity set a HOME symbol now.*/
//    lv_obj_t * mouse_cursor = lv_image_create(lv_screen_active());
//    lv_image_set_src(mouse_cursor, LV_SYMBOL_HOME);
//    lv_indev_set_cursor(indev_mouse, mouse_cursor);

//    /*------------------
//     * Keypad
//     * -----------------*/

//    /*Initialize your keypad or keyboard if you have*/
//    keypad_init();

//    /*Register a keypad input device*/
//    indev_keypad = lv_indev_create();
//    lv_indev_set_type(indev_keypad, LV_INDEV_TYPE_KEYPAD);
//    lv_indev_set_read_cb(indev_keypad, keypad_read);

//    /*Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
//     *add objects to the group with `lv_group_add_obj(group, obj)`
//     *and assign this input device to group to navigate in it:
//     *`lv_indev_set_group(indev_keypad, group);`*/

    /*------------------
     * Encoder
     * -----------------*/

    /*Initialize your encoder if you have*/
    encoder_init();

    /*Register a encoder input device*/
		
    indev_encoder = lv_indev_create();  //创建indev 
    lv_indev_set_type(indev_encoder, LV_INDEV_TYPE_ENCODER);   //设置为旋转编码器
    lv_indev_set_read_cb(indev_encoder, encoder_read);   //设置旋转编码器的状态回调函数
    /*Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
     *add objects to the group with `lv_group_add_obj(group, obj)`
     *and assign this input device to group to navigate in it:
     *`lv_indev_set_group(indev_encoder, group);`*/
//		 lv_group_t *group = lv_group_create();                 // 创建一个组
//   
//		lv_group_add_obj(group, objects.bar);
//		lv_group_add_obj(group, objects.bar2);
//		// 把滑块加入组中
//		lv_indev_set_group(indev_encoder, group);             // 让编码器输入设备控制这个组
//		 
		 

//    /*------------------
//     * Button
//     * -----------------*/

//    /*Initialize your button if you have*/
//    button_init();

//    /*Register a button input device*/
//    indev_button = lv_indev_create();
//    lv_indev_set_type(indev_button, LV_INDEV_TYPE_BUTTON);
//    lv_indev_set_read_cb(indev_button, button_read);

//    /*Assign buttons to points on the screen*/
//    static const lv_point_t btn_points[2] = {
//        {10, 10},   /*Button 0 -> x:10; y:10*/
//        {40, 100},  /*Button 1 -> x:40; y:100*/
//    };
//    lv_indev_set_button_points(indev_button, btn_points);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*------------------
 * Touchpad
 * -----------------*/

/*Initialize your touchpad*/
static void touchpad_init(void)
{
    /*Your code comes here*/
}

/*Will be called by the library to read the touchpad*/
static void touchpad_read(lv_indev_t * indev_drv, lv_indev_data_t * data)
{
    static int32_t last_x = 0;
    static int32_t last_y = 0;

    /*Save the pressed coordinates and the state*/
    if(touchpad_is_pressed()) {
        touchpad_get_xy(&last_x, &last_y);
        data->state = LV_INDEV_STATE_PRESSED;   
    }
    else {
        data->state = LV_INDEV_STATE_RELEASED;
    }

    /*Set the last pressed coordinates*/
    data->point.x = last_x;
    data->point.y = last_y;
}

/*Return true is the touchpad is pressed*/
static bool touchpad_is_pressed(void)
{
    /*Your code comes here*/

    return false;
}

/*Get the x and y coordinates if the touchpad is pressed*/
static void touchpad_get_xy(int32_t * x, int32_t * y)
{
    /*Your code comes here*/

    (*x) = 0;
    (*y) = 0;
}

/*------------------
 * Mouse
 * -----------------*/

/*Initialize your mouse*/
static void mouse_init(void)
{
    /*Your code comes here*/
}

/*Will be called by the library to read the mouse*/
static void mouse_read(lv_indev_t * indev_drv, lv_indev_data_t * data)
{
    /*Get the current x and y coordinates*/
    mouse_get_xy(&data->point.x, &data->point.y);

    /*Get whether the mouse button is pressed or released*/
    if(mouse_is_pressed()) {
        data->state = LV_INDEV_STATE_PRESSED;
    }
    else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

/*Return true is the mouse button is pressed*/
static bool mouse_is_pressed(void)
{
    /*Your code comes here*/

    return false;
}

/*Get the x and y coordinates if the mouse is pressed*/
static void mouse_get_xy(int32_t * x, int32_t * y)
{
    /*Your code comes here*/

    (*x) = 0;
    (*y) = 0;
}

/*------------------
 * Keypad
 * -----------------*/

/*Initialize your keypad*/
static void keypad_init(void)
{
    /*Your code comes here*/
}

/*Will be called by the library to read the mouse*/
static void keypad_read(lv_indev_t * indev_drv, lv_indev_data_t * data)
{
    static uint32_t last_key = 0;

    /*Get the current x and y coordinates*/
    mouse_get_xy(&data->point.x, &data->point.y);

    /*Get whether the a key is pressed and save the pressed key*/
    uint32_t act_key = keypad_get_key();
    if(act_key != 0) {
        data->state = LV_INDEV_STATE_PRESSED;

        /*Translate the keys to LVGL control characters according to your key definitions*/
        switch(act_key) {
            case 1:
                act_key = LV_KEY_NEXT;
                break;
            case 2:
                act_key = LV_KEY_PREV;
                break;
            case 3:
                act_key = LV_KEY_LEFT;
                break;
            case 4:
                act_key = LV_KEY_RIGHT;
                break;
            case 5:
                act_key = LV_KEY_ENTER;
                break;
        }

        last_key = act_key;
    }
    else {
        data->state = LV_INDEV_STATE_RELEASED;
    }

    data->key = last_key;
}

/*Get the currently being pressed key.  0 if no key is pressed*/
static uint32_t keypad_get_key(void)
{
    /*Your code comes here*/

    return 0;
}

void INT_SRC_GPIO_PB08_IrqCallback(void)
{
//		INTC_IntCmd(INTC_INT9,ENABLE);   //失能中断
	
	
}

void INT_SRC_GPIO_PB09_IrqCallback(void)
{
//	INTC_IntCmd(INTC_INT9, DISABLE);   //失能中断
	
	
	 if(GPIO_ReadInputPins(GPIO_PORT_B,GPIO_PIN_09)==PIN_RESET)
	 {
		 DDL_DelayUS(1);
		 if(GPIO_ReadInputPins(GPIO_PORT_B,GPIO_PIN_09)==PIN_RESET)
		{
				if(GPIO_ReadInputPins(GPIO_PORT_B,GPIO_PIN_08)==PIN_RESET)
				{
					encoder_diff++;
		//			 DDL_Printf("+\r\n");
					
				}else{
					encoder_diff--;
		//			DDL_Printf("-\r\n");
					
				}
			
			
			
		 
		}
	 }
//	
	
}

/*轮询按键检测 */
void LVGL_IN_button(void)
{
	/*
	static uint16_t i=0;
	static uint16_t sf=0;  //释放标记
	if(GPIO_ReadInputPins(GPIO_PORT_B,GPIO_PIN_06)==PIN_RESET	)
	{
		
		i++;
	}else{
		i=0;
		sf=0;
	}
	if(i>10 && sf==0)
	{
		
		 encoder_state = LV_INDEV_STATE_PRESSED;
		
	}
	
	
	*/
	
	
	
}


void INT_SRC_GPIO_PB06_IrqCallback(void)
{
//	DDL_DelayUS(100);
//	 if(GPIO_ReadInputPins(GPIO_PORT_B,GPIO_PIN_06)==PIN_RESET)
//	 {
//		    encoder_state = LV_INDEV_STATE_PRESSED;
//		 	//				 DDL_Printf("A\r\n");
//	 }
//		 
	
}

void INT_SRC_TMR6_1_CMP_B_IrqCallback(void)
{
	
	
}



/*------------------
 * Encoder
 * -----------------*/

/*Initialize your encoder*/
static void encoder_init(void)
{
	/*PB13 TIM6_1_PWMB和PA8 TIM6_1_PWMA*/
	
	//		(void)GPIO_StructInit(&stcGpioInit);

//    stc_gpio_init_t stcGpioInit;
//		(void)GPIO_StructInit(&stcGpioInit);
//		stcGpioInit.u16PullUp = PIN_PU_ON;
//    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
//    (void)GPIO_Init(GPIO_PORT_A, GPIO_PIN_08, &stcGpioInit);
//	
//	
//		(void)GPIO_StructInit(&stcGpioInit);
//		stcGpioInit.u16PullUp = PIN_PU_ON;
//    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
//    (void)GPIO_Init(GPIO_PORT_B, GPIO_PIN_13, &stcGpioInit);
//	
//	
//	  GPIO_SetFunc(GPIO_PORT_B, GPIO_PIN_13,  GPIO_FUNC_3 );
//	  GPIO_SetFunc(GPIO_PORT_A, GPIO_PIN_08,  GPIO_FUNC_3 );
//	
//	
//	    FCG_Fcg2PeriphClockCmd(FCG2_PERIPH_TMR6_1, ENABLE);

//		stc_tmr6_init_t stcTmr6Init;
//	
//    (void)TMR6_StructInit(&stcTmr6Init);
//    /* 3. Initializes position-count unit. */
//    stcTmr6Init.u8CountSrc = TMR6_CNT_SRC_HW;  //外部输入 
//    stcTmr6Init.hw_count.u32CountUpCond   = TMR6_CNT_UP_COND_PWMB_LOW_PWMA_FALLING;   //当 PWMB 为低电平时，PWMA 下降沿触发加计数   增加条件
//    stcTmr6Init.hw_count.u32CountDownCond = TMR6_CNT_UP_COND_PWMB_HIGH_PWMA_FALLING;  //当 PWMB 为高电平时，PWMA 下降沿触发加计数   减少条件
//    (void)TMR6_Init(CM_TMR6_1, &stcTmr6Init);
//    /* 3.1. Enable The TMR6_POS_UNIT counter reset when phase Z rising edge */
//    TMR6_HWClearCondCmd(CM_TMR6_1, TMR6_CLR_COND_TRIGA_RISING, ENABLE);
//    TMR6_HWClearCmd(CM_TMR6_1, ENABLE);

//	
//	
//	  TMR6_SetFilterClockDiv(CM_TMR6_1, TMR6_IO_PWMA, TMR6_FILTER_CLK_DIV64);
//    TMR6_FilterCmd(CM_TMR6_1, TMR6_IO_PWMA, ENABLE);
//	
//		TMR6_Start(CM_TMR6_1);
//		 stc_irq_signin_config_t stcIrq;
//	    /* IRQ sign-in */
//    stcIrq.enIntSrc = INT_SRC_TMR0_1_CMP_B;   
//    stcIrq.enIRQn = INT045_IRQn;
//    stcIrq.pfnCallback = &INT_SRC_TMR6_1_CMP_B_IrqCallback;
//    (void)INTC_IrqSignIn(&stcIrq);
//    /* NVIC config */
//    NVIC_ClearPendingIRQ(INT045_IRQn);
//    NVIC_SetPriority(INT045_IRQn, DDL_IRQ_PRIO_15);
//    NVIC_EnableIRQ(INT045_IRQn);
//	
	
	
	
	
	    /* GPIO initialize */
    stc_gpio_init_t stcGpioInit;
	
		(void)GPIO_StructInit(&stcGpioInit);
		stcGpioInit.u16ExtInt = PIN_EXTINT_ON;
    stcGpioInit.u16PinDir = PIN_DIR_IN;
		stcGpioInit.u16PullUp = PIN_PU_ON;
    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
    (void)GPIO_Init(GPIO_PORT_B, GPIO_PIN_08, &stcGpioInit);
	
	
		(void)GPIO_StructInit(&stcGpioInit);
		stcGpioInit.u16ExtInt = PIN_EXTINT_ON;
    stcGpioInit.u16PinDir = PIN_DIR_IN;
		stcGpioInit.u16PullUp = PIN_PU_ON;
    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
    (void)GPIO_Init(GPIO_PORT_B, GPIO_PIN_09, &stcGpioInit);
		
		(void)GPIO_StructInit(&stcGpioInit);
		stcGpioInit.u16ExtInt = PIN_EXTINT_ON;
    stcGpioInit.u16PinDir = PIN_DIR_IN;
		stcGpioInit.u16PullUp = PIN_PU_ON;
    stcGpioInit.u16PinAttr = PIN_ATTR_DIGITAL;
    (void)GPIO_Init(GPIO_PORT_B, GPIO_PIN_06, &stcGpioInit);
	
		stc_extint_init_t stcExtIntInit;
    stc_irq_signin_config_t stcIrqSignConfig;
  /* ExtInt config */
    (void)EXTINT_StructInit(&stcExtIntInit);
    stcExtIntInit.u32Edge = EXTINT_TRIG_FALLING ;  //下降沿触发  
    (void)EXTINT_Init(EXTINT_CH09, &stcExtIntInit);

    /* IRQ sign-in */
    stcIrqSignConfig.enIntSrc    = INT_SRC_PORT_EIRQ9 ;
    stcIrqSignConfig.enIRQn      = INT009_IRQn;
    stcIrqSignConfig.pfnCallback = &INT_SRC_GPIO_PB09_IrqCallback;
    (void)INTC_IrqSignIn(&stcIrqSignConfig);

    /* Disable all */
    INTC_IntCmd(INTC_INT9, ENABLE);   //使能中断
    /* NVIC config */
    NVIC_ClearPendingIRQ(INT009_IRQn);  //清除下事件 
		
    NVIC_SetPriority(INT009_IRQn, DDL_IRQ_PRIO_DEFAULT); //配置优先级
		NVIC_EnableIRQ(INT009_IRQn); // 你没贴这行，必须补上！
		
		
		  /* ExtInt config */
    (void)EXTINT_StructInit(&stcExtIntInit);
    stcExtIntInit.u32Edge = EXTINT_TRIG_RISING  ;  //上升沿触发  
    (void)EXTINT_Init(EXTINT_CH08, &stcExtIntInit);

    /* IRQ sign-in */
    stcIrqSignConfig.enIntSrc    = INT_SRC_PORT_EIRQ8 ;
    stcIrqSignConfig.enIRQn      = INT008_IRQn;
    stcIrqSignConfig.pfnCallback = &INT_SRC_GPIO_PB08_IrqCallback;
    (void)INTC_IrqSignIn(&stcIrqSignConfig);

    /* Disable all */
    INTC_IntCmd(INTC_INT8, ENABLE);   //使能中断
    /* NVIC config */
    NVIC_ClearPendingIRQ(INT008_IRQn);  //清除下事件 
		
    NVIC_SetPriority(INT008_IRQn, DDL_IRQ_PRIO_DEFAULT); //配置优先级
		NVIC_EnableIRQ(INT008_IRQn); // 你没贴这行，必须补上！
		
		
				  /* ExtInt config */
    (void)EXTINT_StructInit(&stcExtIntInit);
    stcExtIntInit.u32Edge = EXTINT_TRIG_FALLING  ;  //下降沿触发     
    (void)EXTINT_Init(EXTINT_CH06, &stcExtIntInit);

    /* IRQ sign-in */
    stcIrqSignConfig.enIntSrc    = INT_SRC_PORT_EIRQ6 ;
    stcIrqSignConfig.enIRQn      = INT006_IRQn;
    stcIrqSignConfig.pfnCallback = &INT_SRC_GPIO_PB06_IrqCallback;
    (void)INTC_IrqSignIn(&stcIrqSignConfig);

    /* Disable all */
    INTC_IntCmd(INTC_INT6, ENABLE);   //使能中断
    /* NVIC config */
    NVIC_ClearPendingIRQ(INT006_IRQn);  //清除下事件 
		
    NVIC_SetPriority(INT006_IRQn, DDL_IRQ_PRIO_DEFAULT); //配置优先级
		NVIC_EnableIRQ(INT006_IRQn); // 你没贴这行，必须补上！
		
		
		
	
	
    /*Your code comes here*/
}

/*Will be called by the library to read the encoder*/
static void encoder_read(lv_indev_t * indev_drv, lv_indev_data_t * data)
{
//		DDL_Printf("%d\r\n",encoder_diff);
    data->enc_diff = encoder_diff;
	
	
	switch(Edit_Mode_Controls)
	{
		case 1:
		config.fan_tem+=encoder_diff;
		if(config.fan_tem<10)
		{
//		lv_label_set_text_fmt(objects.text, "0%d", config.fan_tem);
		}else{
//		lv_label_set_text_fmt(objects.text, "%d", config.fan_tem);
		}
		break;
		
	}

	
	
	
	encoder_diff=0;
	if(GPIO_ReadInputPins(GPIO_PORT_B,GPIO_PIN_06)==PIN_RESET	)
	{
	
		 data->state=LV_INDEV_STATE_PRESSED;
	}else {
		
		data->state=LV_INDEV_STATE_RELEASED;
	}
   
		

}

/*Call this function in an interrupt to process encoder events (turn, press)*/
static void encoder_handler(void)
{
    /*Your code comes here*/

//    encoder_diff += 0;
//   encoder_state = LV_INDEV_STATE_RELEASED;
}

/*------------------
 * Button
 * -----------------*/

/*Initialize your buttons*/
static void button_init(void)
{
    /*Your code comes here*/
}

/*Will be called by the library to read the button*/
static void button_read(lv_indev_t * indev_drv, lv_indev_data_t * data)
{

    static uint8_t last_btn = 0;

    /*Get the pressed button's ID*/
    int8_t btn_act = button_get_pressed_id();

    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PRESSED;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_RELEASED;
    }

    /*Save the last pressed button's ID*/
    data->btn_id = last_btn;
}

/*Get ID  (0, 1, 2 ..) of the pressed button*/
static int8_t button_get_pressed_id(void)
{
    uint8_t i;

    /*Check to buttons see which is being pressed (assume there are 2 buttons)*/
    for(i = 0; i < 2; i++) {
        /*Return the pressed button's ID*/
        if(button_is_pressed(i)) {
            return i;
        }
    }

    /*No button pressed*/
    return -1;
}

/*Test if `id` button is pressed or not*/
static bool button_is_pressed(uint8_t id)
{

    /*Your code comes here*/

    return false;
}

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
