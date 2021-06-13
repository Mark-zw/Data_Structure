#define _CRT_SECURE_NO_WARNINGS 1 
#include"Sort.h"
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void TestInsertSort()
{
	int a[] = { 3,1,4,1,7,9,8,2,0,5 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));

}
void TestShellSort()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));

}
int main()
{
	TestInsertSort();
	TestShellSort();
	return 0;
}