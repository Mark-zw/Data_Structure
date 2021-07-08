#define _CRT_SECURE_NO_WARNINGS 1 
#include"Heap.h"
int main()
{
	HPDataType arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	Heap hp;
	//HeapInit(&hp, arr, sizeof(arr) / sizeof(HPDataType));
	HeapSort(arr, sizeof(arr) / sizeof(HPDataType));
	return 0;
}