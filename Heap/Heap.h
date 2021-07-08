#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

//��ʼ��
void HeapInit(Heap* php,HPDataType* a, int n);
//���µ���
void AdjustDown(HPDataType* a, int n, int root);
//���ϵ���
void AdjustUp(HPDataType* a, int n, int child);
//������
void HeapSort(int* a, int n);
//����
void HeapDestory(Heap* php);
//����
void HeapPush(Heap* php, HPDataType x);
//ɾ��
void HeapPop(Heap* php);
//����
void Swap(HPDataType* p1, HPDataType* p2);
//ȡ���Ѷ�������
HPDataType HeapTop(Heap* php);