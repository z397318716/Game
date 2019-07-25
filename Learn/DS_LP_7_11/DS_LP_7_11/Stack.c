#include "Stack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>



void StackInit(Stack* ps)
{
	assert(ps);
	ps->_array = (SDataType*)malloc(sizeof(SDataType)* 3);
	if (NULL == ps->_array)
	{
		assert(0);
		return;
	}
	ps->_capacity = 3;
	ps->_size = 0;
}
void StackPush(Stack* ps, SDataType data)
{
	//检测是否空间足够
	CheckCapacity(ps);

	ps->_array[ps->_size++] = data;  //数据放完结束后在 ++
}
void StackPop(Stack* ps)
{
	assert(ps);
	if (StackEmpty(ps))
		return;

	ps->_size -= 1;
}
SDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_array[ps->_size - 1];
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_size;

}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->_size;

}
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);
		ps->_capacity = 0;
		ps->_size = 0;
	}
}
void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		//开辟新空间
		int NewCapacity = ps->_capacity * 2;
		SDataType* pTemp = (SDataType*)malloc(sizeof(SDataType)* NewCapacity);
		if (NULL == pTemp)
		{
			assert(0);
			return;
		}
		//拷贝元素
		for (int i = 0; i < ps->_size; ++i)
		{
			pTemp[i] = ps->_array[i];
		}
		//释放旧空间
		free(ps->_array);
		ps->_array = pTemp;
		ps->_capacity = NewCapacity;
	}
}