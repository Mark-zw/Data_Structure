#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode {
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