#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Bitonecount(int num){
	//����һ: ���ܴ��� num Ϊ���������
	//int count = 0;
	//while (num){
	//	if (num % 2 == 1){
	//		++count;
	//	}
	//	num >>= 1;
	//}

	//������: ֱ��ʹ����λ������λ����
	int count = 0;
	for (int i = 0; i < 32; ++i){
		//ѭ��һ���ڳ��� num ������ÿһλ
		//��� num �����Ķ�ӦλΪ 0 ,��λ��Ľ��һ���� 0
		//��� num �����Ķ�ӦλΪ 1 ,
		if (num&(1 << i)){
			++count;
		}
	}
	return count;
}


int main(){
	//��һ�����ֶ�����1�ĸ���
	int ret = Bitonecount(10);
	printf("ret=%d\n", ret);
	////λ����
	//// &��λ��
	//int num1 = 7;
	//int num2 = 4;
	//printf("%d\n", num1&num2);

	////  | ��λ��,ȫ0 Ϊ0,��һΪһ

	////  ^ ��λ���,�����ͬΪ0,�������Ϊ1

	system("pause");
	return 0;
}