#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SListDataType;

//结点
typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;

}SListNode;

//打印
void SListPrint(SListNode* phead);

//尾插
void SListPushBack(SListNode* phead, SListDataType x);

//尾删
void SListPopBack(SListNode* phead);

//头插
void SListPushFront(SListNode* phead, SListDataType x);

//头删
void SListPushFront(SListNode* phead);