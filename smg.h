/*
 * @Author: Panyan
 * @Date: 2022-12-28 20:21:23
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-12-28 20:38:20
 * @FilePath: \С��\smg.h
 */
#ifndef __SMG_H_
#define __SMG_H_

#include "publish.h"
#define SMG_A_DP_PORT	P0	//ʹ�ú궨������ܶ����

//���������λѡ�źſ��ƽ�
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
extern u8 gsmg_code[17];

void smg_display(u8 dat[],u8 pos);

#endif