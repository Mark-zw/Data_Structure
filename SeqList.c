#define _CRT_SECURE_NO_WARNINGS 1 
#include"SeqList.h"
//初始化
void SeqListInit(SeqList* pList)
{
	assert(pList);
	pList->array = NULL;
	pList->size = 0;
	pList->capacity = 0;//初始给4个存储单元
}
//销毁 
void SeqListDestory(SeqList* pList)
{
	assert(pList);
	free(pList->array);
	pList->array = NULL;
	pList->size = 0;
	pList->capacity = 0;
	printf("Destory successed!\n");
}

//打印
void SeqListPrint(SeqList* pList)
{
	assert(pList);
	if (pList->size == 0)
	{
		printf("SeqList is empty!\n");
	}
	else
	{
		int i = 0;
		for (i = 0; i < pList->size; i++)
		{
			printf("%d ", pList->array[i]);
		}
	}
}
//空间检查，如果满了，进行增容
void CheckCapacity(SeqList* pList)
{
	assert(pList);
	if (pList->size == pList->capacity)
	{
		//增容的时候数组的空间大小也需要调整
		//判断顺序表容量是否为0，若为0，则先开辟用于存放4个元素的空间大小，
		//若不为0，则扩容为原来容量的两倍
		int NewCapacity = pList->capacity == 0 ? 4 : 2 * pList->capacity;
		SLDataType* NewArray = (SLDataType*)realloc(pList->array, sizeof(SLDataType) * NewCapacity);
		if (NewArray == NULL)
		{
			printf("realloc fail!\n");
			return exit(-1);
		}
		pList->array = NewArray;
		pList->capacity = NewCapacity;
		printf("Capacity of success!\n");
	}
}

//尾插
void SeqListPushBack(SeqList* pList, SLDataType x)
{
	//assert(pList);
	////1.在做插入数据操作时，若涉及到存储空间可能满了的情况，需要先进行判断
	////2.存储空间满了，需要进行相应的扩容操作
	////考虑到后续还会写其它的插入函数，也会涉及这一步，干脆将其进行封装成独立的函数模块
	//CheckCapacity(pList);
	////3.尾部插入数据
	//pList->array[pList->size] = x;
	//pList->size++;

	//可以直接调用在任意位置插入的函数
	SeqListInsert(pList, pList->size, x);
}
//尾删
void SeqListPopBack(SeqList* pList)
{
	//assert(pList);
	////1.在涉及到数据的删除时，首先要判断该空间是否还有数据
	//if (pList->size == 0)
	//{
	//	printf("No element in SeqList\n");
	//	printf("PopBack failure\n");
	//}
	////2.存在数据的时，删除数据只需要将pList->size--，且不需要将该位置数组元素置为0，
	////置为0没有任何意义，因为后续也不知道这个0是本身的数据元素还是置为的0。
	//else
	//{
	//	pList->size--;
	//	//一般来说，增容之后的capacity不会再被重置回去，待讨论
	//}

	//可以直接调用在任意位置删除的函数
	SeqListErase(pList, pList->size);
}
//头插
void SeqListPushFront(SeqList* pList, SLDataType x)
{
	//assert(pList);
	//int i = 0;
	////1.在做插入数据操作时，若涉及到存储空间可能满了的情况，需要先进行判断
	////2.存储空间满了，需要进行相应的扩容操作
	////考虑到后续还会写其它的插入函数，也会涉及这一步，干脆将其进行封装成独立的函数模块
	//CheckCapacity(pList);
	////(1)先将pList->size++
	//pList->size++;
	////(2)按照从后往前的方式依次移动元素到相邻位置
	//for (i = pList->size - 1; i > 0; i--)
	//{
	//	pList->array[i] = pList->array[i - 1];
	//}
	////(3)将x插入首地址处
	//pList->array[0] = x;

	//可以直接调用在任意位置插入的函数
	SeqListInsert(pList, 0, x);

}
//头删
void SeqListPopFront(SeqList* pList)
{
	//assert(pList);
	////1.在涉及到数据的删除时，首先要判断该空间是否还有数据
	//if (pList->size == 0)
	//{
	//	printf("No element in SeqList\n");
	//	printf("PopBack failure\n");
	//}
	//else
	//{
	//	//2.将数组中的元素按照从前往后的顺序移动至相邻位置
	//	int i = 0;
	//	for (i = 0; i < pList->size - 1; i++)
	//	{
	//		pList->array[i] = pList->array[i + 1];
	//	}
	//	//3.将pList->size-- 数组元素-1
	//	pList->size--;
	//}

	//可以直接调用在任意位置删除的函数
	SeqListErase(pList, 0);
}
//查找  查找到了就返回下标值，如果查找不到就返回-1，下标不可能为-1
int SeqListFind(SeqList* pList, SLDataType x)
{
	assert(pList);
	int i = 0;
	//数组没有元素和查找不到可以放到同一种情况---查找不到！
	for (i = 0; i < pList->size; i++)
	{
		if (pList->array[i] == x)
		{
			return i;
		}
	}
	return -1;//查找不到，返回-1
}
//在任意位置插入
void SeqListInsert(SeqList* pList, size_t pos, SLDataType x)
{
	assert(pList);
	//1.在做插入数据操作时，若涉及到存储空间可能满了的情况，需要先进行判断
	//2.存储空间满了，需要进行相应的扩容操作
	//考虑到后续还会写其它的插入函数，也会涉及这一步，干脆将其进行封装成独立的函数模块
	CheckCapacity(pList);
	if (pos > pList->size)
	{
		printf("The position to insert is wrong!\n");
	}
	else
	{
		//(1)先将pList->size++
		pList->size++;
		//(2)将pos及其右边的元素按照从后往前的顺序，移动至相邻位置
		int i = 0;
		for (i = pList->size-1; i > pos; i--)
		{
			pList->array[i] = pList->array[i - 1];
		}
		pList->array[pos] = x;
	}
}

//在任意位置删除
void SeqListErase(SeqList* pList, size_t pos)
{
	assert(pList);
	//1.在涉及到数据的删除时，首先要判断该空间是否还有数据
	if (pList->size == 0)
	{
		printf("No element in SeqList\n");
		printf("PopBack failure\n");
	}
	if (pos > pList->size)
	{
		printf("The position to Erase element is wrong!\n");
	}
	else
	{
		//(1)将下标为pos及其右边的元素按照从前往后的顺序移动至相邻位置
		int i = 0;
		for (i = pos; i < pList->size - 1; i++)
		{
			pList->array[i] = pList->array[i + 1];
		}
		//(2)将size-1
		pList->size--;
	}
}