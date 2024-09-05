#ifndef __GUI_H__
#define __GUI_H__
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//测试硬件：单片机STM32F103RBT6,主频72M  单片机工作电压3.3V
//QDtech-TFT液晶驱动 for STM32 IO模拟
//xiao冯@ShenZhen QDtech co.,LTD
//公司网站:www.qdtech.net
//淘宝网站：http://qdtech.taobao.com
//我司提供技术支持，任何技术问题欢迎随时交流学习
//固话(传真) :+86 0755-23594567 
//手机:15989313508（冯工） 
//邮箱:QDtech2008@gmail.com 
//Skype:QDtech2008
//技术交流QQ群:324828016
//创建日期:2013/5/13
//版本：V1.1
//版权所有，盗版必究。
//Copyright(C) 深圳市全动电子技术有限公司 2009-2019
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
extern void Gui_Drawbmp16(Uint16 x,Uint16 y,const unsigned char *p); //显示40*40 QQ图片
extern void gui_circle(int xc, int yc,Uint16 c,int r, int fill);
extern void Gui_StrCenter(Uint16 x, Uint16 y, Uint16 fc, Uint16 bc, Uint16 *str,Uint16 size,Uint16 mode);
extern void LCD_DrawFillRectangle(Uint16 x1, Uint16 y1, Uint16 x2, Uint16 y2);
#endif

