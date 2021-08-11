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
	int top;//栈顶
	int capacity;//容量
}Stack;

//初始化
void StackInit(Stack* pst);
//销毁
void StakDestroy(Stack* pst);
//入栈
void StackPush(Stack* pst, STDataType x);
//出栈
void StackPop(Stack* pst);
//获取栈顶元素
STDataType StackTop(Stack* pst);
//检测栈是否为空，空-非零 非空-0
bool StackEmpty(Stack* pst);
//获取栈中有效元素的个数
int StackSize(Stack* pst);