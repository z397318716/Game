#include<stdio.h>
#include<stdlib.h>
#include<string.h>
////Cmpare 是 qsort 的比较函数,Cmpare 的调用时机不是由程序员决定的,而是由 qsort 内部来决定的
////像这种风格的函数,叫做 "回调函数".
//int Cmpare(void* p1,void* p2){
//	int* a = (int*)p1;
//	int* b = (int*)p2;
//	//如果 *a<*b,相当于让函数返回真.  *a>=*b,函数就返回假
//	// p1 和 p2,如果期望 p2 指向的元素在 p1 的前面,返回真
//	return *a < *b;
//}
//
//
int main(){
	//	//int arr[] = { 9, 5, 2, 7 };
	//	////qsort 实现是基于快速排序算法
	//	//qsort(arr,sizeof(arr)/sizeof(arr[0]),sizeof(arr[0]),&Cmpare);//取地址符可写可不写
	//	//for (int i = 0; i < 4; ++i){
	//	//	printf("%d\n", arr[i]);
	//	//}
	//
	//	int a[] = { 1, 2, 3, 4 };
	//	printf("%d\n", sizeof(a));//16
	//	printf("%d\n", sizeof(a+0));//4  a 已经隐式转换成了指针  拿数字加减数组名 得到了指针 求的是指针的大小
	//	printf("%d\n", sizeof(*a));//4  
	//	printf("%d\n", sizeof(a+1));//4
	//	printf("%d\n", sizeof(a[1]));//4
	//	printf("%d\n", sizeof(&a));//4   &a 数组指针
	//	printf("%d\n", sizeof(*&a));//16 &a 数组指针  *&a  对 &a数组指针 解引用得到的仍然是原来的数组
	//	printf("%d\n", sizeof(&a+1));//4
	//	printf("%d\n", sizeof(&a[0]));//4
	//	printf("%d\n", sizeof(&a[0]+1));//4
	//
	//
	//	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	//	printf("%d\n", sizeof(arr));//6
	//	printf("%d\n", sizeof(arr + 0));//4   隐式转换成指针
	//	printf("%d\n", sizeof(*arr));//1
	//	printf("%d\n", sizeof(arr[1]));//1
	//	printf("%d\n", sizeof(&arr));//4     &arr 数组指针
	//	printf("%d\n", sizeof(&arr+1));//4
	//	printf("%d\n", sizeof(&arr[0]+1));//4
	//
	//
	//	printf("%d\n", strlen(arr));//值不确定  会一直尝试找到 \0   
	//	printf("%d\n", strlen(arr+0));//同上
	//	printf("%d\n", strlen(*arr));//程序崩溃   *arr 解引用arr 取到的是第一个字符,此时不应该进行 strlen 操作 类型不相同
	//	printf("%d\n", strlen(arr[1]));//同上
	//	printf("%d\n", strlen(&arr));//  strlen 不管是数组还是指针 都是一直尝试找 \0 
	//	printf("%d\n", strlen(&arr+1));//同上
	//	printf("%d\n", strlen(&arr[0]+1));//指针  同上
	//	//皆是未定义行为
	//
	//	char arr[] = "abcdef";// 此时 arr 中就包含了  \0
	//	printf("%d\n", sizeof(arr));//7   \0 也被算上了
	//	printf("%d\n", sizeof(arr+0));//4    隐式转换成 指针
	//	printf("%d\n", sizeof(*arr));//1     取到的是首元素
	//	printf("%d\n", sizeof(arr[1]));//1
	//	printf("%d\n", sizeof(&arr));//4   指针
	//	printf("%d\n", sizeof(&arr+1));//4
	//	printf("%d\n", sizeof(&arr[0])+1);//4
	//	
	//	printf("%d\n", strlen(arr));//strlen 求字符串长度的时候,不会计算末尾的  \0
	//	printf("%d\n", strlen(arr + 0));//6
	//	printf("%d\n", strlen(*arr));//程序崩溃  
	//	printf("%d\n", strlen(arr[1]));
	//	printf("%d\n", strlen(&arr));//6
	//	printf("%d\n", strlen(&arr + 1));//  数组指针 +1  就跳过了这个完整数组  在找 \0 
	//	printf("%d\n", strlen(&arr[0] + 1));//5   首元素 + 1 到下一个元素 然后 在 strlen
	//
	//
	//	char* p = "abcdef";
	//	printf("%d\n", sizeof(p));//4
	//	printf("%d\n", sizeof(p+1));//4
	//	printf("%d\n", sizeof(*p));//1
	//	printf("%d\n", sizeof(p[0]));//1
	//	printf("%d\n", sizeof(&p));//4     指针在 & 变成 二级指针
	//	printf("%d\n", sizeof(&p+1));//4
	//	printf("%d\n", sizeof(&p[0]+1));//4
	//	
	//
	//	printf("%d\n", strlen(p));//6
	//	printf("%d\n", strlen(p+1));// 普通指针 只跳过一个元素  数组指针 +1 会跳过整个数组
	//	printf("%d\n", strlen(*p));// 程序崩溃        
	//	printf("%d\n", strlen(p[0]));//同上
	//	printf("%d\n", strlen(&p));//
	//	printf("%d\n", strlen(&p+1));//
	//	printf("%d\n", strlen(&p[0]+1));//

	//   int a[3][4] = { 0 };
	//printf("%d\n", sizeof(a));//48
	//printf("%d\n", sizeof(a[0][0]));//4
	//printf("%d\n", sizeof(a[0]));//16
	//printf("%d\n", sizeof(a[0]+1));//4  只要进行了 数学运算 就变成了 数组指针
	//printf("%d\n", sizeof(*(a[0]+1)));//4   等价于 a[0][1]
	//printf("%d\n", sizeof(a+1));//4
	//printf("%d\n", sizeof(*(a+1)));//16     *(a+1)  相当于 a[1]
	//printf("%d\n", sizeof(&a[0]+1));//4
	//printf("%d\n", sizeof(*(&a[0]+1)));//16   数组指针解引用 得到 数组
	//printf("%d\n", sizeof(*a));//16   *a 相当于 a[0]
	//printf("%d\n", sizeof(a[3]));//16

	////指针笔试题1:

	//int a[5] = { 1, 2, 3, 4, 5 };
	//int* ptr = (int*)(&a + 1);// ptr 指向比较关键 &a+1 得到的结果是一个指向数组最后一个元素的下一个位置的地址
	//printf("%d,%d", *(a + 1), *(ptr - 1));//2  5

	////指针笔试题3:
	//int a[4] = { 1, 2, 3, 4 };
	//int* ptr1 = (int*)(&a + 1);
	//int* ptr2 = (int*)((int)a + 1);
	//printf("%x,%x", ptr1[-1], *ptr2);
	
	////指针笔试题4:;
	//int a[3][2] = { (0, 1), (2, 3), (4, 5) };//(0,1)  逗号表达式,值就是逗号后的元素 1
	//int* p;
	//p = a[0];
	//printf("%d", p[0]);

	//int y = 1;
	//int z = 0;
	//z = y++;
	//printf("%d\n", z);

	////指针笔试题5:
	//int a[5][5];
	//int(*p)[4];//数组指针
	//p = a;
	//printf("a_ptr=%#p,p_ptr=%#p\n", &a[4][2], &p[4][2]);
	//printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);

	////指针面试题6:
	//int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//int* ptr1 = (int*)(&aa + 1);// ptr1 是一个指向二维数组的指针, +1,就跳过了整个二维数组
	//int* ptr2 = (int*)(*(aa + 1));//  ptr2 指向了第二行的首元素
	//printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));




	system("pause");
	return 0;
}