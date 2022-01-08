#define _CRT_SECURE_NO_WARNINGS 1 
#include"SeqList_Dynamic.h"
int main()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushFront(&seq, 11);
	SeqListPushFront(&seq, 22);
	SeqListPushFront(&seq, 33);
	SeqListPrint(&seq);

	SeqListPopFront(&seq);
	SeqListPopFront(&seq);
	SeqListPopFront(&seq);
	SeqListPopFront(&seq);
	SeqListPrint(&seq);

	SeqListPushBack(&seq, 44);
	SeqListPushBack(&seq, 55);
	SeqListPushBack(&seq, 66);
	SeqListPushBack(&seq, 77);
	SeqListPrint(&seq);

	SeqListPopBack(&seq);
	SeqListPopBack(&seq);
	SeqListPopBack(&seq);
	SeqListPrint(&seq);

	SeqListInsert(&seq, 0, 333);
	SeqListInsert(&seq, 1, 222);
	SeqListInsert(&seq, 2, 111);
	SeqListInsert(&seq, 3, 99);
	SeqListPrint(&seq);

	SeqListErase(&seq, 2);
	SeqListErase(&seq, 1);
	SeqListErase(&seq, 0);
	SeqListPrint(&seq);

	int index = SeqListFind_By_Val(&seq, 99);
	printf("the index of 99 is %d!\n", index);
	SeqListUpdata(&seq, index, 888);
	SeqListPrint(&seq);

	SeqListDestory(&seq);
	return 0;
}
