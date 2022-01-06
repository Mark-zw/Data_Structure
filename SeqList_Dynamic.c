#define _CRT_SECURE_NO_WARNINGS 1 
#include"SeqList_Dynamic.h"
//��ʼ��
void SeqListInit(SeqList* pList) {
	pList->arr = (SLDataType*)malloc(2 * sizeof(SLDataType));
	pList->capacity = 2;
	pList->size = 0;
}
//����
void SeqListDestory(SeqList* pList) {
	free(pList->arr);
	pList->arr = NULL;
	pList->size = 0;
	pList->capacity = 0;
}
//���ݼ��
void CheckCapacity(SeqList* pList) {
	assert(pList);
	if (pList->size >= pList->capacity) {
		int NewCapacity = 2 * (pList->capacity);
		SLDataType* NewArray = (SLDataType*)realloc(pList->arr, NewCapacity * sizeof(SLDataType));
		if (NewArray == NULL) {
			printf("Increase capacity failed!\n");
			exit(-1);//����ʧ�ܣ���ǰ��������
		}
		//���ݳɹ�
		pList->arr = NewArray;
		pList->capacity = NewCapacity;
		printf("Increase capacity successful!\n");
	}
}
//ͷ��
void SeqListPushFront(SeqList* pList, SLDataType x) {
	assert(pList);
	CheckCapacity(pList);
	//�������ݣ��Ƚ��������ݴӺ���ǰ�ƶ�һλ
	int i = 0;
	for (i = pList->size; i > 0; i--) {
		pList->arr[i] = pList->arr[i - 1];
	}
	pList->arr[i] = x;
	pList->size++;
}
//ͷɾ
void SeqListPopFront(SeqList* pList) {
	assert(pList);
	if (SeqListIsEmpty(pList) == 1) {
		printf("SeqList is empty!\n");
		return 0;
	}
	//ɾ�����ݣ�ֱ�ӽ����ݴ�ǰ�����ƶ�����
	int i = 0;
	for (i = 0; i < pList->size - 1; i++) {
		pList->arr[i] = pList->arr[i + 1];
	}
	pList->size--;
}
//β��
void SeqListPushBack(SeqList* pList, SLDataType x) {
	assert(pList);
	CheckCapacity(pList);
	//��������
	pList->arr[pList->size] = x;
	pList->size++;
}
//βɾ
void SeqListPopBack(SeqList* pList) {
	assert(pList);
	if (SeqListIsEmpty(pList) == 1) {
		printf("SeqList is empty!\n");
		return 0;
	}
	pList->size--;
}
//����λ�ò���
void SeqListInsert(SeqList* pList, int pos, SLDataType x) {
	assert(pList);
	CheckCapacity(pList);
	if (pos<0 || pos > pList->size) {
		printf("The position to insert is illegal!\n");
		exit(-1);
	}
	//�������ݣ���posλ�ü�������Ԫ�شӺ���ǰ�ƶ�һλ
	int i = 0;
	for (i = pList->size; i > pos; i--) {
		pList->arr[i] = pList->arr[i - 1];
	}
	pList->arr[i] = x;
	pList->size++;
}
//����λ��ɾ��
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
	//ɾ�����ݣ���pos�����Ԫ�ش�ǰ������ǰ�ƶ�����
	for (int i = pos; i < pList->size - 1; i++) {
		pList->arr[i] = pList->arr[i + 1];
	}
	pList->size--;
}
//����
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
//�޸�
void SeqListUpdata(SeqList* pList, int pos,SLDataType x) {
	assert(pList);
	if (pos<0 || pos>pList->size) {
		printf("The position is illegal!\n");
		exit(-1);
	}
	pList->arr[pos] = x;
}
//��ӡ
void SeqListPrint(SeqList* pList) {
	assert(pList);
	//�п�
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
//�п�
bool SeqListIsEmpty(SeqList* pList) {
	assert(pList);
	if (pList->size == 0)
		return 1;
	else
		return 0;
}
//����
int SeqListLength(SeqList* pList) {
	assert(pList);
	return pList->size; 
}