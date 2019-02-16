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

	////普通的指针变量,指针类型,表示指针指向的变量的类型
	////一个普通的指针,知道对应这个变量的房间号,以及房间的大小
	////但是对于 void* 来说,只知道房间号,但是不关注房间大小
	////1. void*  类型指针不能解引用
	////2. void* 类型的指针不能和整数进行相加减
	////3. void*  类型的两个指针也不能相减
	//// 由于 void* 类型的指针不关注房间大小,从而这个指针里面就可以保存
	//// 各种不同类型的指针了.
	//// 通过 void* 这样的特性,可以达到一定程度上的"泛型编程"
	//int a = 10;
	//void* p = &a;
	//char b = 'a';
	//p = &b;
	//printf("%d\n", p);
	//printf("%d\n", p+1);
	
	//// 数组名可以当做指向数组首元素的指针来使用
	//int arr[10] = { 0 };
	//printf("%p\n", arr);
	//printf("%p\n", &arr[0]);

	//int arr[5] = { 1,2,3,4,5 };
	//printf("%d\n", arr[2]);
	//int* p = arr;
	////以下两种写法是等价的
	//printf("%d\n", p[2]);
	//printf("%d\n", *(p + 2));

	//int arr[5] = { 1, 2, 3, 4, 5 };
	//printf("%d\n", arr[2]);
	//int* p = arr;
	//int* p2 = &arr[4];
	//printf("%d\n", p2 - p);//指针间差了 4 个整形变量 (4个房间)
	////两个指针都指向同一个数组的时候,此时做减法才是有意义的
	////否则,得到的结果是没有意义的

	////经常会使用 NULL 作为一个非法的值
	////假设有一个这样的需求
	//int arr[5] = { 1, 2, 3, 4, 5 };
	//int* p = Find(arr, sizeof(arr) / sizeof(arr[0]),3);
	//if (arr == NULL){
	//	printf("没找到\n");
	//}
	//else{
	//	printf("找到了,地址为%p\n",p);
	//}

	////一般可以使用 typedef 使得二级指针看起来是个一级指针
	//typedef int* int_ptr;
	//int n = 100;
	//int_ptr p = &n;
	//int_ptr* pp=&p
	//**p

	////指针数组  vs  数组指针
	////指针数组,也是一个数组,只不过数组中的元素,是指针类型的变量
	//int* arr[10];
	////数组指针,也是一个指针,只不过这个指针指向了一个数组

	//Student student = {"tz",100};
	////读
	//printf("%d\n", student.score);
	////写
	//student.score = 60;
	//Student* p = &student;
	////以下两个写法等价
	////(*p).score = 90;
	////p->score = 90;

	////一个空指针对应的内存,既不能读,也不能写
	////不能对 空指针 解引用
	//Student* p = NULL;
	//printf("%d\n", p->score);
	//
	////带有垃圾回收机制的编程语言,都具有 STW 问题  (stop the world)

	system("pause");
	return 0;
}

