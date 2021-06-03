#define _CRT_SECURE_NO_WARNINGS 1 
#include"SeqList.h"
SeqList;
void SeqListTest1()
{
	SeqList SL;
	SeqList* pList = &SL;
	SeqListInit(pList);
	SeqListPrint(pList);

	SeqListPushBack(pList, 1);
	SeqListPushBack(pList, 2);
	SeqListPushBack(pList, 3);
	SeqListPushBack(pList, 4);

	SeqListPrint(pList);
	printf("\n_______________________\n");

	SeqListPopBack(pList);
	SeqListPopBack(pList);
	SeqListPopBack(pList);
	//SeqListPopBack(pList);
	//SeqListPopBack(pList);

	SeqListPrint(pList);
	printf("\n_______________________\n");
}

int main()
{
	SeqListTest1();
	return 0;
}