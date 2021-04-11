#ifndef _MENU_H_
#define _MENU_H_

//头文件部分
#include "system.h"

//宏定义部分
#define PAGE0_ITEM_COUNT    3

//全局变量部分
extern uint8_t MENU_PAGE;
extern uint8_t MENU_SELECT;

//函数声明部分
void Display_Menu(uint16_t Background_Color, uint16_t Point_Color);
void Display_Page0(void);

#endif
