#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<assert.h>

//��ӡ����
void PrintArray(int* a, int n);

//��������
void InsertSort(int* a, int n);

//ϣ������
void ShellSort(int* a, int n);

//ѡ������
void SelectSort(int* a, int n);

//������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

//��������
void QuickSort(int* a, int left, int right);