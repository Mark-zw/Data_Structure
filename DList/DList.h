#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//˫���ͷѭ������
typedef int LTDatatype;
typedef struct DList
{
	LTDatatype data;
	struct DList* next;
	struct DList* prev;
}DList,DNode;

//����һ���ڵ�
DNode* CreateDNode(LTDatatype x);
//�����ʼ��
DList* DListInit();
//����
void DListDestory(DList** pphead);
//��ӡ
void DListPrint(DList* phead);
//β��
void DListPushBack(DList* phead,LTDatatype x);
//ͷ��
void DListPushFront(DList* phead, LTDatatype x);
//βɾ
void DListPopBack(DList* phead);
//ͷɾ
void DListPopFront(DList* phead);
//����
DNode* DListFind(DList* phead, LTDatatype x);
//������λ�ò���
void DListInsert(DNode* pos, LTDatatype x);
//������λ��ɾ��
void DListErase(DNode* pos);
//�п� 1-Ϊ�� 0-�ǿ�
int DListEmpty(DList* phead);
//�󳤶�
int DListLength(DList* phead);