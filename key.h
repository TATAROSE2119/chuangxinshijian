/*
 * @Author: Panyan
 * @Date: 2022-12-28 20:21:46
 * @LastEditors: Do not edit
 * @LastEditTime: 2023-01-01 21:03:56
 * @FilePath: \undefinedd:\kEILPROJECT\Ð¡Ðí\key.h
 */
#ifndef __KEY_H_
#define __KEY_H_

#include "publish.h"
sbit KEY1=P3^5;
sbit KEY2=P3^6;
sbit KEY3=P3^7;

#define KEY1_PRESS	1
#define KEY2_PRESS	2
#define KEY3_PRESS	3
#define KEY_UNPRESS	0
u8 key_scan(u8 mode);

#endif // !__KEY_H_
