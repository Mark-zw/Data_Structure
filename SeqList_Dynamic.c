#define _CRT_SECURE_NO_WARNINGS 1 
#include"SeqList_Dynamic.h"
//初始化
void SeqListInit(SeqList* pList) {
	pList->arr = (SLDataType*)malloc(2 * sizeof(SLDataType));
	pList->capacity = 2;
	pList->size = 0;
}
//销毁
void SeqListDestory(SeqList* pList) {
	free(pList->arr);
	pList->arr = NULL;
	pList->size = 0;
	pList->capacity = 0;
}
//扩容检查
void CheckCapacity(SeqList* pList) {
	assert(pList);
	if (pList->size >= pList->capacity) {
		int NewCapacity = 2 * (pList->capacity);
		SLDataType* NewArray = (SLDataType*)realloc(pList->arr, NewCapacity * sizeof(SLDataType));
		if (NewArray == NULL) {
			printf("Increase capacity failed!\n");
			exit(-1);//扩容失败，提前结束进程
		}
		//扩容成功
		pList->arr = NewArray;
		pList->capacity = NewCapacity;
		printf("Increase capacity successful!\n");
	}
}
//头插
void SeqListPushFront(SeqList* pList, SLDataType x) {
	assert(pList);
	CheckCapacity(pList);
	//插入数据，先将所有数据从后往前移动一位
	int i = 0;
	for (i = pList->size; i > 0; i--) {
		pList->arr[i] = pList->arr[i - 1];
	}
	pList->arr[i] = x;
	pList->size++;
}
//头删
void SeqListPopFront(SeqList* pList) {
	assert(pList);
	if (SeqListIsEmpty(pList) == 1) {
		printf("SeqList is empty!\n");
		return 0;
	}
	//删除数据，直接将数据从前往后移动覆盖
	int i = 0;
	for (i = 0; i < pList->size - 1; i++) {
		pList->arr[i] = pList->arr[i + 1];
	}
	pList->size--;
}
//尾插
void SeqListPushBack(SeqList* pList, SLDataType x) {
	assert(pList);
	CheckCapacity(pList);
	//插入数据
	pList->arr[pList->size] = x;
	pList->size++;
}
//尾删
void SeqListPopBack(SeqList* pList) {
	assert(pList);
	if (SeqListIsEmpty(pList) == 1) {
		printf("SeqList is empty!\n");
		return 0;
	}
	pList->size--;
}
//任意位置插入
void SeqListInsert(SeqList* pList, int pos, SLDataType x) {
	assert(pList);
	CheckCapacity(pList);
	if (pos<0 || pos > pList->size) {
		printf("The position to insert is illegal!\n");
		exit(-1);
	}
	//插入数据，将pos位置及其后面的元素从后往前移动一位
	int i = 0;
	for (i = pList->size; i > pos; i--) {
		pList->arr[i] = pList->arr[i - 1];
	}
	pList->arr[i] = x;
	pList->size++;
}
//任意位置删除
void SeqListErase(SeqList* pList, int pos) {
	assert(pList);
	if (SeqListIsEmpty(pList) == 1) {
		printf("SeqList is empty!\n");
		return 0;
	}
	if (pos < 0 || pos >pList->size) {
		printf("The position to erase is illegal\n");
		exit(-1);
	}
	//删除数据，将pos后面的元素从前往后向前移动覆盖
	for (int i = pos; i < pList->size - 1; i++) {
		pList->arr[i] = pList->arr[i + 1];
	}
	pList->size--;
}
//查找
int SeqListFind_By_Val(SeqList* pList,SLDataType x) {
	assert(pList);
	if (SeqListIsEmpty(pList) == 1) {
		printf("SeqList is empty!  Can't Find Anything!\n");
		return 0;
	}
	int i = 0;
	for (i = 0; i < pList->size; i++) {
		if (pList->arr[i] == x)
			break;
	}
	if (i == pList->size)
		printf("Can't find it!\n");
	else {
		printf("Got it,the index is %d !\n", i);
		return i;
	}
}
//修改
void SeqListUpdata(SeqList* pList, int pos,SLDataType x) {
	assert(pList);
	if (pos<0 || pos>pList->size) {
		printf("The position is illegal!\n");
		exit(-1);
	}
	pList->arr[pos] = x;
}
//打印
void SeqListPrint(SeqList* pList) {
	assert(pList);
	//判空
	if (SeqListIsEmpty(pList) == 1) 
		printf("SeqList is empty!\n");
	for (int i = 0; i < pList->size; i++) {
		if (i != pList->size - 1)
			printf(" %d ---", pList->arr[i]);
		else
			printf(" %d\n", pList->arr[i]);
	}
	printf("------------------------\n");
}
//判空
bool SeqListIsEmpty(SeqList* pList) {
	assert(pList);
	if (pList->size == 0)
		return 1;
	else
		return 0;
}
//长度
int SeqListLength(SeqList* pList) {
	assert(pList);
	return pList->size; 
}