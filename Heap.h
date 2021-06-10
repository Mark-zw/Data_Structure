#pragma once
#include<stdio.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity
}Heap;

//初始化
void HeapInit(Heap* php,HPDataType* a, int n);
//销毁
void HeapDestory(Heap* php);
//插入
void HeapPush(Heap* php, HPDataType x);
//删除
void HeapPop(Heap* php);