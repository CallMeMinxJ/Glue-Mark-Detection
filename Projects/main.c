/**
 * @file      main.c
 * @brief     胶痕检测项目主函数
 * @author    MINXJ (CallMeMinxJ@outlook.com)
 * @version   0.1
 * @date      2021-03-28
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
#include "menu.h"

int main (void)
{
	Delay_Init();//延迟函数初始化
	Global_Init();//全局初始化
	Nvic_Init();//中断配置

	while(1)
	{
		Key_Function(Key_Scan(Mode_Ucnt));
		Display_Menu(WHITE,RED);
	} 
}
