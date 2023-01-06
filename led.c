/*
 * @Author: Panyan
 * @Date: 2022-12-28 20:21:31
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-12-28 22:08:02
 * @FilePath: \Ð¡Ðí\led.c
 */
#include "led.h"

u8 LED_on(u8 num)
{
    switch (num)
    {
    case 1:
        LED1=0;
        return 1;
        break;
    case 2:
        LED2=0;
        return 2;
        break;
    case 3:
        LED3=0;
        return 3;
        break;
    default:
        return 0;
        break;
    }    
}
void LED_off(u8 num)
{
    switch (num)
    {
    case 1:
        LED1=1;
        break;
    case 2:
        LED2=1;
        break;
    case 3:
        LED3=1;
        break;
    default:
        break;
    }    
}