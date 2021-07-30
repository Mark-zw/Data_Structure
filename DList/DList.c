#include"DList.h"
//创建一个节点
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
//链表初始化
DList* DListInit()
{
	DNode* phead = CreateDNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//销毁
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
//打印
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
//尾插
void DListPushBack(DList* phead, LTDatatype x)
{
	////1.找到尾巴
	//DNode* tail = phead->prev;
	////2.申请一个节点
	//DNode* newnode = CreateDNode(x);
	////3.进行尾插操作
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;

	DListInsert(phead, x);
}
//头插
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
//尾删
void DListPopBack(DList* phead)
{
	////链表为空，或链表仅有头节点
	//if (phead == NULL || phead->next == phead)
	//{
	//	printf("No element to pop!\n");
	//	return;
	//}
	//DNode* tail = phead->prev;
	//DNode* prev_tail = tail -> prev;
	////尾删操作
	//prev_tail->next = phead;
	//phead->prev = prev_tail;
	//free(tail);
	//tail = NULL;

	DListErase(phead->prev);
}
//头删
void DListPopFront(DList* phead)
{
	//assert(phead && (phead->next != phead));
	//DNode* first = phead->next;
	//DNode* second = first->next;
	////头插操作
	//second->prev = phead;
	//phead->next = second;
	//free(first);
	//first = NULL;

	DListErase(phead->next);
}
//查找
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
	return NULL;//查找不到就返回NULL
}
//在任意位置插入--前面插入
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
//在任意位置删除
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
//判空 1-为空 0-非空
int DListEmpty(DList* phead)
{
	return phead->next == phead ? 1 : 0;
}
//求长度
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
