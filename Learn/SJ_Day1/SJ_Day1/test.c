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

//1. ��ӡ100~200֮�������
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
//2. ����˷��ھ���
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
//3. �ж�1000��-- - 2000��֮�������
//-----��ͨ�꣨���ܱ�100��������ݣ��ܱ�4������Ϊ���ꡣ����2004��������꣬1999�겻�����꣩�������꣨�ܱ�100��������ݣ��ܱ�400�����������ꡣ����2000�������꣬1900�겻�����꣩
void JudgeYear()
{
	while (1)
	{
		printf("����1000-2000����������\n");
		int num = 0;
		scanf("%d", &num);
		if (num % 100 == 0 && num % 400 == 0)
			printf("%d����������\n", num);
		else if (num % 100 != 0 && num % 4 == 0)
			printf("%d����ͨ����\n", num);
		else
			printf("%d��������\n");

	}
}
//1. �����������α�����ֵ��������ֵ�����ݽ��н�����
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
//2. ����������ʱ���������������������ݣ������⣩
void ExchangeNumber1()
{
	int a = 1;
	int b = 2;
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a=%d,b=%d\n", a, b);
}
//3.��10 �����������ֵ��
void GetMaxNumber()
{
	int tmp = 0;
	int a[10] = { 1, 23, 2, 3435, 4, 654, 8, 69, 78,90 };
	for (int i = 0; i < 10; i++)
	{
		if (tmp < a[i])
			tmp = a[i];
	}
	printf("%d�������\n", tmp);
}
//4.�����������Ӵ�С�����
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
//5.�������������Լ����
void Max_ApproximateNum()
{
	while (1)
	{

		int num1 = 0;
		int num2 = 0;
		int tmp = 0;
		printf("����������:\n");
		scanf("%d,%d", &num1, &num2);
		for (int i = 1; i < num1 && i < num2; i++)
		{
			if (num1 % i == 0 && num2 % i == 0)
				tmp = i;
		}
		printf("%d��%d�����Լ��Ϊ%d\n", num1, num2, tmp);
	}
}

//1. ������A�е����ݺ�����B�е����ݽ��н�����������һ���� 
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
//2. ����1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ���� + 1 / 99 - 1 / 100 ��ֵ��
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
//3. ��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9��
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

//1.����Ļ������������ 
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
//2.���100��999֮������С�ˮ�ɻ������������
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
			printf("%d��ˮ�ɻ���\n", i);
	}
}
//3.��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222
void Sum5()
{
	int a = 0;
	int sum = 0;
	int sn = 0;

	printf("��������:\n");
	scanf("%d", &a);
	for (int i = 0; i < 5; i++)
	{
		sn += a*pow(10,i);
		sum += sn;
	}
	printf("%d", sum);
}
//1.��ɲ�������Ϸ��
void GuessNumber()
{
	srand(time(NULL));

	int a = 0;
	a = rand() % 10 + 1;
	while (1)
	{
		int num = 0;
		printf("��������:\n");
		scanf("%d", &num);
		if (num == a)
		{
			printf("�¶���\n");
			break;
		}  else
			printf("�´���\n");
	}
}

//2.д����������������������в�����Ҫ�����֣��ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�
void SearchNmuber()
{
	int num = 0;
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int left = 0;
	int right = 0;
	int mid = 0;
	printf("������Ҫ���ҵ�����:\n");
	scanf("%d", &num);
	right = sizeof(a)/sizeof(a[0])+1;
	mid = (left + right) / 2;
	while (left <= right)
	{
		if (a[mid] == num)
		{
			printf("�ҵ���,�±�Ϊ%d", mid);
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
//3.��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���, ������󣬿����������룬����������Ρ����ξ�������ʾ�˳�����
void Password()
{
	char a[] = "12345";
	int i = 0;
	char b[1024] = "";
	printf("��������:\n");
	while (i<3)
	{
		scanf("%s", &b);
		if (0 == strcmp(a, b))
		{
			printf("��¼�ɹ�\n");
			break;
		}
		i++;
	}
	if (i > 2)
	{
		printf("��������\n");
	}
}
//4.��дһ�����򣬿���һֱ���ռ����ַ���
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
//��������ֲ������
void Keyboard()
{
	while (1)
	{
		char s1[1024] = "";
		int len = 0;
		printf("�����ַ���:\n");
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