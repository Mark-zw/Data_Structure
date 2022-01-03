#define _CRT_SECURE_NO_WARNINGS 1 
#include"SeqList_static.h"
//Initialize SeqList
void SeqListInit(SeqList* pList) {
	assert(pList);
	pList->size = 0;
}
bool CapacityIsFull(SeqList* pList) {
	//check the capacity of array
	if (pList->size >= N)
		return 1;
	return 0;
}
//Push new element to SeqList in the end
void SeqListPushBack(SeqList* pList, SLDataType x) {
	assert(pList);
	if (CapacityIsFull(pList)) {
		printf("PushBack fail,the capacity of SeqList is Full!\n");
		return 0;
	}
	pList->arr[pList->size] = x;
	pList->size++;
}
//Erase the last element of SeqList
void SeqListPopBack(SeqList* pList) {
	assert(pList);
	if (SeqListIsEmpty(pList)) {
		printf("SeqList is empty!\n");
		return 0;
	}
	pList->size--;
}
//Insert new element in front of SeqList
void SeqListPushFront(SeqList* pList, SLDataType x) {
	assert(pList);
	if (CapacityIsFull(pList)) {
		printf("PushBack fail,the capacity of SeqList is Full!\n");
		return 0;
	}
	int i = 0;
	for (i = pList->size; i > 0; i--) {     
		pList->arr[i] = pList->arr[i - 1];
	}
	pList->arr[i] = x;
	pList->size++;
}
//Erase the first element of SeqList
void SeqListPopFront(SeqList* pList) {
	assert(pList);
	if (SeqListIsEmpty(pList)) {
		printf("SeqList is empty!\n");
		return 0;
	} 
	int i = 0;
	for (i = 0; i < pList->size - 1; i++) {
		pList->arr[i] = pList->arr[i + 1];
	}
	pList->size--;
}
void SeqListPrint(SeqList* pList) {
	if (SeqListIsEmpty(pList))
		printf("The SeqList is empty!\nNothing to print\n");
	printf("--------------------------\n");
	for (int i = 0; i < pList->size; i++) {
		if (i != pList->size - 1)
			printf(" %d ---", pList->arr[i]);
		else
			printf(" %d |", pList->arr[i]);
	}
	printf("\n");
}
//judge SeqList is empty whether or not
bool SeqListIsEmpty(SeqList* pList) {
	assert(pList);
	if (!(pList->size))
		return 1;
	return 0;
}
int SeqListLength(SeqList* pList) {
	assert(pList);
	return pList->size;
}
