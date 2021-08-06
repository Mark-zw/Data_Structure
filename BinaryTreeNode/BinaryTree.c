#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"


//ǰ��
void BinaryTreePreOrder(BTNode* root) 
{
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	//��   ������   ������
	printf("%c ", root->data);
	BinaryTreePreOrder(root->left);
	BinaryTreePreOrder(root->right);
}
//���� ������ �� ������
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
//���� ������ �� ������
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
//�����������ڵ�
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
//ͳ�ƽڵ����
int TreeSize(BTNode* root) 
{
	//return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
	if (root == NULL)
		return 0;
	else
		return TreeSize(root->left) + TreeSize(root->right) + 1;
}
//��Ҷ�ӽڵ�ĸ���
int TreeLeafSize(BTNode* root) 
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
//���k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k) 
{
	if (root == NULL)
		return 0;
	else if (k == 1)
		return 1;
	else
		return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
//����ֵΪx�Ľڵ�
//˼·��1��root == NULL return NULL
//2��root �ڵ㲻������Ҫ�ҵģ��ȵ�����ȥ�ң��������û�У��ٵ�����ȥ�ң����Ҷ�û�У�����NULL
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	//���һ��if�����
	//if (BinaryTreeFind(root->left, x) == NULL && BinaryTreeFind(root->right, x) == NULL)//�������Ī�������
	//	return NULL;

	BTNode* left = BinaryTreeFind(root->left, x);
	if (left) 
		return left;
	BTNode* right = BinaryTreeFind(root->right, x);
	if (right)
		return right;
	return NULL;
}
//������������
int BinaryDepth(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
		return BinaryDepth(root->left) > BinaryDepth(root->right) ? 
		BinaryDepth(root->left) + 1 : BinaryDepth(root->right) + 1;
}
//������������ 1.ǰ��
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

////������������ 1.����
//void BinaryDestroy(BTNode** proot)
//{
//	if (*proot == NULL)
//		return;
//	BinaryDestroy(&(*proot)->left);
//	BinaryDestroy(&(*proot)->left);
//	free(*proot);
//	*proot = NULL;
//}

//������������ 1.����  һ��ָ�룬��Ҫ���õ����ֶ���ΪNULL
void BinaryDestroy(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryDestroy(root->left);
	BinaryDestroy(root->right);
	free(root);
	root = NULL;
}
//�������
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
//�ж϶������Ƿ�����ȫ������
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