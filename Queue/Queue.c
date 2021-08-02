#define _CRT_SECURE_NO_WARNINGS 1 
#include"Queue.h"
//��ʼ������
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
//����
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
//��β�����
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
//��ͷ������
void QueuePop(Queue* pq)
{
	assert(pq);
	//����һ������
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else//���ڶ������
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}
//��ȡ��ͷԪ��
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head != NULL);
	return pq->head->data;
}
//��ȡ��βԪ��
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head != NULL);
	return pq->tail->data;
}
//��ȡ��������ЧԪ�ظ���
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
//�������Ƿ�Ϊ�գ��� --��0 �ǿ�--0	
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}