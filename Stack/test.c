#define _CRT_SECURE_NO_WARNINGS 1 
#include"Stack.h"
void TestStack()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	printf("%d ", StackTop(&st));
	StackPop(&st);
	StackPush(&st, 2);
	printf("%d ", StackTop(&st));
	StackPop(&st);
	StackPush(&st, 3);
	StackPush(&st, 4);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}

	StakDestroy(&st);
}

int main()
{
	TestStack();
	return 0;
}