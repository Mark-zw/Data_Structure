#define _CRT_SECURE_NO_WARNINGS 1 
#include"Sort.h"
//��ӡ����
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//��������
void InsertSort(int* a, int n)
{
	assert(a);
	int i = 0;
	//�߽���Ʋ��ã����׵��³������ ����i<n 
	//���飺��ͼ + дע��
	for (i = 0; i < n - 1; i++)
	{
		//��end+1���鼮���뵽[0,end]����������
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//ϣ������
void ShellSort(int* a, int n)
{
	//1.gap>1�൱��Ԥ����������ӽ�����
	//2.gap == 1�൱��ֱ�Ӳ������򣬱�֤����
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//+1��֤�����һ��gapһ��Ϊ1
		//gapΪ1ʱ���൱��ֱ�Ӳ�������
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
//����
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//ѡ������
void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		//��begin��end֮���ҳ���С�����������С��
		int min_i, max_i;
		min_i = max_i = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] > a[max_i])
			{
				max_i = i;
			}
			if (a[i] < a[min_i])
			{
				min_i = i;
			}
		}
		//�����ֵ����Сֵ���������˵�λ��
		Swap(&a[begin], &a[min_i]);
		//���max_i��beginλ���ص�����Ҫ������������Ȼ�������� == û����
		if (begin == max_i)
		{
			max_i == min_i;
		}
		Swap(&a[end], &a[max_i]);
		begin++;
		end--;
	}
}

//������
void AdjustDwon(int* a, int n, int root)
{

	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child < n && a[child + 1]>a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
	}
}
void HeapSort(int* a, int n)
{
	//�����򣬽����
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}

//���˿�������
int PartSort(int* a, int begin, int end)
{
	int keyindex = end;
	while (begin < end)
	{
		//begin�Ҵ�
		while (begin < end && a[begin] <= a[keyindex])
		{
			begin++;
		}
		//end��С
		while (begin < end && a[end] >= a[keyindex])
		{
			end--;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyindex]);
	return begin;
}

//��������--�ݹ����
void QuickSort(int* a, int left, int right)
{
	assert(a);
	//if (left < right)
	//{
	//	int div = PartSort(a, left, right);
	//	QuickSort(a, left, div - 1);
	//	QuickSort(a, div + 1, right);
	//}
	//return;
	if (left >= right)
		return;

	int div = PartSort(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}