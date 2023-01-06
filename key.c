/*
 * @Author: Panyan
 * @Date: 2022-12-28 20:21:42
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-12-28 21:00:54
 * @FilePath: \С��\key.c
 */
#include "key.h"

u8 key_scan(u8 mode)
{
	static u8 key=1;

	if(mode)key=1;//����ɨ�谴��
	if(key==1&&(KEY1==0||KEY2==0||KEY3==0))//���ⰴ������
	{
		Delay_10us(1000);//����
		key=0;
		if(KEY1==0)
			return KEY1_PRESS;
		else if(KEY2==0)
			return KEY2_PRESS;
		else if(KEY3==0)
			return KEY3_PRESS;
	}
	else if(KEY1==1&&KEY2==1&&KEY3==1)	//�ް�������
	{
		key=1;			
	}
	return KEY_UNPRESS;		
}