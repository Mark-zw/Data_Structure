#include"DList.h"
//����һ���ڵ�
DNode* CreateDNode(LTDatatype x)
{
	DNode* node = (DNode*)malloc(sizeof(DNode));
	if (node == NULL)
	{
		printf("malloc fail!\n");
		return NULL;
	}
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}
//�����ʼ��
DList* DListInit()
{
	DNode* phead = CreateDNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//����
void DListDestory(DList** pphead)
{
	assert(pphead);
	DNode* cur = (*pphead)->next;
	DNode* next = NULL;
	while (cur != *pphead)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}
//��ӡ
void DListPrint(DList* phead)
{
	if (phead == NULL)
	{
		printf("The DList is empty!\n");
		return;
	}
	DNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n------------------------\n");
}
//β��
void DListPushBack(DList* phead, LTDatatype x)
{
	////1.�ҵ�β��
	//DNode* tail = phead->prev;
	////2.����һ���ڵ�
	//DNode* newnode = CreateDNode(x);
	////3.����β�����
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;

	DListInsert(phead, x);
}
//ͷ��
void DListPushFront(DList* phead, LTDatatype x)
{
	//assert(phead);
	//DNode* newnode = CreateDNode(x);
	//DNode* pnext = phead->next;
	//newnode->next = pnext;
	//newnode->prev = phead;
	//pnext->prev = newnode;
	//phead->next = newnode;
	DListInsert(phead->next, x);
}
//βɾ
void DListPopBack(DList* phead)
{
	////����Ϊ�գ����������ͷ�ڵ�
	//if (phead == NULL || phead->next == phead)
	//{
	//	printf("No element to pop!\n");
	//	return;
	//}
	//DNode* tail = phead->prev;
	//DNode* prev_tail = tail -> prev;
	////βɾ����
	//prev_tail->next = phead;
	//phead->prev = prev_tail;
	//free(tail);
	//tail = NULL;

	DListErase(phead->prev);
}
//ͷɾ
void DListPopFront(DList* phead)
{
	//assert(phead && (phead->next != phead));
	//DNode* first = phead->next;
	//DNode* second = first->next;
	////ͷ�����
	//second->prev = phead;
	//phead->next = second;
	//free(first);
	//first = NULL;

	DListErase(phead->next);
}
//����
DNode* DListFind(DList* phead, LTDatatype x)
{
	assert(phead);
	DNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;//���Ҳ����ͷ���NULL
}
//������λ�ò���--ǰ�����
void DListInsert(DNode* pos, LTDatatype x)
{
	assert(pos);
	DNode* prev = pos->prev;
	DNode* newnode = CreateDNode(x);
	newnode->next = pos;
	newnode->prev = prev;
	pos->prev = newnode;
	prev->next = newnode;
}
//������λ��ɾ��
void DListErase(DNode* pos)
{
	assert(pos && pos->next != pos);
	DNode* prev = pos->prev;
	DNode* next = pos->next;

	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}
//�п� 1-Ϊ�� 0-�ǿ�
int DListEmpty(DList* phead)
{
	return phead->next == phead ? 1 : 0;
}
//�󳤶�
int DListLength(DList* phead)
{
	int length = 0;
	DNode* cur = phead->next;
	while (cur != phead)
	{
		cur = cur->next;
		length++;
	}
}
