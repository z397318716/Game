
#include "seqList.h"
#include "slist.h"

//int main()
void main_morning()
{
	SeqList test;

	SeqListInit(&test, 10);

	SeqListPushBack(&test, 1);
	SeqListPushBack(&test, 2);
	SeqListPushBack(&test, 3);
	SeqListPushBack(&test, 4);
	SeqListPushBack(&test, 5);
	SeqListPushBack(&test, 6);
	SeqListPushBack(&test, 7);
	
	SeqListPushFront(&test, 6);

	SeqListInsert(&test, 1, 78);


	SeqListErase(&test, 2);

	SeqListBubbleSort(&test);
	printf("%d\n",SeqListBinaryFind(&test, 4));

	SeqListPrint(&test);


	SeqListDestory(&test);

	system("pause");
	return 0;
}

void list_test()
{
	SList test;
	SListInit(&test);


	SListPushFront(&test, 1);
	SListPushFront(&test, 2);
	SListPushFront(&test, 3);
	SListPushFront(&test, 4);
	SListPushFront(&test, 5);
	SListPushFront(&test, 6);

	SListFind(&test, 3);

	SListPopFront(&test);
	SListPrint(&test);
	SListReverse(&test);
	SListPrint(&test);
	
}

int main()
{

	list_test();
	return 0;
}