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
	//phead    tail   newnode  三者之间的关系链接
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
//头插
void ListPushFront(ListNode* phead, LTDataType x)
{
	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);

	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = first;
	first->prev = newnode;
	//当phead指向的链表中没有元素也符合这个条件
	//所以不需要进行额外的判断
}
//头删
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//头节点不能删除

	ListNode* first = phead->next;
	ListNode* second = first->next;

	phead->next = second;
	second->prev = phead;

	free(first);
	first = NULL;
}
//查找
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
//插入
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
//删除
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
//清理
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
	//头节点删不删需要分情况，1.如果后面需要继续使用，不删除
	//2.如果后面不使用了，删除   可以将这个独立出来成一个模块 ListClear
	phead->next = phead;
	phead->prev = phead;
}
//销毁
void ListDestory(ListNode** pphead)
{
	assert(*pphead);
	ListClear(*pphead);
	free(*pphead);//销毁头节点
	//phead = NULL;这句话置空对于外面的phead来说没用，因为传参是值传递
	//要想解决这个问题
	//1.return  NULL
	//2.使用二级指针
	*pphead = NULL;
}
