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
//两数交换
void Swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
//堆向下调整  大堆向下调整、小堆向下调整 
void AdjustDown_small(int* arr, int n, int root)
{
	//小堆向下调整
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (arr[child] > arr[child + 1])
		{
			child++;
		}
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}
void AdjustDown_big(int* arr, int n, int root)
{
	//小堆向下调整
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] < arr[child + 1] )//&& 操作符的特性  注意要先检查然后才判断，避免越界访问
		{
			child++;
		}
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}
//堆排序
void HeapSort(int* arr, int n)
{
	//根据数组建立堆 排升序建大堆，排降序建小堆
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown_big(arr, n , i);//n实际上是数组右边边界
	}
	//每次都将堆顶的元素跟堆最后一个元素交换，堆的大小-1
	i = n - 1;
	while (i > 0)
	{
		Swap(&arr[0], &arr[i]);
		AdjustDown_big(arr, i, 0);
		i--;
	}
}
//冒泡排序
void BubbleSort(int* arr, int n)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n -1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
//hoare版本 左右指针版
int PartSort(int* arr, int begin, int end)
{
	//优化 三数取中
	int mid = GetMidIndex(arr, begin, end);
	Swap(arr[begin], arr[mid]);

	int left = begin;
	int right = end;
	int key = left;
	while (left < right)
	{
		//right找比key小的数
		while (right > left && arr[right] >= arr[key])
		{
			right--;
		}
		//left找比key大的数
		while (left < right && arr[left] <= arr[key])
		{
			left++;
		}
		if (left < right)
			Swap(&arr[left], &arr[right]);
	}
	int meet = left;
	//将key与相遇位置交换
	Swap(&arr[key], &arr[meet]);
	return meet;
}
//快速排序
void QuickSort(int* arr, int begin,int end)
{
	if (begin >= end)
		return;
	int meet = PartSort(arr, begin, end);
	//[begin,meet-1] [meet+1 end]
	QuickSort(arr, begin, meet - 1);
	QuickSort(arr, meet + 1, end);
}
int GetMidIndex(int* arr, int left, int right)
{
	int mid = (left + right) >> 1;
	if (arr[left] < arr[mid])
	{
		if (arr[mid] < arr[right])
			return mid;
		else if (arr[left] > arr[right])
			return left;
		else
			return right;
	}
	else
	{
		if (arr[left] > arr[right])
			return right;
		else if (arr[mid] > arr[right])
			return mid;
		else
			return right;
	}
}

//挖坑法
int PartSort1(int* arr, int begin, int end)
{
	//挖坑，形成坑位
	int key = arr[begin];
	int left = begin;
	int right = end;
	while (left < right)
	{
		//右边找小
		while (left < right && arr[right] >= key)
		{
			right--;
		}
		//填坑，形成新的坑位
		arr[left] = arr[right];
		//左边找大
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		//填坑，形成新的坑位
		arr[right] = arr[left];
	}
	//left = right时相遇
	arr[left] = key;
}

//前后指针法