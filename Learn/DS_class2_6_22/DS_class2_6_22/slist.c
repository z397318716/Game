#include "slist.h"

/*
//单向无头链表遍历
for(cur = head; cur; cur = cur->_next)
{
	cur;
}
//双向有头链表遍历
for(cur = head->_next; cur != _head; cur = cur->_next)
{
	cur;
}


*/

void SListInit(SList* plist)
{
	plist->_head = NULL;

}
void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* tmp;
	while (plist->_head)
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}

}


void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;

}

void SListPopFront(SList* plist)
{
	assert(plist);

	SListNode* tmp;
	if (plist->_head)
	{

		SListNode* tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

void SListPrint(SList* plist)
{
	assert(plist);

	SListNode* cur;
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("NULL\n");
}

SListNode* SListFind(SList* plist, SLTDataType x) 
{
	assert(plist);
	SListNode* cur;
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}
//未完
/*
void SListInsertFront(SListNode* plist, SLTDataType x,SLTDataType src)
{
	SListNode* cur;
	if (plist->_head->_data == x)
	{
		SListPushFront(plist, x);
		return;
	}
	for(cur = plist->_head;cur->_next;cur = cur->_next)
	{
		if(cur->_next->_data == x)
		{
			break;
		}
	}
	newdata->_data = src;
	newdata->_next = cur->_next;
	cur->_next = newdata;
}
*/

void SListInsertAfter(SListNode* pos, SLTDataType x) // 在pos的前面进行插入 
{
	assert(pos);

	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = pos->_next;
	pos->_next = cur;

}

void SListEraseAfter(SListNode* pos)
{
	SListNode* tmp = pos->_next;

	pos->_next = tmp->_next;
	free(tmp);
}

void SListReverse(SList* plist)
{
#if 0
	assert(plist->_head);
	SListNode* tmp = plist->_head->_next;
	SListNode* cur = plist->_head;
	while(tmp)                      //for (;;)    // while(1)   [循环条件留空->死循环]
	{
		cur->_next = tmp->_next;
		tmp->_next = plist->_head;

		plist->_head = tmp;
		tmp = cur->_next;

	}
#else
	SListNode* tmp = plist->_head->_next;  //记录 next
	SListNode* cur = plist->_head;
	cur->_next = NULL;                     //断链, 将头结点与他的 next 断开    有tmp记录 能找到

	while (tmp)						//每次循环都要完成断链,然后和旧头重新成链
	{
		plist->_head = tmp;                 //换新头, tmp 位置会成为新的头 , 
		tmp = tmp->_next;					//记录下次循环中 tmp 的位置,因为 tmp 在这次已经用完了,
		plist->_head->_next = cur;			//断链,与旧头形成新链
		cur = plist->_head;					//记录旧头位置,方便下次循环成链
	}
#endif
}
