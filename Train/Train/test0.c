////�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
////�ݹ�ʵ��
//int Recursion(int a){
//	if (a > 2){
//		return Recursion(a - 2) + Recursion(a - 1);
//	}
//	else{
//		return 1;
//	}
//}
//
////�ǵݹ�ʵ��
//int Non_Recursion(int n){
//	int b1 = 1;
//	int b2 = 1;
//	int  tmp= 0;
//	if (n<= 2){
//		return 1;
//	}
//	else{
//		while(n>2){
//			tmp = b1 + b2;
//			b1 = b2;
//			b2=tmp;
//			--n;
//		}
//		return b2;
//	}
//}
//int main(){
//	int num = 0;
//	printf("������Ҫ��ĵڼ�λ쳲�������\n");
//	scanf("%d", &num);
//	printf("%d\n", Recursion(num));
//	printf("%d\n", Non_Recursion(num));
//	system("pause");
//	return 0;
//}