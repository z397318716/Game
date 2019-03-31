//打印100-200之间的素数
#include<stdio.h>
#include<stdlib.h>

int Number(int n){
	for (int i = 2; i < n; ++i){
		if (n%i == 0){
			return 0;
		}
	}
	return 1;
}

int main(){
	for (int n = 100; n < 200; ++n){
		if (Number(n) == 1){
			printf("%d\n", n);
		}
	}
	system("pause");
	return 0;
}