#include <reg52.h>
#include <intrins.h>
#include "koukou.h"
#include "xqq.h"

//UCHAR synchronization=SYN_EXTERNAL;
UCHAR synchronization = SYN_INTERNAL;
/*********************************************************************************************************
** ????: Delay_ms
** ????: ??ms?? (???)
** ? ?:   2016?6?15?
********************************************************************************************************/
void Delay_ms(UINT ms)
{
	UINT i, j, k;
	for (k = 0; k<ms; k++)
	for (i = 48; i>0; i--)
	for (j = 10; j>0; j--);
}

/*********************************************************************************************************
** ????: MB90092_WriteByte
** ????: ?MB90092 ???????
** ? ?:   2016?6?15?
********************************************************************************************************/
void MB90092_WriteByte(UCHAR _data)
{
	UCHAR i;

	ACC = _data;
	CS = 0x00;
	for (i = 8; i>0; i--){
		CLK = 0;
		SIN = ACC_0;
		CLK = 1;
		ACC >>= 1;
	}
	CS = 0x01;
}

/*********************************************************************************************************
** ????: MB90092_ClearXY
** ????: ????????(x,y)????,y=0x00~0x0B and x=0x00~0x17 for main screen
** ? ?:   2016?6?15?
********************************************************************************************************/
void  MB90092_ClearXY(UCHAR x, UCHAR y)
{
	UCHAR byte1, byte2;

	if (x>0x17 || y>0x0B) return;           //invalid col number or row number

	byte1 = ((y >> 2) & 0x3) + 0x80;
	byte2 = ((y << 5) & 0x60) + x;

	MB90092_WriteByte(byte1);             //command 0,??????,???
	MB90092_WriteByte(byte2);

	MB90092_WriteByte(0x88);              //command1-1,??????,????
	MB90092_WriteByte(0x00);

	MB90092_WriteByte(0x90 + 62 / 128);       //command2-1,????????,??62??????
	MB90092_WriteByte(62 % 128);
}

/*********************************************************************************************************
** ????: MB90092_ClearRow
** ????: ????????y???,y=0x00~0x0B for main screen
** ? ?:   2016?6?15?
********************************************************************************************************/
void  MB90092_ClearRow(UCHAR y)
{
	UCHAR x;

	if (y>0x0B) return;                   //invlid row number

	for (x = 0; x<0x18; x++)
		MB90092_ClearXY(x, y);
}

/*********************************************************************************************************
** ????: MB90092_ClearScreen
** ????: ??
** ? ?:   2016?6?15?
********************************************************************************************************/
void  MB90092_ClearScreen()
{
	UCHAR i;
	for (i = 0; i<0x0C; i++)
		MB90092_ClearRow(i);
}

/*********************************************************************************************************
** ????: MB90092_DisColor
** ????: MB90092?????
** ? ?:   2016?6?15?
********************************************************************************************************/
void  MB90092_DisColor(UCHAR y)
{
	UCHAR temp1, temp2;

	temp1 = ((y >> 2) & 0x3) + 0x84;
	temp2 = ((y << 5) & 0x60) + 1;

	MB90092_WriteByte(temp1);             //command 0,??????,???
	MB90092_WriteByte(temp2);

	MB90092_WriteByte(0x88);              //ff??????
	MB90092_WriteByte(0x00);              //command1-1,??????,????

	MB90092_WriteByte(0x90);              //command2-1,????????rom???
	MB90092_WriteByte(0x00);
}

/*********************************************************************************************************
** ????: MB90092_DisChar
** ????: ?????(x,y)???????,???????????addr,??24x32?????
** ?  ?:   x,y?????,addr???????rom?????,mul?????,bc???????,
cc?????,ff??????.
** ? ?:   2016?6?15?
********************************************************************************************************/
void  MB90092_DisChar(UCHAR x, UCHAR y, int addr, UCHAR mul, UCHAR bc, UCHAR cc, UCHAR ff)
{
	UCHAR temp1, temp2, color;

	if (x>0x17 || y>0x0B) return;           //invalid col number or row number

	temp1 = ((y >> 2) & 0x3) + 0x80;
	temp2 = ((y << 5) & 0x60) + x;

	MB90092_WriteByte(temp1);             //command 0,??????,???
	MB90092_WriteByte(temp2);

	MB90092_WriteByte(0xB0 | mul);          //command 6,mul->??????(datasheel82),?????
	MB90092_WriteByte(0x20 | y);

	if (synchronization == SYN_EXTERNAL){
		cc = 7;
		bc = 0;
	}
	color = ((cc << 4) & 0x70) | bc;

	MB90092_WriteByte(0x88 | ff);           //ff??????
	MB90092_WriteByte(color);             //command1-1,??????,????

	MB90092_WriteByte(0x90 + addr / 128);     //command2-1,????????rom???
	MB90092_WriteByte(addr % 128);
}

/*********************************************************************************************************
** ????: MainScreen_Init
** ????: MB90092?????
** ? ?:   2016?6?15?
********************************************************************************************************/
void  MainScreen_Init(UCHAR bc)
{
	UCHAR i;

	CS = 0;
	Delay_ms(10);                         //?????,???CS?????????,?????????????
	CS = 1;
	Delay_ms(10);
	CS = 0;
	Delay_ms(10);
	CS = 1;
	Delay_ms(10);
	CS = 0;
	Delay_ms(10);
	CS = 1;
	Delay_ms(10);
	CS = 0;
	Delay_ms(10);
	CS = 1;
	Delay_ms(10);

	MB90092_WriteByte(0xA0);              //command 4,???????
	MB90092_WriteByte(0x00);

	MB90092_WriteByte(0xAD);              //command 5
	MB90092_WriteByte(0x10);              //KID=0;APC?????;GYZ=0;W3--W0????;10101 KID APC GYZ0 BH2 BH1 BH0 W3 W2 W1 W0

	MB90092_WriteByte(0xBC);              //command 7
	MB90092_WriteByte(0x2A);              //????????

	MB90092_WriteByte(0xC0);              //command 8
	MB90092_WriteByte(0x18);              //????????

	MB90092_WriteByte(0xC8);              //command 9,GRM???????????????
	MB90092_WriteByte(0x20);

	MB90092_WriteByte(0xD1);              //command 10,??????/??????,??,????,????/??,????/??
	MB90092_WriteByte(0x38 | bc);

	MB90092_WriteByte(0xA2 | synchronization);//command 4,?/?????
	MB90092_WriteByte(0x2B);

	for (i = 0; i<0x0B; i++)
		MB90092_DisColor(i);
	MB90092_ClearScreen();
}
