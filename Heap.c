#define _CRT_SECURE_NO_WARNINGS 1 
#include"Heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//前提：左右子树都是小堆
void AdjustDown(HPDataType* a, int n, int root)
{

	int parent = root;
	int child = parent * 2 + 1;//默认交换到左孩子
	while (child < n)
	{
		//找出左右孩子中小的那个
		if (a[child] > a[child + 1] && child + 1< n)//然后将左孩子跟右孩子相比  child + 1防止右孩子越界
		{
			++child;
		}
		//如果父亲大于孩子，两者交换
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}

}

//初始化
void HeapInit(Heap* php, HPDataType* a, int n)
{
	php->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	//初始值
	memcpy(php->_a, a, sizeof(HPDataType) * n);
	php->_size = n;
	php->_capacity = n;
	//构建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(php->_a, php->_size, i);
	}
}
//小堆
  

//销毁
void HeapDestory(Heap* php);
//插入
void HeapPush(Heap* php, HPDataType x);
//删除
void HeapPop(Heap* php);