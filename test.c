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

	SeqListDestory(&seq);
	SeqListPrint(&seq);

}

int main()
{
	TestSeqList1();
	return 0;
 }