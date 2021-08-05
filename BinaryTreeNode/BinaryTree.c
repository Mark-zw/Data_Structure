#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"
//前序
void BinaryTreePreOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	//根   左子树   右子树
	printf("%c ", root->data);
	BinaryTreePreOrder(root->left);
	BinaryTreePreOrder(root->right);
}
//中序 左子树 根 右子树
void BinaryTreeInOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}
//后序 左子树 根 右子树
void BinaryTreePostOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}
//构建二叉树节点
BTNode* CreateTreeNode(BTDataType x) {
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL) {
		printf("malloc fail!\n");
		exit(-1);
	}
	node->data = x;
	node->left = node->right = NULL;
	return node;
}
//统计节点个数
int TreeSize(BTNode* root) {
	//return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
	if (root == NULL)
		return 0;
	else
		return TreeSize(root->left) + TreeSize(root->right) + 1;
}
//求叶子节点的个数
int TreeLeafSize(BTNode* root) {
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
//求第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL)
		return 0;
	else if (k == 1)
		return 1;
	else
		return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
//查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//求二叉树的深度
int BinaryDepth(BTNode* root) {
	if (root == NULL)
		return 0;
	else
		return BinaryDepth(root->left) > BinaryDepth(root->right) ? 
		BinaryDepth(root->left) + 1 : BinaryDepth(root->right) + 1;
}