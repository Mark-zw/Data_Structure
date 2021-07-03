#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

ListNode* BuyListNode(LTDataType x);

ListNode* ListInit();
//打印链表
void ListPrint(ListNode* phead);
//尾插
void ListPushBack(ListNode* phead, LTDataType x);
//尾删
void ListPopBack(ListNode* phead);
//头插
void ListPushFront(ListNode* phead, LTDataType x);
//头删
void ListPopFront(ListNode* phead);
//查找
ListNode* ListFind(ListNode* phead, LTDataType x);
//插入
void ListInsert(ListNode* pos, LTDataType  x);
//删除
void ListErase(ListNode* pos);
//销毁
void ListDestory(ListNode* phead);
//清理
void ListClear(ListNode* phead);