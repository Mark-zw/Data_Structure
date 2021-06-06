#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;//头指针
	QueueNode* _tail;//尾指针
}Queue;

//初始化
void  QueueInit(Queue* pq);
//销毁
void QueueDestory(Queue* pq);
//入队列
void QueuePush(Queue* pq,QDataType x);
//出队列
void QueuePop(Queue* pq);
//获取队列头部数据
QDataType QueueFront(Queue* pq);
//获取队列尾部数据
QDataType QueueBack(Queue* pq);
//栈状态判断 返回1是空，返回0是非空
int QueueEmpty(Queue* pq);
//队列的元素个数
int QueueSize(Queue* pq);