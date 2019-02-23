////递归和非递归分别实现求n的阶乘
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//
//////非递归实现 n 的阶乘
////int Non_Factorial(int num){
////	if (num == 0 || num == 1){
////		return 1;
////	}
////	else{
////		int tmp = num;
////		for (; num > 1; --num){
////			tmp = tmp*(num - 1);
////		}
////		return tmp;
////	}
////}
//
////递归实现 n 的阶乘
//int Factorial(int num){
//	if (num == 0 || num == 1){
//		return 1;
//	}
//	else{
//		int tmp = num;
//		for (; num > 1; num--){
//			tmp = tmp*Factorial(num-1);
//		}
//		return tmp;
//	}
//}
//int main(){
//	int n = 0;
//	while (1){
//		printf("请输入整数n:");
//		scanf("%d", &n);
//		if (n < 0){
//			printf("非法输入(负数没有阶乘)\n");
//		}
//		else{
//			//printf("%d\n", Non_Factorial(n));
//			printf("%d\n", Factorial(n));
//		}
//	}
//	system("pause");
//	return 0;
//}