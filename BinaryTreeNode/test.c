#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"
int main()
{
	BTNode* a = CreateTreeNode('A');
	BTNode* b = CreateTreeNode('B');
	BTNode* c = CreateTreeNode('C');
	BTNode* d = CreateTreeNode('D');
	BTNode* e = CreateTreeNode('E');
	BTNode* f = CreateTreeNode('F');
	BTNode* g = CreateTreeNode('F');

	a->left = b;
	b->left = d;
	a->right = c;
	c->left = e;
	c->right = f;

	b->right = g;

	BinaryTreePreOrder(a);
	printf("\n");
	BinaryTreeInOrder(a);
	printf("\n");
	BinaryTreePostOrder(a);
	printf("\n");
	printf("TreeSize = %d \n", TreeSize(a));
	printf("TreeLeafSize = %d \n", TreeLeafSize(a));
	printf("KLevelTreeSize = %d \n", BinaryTreeLevelKSize(a,3));
	printf("BinaryDepth = %d \n", BinaryDepth(a));
	BTNode* retArr = BinaryTreeFind(a, 'E');
	printf("retArr->data = %c\n", retArr->data);
	BinaryTreeLevelOrder(a);
	bool ret = BinaryTreeComplete(a);
	if (ret == true)
		printf("\nBinaryTreeComplete = 1\n");
	else
		printf("\nBinaryTreeComplete = 0\n");
	BinaryDestroy(&a);
	a = NULL;
	return 0;
}