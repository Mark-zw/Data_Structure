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
void SeqListInit(SeqList* pList);//��ʼ��
void SeqListDestory(SeqList* pList);//����
void SeqListPushFront(SeqList* pList,SLDataType x);//ͷ��
void SeqListPopFront(SeqList* pList);//ͷɾ
void SeqListPushBack(SeqList* pList,SLDataType x);//β��
void SeqListPopBack(SeqList* pList);//βɾ
void SeqListInsert(SeqList* pList,int pos,SLDataType x);//����λ�ò���
void SeqListErase(SeqList* pList,int pos);//����λ��ɾ��
int SeqListFind_By_Val(SeqList* pList,SLDataType x);//����
void SeqListUpdata(SeqList* pList,int pos,SLDataType x);//�޸�
void SeqListPrint(SeqList* pList);//��ӡ
bool SeqListIsEmpty(SeqList* pList);//�п�
int SeqListLength(SeqList* pList);//����
