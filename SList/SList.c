#define _CRT_SECURE_NO_WARNINGS 1 
#include "SList.h"

//打印
void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ---> ", cur->data);
		cur = cur->next;//指针指向的地址移动到下一个数据的地址
	}
}

//封装创建结点
SListNode* CreateNewNode(SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("Failed to allocate memory !");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//尾插
void SListPushBack(SListNode** pphead, SListDataType x)
{
	SListNode* newNode = CreateNewNode(x);
	if ((*pphead) == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//循环出来后的tail就是NULL，尾指针

		tail->next = newNode;
	}


}

//尾删
void SListPopBack(SListNode* phead)
{
	//1.空
	//2.一个结点
	//3.两个及其以上结点

}

//头插
void SListPushFront(SListNode* phead, SListDataType x);

//头删
void SListPushFront(SListNode* phead);