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
	//������
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(php->_a, php->_size, i);
	}
}
//С��
  

//����
void HeapDestory(Heap* php);
//����
void HeapPush(Heap* php, HPDataType x);
//ɾ��
void HeapPop(Heap* php);