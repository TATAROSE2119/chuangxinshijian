/*
 * @Author: Panyan
 * @Date: 2023-01-01 22:20:29
 * @LastEditors: Do not edit
 * @LastEditTime: 2023-01-01 22:24:13
 * @FilePath: \����ʵ��\uart.h
 */
#ifndef _uart_H
#define _uart_H

#include "publish.h"
#include "stdio.h"


#define UART_REC_LEN  			50  	//�����������ֽ��� 50

extern u8  UART_RX_BUF[UART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 UART_RX_STA;         		//����״̬���	


typedef enum 
{
	DISABLE = 0, ENABLE = !DISABLE
}FunctionalState;

void UART_Init(void);
void UART_Cmd(FunctionalState ensta);
void UART_SendData(u8 dat);
void UART_SendString(u8 *pbuf);


#endif
