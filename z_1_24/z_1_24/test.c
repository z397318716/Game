#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//�ṹ��
struct Student{
	char name[1024];
	int age;
};

int main(){
	//// ~ ��λȡ��
	//// ! �߼�ȡ��
	//unsigned int x = 0x0;
	//x = ~x;
	//unsigned int a = 0x0;
	//printf("x=%x\n", x);
	//a = !a;
	//printf("a=%x\n", a);

	//// & ��λ��  &&�߼���
	//// 01
	//int num1 = 0x1;
	//int num2 = 0x2;
	//printf("%x\n", num1 & num2);
	//printf("%x\n", num1 && num2);

	////   | ��λ��    || �߼���
	//int num1 = 0x1;
	//int num2 = 0x2;
	//printf("%x\n", num1 | num2);
	//printf("%x\n", num1 || num2);

	////������ǰ�� ++  ���Ǻ��� ++ ,�����ȥȡ���ʽ�ķ���ֵ,��������ȫû������
	//int x = 0;
	//++x;
	//x++;
	
	//int x = 0;
	////int ret = ++x;
	//int ret1 = x++;
	////printf("%d\n", ret);
	//printf("%d\n", ret1);

	//int i = 1;
	//int ret = (++i) + (++i) + (++i);
	//printf("ret=%d\n", ret);

	//int i = 0, a = 0, b = 2, c = 3, d = 4;
	//// ��·��ֵ
	////���߼��������˵,�����������κ�һ��Ϊ0,�����ȻΪ0
	////������ֵ�һ�����������ʽ�Ѿ���0��,�Ͳ���Ҫ�Եڶ��������ֵ��
	////�߼��������˵,�����������κ�һ��Ϊ��0,�����ȻΪ��
	////������ֵ�һ�����������ʽ�Ѿ���0��,�Ͳ���Ҫ�Եڶ������ʽ��ֵ��
	//i = a++ && ++b && d++;
	////i=a++ || ++b || d++;
	//printf("a=%d\n b=%d\n c=%d\n d=%d\n", a, b, c, d);

	//// ��Ŀ�����
	//int a = 10;
	//int b = 20;
	//if (a > b){
	//	printf("%d\n", a);
	//}
	//else{
	//	printf("%d\n", b);
	//}
	////�����Ƚϴ�С  ��������Ŀ���������
	//a > b ? printf("%d\n", a) : printf("%d\n", b);


	//  python  ����(��������ֵ)
	// a=10
	// b=20
	//a , b = b , a


	//  .  ��Ա���ʲ�������ֱ�Ӹ��ṹ�����ʹ�õ�
	//  ->  ��Ա���ʲ�����,�Ǹ�ָ��һ���ṹ�������ָ����ʹ�õ�
	struct Student student;
	strcpy(student.name, "tz");
	student.age = 10;

	system("pause");
	return 0;
}