#include <stdio.h>
#include <stdlib.h>


int* Find(int arr[], int size, int to_find){
	for (int i = 0; i < size; ++i){
		if (arr[i] == to_find){
			return &arr[i];
		}
	}
	return NULL;
}

typedef struct Student {
	char name[1024];
	int score;
}student;

typedef struct Data{
	int arr[100];
	int size;
}Data;
void Printdata(Data data){
	for (int i = 0; i < 100; ++i){
		printf("%d\n", data.arr[i]);
	}
	printf("%d\n", data.size);
}

int main(){

	Data data = { { 0 },100 };
	Printdata(data);

	////��ͨ��ָ�����,ָ������,��ʾָ��ָ��ı���������
	////һ����ͨ��ָ��,֪����Ӧ��������ķ����,�Լ�����Ĵ�С
	////���Ƕ��� void* ��˵,ֻ֪�������,���ǲ���ע�����С
	////1. void*  ����ָ�벻�ܽ�����
	////2. void* ���͵�ָ�벻�ܺ�����������Ӽ�
	////3. void*  ���͵�����ָ��Ҳ�������
	//// ���� void* ���͵�ָ�벻��ע�����С,�Ӷ����ָ������Ϳ��Ա���
	//// ���ֲ�ͬ���͵�ָ����.
	//// ͨ�� void* ����������,���Դﵽһ���̶��ϵ�"���ͱ��"
	//int a = 10;
	//void* p = &a;
	//char b = 'a';
	//p = &b;
	//printf("%d\n", p);
	//printf("%d\n", p+1);
	
	//// ���������Ե���ָ��������Ԫ�ص�ָ����ʹ��
	//int arr[10] = { 0 };
	//printf("%p\n", arr);
	//printf("%p\n", &arr[0]);

	//int arr[5] = { 1,2,3,4,5 };
	//printf("%d\n", arr[2]);
	//int* p = arr;
	////��������д���ǵȼ۵�
	//printf("%d\n", p[2]);
	//printf("%d\n", *(p + 2));

	//int arr[5] = { 1, 2, 3, 4, 5 };
	//printf("%d\n", arr[2]);
	//int* p = arr;
	//int* p2 = &arr[4];
	//printf("%d\n", p2 - p);//ָ������ 4 �����α��� (4������)
	////����ָ�붼ָ��ͬһ�������ʱ��,��ʱ�����������������
	////����,�õ��Ľ����û�������

	////������ʹ�� NULL ��Ϊһ���Ƿ���ֵ
	////������һ������������
	//int arr[5] = { 1, 2, 3, 4, 5 };
	//int* p = Find(arr, sizeof(arr) / sizeof(arr[0]),3);
	//if (arr == NULL){
	//	printf("û�ҵ�\n");
	//}
	//else{
	//	printf("�ҵ���,��ַΪ%p\n",p);
	//}

	////һ�����ʹ�� typedef ʹ�ö���ָ�뿴�����Ǹ�һ��ָ��
	//typedef int* int_ptr;
	//int n = 100;
	//int_ptr p = &n;
	//int_ptr* pp=&p
	//**p

	////ָ������  vs  ����ָ��
	////ָ������,Ҳ��һ������,ֻ���������е�Ԫ��,��ָ�����͵ı���
	//int* arr[10];
	////����ָ��,Ҳ��һ��ָ��,ֻ�������ָ��ָ����һ������

	//Student student = {"tz",100};
	////��
	//printf("%d\n", student.score);
	////д
	//student.score = 60;
	//Student* p = &student;
	////��������д���ȼ�
	////(*p).score = 90;
	////p->score = 90;

	////һ����ָ���Ӧ���ڴ�,�Ȳ��ܶ�,Ҳ����д
	////���ܶ� ��ָ�� ������
	//Student* p = NULL;
	//printf("%d\n", p->score);
	//
	////�����������ջ��Ƶı������,������ STW ����  (stop the world)

	system("pause");
	return 0;
}

