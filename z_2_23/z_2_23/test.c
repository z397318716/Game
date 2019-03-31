#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//通讯录,需要在代码中表示若干个人
typedef struct Personinfo{
	char name[1024];
	char iphone[1024];
}Personinfo;
#define SIZE 1000

typedef struct Addrbook{
	//SIZE 表示通讯录中信息的上限
	Personinfo person_info[SIZE];
	//需要标注出哪些信息是有意义的,哪些信息是没有意义的
	//通讯录并不是程序一启动,里面的 1000条数据都是有意义的
	//[0,1000) 有意义是区间
	int size;
}Addrbook;


Addrbook g_addr_book;

enum{
	EXIT = 0,
	ADD,
	DEL,
	MODIFY,       //修改
	FIND,         //查找某条记录
	PRINT,        //打印所有内容
	CLEAR,        //清空所有内容
};

void Init() {
	g_addr_book.size = 0;

	//初始化两种方式 1.for 循环方式   2. memset  方式
	//for (int i = 0; i < SIZE; ++i){
	//	strcpy(g_addr_book.person_info[i].name, "");
	//	strcpy(g_addr_book.person_info[i].iphone, "");
	//}

	memset(g_addr_book.person_info, 0x0, sizeof(g_addr_book.person_info));

};

int Menu(){
	// to do 打印出给用户提供的操作
	//并且提示用户进行输入
	//把用户输入的结果返回出来
	printf("===================\n");
	printf("1.添加\n");
	printf("2.删除\n");
	printf("3.修改\n");
	printf("4.查找\n");
	printf("5.显示\n");
	printf("6.清除\n");
	printf("0.退出\n");
	printf("===================\n");
	printf("请输入您的选择: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Addpersoninfo(){
	// 添加一个用户信息到通讯录中
	//提示用户输入相关的用户信息,然后把对应的数据更新到数组中

	//断言不适合用 (尽量不要乱用)
	//assert(g_addr_book.size < SIZE);
	if (g_addr_book.size >= SIZE){
		printf("当前通讯录已满,插入失败!\n");
		return;
	}

	printf("添加一个新用户!\n");
	printf("请输入用户名: ");
	// 下标为 size 的位置就是我们需要放置的新元素的位置
	scanf("%s", g_addr_book.person_info[g_addr_book.size].name);
	printf("请输入电话号码: ");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].iphone);
	++g_addr_book.size;
	printf("插入成功!\n");
	return;
}

// 按照用户信息的编号进行删除
void Delpersoninfo(){
	printf("删除指定记录!\n");
	printf("请输入要删除的条目的编号: ");
	int num = 0;
	scanf("%d", &num);
	if (num<0 || num>g_addr_book.size){
		printf("输入的编号不合法!删除失败!\n");
		return;
	}
	// 此时采取简单的方案,
	//1.如果用户要删除的是最后一个元素,那么就直接  --size
	//2.如果用户要删除的是某个中间位置的元素,就把最后一个元素填充到该位置上,在删除最后一条记录

	if (num != g_addr_book.size - 1){
		//2.如果用户要删除的是某个中间位置的元素,就把最后一个元素填充到该位置上,在删除最后一条记录
		strcpy(g_addr_book.person_info[num].name, g_addr_book.person_info[g_addr_book.size - 1].name);
		strcpy(g_addr_book.person_info[num].iphone, g_addr_book.person_info[g_addr_book.size - 1].iphone);
		
	} else{
		//如果用户要删除的是最后一个元素,那么就直接  --size
		// 这个元素的内容是否需要覆盖掉,覆盖或者不覆盖都可以
		--g_addr_book.size;
	}
	printf("删除成功!\n");
	return;

}

//修改某个用户信息,用户输入一个需要修改的编号,然后根据编号进行修改
void Modifypersoninfo(){
	printf("修改某条记录!\n");
	printf("请输入要修改的信息的编号: ");
	int num = 0;
	scanf("%d", &num);
	if (num < 0 || num >= g_addr_book.size){
		printf("输入的编号不合法,修改失败!\n");
		return;
	} else{
		printf("请输入新的用户名: ");
		scanf("%s", g_addr_book.person_info[num].name);
		printf("请输入新的用户号码: ");
		scanf("%s", g_addr_book.person_info[num].iphone);
		printf("修改成功!\n");
	}

}

// 根据用户名查找对应的电话号码
void Findpersoninfo(){
	printf("查找电话号码!\n");
	printf("请输入要查找的姓名: ");
	char name[1024] = { 0 };
	scanf("%s", name);
	for (int i = 0; i <= g_addr_book.size; ++i){
		if (strcmp(name, g_addr_book.person_info[i].name) == 0){
			printf("找到一条结果!电话号码为: %s\n", g_addr_book.person_info[i].iphone);

		}
	}
}

//打印所有的用户信息
void Printpersoninfo(){
	printf("打印所有用户信息!\n");
	for (int i = 0; i < g_addr_book.size; ++i){
		printf("[%d][%s] %s\n",i, g_addr_book.person_info[i].name,
			g_addr_book.person_info[i].iphone);
	}
	printf("打印完成! 共打印了 %d 条记录!\n", g_addr_book.size);
	return;

}

//  rm -rf /    删库跑路
void Clearpersoninfo(){
	printf("清除所有用户信息!\n");
	printf("是否确认删除所有用户信息?(y/n)\n");
	char input[1024] = { 0 };
	scanf("%s", input);
	if (strcmp(input, "y") != 0){
		printf("取消了删除操作!\n");
		return;
	}
	g_addr_book.size = 0;
	printf("清空成功!\n");

}

int main(){
	// 1.先创建一个 通讯录 的变量,并且也需要对这个变量进行初始化
	Init();
	while (1){
		// 2.进入循环,打印一个用户菜单,并且提示用户进行操作
		// 增删查改
		int choice = Menu();
		// 3.用户输入了相应的编号之后,就调用相应的操作函数,完成具体的增删查改
		switch (choice){
		case ADD:
			Addpersoninfo();
			break;
		case DEL:
			Delpersoninfo();
			break;
		case MODIFY:
			Modifypersoninfo();
			break;
		case FIND:
			Findpersoninfo();
			break;
		case PRINT:
			Printpersoninfo();
			break;
		case CLEAR:
			Clearpersoninfo();
			break;
		case EXIT:
			printf("Goodbye!\n");
			system("pause");
			return 0;
		default:
			break;
		}
	
	}
	system("pause");
	return 0;
}