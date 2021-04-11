#ifndef _KEY_H_
#define _KEY_H_

//按键GPIO
#define Key_0	!GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)
#define Key_1	!GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)
#define Key_2	 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)
//按键编码
#define No_Key_Num	0
#define Key_0_Num	1
#define Key_1_Num	2
#define Key_2_Num	3
//按键检测模式
#define Mode_cnt    1
#define Mode_Ucnt   0
//消抖时间
#define Key_Debounce_Time   5

//函数声明部分
void Key_Init(void);
uint8_t Key_Scan(uint8_t mode);
void Key_Function(uint8_t Key_Num);

#endif
