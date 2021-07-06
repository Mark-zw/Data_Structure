#define _CRT_SECURE_NO_WARNINGS 1 
#include"BinaryTree.h"
//����������ĸ���

int TreeSize(BTNode* root)
{
	//����һ
	//static int size = 0;
	//if (root == NULL)
	//	return 0;
	//size++;
	//TreeSize(root->left);
	//TreeSize(root->right);
	//return size;

	//������
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

//ǰ�����
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
//�������
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

//�������
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

//����α������
BTNode* CreateNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));

	node->_data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
//��������k�������
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
