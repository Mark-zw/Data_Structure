#define _CRT_SECURE_NO_WARNINGS 1 
#include"Sort.h"
//打印数组
void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n------------------------\n");
}


////插入排序
//void InsertSort(int* arr, int n)
//{
//	assert(arr);
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		//第一趟找到i应该所在的下标
//		for (j = i - 1; j >= 0; j--)
//		{
//			if (arr[j] < arr[i])
//				break;
//		}
//		//第二趟，进行移动元素，将第j+1到第i的元素全部往后移动
//		int k = 0;
//		int temp = arr[i];
//		for (k = i; k > j+1; k--)
//		{
//			arr[k] = arr[k - 1];
//		}
//		//将元素插入到正确位置
//		arr[k] = temp;
//	}
//}

//代码优化
void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1 ; i++)
	{
		int end = i;
		int temp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > temp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = temp;
	}
}

//希尔排序
void ShellSort(int* arr, int n)
{
	//int gap = 3;gap随数据的规模而变动，
	//gap > 1时，都是预排序，gap == 1时，就是直接插入排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//+1 是为了保证gap可以取到1
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = arr[end + gap];
			while (end >= 0)
			{
				if (temp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = temp;
		}
	}
}
////选择排序
//void SelectSort(int* arr, int n)
//{
//	//经典版
//}

//选择排序
void SelectSort(int* arr, int n)
{
	//优化版--同时选出最小的数和最大的数
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int minIndex = left, maxIndex = left;
		//选出最小值，最大值
		for (int i = left; i <= right; i++)
		{
			if (arr[i] < arr[minIndex])
				minIndex = i;
			if (arr[i] > arr[maxIndex])
				maxIndex = i;
		}
		//将最小值放到最左边，最大值放到最右边
		int temp = arr[minIndex];
		arr[minIndex] = arr[left];
		arr[left] = temp;
		//前者的交换可能会影响后面的交换
		if (left == maxIndex)
		{
			maxIndex = minIndex;
		}

		temp = arr[maxIndex];
		arr[maxIndex] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
}

