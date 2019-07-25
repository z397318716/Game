#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define INTPTR int*
typedef int* int_ptr;


void Test1()
{
	int a[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24 }, *q[4], k;
	for (k = 0; k < 4; k++)
	{
		q[k] = &a[k * 3];
	}
	printf("%d\n", q[3][1]);
}
void Test2()
{
	int i, j, a = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (j % 2)
				break;
			a++;
		}
		a++;
	}
	printf("%d\n", a);
}

/*
void Test3()
{
	int a[5] = { 1, 2, 3, 4, 5, };
	INTPTR a, b;
	int_ptr c, d;

}
*/

//1. 打印100~200之间的素数
void PrimeNumber()
{
	int a = 100;
	int j = 0;
	for (a; a < 200; a++)
	{
		j = 0;
		for (int i = 2; i < a; ++i)
		{
			
			if (a % i == 0)
				j++;
		}
		if (j == 0)
			printf("%d ", a);
	}
}
//2. 输出乘法口诀表
void Mult_Table()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%d  ", j, i, i*j);
		}
		printf("\n");
	}
}
//3. 判断1000年-- - 2000年之间的闰年
//-----普通年（不能被100整除的年份）能被4整除的为闰年。（如2004年就是闰年，1999年不是闰年）；世纪年（能被100整除的年份）能被400整除的是闰年。（如2000年是闰年，1900年不是闰年）
void JudgeYear()
{
	while (1)
	{
		printf("输入1000-2000年间任意年份\n");
		int num = 0;
		scanf("%d", &num);
		if (num % 100 == 0 && num % 400 == 0)
			printf("%d是世纪闰年\n", num);
		else if (num % 100 != 0 && num % 4 == 0)
			printf("%d是普通闰年\n", num);
		else
			printf("%d不是闰年\n");

	}
}
//1. 给定两个整形变量的值，将两个值的内容进行交换。
void ExchangeNumber()
{
	int a = 1;
	int b = 2;
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
	printf("a=%d,b=%d\n", a, b);
}
//2. 不允许创建临时变量，交换两个数的内容（附加题）
void ExchangeNumber1()
{
	int a = 1;
	int b = 2;
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a=%d,b=%d\n", a, b);
}
//3.求10 个整数中最大值。
void GetMaxNumber()
{
	int tmp = 0;
	int a[10] = { 1, 23, 2, 3435, 4, 654, 8, 69, 78,90 };
	for (int i = 0; i < 10; i++)
	{
		if (tmp < a[i])
			tmp = a[i];
	}
	printf("%d是最大数\n", tmp);
}
//4.将三个数按从大到小输出。
void SortNum()
{
	int tmp = 0;
	int a[3] = { 1, 2, 3 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3 - i - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < 3; i++)
		printf("%d ", a[i]);
	printf("\n");

}
//5.求两个数的最大公约数。
void Max_ApproximateNum()
{
	while (1)
	{

		int num1 = 0;
		int num2 = 0;
		int tmp = 0;
		printf("输入两个数:\n");
		scanf("%d,%d", &num1, &num2);
		for (int i = 1; i < num1 && i < num2; i++)
		{
			if (num1 % i == 0 && num2 % i == 0)
				tmp = i;
		}
		printf("%d与%d的最大公约数为%d\n", num1, num2, tmp);
	}
}

//1. 将数组A中的内容和数组B中的内容进行交换。（数组一样大） 
void ExchangeArray()
{
	int a[5] = { 1, 3, 5, 7, 9 };
	int b[5] = { 2, 4, 6, 8, 10 };
	int tmp = 0;
	for (int i = 0; i < 5; i++)
	{
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//2. 计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值。
void Sum()
{
	double i = 1;
	double j = 2;
	double sum1 = 0;
	double sum2 = 0;
	for (i,j; i < 100,j<=100; i += 2,j+=2)
	{
		sum1 += 1 / i;
		sum2 -= 1 / j;
	}
	printf("%f\n", sum1 + sum2);
}
//3. 编写程序数一下 1到 100 的所有整数中出现多少次数字9。
void Count_9()
{
	int count = 1;
	for (int i =1; i < 100; i++)
	{
		if (i % 10 == 9)
			count++;
		else if (i / 10 == 9)
			count++;
	}
	printf("%d\n", count);
}

//1.在屏幕上输出半个菱形 
void PrintDiamond()
{
	for (int i = 1; i < 14; i+=2)
	{
		for (int j = 1; j <=i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (int i = 14; i>=0; i-=2)
	{
		for (int j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}
}
//2.求出100～999之间的所有“水仙花数”并输出。
void DaffodilNumber()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int sum = 0;
	for (int i = 100; i < 1000; i++)
	{
		a = i / 100;
		b = (i / 10) % 10;
		c = i % 10;
		sum = pow(a, 3) + pow(b, 3) + pow(c, 3);
		if (i == sum)
			printf("%d是水仙花数\n", i);
	}
}
//3.求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222
void Sum5()
{
	int a = 0;
	int sum = 0;
	int sn = 0;

	printf("输入数字:\n");
	scanf("%d", &a);
	for (int i = 0; i < 5; i++)
	{
		sn += a*pow(10,i);
		sum += sn;
	}
	printf("%d", sum);
}
//1.完成猜数字游戏。
void GuessNumber()
{
	srand(time(NULL));

	int a = 0;
	a = rand() % 10 + 1;
	while (1)
	{
		int num = 0;
		printf("输入数字:\n");
		scanf("%d", &num);
		if (num == a)
		{
			printf("猜对了\n");
			break;
		}  else
			printf("猜错了\n");
	}
}

//2.写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回 - 1.（折半查找）
void SearchNmuber()
{
	int num = 0;
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int left = 0;
	int right = 0;
	int mid = 0;
	printf("输入想要查找的数字:\n");
	scanf("%d", &num);
	right = sizeof(a)/sizeof(a[0])+1;
	mid = (left + right) / 2;
	while (left <= right)
	{
		if (a[mid] == num)
		{
			printf("找到了,下标为%d", mid);
			break;
		}
		else if (a[mid]> num)
		{
			right = mid;
			mid = (left + right) / 2;
		}
		else
		{
			left = mid;
			mid = (left + right) / 2;
		}
	}
	return -1;
}
//3.编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，可以重新输入，最多输入三次。三次均错，则提示退出程序。
void Password()
{
	char a[] = "12345";
	int i = 0;
	char b[1024] = "";
	printf("输入密码:\n");
	while (i<3)
	{
		scanf("%s", &b);
		if (0 == strcmp(a, b))
		{
			printf("登录成功\n");
			break;
		}
		i++;
	}
	if (i > 2)
	{
		printf("超过三次\n");
	}
}
//4.编写一个程序，可以一直接收键盘字符，
//如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，
//如果是数字不输出。
void Keyboard()
{
	while (1)
	{
		char s1[1024] = "";
		int len = 0;
		printf("输入字符串:\n");
		gets(s1);
		len = strlen(s1);
		for (int i = 0; i < len; i++)
		{
			if (s1[i]>'a' && s1[i] < 'z')
			{
				s1[i] -= 'a' - 'A';
				printf("%c", s1[i]);
			}
			else if (s1[i]>'A' && s1[i] < 'Z')
			{
				s1[i] += 'a' - 'A';
				printf("%c", s1[i]);
			}
		}
		
	}
}


int main()
{
	ExchangeNumber();
	ExchangeNumber1();
	GetMaxNumber();
	SortNum();
	//Max_ApproximateNum();

	ExchangeArray();
	Sum();
	Count_9();

	PrintDiamond();
	DaffodilNumber();
	//Sum5();

	//GuessNumber();
	//SearchNmuber();
	//Password();
	Keyboard();

	system("pause");
	return 0;
}