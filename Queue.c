#define _CRT_SECURE_NO_WARNINGS 1 
#include"Queue.h"
//初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
//销毁
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
}
//队尾入队列
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = pq->tail->next;
	}
}
//队头出队列
void QueuePop(Queue* pq)
{
	assert(pq);
	//仅有一个数据
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else//存在多个数据
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}
//获取队头元素
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head != NULL);
	return pq->head->data;
}
//获取队尾元素
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head != NULL);
	return pq->tail->data;
}
//获取队列中有效元素个数
int QueueSize(Queue* pq)
{
	assert(pq);
	assert(pq->head != NULL);
	QueueNode* cur = pq->head;
	int length = 0;
	while (cur)
	{
		cur = cur->next;
		length++;
	}
	return length;
}
//检测队列是否为空，空 --非0 非空--0	
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}