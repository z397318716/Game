#include <stdio.h>
#include "Stack.h"


void TestStack()
{
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));

	StackPush(&s, 4);
	StackPush(&s, 5);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));

	StackPop(&s);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));

	StackDestroy(&s);
}



int main()
{
	TestStack();


	return 0;
}