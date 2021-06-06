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
	QueueNode* _head;//ͷָ��
	QueueNode* _tail;//βָ��
}Queue;

//��ʼ��
void  QueueInit(Queue* pq);
//����
void QueueDestory(Queue* pq);
//�����
void QueuePush(Queue* pq,QDataType x);
//������
void QueuePop(Queue* pq);
//��ȡ����ͷ������
QDataType QueueFront(Queue* pq);
//��ȡ����β������
QDataType QueueBack(Queue* pq);
//ջ״̬�ж� ����1�ǿգ�����0�Ƿǿ�
int QueueEmpty(Queue* pq);
//���е�Ԫ�ظ���
int QueueSize(Queue* pq);