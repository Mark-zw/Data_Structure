#define _CRT_SECURE_NO_WARNINGS 1 
#include"ListNode.h"

ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}


ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->next = NULL;
	node->prev = NULL;
	node->data = x;
	return node;
}

void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
}

void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);
	//phead    tail   newnode  ����֮��Ĺ�ϵ����
	tail->next = newnode;
	newnode->prev = tail;

	newnode->next = phead;
	phead->prev = newnode;

}

void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* tail = phead->prev;
	ListNode* cur = tail->prev;
	
	cur->next = phead;
	phead->prev = cur;
	free(tail);
	tail = NULL;
}
//ͷ��
void ListPushFront(ListNode* phead, LTDataType x)
{
	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);

	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = first;
	first->prev = newnode;
	//��pheadָ���������û��Ԫ��Ҳ�����������
	//���Բ���Ҫ���ж�����ж�
}
//ͷɾ
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//ͷ�ڵ㲻��ɾ��

	ListNode* first = phead->next;
	ListNode* second = first->next;

	phead->next = second;
	second->prev = phead;

	free(first);
	first = NULL;
}
//����
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}

}
//����
void ListInsert(ListNode* pos, LTDataType  x)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* newnode = BuyListNode(x);

	posPrev->next = newnode;
	newnode->next = pos;
	newnode->prev = posPrev;
	pos->prev = newnode;


}
//ɾ��
void ListErase(ListNode* pos)
{
	assert(pos);
	assert(pos->next != pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;

	free(pos);
	pos = NULL;
}
//����
void ListClear(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	//ͷ�ڵ�ɾ��ɾ��Ҫ�������1.���������Ҫ����ʹ�ã���ɾ��
	//2.������治ʹ���ˣ�ɾ��   ���Խ��������������һ��ģ�� ListClear
	phead->next = phead;
	phead->prev = phead;
}
//����
void ListDestory(ListNode** pphead)
{
	assert(*pphead);
	ListClear(*pphead);
	free(*pphead);//����ͷ�ڵ�
	//phead = NULL;��仰�ÿն��������phead��˵û�ã���Ϊ������ֵ����
	//Ҫ�����������
	//1.return  NULL
	//2.ʹ�ö���ָ��
	*pphead = NULL;
}
