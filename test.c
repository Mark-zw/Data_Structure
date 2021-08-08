#define _CRT_SECURE_NO_WARNINGS 1 
#include"Sort.h"
int main()
{
	int arr[] = { 11,0,2,4,3,1,8,9,10,7,6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//InsertSort(arr, n);
	//ShellSort(arr, n);
	SelectSort(arr, n);
	PrintArray(arr, n);
	return 0;
}