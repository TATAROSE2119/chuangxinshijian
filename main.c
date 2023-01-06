/*
 * @Author: Panyan
 * @Date: 2022-12-28 20:17:38
 * @LastEditors: Do not edit
 * @LastEditTime: 2023-01-01 22:45:21
 * @FilePath: \创新实践\MAIN.C
 */
#include "reg52.h"
#include "publish.h"
#include "led.h"
#include "smg.h"
#include "key.h"
#include "uart.h"
#include "stdio.h"
void Timer0Init(void);		//1�????@11.0592MHz
u16 time_count=0;           //倒�?�???
u16 t0_count=0;             
u8 Digbuff[8];
u8 key_v=0;                 //按键�???
bit key_flag=0;             //按下检�???
u8 led_on_num=0;            //打开的led序号
u8 rec_data;
u8 send_buf[16];


void main(void)
{
    Timer0Init();
    UART_Init();
    Digbuff[1]=0x00;
    Digbuff[2]=0x00;
    Digbuff[3]=0x00;
    Digbuff[4]=0x00;
    Digbuff[5]=0x00;
    Digbuff[6]=0x00;
    Digbuff[7]=0x00;
    Digbuff[8]=0x00;
    UART_SendString("POWER_ON!\r\n");
    while (1)
    {
        Digbuff[2]=0x40;
        Digbuff[3]=0x40;
        Digbuff[4]=0x40;
        Digbuff[5]=0x40;
        key_v=key_scan(0);
        if (key_v==KEY1_PRESS)
        {
            Digbuff[0]=gsmg_code[1];
            Digbuff[1]=gsmg_code[1];
            time_count=5;
            key_flag=1;
            led_on_num= LED_on(1);
            LED_off(2);
            LED_off(3);
            UART_SendString("GATE_1_IS_ON!\r\n");
        }
        else if (key_v==KEY2_PRESS)
        {
            Digbuff[0]=gsmg_code[0];
            Digbuff[1]=gsmg_code[2];
            time_count=10;
            key_flag=1;
            led_on_num=LED_on(2);
            LED_off(1);
            LED_off(3);
            UART_SendString("GATE_2_IS_ON!\r\n");
        }
        else if (key_v==KEY3_PRESS)
        {
            Digbuff[0]=gsmg_code[0];
            Digbuff[1]=gsmg_code[3];
            time_count=15;
            key_flag=1;
            led_on_num=LED_on(3);
            LED_off(2);
            LED_off(1);
            UART_SendString("GATE_3_IS_ON!\r\n");
        }
        
        Digbuff[6]=gsmg_code[time_count/10];
        Digbuff[7]=gsmg_code[time_count%10];
        smg_display(Digbuff,1);
    }
}
void Timer0Init(void)		//1�????@11.0592MHz
{
	AUXR |= 0x80;		//定时器时�???1T模式
	TMOD &= 0xF0;		//设置定时器模�???
	TL0 = 0xCD;		//设置定时初�?�???
	TH0 = 0xD4;		//设置定时初�?�???
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时�???0开始�?�???
    ET0=1;
    EA=1;
}
void tm0_isr() interrupt 1
{
    TL0 = 0xCD;		//设置定时初�?�???
	TH0 = 0xD4;		//设置定时初�?�???

    if (++t0_count==1000)
    {
        t0_count=0;
        if (key_flag==1)
        {
            time_count--;
            if (time_count==0)
            {   
                LED_off(led_on_num);
                key_flag=0;
            }
        }
    }
}
