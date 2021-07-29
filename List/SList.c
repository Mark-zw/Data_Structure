#pragma once
#include"SList.h"
//打印
void SListPrint(SList** ppList)
{
	if (*ppList == NULL)
	{
		printf("The SList is empty!\n");
	}
	SNode* cur = *ppList;
	while (cur)
	{
		if (cur->next != NULL)
		{
			printf("%d->", cur->data);
			cur = cur->next;
		}
		if (cur->next == NULL)
		{
			printf("%d->NULL", cur->data);
			cur = cur->next;
		}
	}
	printf("\n");
}

//创建一个节点
SList* CreateNode(SLDatatype x)
{
	SNode* node = (SNode*)malloc(sizeof(SNode));
	if (node == NULL)
	{
		perror("CreateNode:");
		printf("Create a node fail!\n");
		return NULL;
	}
	node->data = x;
	node->next = NULL;
	return node;
}

//尾插
void SListPushBack(SList** ppList, SLDatatype x)
{
	SNode* node = CreateNode(x);
	//判断链表是否为空
	if (*ppList == NULL)
	{
		//创建一个结点给pList
		*ppList = node;
	}
	else
	{
		//遍历链表找尾部
		SNode* tail = *ppList;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = node;
	}

	//SNode* cur = (SNode*)malloc(sizeof(SNode));
	//if (cur == NULL)
	//{
	//	perror("SListPushBack:");
	//	printf("malloc fail!\n");
	//	return;
	//}
	//cur->data = x;
	//cur->next = NULL;
	//tail->next = cur;
}
//头插
void SListPushFront(SList** ppList, SLDatatype x)
{
	SList* node = CreateNode(x);
	node->next = *ppList;
	*ppList = node;
}
//头删 1.链表为空 2.链表一个结点  3.链表多个结点
void SListPopFront(SList** ppList)
{
	if (*ppList == NULL)
	{
		printf("The SList is empty!\n");
		return;
	}
	else 
	{
		SNode* cur = *ppList;
		if (cur->next == NULL)
		{
			free(cur);
			cur = NULL;
			*ppList = NULL;
		}
		else
		{
			*ppList = cur->next;
			free(cur);
			cur = NULL;
		}
	}
}
//尾删 1.链表为空 2.链表一个结点  3.链表多个结点
void SListPopBack(SList** ppList)
{
	SNode* prev = NULL;
	SNode* tail = *ppList;
	if (tail == NULL)
	{
		printf("The SList is empty!\n");
	}
	else
	{
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		if (prev != NULL)
		{
			prev->next = NULL;
		}
	}
	////判断链表是否为空
	//if (*ppList == NULL) 
	//{
	//	printf("The SList is empty!\n");
	//}
	//else
	//{
	//	SNode* cur = *ppList;
	//	if (cur->next == NULL)
	//	{
	//		free(cur);
	//		cur = NULL;
	//		*ppList = NULL;
	//	}
	//	else
	//	{
	//		SNode* next = cur->next;
	//		while (cur->next)
	//		{
	//			next = next->next;
	//			cur = cur->next;
	//		}
	//		free(next);
	//		next = NULL;
	//		cur->next = NULL;
	//	}
	//}
}
//查找 1.空表  2.非空表
SNode* SListSearch(SList* pList, SLDatatype x)
{
	////1.空表，可以被下面的情况包含
	//if (pList == NULL)
	//{
	//	printf("The SList is empty!\n");
	//	return NULL;
	//}
	SNode* cur = pList;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//在任意位置插入
void SListInsertafter(SNode* pos, SLDatatype x)
{
	if (pos == NULL)
	{
		SNode* newnode = CreateNode(x);
		pos = newnode;
	}
	else
	{
		SNode* newnode = CreateNode(x);
		newnode->next = pos->next;
		pos->next = newnode;
	}
}
//在任意位置删除
void SListEraseafter(SNode* pos)
{
	if (pos == NULL)
	{
		printf("The SList is empty!\n");
	}
	else
	{
		SNode* next = pos->next;
		pos->next = next->next;
		free(next);
		next = NULL;
	}
}
//在任意位置之前插入
void SListInsertbefore(SList** ppList, SNode* pos, SLDatatype x)
{
	if (*ppList == NULL || pos == NULL)
	{
		printf("error!\n");
	}
	//头插
	if (pos == *ppList)
	{
		SNode* newnode = CreateNode(x);
		(*ppList)->next = newnode;
	}
	else
	{
		SNode* prev = NULL;
		SNode* cur = *ppList;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		SNode* newnode = CreateNode(x);
		prev->next = newnode;
		newnode->next = cur;
	}
}
//在任意位置删除当前位置
void SListErasecur(SList** ppList, SNode* pos)
{
	if (*ppList == NULL || pos == NULL)
	{
		printf("error!\n");
	}
	else
	{
		if (pos == *ppList)//头删
		{
			*ppList = pos->next;
			free(pos);
			pos = NULL;
		}
	}
}