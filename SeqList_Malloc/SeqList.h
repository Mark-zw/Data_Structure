#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//最初版本
//struct SeqList
//{
//	int* p;//指向动态开辟空间的指针
//	int size;//有效元素的个数
//	int capacity;//动态开辟空间的容量
//};
//优化版本
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array;//指向动态开辟空间的指针
	size_t size;//有效元素的个数
	size_t capacity;//动态开辟空间的容量
}SeqList;
//初始化
void SeqListInit(SeqList* pList);
//销毁
void SeqListDestory(SeqList* pList);
//打印
void SeqListPrint(SeqList* pList);
//空间检查，如果满了，进行增容
void CheckCapacity(SeqList* pList);
//尾插
void SeqListPushBack(SeqList* pList, SLDataType x);
//尾删
void SeqListPopBack(SeqList* pList);
//头插
void SeqListPushFront(SeqList* pList, SLDataType x);
//头删
void SeqListPopFront(SeqList* pList);
//查找
int SeqListFind(SeqList* pList, SLDataType x);
//在任意位置插入
void SeqListInsert(SeqList* pList, size_t pos, SLDataType x);
//在任意位置删除
void SeqListErase(SeqList* pList, size_t pos);