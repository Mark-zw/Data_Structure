#define _CRT_SECURE_NO_WARNINGS 1 
#include "SList.h"
int main()
{
	SListNode* pList = NULL;//ˢ���ʱ��һ����Ǹ�һ��ͷָ��
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);

	SListPrint(pList);
	return 0;
}