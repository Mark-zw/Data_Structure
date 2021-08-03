#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
void Swap(int* p1, int* p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void AdjustDown_small(int* arr, int n, int parent)//建立小堆
{
	int child = parent * 2 + 1;
	while (child < n) {
		if (arr[child] > arr[child + 1] && (child+1) < n) {
			child++;
		}
		if (arr[child] < arr[parent]) {
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
void AdjustDown_bigger(int* arr, int n, int parent)//建立大堆
{
	int child = parent * 2 + 1;
	while (child < n) {
		if (arr[child] < arr[child + 1] && (child + 1) < n) {
			child++;
		}
		if (arr[child] > arr[parent]) {
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
//排升序，建小堆还是大堆？ --建立大堆
void HeapSort(int* arr, int n) {
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown_bigger(arr, n, i);
	}
	int end = n - 1;
	while (end)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown_bigger(arr, end, 0);//选出次大的数
		end--;
	}
}
int main()
{
	int arr[] = { 27,15,19.18,28,34,65,49,25,37 };
	int n = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, n);
	//AdjustDown(arr, n, 0);
	//建堆
	//int i = 0;
	//for (i = (n - 1 - 1) / 2; i >= 0; i--) {
	//	AdjsutDown(arr, n, i);
	//}
	return 0;
}