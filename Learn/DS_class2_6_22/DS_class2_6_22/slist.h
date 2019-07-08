#ifndef _SLIST_H_
#define _SLIST_H_


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



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>





// 1、无头单向非循环链表增删查改实现 
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plist);
void SListDestory(SList* plist);

SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
SListNode* SListFind(SList* plist, SLTDataType x); 
void SListInsertAfter(SListNode* pos, SLTDataType x); // 在pos的前面进行插入 
void SListEraseAfter(SListNode* pos); 
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist); 
void TestSList();
void SListReverse(SList* plist);
#endif