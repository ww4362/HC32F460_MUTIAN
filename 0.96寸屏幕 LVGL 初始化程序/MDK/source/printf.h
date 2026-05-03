#ifndef __PRINT_H
#define __PRINT_H		

void PrintfInit(void);


typedef struct _Sprintf Sprintf;

struct _Sprintf {
	uint8_t* i;
	uint8_t sendflag;   //发送状态 这个是用于串口绘图的 
	 void (*Usart_send)(Sprintf* self);
	
};
extern  Sprintf Send;


#endif