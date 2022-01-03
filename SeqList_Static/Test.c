#define _CRT_SECURE_NO_WARNINGS 1 
#include"SeqList_static.h"
int main()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushBack(&seq, 66);
	SeqListPushBack(&seq, 77);
	SeqListPushBack(&seq, 88);
	SeqListPushBack(&seq, 99);

	SeqListPrint(&seq);
	printf("The Length of SeqList is %d\n", SeqListLength(&seq));

	SeqListPopBack(&seq);
	SeqListPrint(&seq);
	printf("The Length of SeqList is %d\n", SeqListLength(&seq));

	SeqListPopBack(&seq);
	SeqListPrint(&seq);
	printf("The Length of SeqList is %d\n", SeqListLength(&seq));

	SeqListPopBack(&seq);
	SeqListPrint(&seq);
	printf("The Length of SeqList is %d\n", SeqListLength(&seq));

	SeqListPushFront(&seq, 11);
	SeqListPrint(&seq);
	printf("The Length of SeqList is %d\n", SeqListLength(&seq));

	SeqListPushFront(&seq, 22);
	SeqListPrint(&seq);
	printf("The Length of SeqList is %d\n", SeqListLength(&seq));

	SeqListPushFront(&seq, 33);
	SeqListPrint(&seq);
	printf("The Length of SeqList is %d\n", SeqListLength(&seq));

	SeqListPushFront(&seq, 44);
	SeqListPrint(&seq);
	printf("The Length of SeqList is %d\n", SeqListLength(&seq));

	SeqListPopFront(&seq);
	SeqListPrint(&seq);
	printf("The Length of SeqList is %d\n", SeqListLength(&seq));

	SeqListPopFront(&seq);
	SeqListPrint(&seq);
	printf("The Length of SeqList is %d\n", SeqListLength(&seq));

	SeqListPopFront(&seq);
	SeqListPrint(&seq);
	printf("The Length of SeqList is %d\n", SeqListLength(&seq));

	SeqListPopFront(&seq);
	SeqListPrint(&seq);
	printf("The Length of SeqList is %d\n", SeqListLength(&seq));

	return 0;
}
