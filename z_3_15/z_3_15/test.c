//#include<stdio.h>
//#include<stdlib.h>
//
//
//
//int main(){
//
//	////未定义行为, malloc 和 free 是搭配使用的
//	//int arr[10] = { 0 };
//	//free(arr);
//
//
//	// billion--10亿字节--1GB   million--1百万字节--1MB
//
//	int* p = (int *)malloc(INT_MAX / 4);
//	printf("%p\n", p);
//	*p = 20;//如果p的值是 NULL,就会有问题
//
//
//
//
//	system("pause");
//	return 0;
//}