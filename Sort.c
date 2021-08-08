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

