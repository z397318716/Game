#include <stdio.h>


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
void Test3()
{
	int a[5] = { 1, 2, 3, 4, 5, };
	INTPTR a, b;
	int_ptr c, d;

}
int main()
{
	Test1();
	Test2();

	system("pause");
	return 0;
}