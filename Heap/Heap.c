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
}
//小堆
//堆排序
void HeapSort(int* a, int n)
{
	//构建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//时间复杂度？
	//假设树有N个结点，树的高度 logN
	//注意这里的时间复杂度不是N*logN，是O(N)
	int end = n - 1;
	while (end)
	{ 
		Swap(&a[0], &a[end]);
		//再选择次小的
		AdjustDown(a, end, 0);
		end--;
	}
 }

//销毁
void HeapDestory(Heap* php)
{
	assert(php);
	free(php->_a);
	php->_a = NULL;
	php->_capacity = 0;
	php->_size = 0;
}
void AdjustUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child],&a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}

	}
}

//插入
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	//扩容检查
	if (php->_size == php->_capacity)
	{
		php->_capacity *= 2;
		HPDataType* tmp = realloc(php->_a, sizeof(HeapDestory) * php->_capacity);
		php->_a = tmp;
	}
	//插入数据
	php->_a[php->_size++] = x;
	//向上调整

}
//删除
void HeapPop(Heap* php)
{
	//删除堆顶的数据
	assert(php);
	assert(php->_size > 0);
	Swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;
	AdjustDown(php->_a, php->_size, 0);
}
HPDataType HeapTop(Heap* php)
{
	assert(php);
	return php->_a[0];
}