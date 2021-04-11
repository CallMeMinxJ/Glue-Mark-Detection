/**
 * @file      control.c
 * @brief     关于全局控制相关的函数
 * @author    MINXJ (CallMeMinxJ@outlook.com)
 * @version   0.1
 * @date      2021-04-11
 * 
 * @copyright Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 *            Everyone is permitted to copy and distribute verbatim copies
 *            of this license document, but changing it is not allowed.
 * 
 */

#include "system.h"
#include "control.h"
#include "hw_key.h"
#include "hw_lcd.h"
#include "hw_lcd_usart1.h"

/**
 * @brief     全局初始化
 */
void Global_Init (void)
{
    Key_Init();//按键初始化
    LCD_Usart1_Init(115200);//设置驱动LCD的串口1的波特率
    LCD_Init();//LCD屏幕初始化
}
