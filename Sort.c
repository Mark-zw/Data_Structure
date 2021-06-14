#define _CRT_SECURE_NO_WARNINGS 1 
#include"Sort.h"
//打印函数
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//插入排序
void InsertSort(int* a, int n)
{
	assert(a);
	int i = 0;
	//边界控制不好，容易导致程序崩溃 比如i<n 
	//建议：画图 + 写注释
	for (i = 0; i < n - 1; i++)
	{
		//把end+1的书籍插入到[0,end]的有序区间
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

//希尔排序
void ShellSort(int* a, int n)
{
	//1.gap>1相当于预排序，让数组接近有序
	//2.gap == 1相当于直接插入排序，保证有序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//+1保证了最后一次gap一定为1
		//gap为1时就相当于直接插入排序
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
//交换
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//选择排序
void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		//在begin和end之间找出最小数和最大数的小标
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
		//将最大值和最小值交换到两端的位置
		Swap(&a[begin], &a[min_i]);
		//如果max_i与begin位置重叠，需要进行修正，不然交换两次 == 没交换
		if (begin == max_i)
		{
			max_i == min_i;
		}
		Swap(&a[end], &a[max_i]);
		begin++;
		end--;
	}
}

//堆排序
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
	//排升序，建大堆
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

//单趟快速排序
int PartSort(int* a, int begin, int end)
{
	int keyindex = end;
	while (begin < end)
	{
		//begin找大
		while (begin < end && a[begin] <= a[keyindex])
		{
			begin++;
		}
		//end找小
		while (begin < end && a[end] >= a[keyindex])
		{
			end--;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyindex]);
	return begin;
}

//快速排序--递归分治
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