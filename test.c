#define _CRT_SECURE_NO_WARNINGS 1 
#include"BinaryTree.h"
int main()
{
	BTNode* A = CreateNode('A');
	BTNode* B = CreateNode('B');
	BTNode* C = CreateNode('C');
	BTNode* D = CreateNode('D');
	BTNode* E = CreateNode('E');
	A->left = B; 
	A->right = C;
	B->left = D;
	B->right = E;

	BinaryTreePrevOrder(A);
	printf("\n");
	BinaryTreeInOrder(A);
	printf("\n");
	BinaryTreePostOrder(A);
	printf("\n");
	printf("TreeSize:%d \n", TreeSize(A));

	printf("TreeLeafSize:%d \n", TreeLeafSize(A));
	printf("%d\n", BinaryTreeLevelKSize(A, 3));
	return 0;
}

//enum Color
//{
//	Red,
//	Green = 3,
//	Blue
//};
//int main()
//{
//	enum Color r = Red;
//	enum Color g = Green;
//	enum Color b = Blue;
//
//	printf("%d\n", r);
//	printf("%d\n", g);
//	printf("%d\n", b);
//
//	return 0;
//}


//#include <stdio.h>
//int Sub(int a, int b)
//{
//	return (a - b);
//}
//main()
//{
//	int  x, y, result = 0;
//	scanf("%d,%d", &x, &y);
//	result = Sub(x, y);
//	printf("result = %d\n", result);
//}
//#include<stdio.h>
//main()
//{
//	struct stu
//	{
//		int num;
//		char a[5];
//		float score;
//	}m = { 1234,"wang",89.5 };
//	printf(" % d, % s, % f", m.num, m.a, m.score);
//}