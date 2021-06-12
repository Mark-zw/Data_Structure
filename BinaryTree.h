#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;

}BTNode;

//����������ĸ���
int TreeSize(BTNode* root);

//ǰ�����
void BinaryTreePrevOrder(BTNode* root);

//�������
void BinaryTreeInOrder(BTNode* root);

//�������
void BinaryTreePostOrder(BTNode* root);

//����α������
BTNode* CreateNode(int x);