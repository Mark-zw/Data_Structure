#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//双向带头循环链表
typedef int LTDatatype;
typedef struct DList
{
	LTDatatype data;
	struct DList* next;
	struct DList* prev;
}DList,DNode;

//创建一个节点
DNode* CreateDNode(LTDatatype x);
//链表初始化
DList* DListInit();
//销毁
void DListDestory(DList** pphead);
//打印
void DListPrint(DList* phead);
//尾插
void DListPushBack(DList* phead,LTDatatype x);
//头插
void DListPushFront(DList* phead, LTDatatype x);
//尾删
void DListPopBack(DList* phead);
//头删
void DListPopFront(DList* phead);
//查找
DNode* DListFind(DList* phead, LTDatatype x);
//在任意位置插入
void DListInsert(DNode* pos, LTDatatype x);
//在任意位置删除
void DListErase(DNode* pos);
//判空 1-为空 0-非空
int DListEmpty(DList* phead);
//求长度
int DListLength(DList* phead);