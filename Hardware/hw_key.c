/**
 * @file      hw_key.c
 * @brief     关于按键的C文件
 * @author    MINXJ (CallMeMinxJ@outlook.com)
 * @version   0.1
 * @date      2021-04-11
 * 
 * @copyright Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 *            Everyone is permitted to copy and distribute verbatim copies
 *            of this license document, but changing it is not allowed.
 * 
 */


//头文件部分
#include "system.h"
#include "hw_key.h"
#include "menu.h"
#include "hw_lcd.h"

/**
 * @brief     按键初始化
 */
void Key_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4|GPIO_Pin_3;//KEY0-KEY1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIOE4,3

	//初始化 WK_UP-->GPIOA.0	  下拉输入
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0设置成输入，默认下拉	  
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.0

    //TEST测试按键用 LED1
    GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin	=	GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_Out_PP;//推挽输出
	GPIO_Init(GPIOE,&GPIO_InitStructure);
    
}

/**
 * @brief     按键检测函数
 * @param     mode - 选择按键检测的模式
 *              Mode_cnt - 连续监测
 *              Mode_Ucnt - 非连续监测
 * @return    uint8_t 为按键编码
 */
uint8_t Key_Scan(uint8_t mode)
{
    static int8_t KEY_STATE = 1;//状态标志
    int8_t cnt   = 0,//防止误触
           test1 = 0,//检测1
           test2 = 0;//检测2
    if (mode == Mode_cnt)   KEY_STATE = 1;
    
    //初次检测
    if (Key_0)	test1 = Key_0_Num	,cnt++;
    if (Key_1)	test1 = Key_1_Num	,cnt++;
    if (Key_2)	test1 = Key_2_Num	,cnt++;
    
    if (cnt==1 && KEY_STATE)
    {
        cnt       = 0;
        KEY_STATE = 0;//判断状态
        Delay_ms(Key_Debounce_Time);//延迟消抖
        
        //第二次检测
        if (Key_0)  test2 = Key_0_Num	,cnt++;
        if (Key_1)	test2 = Key_1_Num	,cnt++;
        if (Key_2)	test2 = Key_2_Num	,cnt++;
        if (cnt==1 && test1 == test2) return test2;
    }
    else
        if (!cnt)  KEY_STATE = 1;//更新状态
    return  No_Key_Num;
}

/**
 * @brief     实现按键对应功能
 * @param     Key_Num - 按下的按键编码
 */
void Key_Function(uint8_t Key_Num)
{
    switch(Key_Num)
    {
        case 1  :
            //在根目录
            if((MENU_PAGE & 0X80) == 0X00)
            {
                if(MENU_SELECT<3) MENU_SELECT++;
                else MENU_SELECT = 1;
            }
            else
            {
                switch(MENU_PAGE & 0X0F)
                {
                    case 1:break;
                    case 2:break;
                    case 3:break;
                }
            }
            PEout(5) = !PEout(5);
            LCD_Clear(WHITE);//清屏函数
            break;
        case 2  :
            MENU_PAGE &= 0XF0;
            //菜单返回上级
            MENU_PAGE = ((0XF0 & MENU_PAGE)<<1) + (MENU_PAGE & 0X0F);
            LCD_Clear(WHITE);//清屏函数
            break;
        case 3  : 
            MENU_PAGE |= MENU_SELECT;
            MENU_PAGE |= 0X80;
            LCD_Clear(WHITE);//清屏函数
            break;
    }
}
