#include <reg52.h>
#include "xqq.h"
#include "koukou.h"
#include "ds1302.h"
unsigned char F_size, F_color, F_back, T_set, T_mov, T_change, T_dis;
void Key_Check();
void display(UCHAR F_s, UCHAR F_c, UCHAR F_b, UCHAR T_dis);
/********************************************************************
* 函数名 : main
* 函数功能 : 主函数
* 输入 : 无
* 输出 : 无
*******************************************************************/
void main()
{
	unsigned char i;
	/*全局变量初始化*/
	F_size = 0;
	F_color = 0;
	F_back = 0;
	T_set = 0;
	T_mov = 0;
	T_change = 0;
	T_dis = 0;
	DS1302Init();	           //ds1302初始化
	MainScreen_Init(7);		    //MB90092初始化
	MB90092_ClearScreen();     //MB90092清屏
	while (1)
	{
		//	MB90092_WriteByte('X');
		Key_Check();
		if (T_dis == 1)
		{
			if (T_set == 0)
			{
				DS1302ReadTime();
			}


			else
			{
				/*********检测移位操作********/
				if (K5 == 0)  				//控制字体大小按键
				{
					Delay_ms(10);			//消除抖动
					if (K5 == 0)
					{
						T_mov++;
						if (T_mov > 7)	    	//年月日时分秒周，共7个字段
						{
							T_mov = 0;
						}
					}
					while ((i < 50) && (K5 == 0))	 //检测按键是否松开
					{
						Delay_ms(10);
						i++;
					}
					i = 0;
				}
				/******检测数值设定按键*******/
				if (K6 == 0)  			        //控制字体大小按键
				{
					Delay_ms(10);			 //消除抖动
					if (K6 == 0)
					{
						TIME[T_mov]++;
						if ((TIME[T_mov] & 0x0f) > 9)	//换成BCD码。
						{
							TIME[T_mov] = TIME[T_mov] + 6;
						}
						if ((TIME[T_mov] >= 0x60) && (T_mov < 2))  //分秒只能到59
						{
							TIME[T_mov] = 0;
						}
						if ((TIME[T_mov] >= 0x24) && (T_mov == 2)) //小时只能到23
						{
							TIME[T_mov] = 0;
						}
						if ((TIME[T_mov] >= 0x32) && (T_mov == 3))	//日只能到31
						{
							TIME[T_mov] = 0;
						}
						if ((TIME[T_mov] >= 0x13) && (T_mov == 4))	//月只能到12
						{
							TIME[T_mov] = 0;
						}
						if ((TIME[T_mov] >= 0x7) && (T_mov == 5))	//周只能到7
						{
							TIME[T_mov] = 1;
						}
					}
					while ((i < 50) && (K6 == 0))	          //检测按键是否松开
					{
						Delay_ms(10);
						i++;
					}
					i = 0;
				}
			}
		}
		display(F_size, F_color, F_back, T_dis);
	}
}
/********************************************************************
* 函数名 : Key_Check
* 函数功能 : 检测按键是否被按下，并操作对应全局变量
* 输入 : 无
* 输出 : 无
*******************************************************************/
void Key_Check()
{
	unsigned char i;			//定义局部变量，用作松手检测
	if (K1 == 0)  			   //控制字体大小按键
	{
		Delay_ms(10);		//消除抖动
		if (K1 == 0)
		{
			F_size = ~F_size;	     //每次按下，则切换状态
		}
		while ((i < 50) && (K1 == 0))	  //检测按键是否松开
		{
			Delay_ms(10);
			i++;
		}
		i = 0;
	}
	if (K2 == 0)  			    //控制字体颜色按键
	{
		Delay_ms(10);		//消除抖动
		if (K2 == 0)
		{
			F_color = ~F_color;    	//每次按下，则切换状态
		}
		while ((i < 50) && (K2 == 0))	    //检测按键是否松开
		{
			Delay_ms(10);
			i++;
		}
		i = 0;
	}
	if (K3 == 0)  				   //控制字体背景颜色按键
	{
		Delay_ms(10);			//消除抖动
		if (K1 == 0)
		{
			F_back = ~F_back;	    //每次按下，则切换状态
		}
		while ((i < 50) && (K3 == 0))  //检测按键是否松开
		{
			Delay_ms(10);
			i++;
		}
		i = 0;
	}
	if (K4 == 0)  			   //时钟调整按键
	{
		Delay_ms(10);		//消除抖动
		if (K4 == 0)
		{
			T_set = ~T_set;	//每次按下，则切换状态	  
			T_mov = 0;	 	//清除位置信息
			DS1302Init();	 //初始化DS1302
		}
		while ((i < 50) && (K4 == 0))  	//检测按键是否松开
		{
			Delay_ms(10);
			i++;
		}
		i = 0;
	}
	if (K7 == 0)  				  //显示时钟按键
	{
		Delay_ms(10);		  //消除抖动
		if (K7 == 0)
		{
			T_dis = 1;		   //每次按下，则固定赋值
		}
		while ((i < 50) && (K7 == 0)) 	//检测按键是否松开
		{
			Delay_ms(10);
			i++;
		}
		i = 0;
	}
	if (K8 == 0)  				 //控制字体大小按键
	{
		Delay_ms(10);		 //消除抖动
		if (K8 == 0)
		{
			T_dis = 1;			          //每次按下，则固定赋值
		}
		while ((i < 50) && (K8 == 0))	   //检测按键是否松开
		{
			Delay_ms(10);
			i++;
		}
		i = 0;
	}
}
/********************************************************************
* 函数名 : display
* 函数功能 : 将对应的字码显示加载到视频的显示器上面
* 输入:   F_s：设置字体大小, 取值为0/1；
*	   F_c: 设置字体颜色，取值为0/1;
*	   F_b: 设置字体背景颜色，取值为0/1；
*	   T_dis:设置是否显示时钟，取值为0/1；
* 输出  : 无
********************************************************************/
void display(UCHAR _s, UCHAR F_c, UCHAR F_b, UCHAR T_dis)
{
	UCHAR  s, c, b;
	UCHAR i = 3;
	/******************字体大小****************/
	if (F_s == 0) s = 1;		 //1号字体
	else	   s = 2;		 //2号字体
	/******************背景颜色****************/
	if (F_b == 0) b = 1;
	else	   b = 2;
	/******************字符颜色****************/
	if (F_c == 0) c = C_COLOR_GREEN;	  //绿色
	else	   c = C_COLOR_RED;		  //红色
	/*************检测是否显示万年历***********/
	if (T_dis == 1)					      //显示万年历
	{
		MB90092_DisChar(1, i, '0' + TIME[2] / 16, s, b, c, 0);	     //时
		MB90092_DisChar(2, i, '0' + (TIME[2] & 0x0f), s, b, c, 0);
		MB90092_DisChar(3, i, ':', s, b, c, 0);	     //分隔符
		MB90092_DisChar(4, i, '0' + TIME[1] / 16, s, b, c, 0);		 //分
		MB90092_DisChar(5, i, '0' + (TIME[1] & 0x0f), s, b, c, 0);
		MB90092_DisChar(6, i, ':', s, b, c, 0);		    //分隔符
		MB90092_DisChar(7, i, '0' + TIME[0] / 16, s, b, c, 0);	  	 //秒
		MB90092_DisChar(8, i, '0' + (TIME[0] & 0x0f), s, b, c, 0);
		MB90092_DisChar(1, i - 1, '2', s, b, c, 0);	     //年
		MB90092_DisChar(2, i - 1, '0', s, b, c, 0);	  //年
		MB90092_DisChar(3, i - 1, '0' + TIME[6] / 16, s, b, c, 0);	  //年
		MB90092_DisChar(4, i - 1, '0' + (TIME[6] & 0x0f), s, b, c, 0);
		MB90092_DisChar(5, i - 1, ':', s, b, c, 0);	  //分隔符
		MB90092_DisChar(6, i - 1, '0' + TIME[4] / 16, s, b, c, 0);	  //月
		MB90092_DisChar(7, i - 1, '0' + (TIME[4] & 0x0f), s, b, c, 0);
		MB90092_DisChar(8, i - 1, ':', s, b, c, 0);	  //分隔符
		MB90092_DisChar(9, i - 1, '0' + TIME[3] / 16, s, b, c, 0);	  //日
		MB90092_DisChar(10, i - 1, '0' + (TIME[3] & 0x0f), s, b, c, 0);

		MB90092_DisChar(1, i + 2, '0' + (TIME[5] & 0x0f), s, b, c, 0);	  //星期	
	}
