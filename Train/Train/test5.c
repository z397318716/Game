////�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//
//////�ǵݹ�ʵ�� n �Ľ׳�
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
////�ݹ�ʵ�� n �Ľ׳�
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
//		printf("����������n:");
//		scanf("%d", &n);
//		if (n < 0){
//			printf("�Ƿ�����(����û�н׳�)\n");
//		}
//		else{
//			//printf("%d\n", Non_Factorial(n));
//			printf("%d\n", Factorial(n));
//		}
//	}
//	system("pause");
//	return 0;
//}