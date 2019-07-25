#pragma once




typedef int SDataType;

typedef struct Stack
{
	SDataType* _array;
	int _capacity;
	int _size;		//表示栈中有效元素个数  代表栈顶位置
}Stack;


void StackInit(Stack* ps);
void StackPush(Stack* ps, SDataType data);
void StackPop(Stack* ps);
SDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
int StackEmpty(Stack* ps);
void StackDestroy(Stack* ps);
void CheckCapacity(Stack* ps);