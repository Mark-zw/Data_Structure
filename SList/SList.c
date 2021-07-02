#define _CRT_SECURE_NO_WARNINGS 1 
#include "SList.h"

//��ӡ
void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ---> ", cur->data);
		cur = cur->next;//ָ��ָ��ĵ�ַ�ƶ�����һ�����ݵĵ�ַ
	}
}

//��װ�������
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

//β��
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
		//ѭ���������tail����NULL��βָ��

		tail->next = newNode;
	}


}

//βɾ
void SListPopBack(SListNode* phead)
{
	//1.��
	//2.һ�����
	//3.�����������Ͻ��

}

//ͷ��
void SListPushFront(SListNode* phead, SListDataType x);

//ͷɾ
void SListPushFront(SListNode* phead);