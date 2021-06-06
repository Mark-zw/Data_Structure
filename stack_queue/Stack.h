#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

////��̬��ջ
// struct Stack
//{
//	int _a[N];
//	int _size;
//};

typedef int STDataType;

//��̬��ջ
typedef struct Stack
{
	STDataType* _a;//��_��ʾΪ�ṹ���Ա����Ŀ�����о���ʹ��
	int _top;//ջ���±�
	int _capacity;
}Stack;

//��ʼ��
void StackInit(Stack* pst);
//����
void StackDestory(Stack* pst);
//��ջ
void StackPush(Stack* pst, STDataType x);
//��ջ
void StackPop(Stack* pst);
//ջ��Ԫ�ظ���
int StackSize(Stack* pst);
//ջ״̬�ж� ����1�ǿգ�����0�Ƿǿ�
int StackEmpty(Stack* pst);
//��ȡջ��������
STDataType StackTop(Stack* pst);
