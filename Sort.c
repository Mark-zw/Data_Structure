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

////快速排序
//void QuickSort(int* arr, int begin,int end)
//{
//	if (begin >= end)
//		return;
//
//	int meet = PartSort3(arr, begin, end);
//	//[begin,meet-1] [meet+1 end]
//	QuickSort(arr, begin, meet - 1);
//	QuickSort(arr, meet + 1, end);
//}
// 
//快速排序 小区间优化版
void QuickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//1.如果这个子区间的数据较多，继续选key单趟，分割
	if (end - begin > 10)
	{
		int meet = PartSort3(arr, begin, end);
		//[begin,meet-1] [meet+1 end]
		QuickSort(arr, begin, meet - 1);
		QuickSort(arr, meet + 1, end);
	}
	//2.如果子区间的数据较小，再去分治递归就不太好，可以用其它方式代替，使其有序
	//使用插入排序
	else
	{
		InsertSort(arr + begin, end - begin + 1);//小区间优化
	}
}
//快排非递归版  递归现代计算机性能优化很好，已经不是问题，
//递归最大的问题是递归的深度太深，程序本身没问题，但是栈空间不够，导致栈溢出
//这个时候只能改成非递归的方式，改非递归的方式有两种
//1.直接改循环  比如：斐波那契数列求解
//2.栈stack模拟递归，比如树遍历的递归和快排非递归，只能用Stack栈存储数据模拟递归的过程
void QuickSortNonR(int* arr, int begin, int end)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int left, right;
		right = StackTop(&st);
		StackPop(&st);

		left = StackTop(&st);
		StackPop(&st);

		int meet = PartSort3(arr, left, right);
		if (left < meet - 1)
		{
			StackPush(&st, left);
			StackPush(&st, meet - 1);
		}
		if (meet + 1 < right)
		{
			StackPush(&st, meet + 1);
			StackPush(&st, right);
		}
	}
	StakDestroy(&st);
}

//三数取中优化
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
//hoare版本 左右指针版
int PartSort1(int* arr, int begin, int end)
{
	//优化 三数取中
	int mid = GetMidIndex(arr, begin, end);
	Swap(&arr[begin], &arr[mid]);

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

//挖坑法
int PartSort2(int* arr, int begin, int end)
{
	//优化 三数取中
	int mid = GetMidIndex(arr, begin, end);
	Swap(&arr[begin], &arr[mid]);

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
int PartSort3(int* arr, int begin, int end)
{
	//优化 三数取中
	int mid = GetMidIndex(arr, begin, end);
	Swap(&arr[begin], &arr[mid]);

	int key = begin;
	int prev = begin;
	int cur = begin + 1;
	//优化
	while (cur <= end)
	{
		if (arr[cur] < arr[key] && ++prev != cur)
		{
			Swap(&arr[cur], &arr[prev]);
		}
		cur++;
	}
	//while (cur <= end)
	//{
	//	//cur往后找比key小的数
	//	while (cur<= end && arr[cur] < arr[key])
	//	{
	//		cur++;
	//	}
	//	//找到小的后就跟prev位置是数进行交换，交换前prev要先移到下一个位置
	//	Swap(&arr[++prev], &arr[cur]);
	//}
	//将key的位置跟prev交换一下
	Swap(&arr[key], &arr[prev]);
	//key = prev;
	//return key;
	return prev;
}
//归并子函数
void _MergeSort(int* arr, int begin, int end,int* temp)
{
	if (begin >= end)
		return;

	int mid = (begin + end) >> 1;
	//[begin,mid] [mid,end]
	_MergeSort(arr, begin, mid, temp);
	_MergeSort(arr, mid + 1, end, temp);

	//归并：将两段子区间归并到temp中，并拷贝回去
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			temp[i++] = arr[begin1++];
		else
			temp[i++] = arr[begin2++];
	}
	while(begin1<=end1)
		temp[i++] = arr[begin1++];
	while (begin2 <= end2)
		temp[i++] = arr[begin2++];
	//将合并的结果拷贝回原数组arr中
	for (int i = begin; i <= end; i++)
	{
		arr[i] = temp[i];
	}
}

//归并排序  需要借助一个临时数组
void MergeSort(int* arr, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	if (temp == NULL)
	{
		printf("malloc failed!\n");
		return;
	}
	_MergeSort(arr, 0, n - 1,temp);
	free(temp);
}