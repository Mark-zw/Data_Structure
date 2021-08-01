#define _CRT_SECURE_NO_WARNINGS 1 
#include"Stack.h"
//初始化
void StackInit(Stack* pst)
{
	assert(pst);
	pst->capacity = 2;
	pst->top = 0;
	pst->arr = (STDataType*)malloc(pst->capacity * sizeof(STDataType));
}
//销毁
void StakDestroy(Stack* pst)
{
	assert(pst);
	free(pst->arr);
	pst->arr = NULL;
	pst->top = 0;
	pst->capacity = 0;
}
//增容检测
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
			exit(-1);//-1给进程的，结束程序
		}
		pst->arr = ptr;
	}
}

//入栈
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	CheckCapacity(pst);
	pst->arr[pst->top] = x;
	pst->top++;
}
//出栈
void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));
	pst->top--;
}
//获取栈顶元素
STDataType StackTop(Stack* pst)
{
	return pst->arr[pst->top - 1];
}
//检测栈是否为空，空-非零 非空-0
bool StackEmpty(Stack* pst)
{
	//if (pst->top == 0)
	//	return 1;
	//else
	//	return 0;
	assert(pst);
	return pst->top == 0;
}
//获取栈中有效元素的个数
int StackSize(Stack* pst)
{
	return pst->top;
}
