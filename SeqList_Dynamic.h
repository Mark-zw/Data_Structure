#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
typedef int SLDataType;
typedef struct SeqList {
	SLDataType* arr;
	int size;
	int capacity;
}SeqList;
void SeqListInit(SeqList* pList);//初始化
void SeqListDestory(SeqList* pList);//销毁
void SeqListPushFront(SeqList* pList,SLDataType x);//头插
void SeqListPopFront(SeqList* pList);//头删
void SeqListPushBack(SeqList* pList,SLDataType x);//尾插
void SeqListPopBack(SeqList* pList);//尾删
void SeqListInsert(SeqList* pList,int pos,SLDataType x);//任意位置插入
void SeqListErase(SeqList* pList,int pos);//任意位置删除
int SeqListFind_By_Val(SeqList* pList,SLDataType x);//查找
void SeqListUpdata(SeqList* pList,int pos,SLDataType x);//修改
void SeqListPrint(SeqList* pList);//打印
bool SeqListIsEmpty(SeqList* pList);//判空
int SeqListLength(SeqList* pList);//长度
