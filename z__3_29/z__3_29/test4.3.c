//3.��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int main(){
	int n = 0;
	int a = 0;
	int sum = 0;
	printf("������һ������:\n");
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