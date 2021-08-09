#pragma once
#include<stdio.h>
#include<assert.h>
//打印数组
void PrintArray(int* arr, int n);
//插入排序
void InsertSort(int* arr, int n);
//希尔排序
void ShellSort(int* arr, int n);
//选择排序
void SelectSort(int* arr, int n);
//堆向下调整  大堆向下调整、小堆向下调整 
void AdjustDown_small(int* arr, int n, int root);
void AdjustDown_big(int* arr, int n, int root);
//堆排序
void HeapSort(int* arr, int n);
//冒泡排序
void BubbleSort(int* arr, int n);
//快速排序
void QuickSort(int* arr, int n);