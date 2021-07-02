#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SListDataType;

//���
typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;

}SListNode;

//��ӡ
void SListPrint(SListNode* phead);

//β��
void SListPushBack(SListNode* phead, SListDataType x);

//βɾ
void SListPopBack(SListNode* phead);

//ͷ��
void SListPushFront(SListNode* phead, SListDataType x);

//ͷɾ
void SListPushFront(SListNode* phead);