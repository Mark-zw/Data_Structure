#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
TestSeqList1()
{
	SL seq;
	SeqListInit(&seq);
	SeqListPrint(&seq);

	SeqListPushBack(&seq, 0);
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	SeqListPrint(&seq);

	SeqListPushFront(&seq, 1);
	SeqListPushFront(&seq, 2);
	SeqListPushFront(&seq, 3);
	SeqListPrint(&seq);

	SeqListPopBack(&seq);
	SeqListPrint(&seq);

	SeqListPopFront(&seq);
	SeqListPrint(&seq);

	SeqListInsert(&seq, 3, 7);
	SeqListPrint(&seq);

	SeqListErase(&seq, 4);
	SeqListPrint(&seq);

	int ret = SeqListFind(&seq, 3);
	if (ret == -1)
		printf("Can not find!\n");
	else
		printf("Find it!--%d\n", ret);

	SeqListModify(&seq, 3, 99);
	SeqListPrint(&seq);

	int ret2 = SeqListGetElem(&seq, 1);
	printf("%d\n", ret2);

	SeqListDestory(&seq);
	SeqListPrint(&seq);

}

int main()
{
	TestSeqList1();
	return 0;
 }