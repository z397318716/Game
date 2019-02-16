#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//结构体
struct Student{
	char name[1024];
	int age;
};

int main(){
	//// ~ 按位取反
	//// ! 逻辑取反
	//unsigned int x = 0x0;
	//x = ~x;
	//unsigned int a = 0x0;
	//printf("x=%x\n", x);
	//a = !a;
	//printf("a=%x\n", a);

	//// & 按位与  &&逻辑与
	//// 01
	//int num1 = 0x1;
	//int num2 = 0x2;
	//printf("%x\n", num1 & num2);
	//printf("%x\n", num1 && num2);

	////   | 按位或    || 逻辑或
	//int num1 = 0x1;
	//int num2 = 0x2;
	//printf("%x\n", num1 | num2);
	//printf("%x\n", num1 || num2);

	////无论是前置 ++  还是后置 ++ ,如果不去取表达式的返回值,这两种完全没有区别
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
	//// 短路求值
	////对逻辑与操作来说,两个操作数任何一个为0,结果必然为0
	////如果发现第一个操作数表达式已经是0了,就不需要对第二个表达求值了
	////逻辑或操作来说,两个操作数任何一个为非0,结果必然为真
	////如果返现第一个操作数表达式已经非0了,就不需要对第二个表达式求值了
	//i = a++ && ++b && d++;
	////i=a++ || ++b || d++;
	//printf("a=%d\n b=%d\n c=%d\n d=%d\n", a, b, c, d);

	//// 三目运算符
	//int a = 10;
	//int b = 20;
	//if (a > b){
	//	printf("%d\n", a);
	//}
	//else{
	//	printf("%d\n", b);
	//}
	////上述比较大小  可以用三目运算符来简化
	//a > b ? printf("%d\n", a) : printf("%d\n", b);


	//  python  代码(交换两个值)
	// a=10
	// b=20
	//a , b = b , a


	//  .  成员访问操作符是直接给结构体变量使用的
	//  ->  成员访问操作符,是给指向一个结构体变量的指针来使用的
	struct Student student;
	strcpy(student.name, "tz");
	student.age = 10;

	system("pause");
	return 0;
}