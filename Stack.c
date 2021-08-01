#define _CRT_SECURE_NO_WARNINGS 1 
#include"Stack.h"
//��ʼ��
void StackInit(Stack* pst)
{
	assert(pst);
	pst->capacity = 2;
	pst->top = 0;
	pst->arr = (STDataType*)malloc(pst->capacity * sizeof(STDataType));
}
//����
void StakDestroy(Stack* pst)
{
	assert(pst);
	free(pst->arr);
	pst->arr = NULL;
	pst->top = 0;
	pst->capacity = 0;
}
//���ݼ��
void CheckCapacity(Stack* pst)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		pst->capacity *= 2;
		STDataType* ptr = (STDataType*)realloc(pst->arr, pst->capacity * sizeof(STDataType));
		if (ptr == NULL)
		{
			printf("realloc fail!\n");
			exit(-1);//-1�����̵ģ���������
		}
		pst->arr = ptr;
	}
}

//��ջ
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	CheckCapacity(pst);
	pst->arr[pst->top] = x;
	pst->top++;
}
//��ջ
void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));
	pst->top--;
}
//��ȡջ��Ԫ��
STDataType StackTop(Stack* pst)
{
	return pst->arr[pst->top - 1];
}
//���ջ�Ƿ�Ϊ�գ���-���� �ǿ�-0
bool StackEmpty(Stack* pst)
{
	//if (pst->top == 0)
	//	return 1;
	//else
	//	return 0;
	assert(pst);
	return pst->top == 0;
}
//��ȡջ����ЧԪ�صĸ���
int StackSize(Stack* pst)
{
	return pst->top;
}
