#pragma once
#include"SList.h"
//��ӡ
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

//����һ���ڵ�
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

//β��
void SListPushBack(SList** ppList, SLDatatype x)
{
	SNode* node = CreateNode(x);
	//�ж������Ƿ�Ϊ��
	if (*ppList == NULL)
	{
		//����һ������pList
		*ppList = node;
	}
	else
	{
		//����������β��
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
//ͷ��
void SListPushFront(SList** ppList, SLDatatype x)
{
	SList* node = CreateNode(x);
	node->next = *ppList;
	*ppList = node;
}
//ͷɾ
void SListPopFront(SList** ppList)
{

}
//βɾ 1.����Ϊ�� 2.����һ�����  3.���������
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
	////�ж������Ƿ�Ϊ��
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