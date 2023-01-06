/*
 * @Author: Panyan
 * @Date: 2022-12-28 20:29:18
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-12-28 20:55:09
 * @FilePath: \Ð¡Ðí\publish.c
 */
#include "publish.h"

void Delay_ms(u16 ms)		//@11.0592MHz
{
	unsigned char i, j,k;
    for ( k = 0; k < ms; k++)
    {
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j);
        } while (--i);
    }
    
}
void Delay_10us(u8 ten_us)		//@11.0592MHz
{
	unsigned char i,j;
    for ( j = 0; j < ten_us; j++)
    {
        i = 2;
        while (--i);
    }
    
}

