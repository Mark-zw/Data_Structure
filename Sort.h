#pragma once
#include<stdio.h>
#include<assert.h>
//��ӡ����
void PrintArray(int* arr, int n);
//��������
void InsertSort(int* arr, int n);
//ϣ������
void ShellSort(int* arr, int n);
//ѡ������
void SelectSort(int* arr, int n);
//�����µ���  ������µ�����С�����µ��� 
void AdjustDown_small(int* arr, int n, int root);
void AdjustDown_big(int* arr, int n, int root);
//������
void HeapSort(int* arr, int n);
//ð������
void BubbleSort(int* arr, int n);
//��������
void QuickSort(int* arr, int n);