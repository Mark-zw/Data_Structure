#define _CRT_SECURE_NO_WARNINGS 1 
#include"Sort.h"

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