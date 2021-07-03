#define _CRT_SECURE_NO_WARNINGS 1 
#include"ListNode.h"
void TestList1()
{
	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPushBack(phead, 5);
	ListPrint(phead);
	printf("_________________\n");
	ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);
	//ListPopBack(phead);
	printf("_________________\n");
	ListPrint(phead);
	ListPushFront(phead, 6);
	ListPushFront(phead, 7);
	ListPushFront(phead, 8);
	ListPushFront(phead, 9);
	ListPrint(phead);
	printf("_________________\n");
	ListPopFront(phead);
	ListPopFront(phead);
	ListPopFront(phead);
	ListPrint(phead);
	printf("_________________\n");

}
void TestList2()
{
	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPushBack(phead, 5);

	ListNode* pos = ListFind(phead, 3);
	ListInsert(pos, 30);
	ListPrint(phead);
	printf("_________________\n");
}
int main()
{
	//TestList1();
	TestList2();

	return 0;
}