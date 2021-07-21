#define _CRT_SECURE_NO_WARNINGS 1 
#include"SeqList.h"

//创建---初始化
void SeqListInit(SL* seq)
{
	seq->capacity = Init_SIZE;
	seq->size = 0;
	seq->arr = (SLDatatype*)malloc(seq->capacity * sizeof(SLDatatype));
}

//销毁
void SeqListDestory(SL* seq)
{
	free(seq->arr);
	seq->arr = NULL;
	seq->size = 0;
	seq->capacity = 0;
}

//打印
void SeqListPrint(SL* seq)
{
	int i = 0;
	for (i = 0; i < seq->size; i++)
	{
		printf("%d  ", seq->arr[i]);
	}
	printf("\n-------------------------\n");
}

//扩容检查
void CheckCapacity(SL* seq)
{
	//判断是否需要扩容
	if (seq->size == seq->capacity)
	{
		//进行扩容操作
		seq->capacity = 2 * seq->capacity;
		SLDatatype* ptr = (SLDatatype*)realloc(seq->arr, seq->capacity * sizeof(SLDatatype));
		if (ptr != NULL)
		{
			seq->arr = ptr;
			printf("Increase Capacity Success!\n");
		}
		else
		{
			perror("Increase Capacity Failed!\n");
		}
	}
}


//尾插
void SeqListPushBack(SL* seq, SLDatatype x)
{
	//1.插入数据时，首先要判断是否有空间供插入使用
	//将检测是否扩容封装成一个函数
	CheckCapacity(seq);
	//2.扩容结束后，进行数据的插入
	seq->arr[seq->size] = x;
	//3.seq->size+1
	seq->size++;
}

//头插
void SeqListPushFront(SL* seq, SLDatatype x)
{
	int i = 0;
	CheckCapacity(seq);
	//1.先将所有元素按照从后往前的顺序移动
	for (i = seq->size; i > 0; i--)
	{
		seq->arr[i] = seq->arr[i-1];
	}
	//2.在头部插入数据
	seq->arr[i] = x;//也可以写成seq->arr[0] = x;
	//3.seq->size+1
	seq->size++;
}

//尾删
void SeqListPopBack(SL* seq)
{
	//删除数据时，需要判断是否有数据
	if (seq->size == 0)
	{
		printf("The SeqList is empty!\n");
		return;
	}
	seq->size--;
}
//头删
void SeqListPopFront(SL* seq)
{
	//删除数据时，需要判断是否有数据
	if (seq->size == 0)
	{
		printf("The SeqList is empty!\n");
		return;
	}
	//利用元素的覆盖来实现数据删除
	//将第二个元素及其之后的元素按照从前往后顺序依次移到前一位
	int i = 0;
	for (i = 0; i < seq->size - 1; i++)
	{
		seq->arr[i] = seq->arr[i + 1];
	}
	seq->size--;
}