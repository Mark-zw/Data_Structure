#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once
#include<stdio.h>
#include<assert.h>

//最初版本
//struct SeqList
//{
//	int data[100];//一个定长的数组
//	struct SeqList* next;//指向下一个结点的地址的指针
//};

//进行优化
//1.这个结构体中的数据类型是int，这样就将数组的类型局限了，可能后面我们需要处理char、double或各种类型的数据
//为了数组类型的通用，我们可以将这个int进行类型重定义，后面如果有涉及到数据类型的修改，直接改动重定义部分的类型
//不涉及到结构体内数组元素类型的修改---便携性和通用性
//2.基于同样的道理，数组的大小100在结构体内局限性太强，为了方便数组大小实际应用过程中的调整
//可以将100用#define N,宏命令---便携性和通用性
//3.定义的结构体类型是 struct SeqList 这个类型名称太长，不方便我们后续写代码，可以对其进行类型重定义

//优化版本

#define N 100
typedef int SLDataType;//SL是SeqLsit的缩写，DataType表示数据类型

typedef struct SeqList
{
	SLDataType data[N];//定长数组
	//struct SeqList* next;//或者也可以用 SeqList* next;
	size_t size;//有效数据的个数
}SeqList;

//初始化
void SeqListInit(SeqList* pList);

//尾插
void SeqListPushBack(SeqList* pList, SLDataType x);

//尾删
void SeqListPopBack(SeqList* pList);

//打印
void SeqListPrint(SeqList* pList);