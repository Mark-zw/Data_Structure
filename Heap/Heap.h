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

//初始化
void HeapInit(Heap* php,HPDataType* a, int n);
//向下调整
void AdjustDown(HPDataType* a, int n, int root);
//向上调整
void AdjustUp(HPDataType* a, int n, int child);
//构建堆
void HeapSort(int* a, int n);
//销毁
void HeapDestory(Heap* php);
//插入
void HeapPush(Heap* php, HPDataType x);
//删除
void HeapPop(Heap* php);
//交换
void Swap(HPDataType* p1, HPDataType* p2);
//取出堆顶的数据
HPDataType HeapTop(Heap* php);