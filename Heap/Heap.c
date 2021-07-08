#define _CRT_SECURE_NO_WARNINGS 1 
#include"Heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//ǰ�᣺������������С��
void AdjustDown(HPDataType* a, int n, int root)
{

	int parent = root;
	int child = parent * 2 + 1;//Ĭ�Ͻ���������
	while (child < n)
	{
		//�ҳ����Һ�����С���Ǹ�
		if (a[child] > a[child + 1] && child + 1< n)//Ȼ�����Ӹ��Һ������  child + 1��ֹ�Һ���Խ��
		{
			++child;
		}
		//������״��ں��ӣ����߽���
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

//��ʼ��
void HeapInit(Heap* php, HPDataType* a, int n)
{
	php->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	//��ʼֵ
	memcpy(php->_a, a, sizeof(HPDataType) * n);
	php->_size = n;
	php->_capacity = n;
}
//С��
//������
void HeapSort(int* a, int n)
{
	//������
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//ʱ�临�Ӷȣ�
	//��������N����㣬���ĸ߶� logN
	//ע�������ʱ�临�ӶȲ���N*logN����O(N)
	int end = n - 1;
	while (end)
	{ 
		Swap(&a[0], &a[end]);
		//��ѡ���С��
		AdjustDown(a, end, 0);
		end--;
	}
 }

//����
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

//����
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	//���ݼ��
	if (php->_size == php->_capacity)
	{
		php->_capacity *= 2;
		HPDataType* tmp = realloc(php->_a, sizeof(HeapDestory) * php->_capacity);
		php->_a = tmp;
	}
	//��������
	php->_a[php->_size++] = x;
	//���ϵ���

}
//ɾ��
void HeapPop(Heap* php)
{
	//ɾ���Ѷ�������
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