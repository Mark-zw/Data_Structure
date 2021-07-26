#pragma once
#include<stdio.h>
#include<stdlib.h>


//���� ����ͷ ��ѭ��
typedef int SLDatatype;
//����һ������
typedef struct SList
{
	SLDatatype data;
	struct SList* next;
}SNode,SList;//SNodeǿ����㣬*SListǿ������

//��ʼ��
void SListInit(SList* pList);
//����
void SListDestory(SList* pList);
//��ӡ
void SListPrint(SList** ppList);
//����һ���ڵ�
SList* CreateNode(SLDatatype x);
//ͷ��
void SListPushFront(SList** ppList, SLDatatype x);
//β��
void SListPushBack(SList** ppList, SLDatatype x);
//ͷɾ
void SListPopFront(SList** ppList);
//βɾ
void SListPopBack(SList** ppList);
//������λ�ò���
void SListInsert(SList* pList, int pos, SLDatatype x);
//������λ��ɾ��
void SListErase(SList* pList, int pos, SLDatatype x);
//����
int SListSearch(SList* pList, SLDatatype x);
//�޸�
void SListModify(SList* pList, int pos, SLDatatype x);
