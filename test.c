#define _CRT_SECURE_NO_WARNINGS 1 
#include"SeqList.h"
void SeqListTest1()
{
	SeqList SList;
	SeqList* pList = &SList;
	SeqListInit(pList);
	SeqListPrint(pList);
	printf("\n------------------\n");

	SeqListPushBack(pList, 1);
	SeqListPushBack(pList, 2);
	SeqListPushBack(pList, 3);
	SeqListPushBack(pList, 4);
	SeqListPushBack(pList, 5);
	SeqListPrint(pList);
	printf("\n------------------\n");

	SeqListPopBack(pList);
	SeqListPopBack(pList);
	SeqListPopBack(pList);
	SeqListPopBack(pList);
	//SeqListPopBack(pList);
	//SeqListPopBack(pList);
	SeqListPrint(pList);
	printf("\n------------------\n");

	SeqListPushFront(pList, 10);
	SeqListPushFront(pList, 11);
	SeqListPushFront(pList, 12);
	SeqListPushFront(pList, 13);
	SeqListPrint(pList);
	printf("\n------------------\n");

	SeqListPopFront(pList);
	SeqListPopFront(pList);
	SeqListPopFront(pList);
	//SeqListPopFront(pList);
	//SeqListPopFront(pList);

	SeqListPrint(pList);
	printf("\n------------------\n");

	

	//int ret = SeqListFind(pList, 1);
	//if (ret == -1)
	//{
	//	printf("Can not Find!\n");
	//}
	//else
	//{
	//	printf("Find it,index word is %d\n", ret);
	//}

	SeqListInsert(pList, 1, 33);
	SeqListInsert(pList, 0, 22);
	SeqListInsert(pList, 2, 44);
	SeqListPrint(pList);
	printf("\n------------------\n");

	SeqListErase(pList, 1);
	SeqListErase(pList, 2);
	SeqListErase(pList, 0);
	SeqListPrint(pList);
	printf("\n------------------\n");

	SeqListDestory(pList);//´ýÓÅ»¯
}
int main()
{
	SeqListTest1();
	return 0;
}



