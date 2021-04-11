/**
 * @file      menu.c
 * @brief     菜单显示相关函数
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
#include "menu.h"
#include "hw_lcd.h"

/**
 * @brief     用来记录的当前所在页码
 * 前四位记录第几级菜单
 * 后几位记录第几个子项
 * 目前仅用两级菜单
 * 详情见以下代码
 */
uint8_t MENU_PAGE = 0X00;
uint8_t MENU_SELECT = 1;//记录光标选择

/**
 * @brief     菜单显示函数
 * @param     Background_Color - 背景颜色
 * @param     Point_Color - 画笔颜色
 */
void Display_Menu(uint16_t Background_Color, uint16_t Point_Color)
{
    POINT_COLOR=Point_Color;

    //表示停留在总界面
    if((MENU_PAGE & 0X80) == 0X00)
    {
        Display_Page0();
    }
    //此时表示点击一个子项进入第二级菜单
    else
    {
        switch(MENU_PAGE & 0X0F)
        {

        }
    }

    //选中子项
    LCD_DrawRectangle(20,55+(MENU_SELECT-1)*30,250,85+(MENU_SELECT-1)*30);

    LCD_WriteRAM_Prepare();//刷新缓存
}

/**
 * @brief     显示根目录菜单
 */
void Display_Page0(void)
{
    LCD_ShowString(100,30,210,24,24,"Glue Mark Detection"); 

    //显示菜单子项
    LCD_ShowString(30,60,210,24,24,"Global Init");
    LCD_ShowString(30,90,210,24,24,"WIFI Setting");
    LCD_ShowString(30,120,210,24,24,"OpenVC Setting");
}
