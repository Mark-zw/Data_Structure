#pragma once
#include<stdio.h>
#include<assert.h>
#include"Stack.h"
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
//hoare�汾 ����ָ���
int PartSort1(int* arr, int begin, int end);
//�ڿӷ�
int PartSort2(int* arr, int begin, int end);
//ǰ��ָ�뷨
int PartSort3(int* arr, int begin, int end);
//����ȡ���Ż�
int GetMidIndex(int* arr, int left, int right);
//���ŷǵݹ��
void QuickSortNonR(int* arr, int begin, int end);
//�鲢����
void MergeSort(int* arr, int n);