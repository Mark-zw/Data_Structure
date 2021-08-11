#pragma once
#include<stdio.h>
#include<assert.h>
#include"Stack.h"
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
//hoare版本 左右指针版
int PartSort1(int* arr, int begin, int end);
//挖坑法
int PartSort2(int* arr, int begin, int end);
//前后指针法
int PartSort3(int* arr, int begin, int end);
//三数取中优化
int GetMidIndex(int* arr, int left, int right);
//快排非递归版
void QuickSortNonR(int* arr, int begin, int end);
//归并排序
void MergeSort(int* arr, int n);