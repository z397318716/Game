////写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int DigitSum(int num){
//	if (num < 10){
//		return num;
//	}
//	else{
//		return num % 10 + DigitSum(num / 10);
//	}
//}
//int main(){
//	while (1){
//		int n = 0;
//		printf("input:\n");
//		scanf("%d", &n);
//		if (n < 0){
//			printf("非法输入\n");
//		}
//		else{
//			printf("%d\n", DigitSum(n));
//		}
//	}
//	system("pause");
//	return 0;
//}