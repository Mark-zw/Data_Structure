#define _CRT_SECURE_NO_WARNINGS 1 
#include"Stack.h"
//初始化
void StackInit(Stack* pst)
{
	assert(pst);
	//第一种方式
	//pst->_a = NULL;
	//pst->_top = 0;
	//pst->_capacity = 0;

	//第二种方式
	pst->_a = malloc(sizeof(STDataType) * 4);
	pst->_top = 0;
	pst->_capacity = 4;

}
//销毁
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->_top = pst->_capacity = 0;
}
//入栈/进栈
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	//空间不够则增容
	if (pst->_top == pst->_capacity)
	{
		pst->_capacity *= 2;
		STDataType* tmp = realloc(pst->_a, sizeof(STDataType) * pst->_capacity);
		if (tmp == NULL)
		{
			printf("realloc fail!\n");
			exit(-1);
		}
	}
	pst->_a[pst->_top] = x;
	pst->_top++;
}
//出栈
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);

	--pst->_top;
}
//栈的元素个数
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}
//栈状态判断 返回1是空，返回0是非空
int StackEmpty(Stack* pst)
{
	assert(pst);
	//return pst->_top == 0 ? 1 : 0;
	return !pst->_top;
}
//获取栈顶的数据
STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);
	return pst->_a[pst->_top - 1];
}
