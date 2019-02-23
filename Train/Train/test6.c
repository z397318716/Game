//递归方式实现打印一个整数的每一位
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void P_rintf(int num){
	if (num > 9){
		P_rintf(num/10);
	}
		printf("%d  ", num % 10);		
	}
int main(){
	int n = 0;
	printf("请输入一个整数:\n");
	scanf("%d", &n);
	Printf(n);

	system("pause");
	return 0;
}
