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
//��ӡ����
void ListPrint(ListNode* phead);
//β��
void ListPushBack(ListNode* phead, LTDataType x);
//βɾ
void ListPopBack(ListNode* phead);
//ͷ��
void ListPushFront(ListNode* phead, LTDataType x);
//ͷɾ
void ListPopFront(ListNode* phead);
//����
ListNode* ListFind(ListNode* phead, LTDataType x);
//����
void ListInsert(ListNode* pos, LTDataType  x);
//ɾ��
void ListErase(ListNode* pos);
//����
void ListDestory(ListNode* phead);
//����
void ListClear(ListNode* phead);