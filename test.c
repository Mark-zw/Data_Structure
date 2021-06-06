#define _CRT_SECURE_NO_WARNINGS 1 
#include"Stack.h"
#include"Queue.h"

void TestStack()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);

	printf("%d ", StackTop(&st));
	StackPop(&st);

	StackPush(&st, 3);
	StackPush(&st, 4);
	while (StackEmpty(&st) == 0)
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	StackDestory(&st);

}
void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);

	printf("%d ", QueueFront(&q));
	QueuePop(&q);

	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestory(&q);

}
int main()
{
	//TestStack();
	TestQueue();
	return 0;
}