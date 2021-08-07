#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
#include<stdbool.h>

typedef char BTDataType;
typedef struct BinaryTreeNode 
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//ǰ��
void BinaryTreePreOrder(BTNode* root);
//����
void BinaryTreeInOrder(BTNode* root);
//����
void BinaryTreePostOrder(BTNode* root);
//�������
void BinaryTreeLevelOrder(BTNode* root);
//�����������ڵ�
BTNode* CreateTreeNode(BTDataType x);
//ͳ�ƽڵ����
int TreeSize(BTNode* root);
//��Ҷ�ӽڵ�ĸ���
int TreeLeafSize(BTNode* root);
//���k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
//����ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root,BTDataType x);
//������������
int BinaryDepth(BTNode* root);
//������������
void BinaryDestroy(BTNode* root);
//�ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root);