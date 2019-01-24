#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Bitonecount(int num){
	//方法一: 不能处理 num 为负数的情况
	//int count = 0;
	//while (num){
	//	if (num % 2 == 1){
	//		++count;
	//	}
	//	num >>= 1;
	//}

	//方法二: 直接使用移位操作和位操作
	int count = 0;
	for (int i = 0; i < 32; ++i){
		//循环一次在尝试 num 变量的每一位
		//如果 num 变量的对应位为 0 ,按位与的结果一定是 0
		//如果 num 变量的对应位为 1 ,
		if (num&(1 << i)){
			++count;
		}
	}
	return count;
}


int main(){
	//求一个数字二进制1的个数
	int ret = Bitonecount(10);
	printf("ret=%d\n", ret);
	////位操作
	//// &按位与
	//int num1 = 7;
	//int num2 = 4;
	//printf("%d\n", num1&num2);

	////  | 按位或,全0 为0,有一为一

	////  ^ 按位异或,如果相同为0,如果相异为1

	system("pause");
	return 0;
}