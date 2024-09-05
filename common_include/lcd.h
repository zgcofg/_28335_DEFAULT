#ifndef __LCD_H
#define __LCD_H		


//////////////////////////////////////////////////////////////////////////////////	
/****************************************************************************************************
//=======================================Һ���������߽���==========================================//
//CS		��PB11	//Ƭѡ�ź�
//CLK	    ��PB13	//SPIʱ���ź�
//SDI(DIN)	��PB15	//SPI���������ź�
//=======================================Һ���������߽���==========================================//
//LED	    ��PB9	//��������źţ��ߵ�ƽ����
//RS(D/C)   ��PB10	//�Ĵ���/����ѡ���ź�(RS=0�������߷��͵���ָ�RS=1�������߷��͵�����������)
//RST	    ��PB12	//Һ������λ�źţ��͵�ƽ��λ
/////////////////////////////////////////////////////////////////////////////////////////////////
//==================================��ξ���ֻ��Ҫ3��IO=======================================//
//1.CS�źſ��Ծ��򣬲���SPI����Ƭѡ�ɽ�CS�ӵس��ͣ���ʡ1��IO
//2.LED��������źſ��ԽӸߵ�ƽ3.3V���ⳣ������ʡ1��IO
//3.RST��λ�źſ��Խӵ���Ƭ���ĸ�λ�ˣ�����ϵͳ�ϵ縴λ����ʡ1��IO
//==================================����л���������ʾ=======================================//
//��lcd.hͷ�ļ����޸ĺ�#define USE_HORIZONTAL ֵΪ0ʹ������ģʽ.1,ʹ�ú���ģʽ
//===========================����л�ģ��SPI����������Ӳ��SPI��������=========================//
//��lcd.hͷ�ļ����޸ĺ�#define USE_HARDWARE_SPI  ֵΪ0ʹ��ģ��SPI����.1,ʹ��Ӳ��SPI����
**************************************************************************************************/	

//LCD��Ҫ������
typedef struct  
{										    
	Uint16 width;			//LCD ���
	Uint16 height;			//LCD �߶�
	Uint16 id;				//LCD ID
	Uint16  dir;			//���������������ƣ�0��������1��������
	Uint16	 wramcmd;		//��ʼдgramָ��
	Uint16  setxcmd;		//����x����ָ��
	Uint16  setycmd;		//����y����ָ��
}_lcd_dev; 	

//LCD����
extern _lcd_dev lcddev;	//����LCD��Ҫ����
/////////////////////////////////////�û�������///////////////////////////////////	 
//֧�ֺ��������ٶ����л���֧��8/16λģʽ�л�
//#define USE_HORIZONTAL  	1	//�����Ƿ�ʹ�ú��� 		0,��ʹ��.1,ʹ��.
//ʹ��Ӳ��SPI ����ģ��SPI��Ϊ����
#define USE_HARDWARE_SPI    0 //1:Enable Hardware SPI;0:USE Soft SPI
//////////////////////////////////////////////////////////////////////////////////	  
//����LCD�ĳߴ�
//#if USE_HORIZONTAL==1	//ʹ�ú���
#define LCD_W 320
#define LCD_H 240
//#else
//#define LCD_W 240
//#define LCD_H 320
//#endif

//TFTLCD������Ҫ���õĺ���		   
extern Uint16  POINT_COLOR;//Ĭ�Ϻ�ɫ
extern Uint16  BACK_COLOR; //������ɫ.Ĭ��Ϊ��ɫ


/********************************�궨�������λѡ IO �ӿ�*******************************************/
//#define  SET_DATA	GpioDataRegs.GPBSET.bit.GPIO53	 = 1 		//������� 8_LEDS ���ӵ� IO70 ��Ӧ
//#define  CLC_COMD	GpioDataRegs.GPBCLEAR.bit.GPIO53 = 1		//������� 8_LEDS ���ӵ� IO70 ��Ӧ
//#define  SET_RS   GpioDataRegs.GPBSET.bit.GPIO52	 = 1		//������� 8_LEDS ���ӵ� IO71 ��Ӧ
//#define  CLC_RS	GpioDataRegs.GPBCLEAR.bit.GPIO52 = 1		//������� 8_LEDS ���ӵ� IO71 ��Ӧ
//#define  CS_H	GpioDataRegs.GPBSET.bit.GPIO57=1
//#define  CS_L	GpioDataRegs.GPBCLEAR.bit.GPIO57=1
//#define  SDA_H	GpioDataRegs.GPBSET.bit.GPIO54=1
//#define  SDA_L	GpioDataRegs.GPBCLEAR.bit.GPIO54=1
//#define  SCL_H	GpioDataRegs.GPBSET.bit.GPIO56=1
//#define  SCL_L	GpioDataRegs.GPBCLEAR.bit.GPIO56=1

/*****************************************************************************************************/



//������ɫ
#define WHITE       0xFFFF
#define BLACK      	0x0000//��ɫ---
#define BLUE       	0x001F  //��ɫ--
#define BRED        0XF81F
#define GRED 			 	0XFFE0
#define GBLUE			 	0X07FF//��ɫ--
#define RED         0xF800//��ɫ
#define MAGENTA     0xF81F//��ɫ--
#define GREEN       0x07E0//��ɫ--
#define CYAN        0x7FFF
#define YELLOW      0xFFE0//��ɫ
#define BROWN 			0XBC40 //��ɫ
#define BRRED 			0XFC07 //�غ�ɫ
#define GRAY  			0X8430 //��ɫ
//GUI��ɫ

#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ  
#define GRAYBLUE       	 0X5458 //����ɫ
//������ɫΪPANEL����ɫ 
 
#define LIGHTGREEN     	0X841F //ǳ��ɫ
//#define LIGHTGRAY     0XEF5B //ǳ��ɫ(PANNEL)
#define LGRAY 			 		0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ

#define LGRAYBLUE      	0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE          0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)
	    															  
extern Uint16 BACK_COLOR, POINT_COLOR ;


extern void LCD_Init(void);
extern void LCD_DisplayOn(void);
extern void LCD_DisplayOff(void);
extern void LCD_Clear(Uint16 Color);
extern void LCD_SetCursor(Uint16 Xpos, Uint16 Ypos);
extern void LCD_DrawPoint(Uint16 x,Uint16 y);//����

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
	 
	 



