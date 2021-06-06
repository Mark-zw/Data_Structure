#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

////静态的栈
// struct Stack
//{
//	int _a[N];
//	int _size;
//};

typedef int STDataType;

//动态的栈
typedef struct Stack
{
	STDataType* _a;//带_表示为结构体成员，项目工程中经常使用
	int _top;//栈顶下标
	int _capacity;
}Stack;

//初始化
void StackInit(Stack* pst);
//销毁
void StackDestory(Stack* pst);
//进栈
void StackPush(Stack* pst, STDataType x);
//出栈
void StackPop(Stack* pst);
//栈的元素个数
int StackSize(Stack* pst);
//栈状态判断 返回1是空，返回0是非空
int StackEmpty(Stack* pst);
//获取栈顶的数据
STDataType StackTop(Stack* pst);
