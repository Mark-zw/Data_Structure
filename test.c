#define _CRT_SECURE_NO_WARNINGS 1 
#include"DList.h"
void TestDList1()
{
	DList* pList = DListInit();
	DListPrint(pList);

	DListPushBack(pList, 0);
	DListPushBack(pList, 1);
	DListPushBack(pList, 2);
	DListPushBack(pList, 3);
	DListPushBack(pList, 4);
	DListPushBack(pList, 5);
	DListPrint(pList);
	DListPushFront(pList, 1);
	DListPushFront(pList, 2);
	DListPushFront(pList, 3);
	DListPushFront(pList, 4);
	DListPushFront(pList, 5);
	DListPrint(pList);

	DListPopBack(pList);
	DListPopBack(pList);
	DListPopBack(pList);
	DListPopBack(pList);
	DListPopBack(pList);
	DListPrint(pList);

	int ret = DListEmpty(pList);
	printf("ret == %d\n", ret);
	int length = DListLength(pList);
	printf("length == %d\n", length);

	DListPopFront(pList);
	DListPopFront(pList);
	DListPopFront(pList);
	DListPrint(pList);

	DNode* pos = DListFind(pList, 1);
	if (pos)
	{
		DListInsert(pos, 40);
	}
	DListPrint(pList);

	DListDestory(&pList);
	DListPrint(pList);

}
int main()
{
	TestDList1();
	return 0;
}