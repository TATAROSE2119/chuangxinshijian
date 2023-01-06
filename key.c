/*
 * @Author: Panyan
 * @Date: 2022-12-28 20:21:42
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-12-28 21:00:54
 * @FilePath: \小许\key.c
 */
#include "key.h"

u8 key_scan(u8 mode)
{
	static u8 key=1;

	if(mode)key=1;//连续扫描按键
	if(key==1&&(KEY1==0||KEY2==0||KEY3==0))//任意按键按下
	{
		Delay_10us(1000);//消抖
		key=0;
		if(KEY1==0)
			return KEY1_PRESS;
		else if(KEY2==0)
			return KEY2_PRESS;
		else if(KEY3==0)
			return KEY3_PRESS;
	}
	else if(KEY1==1&&KEY2==1&&KEY3==1)	//无按键按下
	{
		key=1;			
	}
	return KEY_UNPRESS;		
}