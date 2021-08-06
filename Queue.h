#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


struct BinaryTreeNode;//前置声明
typedef struct BinaryTreeNode* QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

//初始化队列
void QueueInit(Queue* pq);
//销毁
void QueueDestroy(Queue* pq);
//队尾入队列
void QueuePush(Queue* pq, QDataType x);
//队头出队列
void QueuePop(Queue* pq);
//获取队头元素
QDataType QueueFront(Queue* pq);
//获取队尾元素
QDataType QueueBack(Queue* pq);
//获取队列中有效元素个数
int QueueSize(Queue* pq);
//检测队列是否为空，空 --非0 非空--0	
bool QueueEmpty(Queue* pq);
