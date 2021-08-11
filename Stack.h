#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;//ջ��
	int capacity;//����
}Stack;

//��ʼ��
void StackInit(Stack* pst);
//����
void StakDestroy(Stack* pst);
//��ջ
void StackPush(Stack* pst, STDataType x);
//��ջ
void StackPop(Stack* pst);
//��ȡջ��Ԫ��
STDataType StackTop(Stack* pst);
//���ջ�Ƿ�Ϊ�գ���-���� �ǿ�-0
bool StackEmpty(Stack* pst);
//��ȡջ����ЧԪ�صĸ���
int StackSize(Stack* pst);