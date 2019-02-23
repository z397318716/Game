#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

// Student 是一种数据类型(结构体类型)
// 抽象:把具体的事物中比较关心的信息提取出来在代码中表示


typedef struct Student{
	char name[1024];
	int score;
}Student;

// 内存对齐是为了硬件计算起来效率更高而设计的.
typedef struct S1{
	double d;
	char i;
	int c2;
}S1;

 struct S2{
	char c1;//8
	struct S1;//16
	double d2;//8
}S2;

struct Node{
	int data;
	struct Node* n;
};

#define OFFSET(a,b)  ((char*)(&b)-(char*)(&a))

struct Data{
	int arr[1000];
	int size;
};

// 数组退化成指针
//结构体变量作为函数参数的时候,一般需要按指针的方式来传参
//目的只有一个,能够减少函数调用时的拷贝开销
void PrintData(struct Data data){
	printf("%d\n", sizeof(data));
	printf("%d\n", data.size);
}

struct A{
	int _a : 2;//表示 只占两个二进制位
	int _b : 5;//表示 只占五个二进制位
	int _c : 10;//表示 只占10个二进制位
	int _d : 30;//表示 只占30个二进制位
};

enum Day{//星期
	mon=1,
	tues,
	wed,
	thur,
	fri,
	sat,
	sun     //最后一个成员后面  可以加 ','   也可以不加  ','
};


//<<Effective C++>>
//第一节:
//C++ 是一门 "联邦语言"
//C++ 支持多种编程风格
// 1.兼容 C 的部分
// 2.面向对象的部分
// 3.泛型编程
// 4.STL 标准模板库
// 5.函数式编程的部分

//第二节:
//尽量不要使用宏 define
//尽量使用 const,enum,template,inline 代替宏定义常量




//C++第一个版本     C++ 98
//C++第二个版本     C++ 2003     相比于98,变化不大(修改了部分bug)
//C++第三个版本     C++ 0x  =>C++ 11(2011年发布), 翻天覆地的版本
//C++第四个版本     C++ 14       小版本(加入很多现代的编程语言的特性)
//C++第五个版本     C++ 17       现今最新版本

//   [](){}    在C++中  该语句相当于一个 匿名函数


union Un{
	int a;
	char i;
};


// ip 地址 :
// 192.168.86.1  
//    1. 点分十进制表示方式)四个部分 每个部分 0-255  
//    2. 也可以使用一个 32位的整数表示    
// 两种表示方式需要进行转换

union IP{
	
	uint32_t ip;         //相当于 unsigned int   需要使用预加载指令 #include<stdint.h>
	struct{
		uint8_t a;
		uint8_t b;
		uint8_t c;
		uint8_t d;
	} ip_;

};



int main(){

	////使用 typedef 将 struct Student 重命名 成 Student 
	////从而可以省略写 struct 直接写成 Student student
	////struct Student student;
	//Student student = {"zhangsan",100};
	//strcpy(student.name, "zhangsan");//这种方式也可以初始化


	////访问一个未被初始化的变量,就是未定义行为
	//printf("%s\n", student.name);//   .  表示 成员访问操作

	
	//printf("%d\n", sizeof(struct s2));
	
	 //S1 s1 ;
	 //printf("%d\n", OFFSET(s1, s1.i));

	//struct Data d = { {0},0 };
	//PrintData(&d);

	//printf("%d\n", sizeof(struct A));

	//printf("%d\n", tues);

	//union Un u;
	//printf("%d\n", sizeof(u));
	//printf("%p\n", &u);
	//printf("%p\n", &u.a);
	//printf("%p\n", &u.i);

	union IP ip;
	ip.ip = 0x12345678;
	printf("%d.%d.%d.%d\n", ip.ip_.a, ip.ip_.b, ip.ip_.c, ip.ip_.d);




	system("pause");
	return 0;
}