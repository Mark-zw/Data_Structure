#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once
#include<stdio.h>
#include<assert.h>

//����汾
//struct SeqList
//{
//	int data[100];//һ������������
//	struct SeqList* next;//ָ����һ�����ĵ�ַ��ָ��
//};

//�����Ż�
//1.����ṹ���е�����������int�������ͽ���������;����ˣ����ܺ���������Ҫ����char��double��������͵�����
//Ϊ���������͵�ͨ�ã����ǿ��Խ����int���������ض��壬����������漰���������͵��޸ģ�ֱ�ӸĶ��ض��岿�ֵ�����
//���漰���ṹ��������Ԫ�����͵��޸�---��Я�Ժ�ͨ����
//2.����ͬ���ĵ�������Ĵ�С100�ڽṹ���ھ�����̫ǿ��Ϊ�˷��������Сʵ��Ӧ�ù����еĵ���
//���Խ�100��#define N,������---��Я�Ժ�ͨ����
//3.����Ľṹ�������� struct SeqList �����������̫�������������Ǻ���д���룬���Զ�����������ض���

//�Ż��汾

#define N 100
typedef int SLDataType;//SL��SeqLsit����д��DataType��ʾ��������

typedef struct SeqList
{
	SLDataType data[N];//��������
	//struct SeqList* next;//����Ҳ������ SeqList* next;
	size_t size;//��Ч���ݵĸ���
}SeqList;

//��ʼ��
void SeqListInit(SeqList* pList);

//β��
void SeqListPushBack(SeqList* pList, SLDataType x);

//βɾ
void SeqListPopBack(SeqList* pList);

//��ӡ
void SeqListPrint(SeqList* pList);