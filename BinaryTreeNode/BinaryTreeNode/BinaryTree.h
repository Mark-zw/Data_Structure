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

//前序
void BinaryTreePreOrder(BTNode* root);
//中序
void BinaryTreeInOrder(BTNode* root);
//后序
void BinaryTreePostOrder(BTNode* root);
//层序遍历
void BinaryTreeLevelOrder(BTNode* root);
//构建二叉树节点
BTNode* CreateTreeNode(BTDataType x);
//统计节点个数
int TreeSize(BTNode* root);
//求叶子节点的个数
int TreeLeafSize(BTNode* root);
//求第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
//查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root,BTDataType x);
//求二叉树的深度
int BinaryDepth(BTNode* root);
//二叉树的销毁
void BinaryDestroy(BTNode* root);
//判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root);