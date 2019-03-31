//#define _CRT_SECURE_NO_WARNINGS
////4.将三个数按从大到小输出。
//#include<stdio.h>
//#include<stdlib.h>
//
//int main(){
//	int arr[3] = { 0 };
//	int max = 0;
//	int min = 0;
//	printf("输入三个数(中间用逗号分隔):\n");
//	scanf("%d,%d,%d", &arr[0], &arr[1], &arr[2]);
//	if (arr[0] > arr[1]){
//		max = arr[0];
//		min = arr[1];
//	} else{
//		max = arr[1];
//		min = arr[0];
//	}
//	if (max > arr[2]&&min>arr[2]){
//		printf("%d %d %d\n", max, min, arr[2]);
//	} else if (max > arr[2] && arr[2] > min){
//		printf("%d %d %d\n", max, arr[2], min);
//	} else{
//		printf("%d %d %d", arr[2], max, min);
//	}
//	system("pause");
//	return 0;
//}