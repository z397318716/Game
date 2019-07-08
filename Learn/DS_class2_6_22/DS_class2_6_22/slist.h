#ifndef _SLIST_H_
#define _SLIST_H_


/*
//������ͷ�������
for(cur = head; cur; cur = cur->_next)
{
	cur;
}
//˫����ͷ�������
for(cur = head->_next; cur != _head; cur = cur->_next)
{
	cur;
}


*/



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>





// 1����ͷ�����ѭ��������ɾ���ʵ�� 
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
void SListInsertAfter(SListNode* pos, SLTDataType x); // ��pos��ǰ����в��� 
void SListEraseAfter(SListNode* pos); 
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist); 
void TestSList();
void SListReverse(SList* plist);
#endif