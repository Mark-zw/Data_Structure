#define _CRT_SECURE_NO_WARNINGS 1 
#include"SList.h"

void TestSList1()
{
	SList *pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(&pList);

	SListPushFront(&pList, 5);
	SListPushFront(&pList, 6);
	SListPushFront(&pList, 7);
	SListPushFront(&pList, 8);
	SListPrint(&pList);

	SListPopBack(&pList);
	SListPrint(&pList);

	SListPopFront(&pList);
	//SListPopFront(&pList);
	//SListPopFront(&pList);
	//SListPopFront(&pList);
	//SListPopFront(&pList);
	//SListPopFront(&pList);

	SListPrint(&pList);

	SNode* ret = SListSearch(pList, 3);
	if (ret != NULL)
	{
		//兼具修改的作用
		printf("%d ", ret->data);
		//ret->data = 30;
		//printf("%d ", ret->data);

	}
	else
	{
		printf("Can not find it!\n");
	}
	SListInsertafter(ret, 33);
	SListPrint(&pList);
	SListInsertbefore(&pList, ret, 99);
	SListPrint(&pList);

	SListEraseafter(ret);
	SListPrint(&pList);

	SListErasecur(&pList, pList);
	SListPrint(&pList);

}
int main()
{
	TestSList1();
	//SList* s1 = (SList*)malloc(sizeof(SList));
	//SList* s2 = (SList*)malloc(sizeof(SList));
	//SList* s3 = (SList*)malloc(sizeof(SList));
	//SList* s4 = (SList*)malloc(sizeof(SList));
	//s1->data = 1;
	//s1->next = s2;
	//s2->data = 2;
	//s2->next = s3;
	//s3->data = 3;
	//s3->next = s4;
	//s4->data = 4;
	//s4->next = NULL;
	//SListPrint(s1);
	return 0;
}
