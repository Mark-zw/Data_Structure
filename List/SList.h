#pragma once
#include<stdio.h>
#include<stdlib.h>


//单向 不带头 非循环
typedef int SLDatatype;
//定义一个链表
typedef struct SList
{
	SLDatatype data;
	struct SList* next;
}SNode,SList;//SNode强调结点，*SList强调链表

//初始化
void SListInit(SList* pList);
//销毁
void SListDestory(SList* pList);
//打印
void SListPrint(SList** ppList);
//创建一个节点
SList* CreateNode(SLDatatype x);
//头插
void SListPushFront(SList** ppList, SLDatatype x);
//尾插
void SListPushBack(SList** ppList, SLDatatype x);
//头删
void SListPopFront(SList** ppList);
//尾删
void SListPopBack(SList** ppList);
//在任意位置之后插入
void SListInsertafter(SNode* pos, SLDatatype x);
//在任意位置之后删除
void SListEraseafter(SNode* pos);

//在任意位置之前插入
void SListInsertbefore(SList* pList,SNode* pos, SLDatatype x);
//在任意位置删除当前位置
void SListErasecur(SList* pList,SNode* pos);

//查找
SNode* SListSearch(SList* pList, SLDatatype x);
//修改
void SListModify(SList* pList, int pos, SLDatatype x);
