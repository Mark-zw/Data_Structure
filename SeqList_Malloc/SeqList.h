#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//����汾
//struct SeqList
//{
//	int* p;//ָ��̬���ٿռ��ָ��
//	int size;//��ЧԪ�صĸ���
//	int capacity;//��̬���ٿռ������
//};
//�Ż��汾
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array;//ָ��̬���ٿռ��ָ��
	size_t size;//��ЧԪ�صĸ���
	size_t capacity;//��̬���ٿռ������
}SeqList;
//��ʼ��
void SeqListInit(SeqList* pList);
//����
void SeqListDestory(SeqList* pList);
//��ӡ
void SeqListPrint(SeqList* pList);
//�ռ��飬������ˣ���������
void CheckCapacity(SeqList* pList);
//β��
void SeqListPushBack(SeqList* pList, SLDataType x);
//βɾ
void SeqListPopBack(SeqList* pList);
//ͷ��
void SeqListPushFront(SeqList* pList, SLDataType x);
//ͷɾ
void SeqListPopFront(SeqList* pList);
//����
int SeqListFind(SeqList* pList, SLDataType x);
//������λ�ò���
void SeqListInsert(SeqList* pList, size_t pos, SLDataType x);
//������λ��ɾ��
void SeqListErase(SeqList* pList, size_t pos);