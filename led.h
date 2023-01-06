/*
 * @Author: Panyan
 * @Date: 2022-12-28 20:21:36
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-12-28 21:40:06
 * @FilePath: \Ð¡Ðí\led.h
 */
#ifndef __LED_H_
#define __LED_H_

#include "publish.h"
sbit LED1=P2^5;
sbit LED2=P2^6;
sbit LED3=P2^7;
u8 LED_on(u8 num);
void LED_off(u8 num);


#endif // !__LED_H_
