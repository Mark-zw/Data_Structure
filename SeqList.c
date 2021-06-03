#define _CRT_SECURE_NO_WARNINGS 1 
#include"SeqList.h"
//初始化
void SeqListInit(SeqList* pList)
{
	assert(pList);
	pList->data[N] = 0 ;
	pList->size = 0;
}

//尾插
void SeqListPushBack(SeqList* pList,SLDataType x)
{
	assert(pList);
	//1.首先考虑是否有空间给数据插入
	if (pList->size == N)
	{
		printf("SeqList is full!\n");
	}
	//2.有空间就往后面插入数据
	else
	{
		int i = pList->size;
		pList->data[i] = x;
		pList->size++;
	}
}

//尾删
void SeqListPopBack(SeqList* pList)
{
	assert(pList);
	//1.首先判断是否还存在可以删除的元素
	if (pList->size == 0)
	{
		printf("SeqList is empty!\n");
		printf("Delete date failure!\n");
	}
	else
	{
		pList->size--;
	}
}

//打印
void SeqListPrint(SeqList* pList)
{
	assert(pList);
	size_t i = 0;
	if (pList->size == 0)
	{
		printf("SeqList is empty!\n");
	}
	else
	{
		for (i = 0; i < pList->size; i++)
		{
			printf("%d ", pList->data[i]);
		}
	}
}