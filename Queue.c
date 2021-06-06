#define _CRT_SECURE_NO_WARNINGS 1 
#include"Queue.h"
//��ʼ��
void  QueueInit(Queue* pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}
//����
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_head;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
}
//�����
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("newnode is NULL!\n");
		exit(-1);
	}
	newnode->_data = x;
	newnode->_next = NULL;
	if (pq->_head == NULL)
	{
		pq->_head = pq->_tail = newnode;
	}
	else
	{
		pq->_tail->_next = newnode;
		pq->_tail = newnode;
	}
}
//������
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->_head);
	QueueNode* next = pq->_head->_next;
	free(pq->_head);
	pq->_head = next;
	if (pq->_head == NULL)
	{
		pq->_tail = NULL;
	}
}
//��ȡ����ͷ������
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->_head);
	return pq->_head->_data;
}
//��ȡ����β������
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->_head);
	return pq->_tail->_data;
}
//ջ״̬�ж� ����1�ǿգ�����0�Ƿǿ�
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_head == NULL ? 1 : 0;
}
//���е�Ԫ�ظ���
int QueueSize(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_head;;
	int size = 0;
	while (cur != pq->_tail)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}