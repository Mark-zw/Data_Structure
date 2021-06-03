#define _CRT_SECURE_NO_WARNINGS 1 
#include"SeqList.h"
//��ʼ��
void SeqListInit(SeqList* pList)
{
	assert(pList);
	pList->data[N] = 0 ;
	pList->size = 0;
}

//β��
void SeqListPushBack(SeqList* pList,SLDataType x)
{
	assert(pList);
	//1.���ȿ����Ƿ��пռ�����ݲ���
	if (pList->size == N)
	{
		printf("SeqList is full!\n");
	}
	//2.�пռ���������������
	else
	{
		int i = pList->size;
		pList->data[i] = x;
		pList->size++;
	}
}

//βɾ
void SeqListPopBack(SeqList* pList)
{
	assert(pList);
	//1.�����ж��Ƿ񻹴��ڿ���ɾ����Ԫ��
	if (pList->size == 0)
	{
		printf("SeqList is empty!\n");
		printf("Delete date failure!\n");
	}
	else
	{
		pList->size--;
	}
}

//��ӡ
void SeqListPrint(SeqList* pList)
{
	assert(pList);
	size_t i = 0;
	if (pList->size == 0)
	{
		printf("SeqList is empty!\n");
	}
	else
	{
		for (i = 0; i < pList->size; i++)
		{
			printf("%d ", pList->data[i]);
		}
	}
}