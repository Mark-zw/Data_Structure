#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


struct BinaryTreeNode;//ǰ������
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

//��ʼ������
void QueueInit(Queue* pq);
//����
void QueueDestroy(Queue* pq);
//��β�����
void QueuePush(Queue* pq, QDataType x);
//��ͷ������
void QueuePop(Queue* pq);
//��ȡ��ͷԪ��
QDataType QueueFront(Queue* pq);
//��ȡ��βԪ��
QDataType QueueBack(Queue* pq);
//��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq);
//�������Ƿ�Ϊ�գ��� --��0 �ǿ�--0	
bool QueueEmpty(Queue* pq);
