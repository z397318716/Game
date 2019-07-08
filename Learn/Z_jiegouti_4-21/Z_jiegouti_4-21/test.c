#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//通讯录,需要在代码中表示若干个人

typedef struct personInfo{
	char name[1024];
	char phone[1024];
}personInfo;

#define SIZE 1000

typedef struct AddrBook{
	//SIZE 表示是通讯录中信息的上限
	personInfo person_info[SIZE];
	//通讯录并不是程序一启动,里面的 1000 条数据都是有意义的
	//所以需要标注出来哪些信息是有意义的,哪些信息是没有意义的
	// [0,size) 有意义的区间
	int size;
}AddrBook;

//创建一个通讯录的变量,(需对其进行初始化)
AddrBook g_addr_book;

enum{
	EXIT = 0,
	ADD,
	DEL,
	MODIFY,     //修改
	FIND,
	PRINT,
	CLEAR,
	SORT
};

void Init(){
	g_addr_book.size = 0;

	//方案1 (初始化)
	for (int i = 0; i < SIZE; ++i)
	{
		strcpy(g_addr_book.person_info[i].name, "");
		strcpy(g_addr_book.person_info[i].phone, "");
	}
	//方案2 
	memset(g_addr_book.person_info, 0x0, sizeof(g_addr_book.person_info));
}

int Menu(){
	// 打印出给用户提供的操作,
	// 提示用户进行输入
	// 把用户输入的结果返回
	printf("==========================\n");
	printf("1.添加\n");
	printf("2.删除\n");
	printf("3.修改\n");
	printf("4.查找\n");
	printf("5.显示\n");
	printf("6.清除\n");
	printf("7.排序\n");
	printf("0.退出\n");
	printf("==========================\n");
	printf("请输入选择:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}


void AddPersonInfo()   
{

	//添加一个用户信息到通讯录中
	//提示用户输入相关的用户信息,然后把对应的数据更新到数组中

	//assert(g_addr_book.size < SIZE);  //此处不该使用断言,如果通讯录存满了,size越界会导致程序崩溃
	if (g_addr_book.size >= SIZE)
	{
		printf("当前通讯录已满,插入信息失败!\n");
		return;
	}
	printf("添加一个新用户\n");
	printf("请输入用户名:\n");
	//下标为 size 的位置就是我们需要放置的新元素的位置
	scanf("%s", g_addr_book.person_info[g_addr_book.size].name);
	printf("请输入电话号码: ");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].phone);
	++g_addr_book.size;
	printf("插入成功!\n");
	return;
}

//按照用户信息的编号进行删除
void DelPersonInfo()
{
	printf("删除指定记录!\n");
	printf("请输入要删除的条目的编号: ");
	int num = 0;
	scanf("%d", &num);
	if (num < 0 || num > g_addr_book.size)
	{
		printf("输入的编号不合法!删除失败!\n");
		return;
	}
	//此时采取一种比较简单的方案
	//1. 如果用户要删除的是最后一个元素, 直接 --g_addr_book.size
	if (num != g_addr_book.size - 1)
	{
		//该位置元素 可覆盖,也可不覆盖
		//2. 如果用户要删除的是中间某个位置元素,就把最后一个元素填充到该位置
		strcpy(g_addr_book.person_info[num].name, g_addr_book.person_info[g_addr_book.size - 1].name);
		strcpy(g_addr_book.person_info[num].phone, g_addr_book.person_info[g_addr_book.size - 1].phone);
	}
	--g_addr_book.size;
	printf("删除成功!\n");
	return;
}

//修改某个用户信息,用户输入一个进行修改的编号,然后根据编号进行修改
void ModifyPersonInfo()
{
	printf("修改某条记录!\n");
	printf("请输入要修改的信息的编号: ");
	int num = 0;
	scanf("%d", &num);
	if (num < 0 || num > g_addr_book.size)
	{
		printf("输入的编号不合法,修改失败!\n");
		return;
	}
	printf("请输入新的用户名: ");
	scanf("%s", g_addr_book.person_info[num].name);
	printf("请输入新的电话号码: ");
	scanf("%s", g_addr_book.person_info[num].phone);
	printf("修改成功!\n");
}

//根据用户名查找对应的电话号码
void FindPersonInfo()
{
	int count = 0;
	printf("查找电话号码!\n");
	printf("请输入要查找的姓名: ");
	char name[1024] = { 0 };
	scanf("%s", name);

	for (int i = 0; i < g_addr_book.size; ++i)
	{
		if (strcmp(name, g_addr_book.person_info[i].name) == 0)
		{
			printf("找到一条结果! 电话号码为: %s\n",g_addr_book.person_info[i].phone);
			++count;
		}
	}
	if (count == 0)
	{
		printf("没找到指定姓名!\n");
	}
	else
	{
		printf("查找成功!共找到 %d 条记录\n",count);
	}
}

//打印所有用户信息
void PrintPersonInfo()
{
	printf("打印所有用户信息!\n");
	for (int i = 0; i < g_addr_book.size; ++i)
	{
		printf("[%d] %s %s\n",i, g_addr_book.person_info[i].name, g_addr_book.person_info[i].phone);
	}
	printf("打印完成!共打印了 %d 条记录!", g_addr_book.size);
	return;
}

// rm -rf /
void ClearPersonInfo()
{
	printf("清除所有用户信息!\n");
	printf("确定删除?(y/n)\n");
	char input[1024] = { 0 };
	scanf("%s", input);
	if (strcmp(input, "y") != 0)
	{
		printf("取消删除操作!\n");
		return;
	}
	g_addr_book.size = 0; 
	printf("清空成功!\n");
}

// 按照姓名排序
void Sort()
{
	int i, j = 0;
	char tmp[1024] = " ";
	for (i = 0; i < g_addr_book.size - 1;++i)
	{
		for (j = 0; j < g_addr_book.size - i - 1; ++j)
		{
			if (strcmp(g_addr_book.person_info[j].name, g_addr_book.person_info[j + 1].name) > 0)
			{
				strcpy(tmp,g_addr_book.person_info[j].name);
				strcpy(g_addr_book.person_info[j].name,g_addr_book.person_info[j + 1].name);
				strcpy(g_addr_book.person_info[j + 1].name,tmp);

			}
		}
	}
}


int main(){

	// 1. 先创建一个 通讯录 的变量,并且对该变量进行初始化
	Init();
	while (1)
	{

		// 2. 进入循环,打印一个用户菜单,并且提示用户进行操作
		//    增删查改
		
		int choice = Menu();
		// 3. 用户输入了相应的编号之后,就调用对应的操作函数,完成具体的 增删查改
		switch (choice)
		{
		case ADD:
			AddPersonInfo();
			break;
		case DEL:
			DelPersonInfo();
			break;
		case MODIFY:
			ModifyPersonInfo();
			break;
		case FIND:
			FindPersonInfo();
			break;
		case PRINT:
			PrintPersonInfo();
			break;
		case CLEAR:
			ClearPersonInfo();
			break;
		case SORT:
			Sort();
			break;
		case EXIT:
			printf("退出!\n");
			system("pause");
			return 0;  //此时如果 break 可以跳出当前这个switch语句,跳不出 while循环
		default:
			break;
		}
	}

	system("pause");
	return 0;
}