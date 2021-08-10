#define _CRT_SECURE_NO_WARNINGS 1 
#include"Sort.h"
//��ӡ����
void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n------------------------\n");
}


////��������
//void InsertSort(int* arr, int n)
//{
//	assert(arr);
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		//��һ���ҵ�iӦ�����ڵ��±�
//		for (j = i - 1; j >= 0; j--)
//		{
//			if (arr[j] < arr[i])
//				break;
//		}
//		//�ڶ��ˣ������ƶ�Ԫ�أ�����j+1����i��Ԫ��ȫ�������ƶ�
//		int k = 0;
//		int temp = arr[i];
//		for (k = i; k > j+1; k--)
//		{
//			arr[k] = arr[k - 1];
//		}
//		//��Ԫ�ز��뵽��ȷλ��
//		arr[k] = temp;
//	}
//}

//�����Ż�
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

//ϣ������
void ShellSort(int* arr, int n)
{
	//int gap = 3;gap�����ݵĹ�ģ���䶯��
	//gap > 1ʱ������Ԥ����gap == 1ʱ������ֱ�Ӳ�������
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//+1 ��Ϊ�˱�֤gap����ȡ��1
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
////ѡ������
//void SelectSort(int* arr, int n)
//{
//	//�����
//}

//ѡ������
void SelectSort(int* arr, int n)
{
	//�Ż���--ͬʱѡ����С������������
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int minIndex = left, maxIndex = left;
		//ѡ����Сֵ�����ֵ
		for (int i = left; i <= right; i++)
		{
			if (arr[i] < arr[minIndex])
				minIndex = i;
			if (arr[i] > arr[maxIndex])
				maxIndex = i;
		}
		//����Сֵ�ŵ�����ߣ����ֵ�ŵ����ұ�
		int temp = arr[minIndex];
		arr[minIndex] = arr[left];
		arr[left] = temp;
		//ǰ�ߵĽ������ܻ�Ӱ�����Ľ���
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
//��������
void Swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
//�����µ���  ������µ�����С�����µ��� 
void AdjustDown_small(int* arr, int n, int root)
{
	//С�����µ���
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
	//С�����µ���
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] < arr[child + 1] )//&& ������������  ע��Ҫ�ȼ��Ȼ����жϣ�����Խ�����
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
//������
void HeapSort(int* arr, int n)
{
	//�������齨���� �����򽨴�ѣ��Ž���С��
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown_big(arr, n , i);//nʵ�����������ұ߽߱�
	}
	//ÿ�ζ����Ѷ���Ԫ�ظ������һ��Ԫ�ؽ������ѵĴ�С-1
	i = n - 1;
	while (i > 0)
	{
		Swap(&arr[0], &arr[i]);
		AdjustDown_big(arr, i, 0);
		i--;
	}
}
//ð������
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
//hoare�汾 ����ָ���
int PartSort(int* arr, int begin, int end)
{
	//�Ż� ����ȡ��
	int mid = GetMidIndex(arr, begin, end);
	Swap(arr[begin], arr[mid]);

	int left = begin;
	int right = end;
	int key = left;
	while (left < right)
	{
		//right�ұ�keyС����
		while (right > left && arr[right] >= arr[key])
		{
			right--;
		}
		//left�ұ�key�����
		while (left < right && arr[left] <= arr[key])
		{
			left++;
		}
		if (left < right)
			Swap(&arr[left], &arr[right]);
	}
	int meet = left;
	//��key������λ�ý���
	Swap(&arr[key], &arr[meet]);
	return meet;
}
//��������
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

//�ڿӷ�
int PartSort1(int* arr, int begin, int end)
{
	//�ڿӣ��γɿ�λ
	int key = arr[begin];
	int left = begin;
	int right = end;
	while (left < right)
	{
		//�ұ���С
		while (left < right && arr[right] >= key)
		{
			right--;
		}
		//��ӣ��γ��µĿ�λ
		arr[left] = arr[right];
		//����Ҵ�
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		//��ӣ��γ��µĿ�λ
		arr[right] = arr[left];
	}
	//left = rightʱ����
	arr[left] = key;
}

//ǰ��ָ�뷨