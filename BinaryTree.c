#define _CRT_SECURE_NO_WARNINGS 1 
#include"BinaryTree.h"
//求二叉树结点的个数

int TreeSize(BTNode* root)
{
	//方法一
	//static int size = 0;
	//if (root == NULL)
	//	return 0;
	//size++;
	//TreeSize(root->left);
	//TreeSize(root->right);
	//return size;

	//方法二
	if (root == NULL)
		return 0;
	else
		return 1 + TreeSize(root->left) + TreeSize(root->right);
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else if (root->left == 0 && root->right == 0)
		return 1;
	return  TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
//中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->right);
}

//后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->_data);
}

//构建伪二叉树
BTNode* CreateNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));

	node->_data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
//二叉树第k层结点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
