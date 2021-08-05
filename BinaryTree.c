#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"
//ǰ��
void BinaryTreePreOrder(BTNode* root) {
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
void BinaryTreeInOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}
//���� ������ �� ������
void BinaryTreePostOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}
//�����������ڵ�
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
//ͳ�ƽڵ����
int TreeSize(BTNode* root) {
	//return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
	if (root == NULL)
		return 0;
	else
		return TreeSize(root->left) + TreeSize(root->right) + 1;
}
//��Ҷ�ӽڵ�ĸ���
int TreeLeafSize(BTNode* root) {
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
//���k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL)
		return 0;
	else if (k == 1)
		return 1;
	else
		return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
//����ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//������������
int BinaryDepth(BTNode* root) {
	if (root == NULL)
		return 0;
	else
		return BinaryDepth(root->left) > BinaryDepth(root->right) ? 
		BinaryDepth(root->left) + 1 : BinaryDepth(root->right) + 1;
}