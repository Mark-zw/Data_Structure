#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<time.h>
int main()
{
	int n = 1000000000;
	int begin = clock();
	for (int i = 0; i < n; i++)
	{
		;
	}
	int end = clock();
	printf("time-running: %d\n", end - begin);
	return 0;
}

//#define MaxSize 20
//typedef int ElemType;
//
//typedef struct SeqList
//{
//	ElemType _data[MaxSize];
//	int length;
//}SeqList;
//
//void InitList(SeqList& Sq)
//{
//	for (int i = 0; i < MaxSize; i++)
//	{
//		Sq._data[i] = 0;
//	}
//	Sq.length = 0;
//}
//
//int main()
//{
//	SeqList Sq;
//	InitList(Sq);
//	for (int i = 0; i < MaxSize; i++)
//	{
//		printf("data[%d] = %d\n", i, Sq._data[i]);
//	}
//	return 0;
//}