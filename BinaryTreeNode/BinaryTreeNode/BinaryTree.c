#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"


//前序
void BinaryTreePreOrder(BTNode* root) 
{
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
void BinaryTreeInOrder(BTNode* root) 
{
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}
//后序 左子树 根 右子树
void BinaryTreePostOrder(BTNode* root) 
{
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}
//构建二叉树节点
BTNode* CreateTreeNode(BTDataType x) 
{
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
int TreeSize(BTNode* root) 
{
	//return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
	if (root == NULL)
		return 0;
	else
		return TreeSize(root->left) + TreeSize(root->right) + 1;
}
//求叶子节点的个数
int TreeLeafSize(BTNode* root) 
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
//求第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k) 
{
	if (root == NULL)
		return 0;
	else if (k == 1)
		return 1;
	else
		return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
//查找值为x的节点
//思路：1）root == NULL return NULL
//2）root 节点不是我们要找的，先到左树去找，左树如果没有，再到右树去找，左右都没有，返回NULL
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	//最后一个if的替代
	//if (BinaryTreeFind(root->left, x) == NULL && BinaryTreeFind(root->right, x) == NULL)//这个好像莫名其妙的
	//	return NULL;

	BTNode* left = BinaryTreeFind(root->left, x);
	if (left) 
		return left;
	BTNode* right = BinaryTreeFind(root->right, x);
	if (right)
		return right;
	return NULL;
}
//求二叉树的深度
int BinaryDepth(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
		return BinaryDepth(root->left) > BinaryDepth(root->right) ? 
		BinaryDepth(root->left) + 1 : BinaryDepth(root->right) + 1;
}
//二叉树的销毁 1.前序
//void BinaryDestroy(BTNode** proot)
//{
//	if (*proot == NULL)
//		return;
//	
//	BTNode* left = (*proot)->left;
//	BTNode* right = (*proot)->right;
//	BinaryDestroy(left);
//	BinaryDestroy(right);
//}

////二叉树的销毁 1.后序
//void BinaryDestroy(BTNode** proot)
//{
//	if (*proot == NULL)
//		return;
//	BinaryDestroy(&(*proot)->left);
//	BinaryDestroy(&(*proot)->left);
//	free(*proot);
//	*proot = NULL;
//}

//二叉树的销毁 1.后序  一级指针，需要调用的人手动置为NULL
void BinaryDestroy(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryDestroy(root->left);
	BinaryDestroy(root->right);
	free(root);
	root = NULL;
}
//层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);
		if(front->left)
		   QueuePush(&q,front->left);
		if(front->right)
		   QueuePush(&q,front->right);  
	}
	QueueDestroy(&q);
}
//判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			break;
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
			return false;
	}
	QueueDestroy(&q);
	return true;
}