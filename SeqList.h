#pragma once
#include<stdio.h>
#include<stdlib.h>

//顺序的静态结构
// 1.最初版本
//struct SeqList
//{
//	int arr[10];
//	int size;
//};

//2.优化版本
//#define MAX_SIZE 100
//typedef int SLDatatype;
//typedef struct SeqList
//{
//	int arr[MAX_SIZE];
//	int size;
//}SeqList;

//顺序表的动态结构
//1.最初版本
//struct SeqList
//{
//	int* arr;//用来指向动态开辟的数组
//	int size;//当前已使用空间的个数
//	int capacity;//动态数组的最大容量
//};

//2.优化版本
#define Init_SIZE 1
typedef int SLDatatype;//方便对不同类型的处理和替换
typedef struct SeqList
{
	SLDatatype* arr;
	int size;
	int capacity;
}SL;

//对数据的基本操作：创销增删查改  ---需要相应的接口
//额外功能：打印、判长、判空

//创建---初始化
void SeqListInit(SL* seq);
//销毁
void SeqListDestory(SL* seq);

//打印
void SeqListPrint(SL* seq);

//增加数据其实就是插入数据
//按照插入数据的位置，可分为头插、尾插、任意位置插入
//实际中，若实现了任意位置插入，头插、尾插可以复用这部分代码

//扩容检查
void CheckCapacity(SL* seq);

//尾插
void SeqListPushBack(SL* seq, SLDatatype x);
//头插
void SeqListPushFront(SL* seq, SLDatatype x);

//尾删
void SeqListPopBack(SL* seq);
//头删
void SeqListPopFront(SL* seq);

//任意位置插入
void SeqListInsert(SL* seq, int pos, SLDatatype x);
//任意位置删除
void SeqListErase(SL* seq, int pos);

//查找---按值查找
int SeqListFind(SL* seq, SLDatatype x);

//查找---按位查找
int SeqListGetElem(SL* seq, int pos);

//修改
void SeqListModify(SL* seq, int pos, SLDatatype x);