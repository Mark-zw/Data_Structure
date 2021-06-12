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

//求二叉树结点的个数
int TreeSize(BTNode* root);

//前序遍历
void BinaryTreePrevOrder(BTNode* root);

//中序遍历
void BinaryTreeInOrder(BTNode* root);

//后序遍历
void BinaryTreePostOrder(BTNode* root);

//构建伪二叉树
BTNode* CreateNode(int x);