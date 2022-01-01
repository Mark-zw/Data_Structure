#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

#define N 5
typedef int SLDataType;

typedef struct SeqList {
	SLDataType arr[N];
	int size;
}SeqList,SLT;

//Initialize SeqList
void SeqListInit(SeqList* pList);
//Push new element to SeqList in the end
void SeqListPushBack(SeqList* pList, SLDataType x);
//Erase the last element of SeqList
void SeqListPopBack(SeqList* pList);
//Insert new element in front of SeqList
void SeqListPushFront(SeqList* pList, SLDataType x);
//Erase the first element of SeqList
void SeqListPopFront(SeqList* pList);
void SeqListPrint(SeqList* pList);
//judge SeqList is empty whether or not
bool SeqListIsEmpty(SeqList* pList);
int SeqListLength(SeqList* pList);
