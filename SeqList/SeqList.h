#pragma once
#include<stdio.h>
#include<stdlib.h>

//˳��ľ�̬�ṹ
// 1.����汾
//struct SeqList
//{
//	int arr[10];
//	int size;
//};

//2.�Ż��汾
//#define MAX_SIZE 100
//typedef int SLDatatype;
//typedef struct SeqList
//{
//	int arr[MAX_SIZE];
//	int size;
//}SeqList;

//˳���Ķ�̬�ṹ
//1.����汾
//struct SeqList
//{
//	int* arr;//����ָ��̬���ٵ�����
//	int size;//��ǰ��ʹ�ÿռ�ĸ���
//	int capacity;//��̬������������
//};

//2.�Ż��汾
#define Init_SIZE 1
typedef int SLDatatype;//����Բ�ͬ���͵Ĵ�����滻
typedef struct SeqList
{
	SLDatatype* arr;
	int size;
	int capacity;
}SL;

//�����ݵĻ���������������ɾ���  ---��Ҫ��Ӧ�Ľӿ�
//���⹦�ܣ���ӡ���г����п�

//����---��ʼ��
void SeqListInit(SL* seq);
//����
void SeqListDestory(SL* seq);

//��ӡ
void SeqListPrint(SL* seq);

//����������ʵ���ǲ�������
//���ղ������ݵ�λ�ã��ɷ�Ϊͷ�塢β�塢����λ�ò���
//ʵ���У���ʵ��������λ�ò��룬ͷ�塢β����Ը����ⲿ�ִ���

//���ݼ��
void CheckCapacity(SL* seq);

//β��
void SeqListPushBack(SL* seq, SLDatatype x);
//ͷ��
void SeqListPushFront(SL* seq, SLDatatype x);

//βɾ
void SeqListPopBack(SL* seq);
//ͷɾ
void SeqListPopFront(SL* seq);

//����λ�ò���
void SeqListInsert(SL* seq, int pos, SLDatatype x);
//����λ��ɾ��
void SeqListErase(SL* seq, int pos);

//����---��ֵ����
int SeqListFind(SL* seq, SLDatatype x);

//����---��λ����
int SeqListGetElem(SL* seq, int pos);

//�޸�
void SeqListModify(SL* seq, int pos, SLDatatype x);