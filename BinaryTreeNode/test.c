#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"
int main(){
	BTNode* a = CreateTreeNode('A');
	BTNode* b = CreateTreeNode('B');
	BTNode* c = CreateTreeNode('C');
	BTNode* d = CreateTreeNode('D');
	BTNode* e = CreateTreeNode('E');
	BTNode* f = CreateTreeNode('F');
	a->left = b;
	b->left = d;
	a->right = c;
	c->left = e;
	c->right = f;
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

	return 0;
}