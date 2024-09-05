/*
 * time.c
 *
 *  Created on: 2018-1-24
 *      Author: Administrator
 */


#include <GPIO_INIT.h>
#include "time.h"


//��ʱ��0��ʼ������
//Freq��CPUʱ��Ƶ�ʣ�150MHz��
//Period����ʱ����ֵ����λus
void TIM0_Init(float Freq, float Period)
{
	EALLOW;
	SysCtrlRegs.PCLKCR3.bit.CPUTIMER0ENCLK = 1; // CPU Timer 0
	EDIS;

	//���ö�ʱ��0���ж���ڵ�ַΪ�ж��������INT0
	EALLOW;
	PieVectTable.TINT0 = &TIM0_IRQn;
	EDIS;

	//ָ��ʱ��0�ļĴ�����ַ
	CpuTimer0.RegsAddr = &CpuTimer0Regs;
	//���ö�ʱ��0�����ڼĴ���ֵ
	CpuTimer0Regs.PRD.all  = 0xFFFFFFFF;
	//���ö�ʱ��Ԥ���������ֵΪ0
	CpuTimer0Regs.TPR.all  = 0;
	CpuTimer0Regs.TPRH.all = 0;
	//ȷ����ʱ��0Ϊֹͣ״̬
	CpuTimer0Regs.TCR.bit.TSS = 1;
	//����ʹ��
	CpuTimer0Regs.TCR.bit.TRB = 1;
	// Reset interrupt counters:
	CpuTimer0.InterruptCount = 0;

	ConfigCpuTimer(&CpuTimer0, Freq, Period);

	//��ʼ��ʱ������
	CpuTimer0Regs.TCR.bit.TSS=0;
	//����CPU��һ���жϲ�ʹ�ܵ�һ���жϵĵ�7��С�жϣ�����ʱ��0
	IER |= M_INT1;
	PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
	//ʹ�����ж�
	EINT;
	ERTM;

}

interrupt void TIM0_IRQn(void)
{
	EALLOW;
	LED2_TOGGLE;
	PieCtrlRegs.PIEACK.bit.ACK1=1;
	EDIS;
}


