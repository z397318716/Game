////用递归实现求一个数的k 次方
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int Index(int n, int k){
//	if (k == 0){
//		return 1;
//	}
//	else if (k == 1){
//		return n;
//	}
//	else {
//		return n*Index(n, k - 1);
//	}
//
//}
//
//int main(){
//	int n = 0;
//	int k = 0;
//	printf("请输入底数和指数(中间用逗号隔开)");
//	scanf("%d,%d",&n, &k);
//	printf("%d\n", Index(n, k));
//	system("pause");
//	return 0;
//}