#ifndef __LCD_H
#define __LCD_H		


//////////////////////////////////////////////////////////////////////////////////	
/****************************************************************************************************
//=======================================液晶屏数据线接线==========================================//
//CS		接PB11	//片选信号
//CLK	    接PB13	//SPI时钟信号
//SDI(DIN)	接PB15	//SPI总线数据信号
//=======================================液晶屏控制线接线==========================================//
//LED	    接PB9	//背光控制信号，高电平点亮
//RS(D/C)   接PB10	//寄存器/数据选择信号(RS=0数据总线发送的是指令；RS=1数据总线发送的是像素数据)
//RST	    接PB12	//液晶屏复位信号，低电平复位
/////////////////////////////////////////////////////////////////////////////////////////////////
//==================================如何精简到只需要3个IO=======================================//
//1.CS信号可以精简，不作SPI复用片选可将CS接地常低，节省1个IO
//2.LED背光控制信号可以接高电平3.3V背光常亮，节省1个IO
//3.RST复位信号可以接到单片机的复位端，利用系统上电复位，节省1个IO
//==================================如何切换横竖屏显示=======================================//
//打开lcd.h头文件，修改宏#define USE_HORIZONTAL 值为0使用竖屏模式.1,使用横屏模式
//===========================如何切换模拟SPI总线驱动和硬件SPI总线驱动=========================//
//打开lcd.h头文件，修改宏#define USE_HARDWARE_SPI  值为0使用模拟SPI总线.1,使用硬件SPI总线
**************************************************************************************************/	

//LCD重要参数集
typedef struct  
{										    
	Uint16 width;			//LCD 宽度
	Uint16 height;			//LCD 高度
	Uint16 id;				//LCD ID
	Uint16  dir;			//横屏还是竖屏控制：0，竖屏；1，横屏。
	Uint16	 wramcmd;		//开始写gram指令
	Uint16  setxcmd;		//设置x坐标指令
	Uint16  setycmd;		//设置y坐标指令
}_lcd_dev; 	

//LCD参数
extern _lcd_dev lcddev;	//管理LCD重要参数
/////////////////////////////////////用户配置区///////////////////////////////////	 
//支持横竖屏快速定义切换，支持8/16位模式切换
//#define USE_HORIZONTAL  	1	//定义是否使用横屏 		0,不使用.1,使用.
//使用硬件SPI 还是模拟SPI作为测试
#define USE_HARDWARE_SPI    0 //1:Enable Hardware SPI;0:USE Soft SPI
//////////////////////////////////////////////////////////////////////////////////	  
//定义LCD的尺寸
//#if USE_HORIZONTAL==1	//使用横屏
#define LCD_W 320
#define LCD_H 240
//#else
//#define LCD_W 240
//#define LCD_H 320
//#endif

//TFTLCD部分外要调用的函数		   
extern Uint16  POINT_COLOR;//默认红色
extern Uint16  BACK_COLOR; //背景颜色.默认为白色


/********************************宏定义数码管位选 IO 接口*******************************************/
//#define  SET_DATA	GpioDataRegs.GPBSET.bit.GPIO53	 = 1 		//与外设板 8_LEDS 端子的 IO70 对应
//#define  CLC_COMD	GpioDataRegs.GPBCLEAR.bit.GPIO53 = 1		//与外设板 8_LEDS 端子的 IO70 对应
//#define  SET_RS   GpioDataRegs.GPBSET.bit.GPIO52	 = 1		//与外设板 8_LEDS 端子的 IO71 对应
//#define  CLC_RS	GpioDataRegs.GPBCLEAR.bit.GPIO52 = 1		//与外设板 8_LEDS 端子的 IO71 对应
//#define  CS_H	GpioDataRegs.GPBSET.bit.GPIO57=1
//#define  CS_L	GpioDataRegs.GPBCLEAR.bit.GPIO57=1
//#define  SDA_H	GpioDataRegs.GPBSET.bit.GPIO54=1
//#define  SDA_L	GpioDataRegs.GPBCLEAR.bit.GPIO54=1
//#define  SCL_H	GpioDataRegs.GPBSET.bit.GPIO56=1
//#define  SCL_L	GpioDataRegs.GPBCLEAR.bit.GPIO56=1

/*****************************************************************************************************/



//画笔颜色
#define WHITE       0xFFFF
#define BLACK      	0x0000//黑色---
#define BLUE       	0x001F  //蓝色--
#define BRED        0XF81F
#define GRED 			 	0XFFE0
#define GBLUE			 	0X07FF//青色--
#define RED         0xF800//红色
#define MAGENTA     0xF81F//紫色--
#define GREEN       0x07E0//绿色--
#define CYAN        0x7FFF
#define YELLOW      0xFFE0//黄色
#define BROWN 			0XBC40 //棕色
#define BRRED 			0XFC07 //棕红色
#define GRAY  			0X8430 //灰色
//GUI颜色

#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
//以上三色为PANEL的颜色 
 
#define LIGHTGREEN     	0X841F //浅绿色
//#define LIGHTGRAY     0XEF5B //浅灰色(PANNEL)
#define LGRAY 			 		0XC618 //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE      	0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE          0X2B12 //浅棕蓝色(选择条目的反色)
	    															  
extern Uint16 BACK_COLOR, POINT_COLOR ;


extern void LCD_Init(void);
extern void LCD_DisplayOn(void);
extern void LCD_DisplayOff(void);
extern void LCD_Clear(Uint16 Color);
extern void LCD_SetCursor(Uint16 Xpos, Uint16 Ypos);
extern void LCD_DrawPoint(Uint16 x,Uint16 y);//画点

extern void LCD_DrawLine(Uint16 x1, Uint16 y1, Uint16 x2, Uint16 y2);
extern void LCD_DrawRectangle(Uint16 x1, Uint16 y1, Uint16 x2, Uint16 y2);
extern void LCD_SetWindows(Uint16 xStar, Uint16 yStar,Uint16 xEnd,Uint16 yEnd);
extern void LCD_DrawPoint_16Bit(Uint16 color);

extern void LCD_WriteReg(Uint16 LCD_Reg, Uint16 LCD_RegValue);
extern void LCD_WR_DATA(Uint16 data);
extern void LCD_WR_DATA_16Bit(Uint16 data);

extern void LCD_WriteRAM_Prepare(void);
extern void LCD_WriteRAM(Uint16 RGB_Code);

extern void LCD_SetParam(void);

						  		 
#endif  
	 
	 



