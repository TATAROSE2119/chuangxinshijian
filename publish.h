/*
 * @Author: Panyan
 * @Date: 2022-12-28 20:29:23
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-12-28 20:54:31
 * @FilePath: \小许\publish.h
 */
#ifndef __PUBLISH_H
#define __PUBLISH_H

#include "reg52.h"
#include "INTRINS.H"

typedef unsigned int u16;	//对系统默认数据类型进行重定义
typedef unsigned char u8;


void Delay_ms(u16 ms);		//@11.0592MHz
void Delay_10us(u8 ten_us);		//@11.0592MHz

#endif // !__PUBLISH_H