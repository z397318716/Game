//3.求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int main(){
	int n = 0;
	int a = 0;
	int sum = 0;
	printf("请输入一个数字:\n");
	scanf("%d", &n);
	a = n;
	sum = n;
	for (int i = 1; i < 5; ++i){
		n = n * 10 + a;
		sum = n+sum;
	}
	printf("%d\n", sum);

	system("pause");
	return 0;
}