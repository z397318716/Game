#define _CRT_SECURE_NO_WARNINGS
//5.�������������Լ����
#include<stdio.h>
#include<stdlib.h>

void Min_divisor(int x, int y){
	int i = 0;
	if (x > y){
		i = x;
	} else{
		i = y;
	}
	while (1){
		if (i%x == 0 && i%y == 0){
			printf("������������С��Լ����:%d\n",i);
			break;
		}
		++i;
	}

int main(){
	int a = 0;
	int b = 0;
	printf("������������(�м��ö��Ÿ���):\n");
	scanf("%d,%d", &a, &b);
	Min_divisor(a, b);
	system("pause");
	return 0;
}