#include "Queue.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>



QNode* BuyQueueNode(QDataType data)
{
	QNode* pNewNode = (QNode*)malloc(sizeof(QNode));	//sizeof(QNode)  QNode不能加 *,加上* 表示申请的是节点的地址而不是节点
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}
void QueueInit(Queue* q)
{
	assert(q);
	q->_back = q->_front = NULL;
}
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* pNewNode = BuyQueueNode(data);
	if (QueueEmpty(q))
		q->_front = q->_back = pNewNode;
	q->_back->_pNext = pNewNode;
	q->_back = pNewNode;
}
void QueuePop(Queue* q)
{
	QNode* pDelNode = NULL;
	if (QueueEmpty(q))
		return;

	pDelNode = q->_front;
	if (NULL == pDelNode->_pNext)
	{
		q->_front = q->_back = NULL;
	}
	else
	{
		q->_front = pDelNode->_pNext;
	}
	free(pDelNode);
}
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_back->_data;
}
int QueueSize(Queue* q)
{
	int count = 0;
	QNode* pCur = q->_front;
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}
int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->_front;
}
void QueueDestroy(Queue* q)
{
	QNode* pCur = q->_front;
	while (pCur)
	{
		q->_front = pCur->_pNext;
		free(pCur);
		pCur = q->_front;
	}
	q->_front = q->_back = NULL;
}
void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("size = %d\n", QueueSize(&q));

	QueueDestroy(&q);
}