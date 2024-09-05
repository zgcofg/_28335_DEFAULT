#ifndef __GUI_H__
#define __GUI_H__
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//����Ӳ������Ƭ��STM32F103RBT6,��Ƶ72M  ��Ƭ��������ѹ3.3V
//QDtech-TFTҺ������ for STM32 IOģ��
//xiao��@ShenZhen QDtech co.,LTD
//��˾��վ:www.qdtech.net
//�Ա���վ��http://qdtech.taobao.com
//��˾�ṩ����֧�֣��κμ������⻶ӭ��ʱ����ѧϰ
//�̻�(����) :+86 0755-23594567 
//�ֻ�:15989313508���빤�� 
//����:QDtech2008@gmail.com 
//Skype:QDtech2008
//��������QQȺ:324828016
//��������:2013/5/13
//�汾��V1.1
//��Ȩ���У�����ؾ���
//Copyright(C) ������ȫ�����Ӽ������޹�˾ 2009-2019
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////
extern void GUI_DrawPoint(Uint16 x,Uint16 y,Uint16 color);
extern void LCD_Fill(Uint16 sx,Uint16 sy,Uint16 ex,Uint16 ey,Uint16 color);
extern void LCD_DrawLine(Uint16 x1, Uint16 y1, Uint16 x2, Uint16 y2);
extern void LCD_DrawRectangle(Uint16 x1, Uint16 y1, Uint16 x2, Uint16 y2);
extern void Draw_Circle(Uint16 x0,Uint16 y0,Uint16 fc,Uint16 r);
extern void LCD_ShowChar(Uint16 x,Uint16 y,Uint16 fc, Uint16 bc, Uint16 num,Uint16 size,Uint16 mode);
extern void LCD_ShowNum(Uint16 x,Uint16 y,Uint32 num,Uint16 len,Uint16 size);
extern void LCD_Show2Num(Uint16 x,Uint16 y,Uint16 num,Uint16 len,Uint16 size,Uint16 mode);
extern void LCD_ShowString(Uint16 x,Uint16 y,Uint16 size,Uint16 *p,Uint16 mode);
extern void GUI_DrawFont16(Uint16 x, Uint16 y, Uint16 fc, Uint16 bc, Uint16 *s,Uint16 mode);
extern void GUI_DrawFont24(Uint16 x, Uint16 y, Uint16 fc, Uint16 bc, Uint16 *s,Uint16 mode);
extern void GUI_DrawFont32(Uint16 x, Uint16 y, Uint16 fc, Uint16 bc, Uint16 *s,Uint16 mode);
extern void Show_Str(Uint16 x, Uint16 y, Uint16 fc, Uint16 bc, Uint16 *str,Uint16 size,Uint16 mode);
extern void Gui_Drawbmp16(Uint16 x,Uint16 y,const unsigned char *p); //��ʾ40*40 QQͼƬ
extern void gui_circle(int xc, int yc,Uint16 c,int r, int fill);
extern void Gui_StrCenter(Uint16 x, Uint16 y, Uint16 fc, Uint16 bc, Uint16 *str,Uint16 size,Uint16 mode);
extern void LCD_DrawFillRectangle(Uint16 x1, Uint16 y1, Uint16 x2, Uint16 y2);
#endif

