#pragma once
#include<stdio.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity
}Heap;

//��ʼ��
void HeapInit(Heap* php,HPDataType* a, int n);
//����
void HeapDestory(Heap* php);
//����
void HeapPush(Heap* php, HPDataType x);
//ɾ��
void HeapPop(Heap* php);