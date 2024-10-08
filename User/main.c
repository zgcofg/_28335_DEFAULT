/*
 * main.c
 *
 *  Created on: 2024-9-02
 *      Author: zcc
 */



#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#include "GPIO_INIT.h"
#include "time.h"



/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void main()
{
	int i=0;

	InitSysCtrl();

	InitPieCtrl();
	IER = 0x0000;
	IFR = 0x0000;
	InitPieVectTable();

	LED_Init();
	TIM0_Init(150,500000);

	while(1)
	{
		i++;
		if(i%2000==0)
		{
			LED1_TOGGLE;
		}
		DELAY_US(100);
	}
}

