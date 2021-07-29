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
//ͷɾ 1.����Ϊ�� 2.����һ�����  3.���������
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
//���� 1.�ձ�  2.�ǿձ�
SNode* SListSearch(SList* pList, SLDatatype x)
{
	////1.�ձ����Ա�������������
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
//������λ�ò���
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
//������λ��ɾ��
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
//������λ��֮ǰ����
void SListInsertbefore(SList** ppList, SNode* pos, SLDatatype x)
{
	if (*ppList == NULL || pos == NULL)
	{
		printf("error!\n");
	}
	//ͷ��
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
//������λ��ɾ����ǰλ��
void SListErasecur(SList** ppList, SNode* pos)
{
	if (*ppList == NULL || pos == NULL)
	{
		printf("error!\n");
	}
	else
	{
		if (pos == *ppList)//ͷɾ
		{
			*ppList = pos->next;
			free(pos);
			pos = NULL;
		}
	}
}