#define _CRT_SECURE_NO_WARNINGS 1 
#include"SeqList.h"
//��ʼ��
void SeqListInit(SeqList* pList)
{
	assert(pList);
	pList->array = NULL;
	pList->size = 0;
	pList->capacity = 0;//��ʼ��4���洢��Ԫ
}
//���� 
void SeqListDestory(SeqList* pList)
{
	assert(pList);
	free(pList->array);
	pList->array = NULL;
	pList->size = 0;
	pList->capacity = 0;
	printf("Destory successed!\n");
}

//��ӡ
void SeqListPrint(SeqList* pList)
{
	assert(pList);
	if (pList->size == 0)
	{
		printf("SeqList is empty!\n");
	}
	else
	{
		int i = 0;
		for (i = 0; i < pList->size; i++)
		{
			printf("%d ", pList->array[i]);
		}
	}
}
//�ռ��飬������ˣ���������
void CheckCapacity(SeqList* pList)
{
	assert(pList);
	if (pList->size == pList->capacity)
	{
		//���ݵ�ʱ������Ŀռ��СҲ��Ҫ����
		//�ж�˳��������Ƿ�Ϊ0����Ϊ0�����ȿ������ڴ��4��Ԫ�صĿռ��С��
		//����Ϊ0��������Ϊԭ������������
		int NewCapacity = pList->capacity == 0 ? 4 : 2 * pList->capacity;
		SLDataType* NewArray = (SLDataType*)realloc(pList->array, sizeof(SLDataType) * NewCapacity);
		if (NewArray == NULL)
		{
			printf("realloc fail!\n");
			return exit(-1);
		}
		pList->array = NewArray;
		pList->capacity = NewCapacity;
		printf("Capacity of success!\n");
	}
}

//β��
void SeqListPushBack(SeqList* pList, SLDataType x)
{
	//assert(pList);
	////1.�����������ݲ���ʱ�����漰���洢�ռ�������˵��������Ҫ�Ƚ����ж�
	////2.�洢�ռ����ˣ���Ҫ������Ӧ�����ݲ���
	////���ǵ���������д�����Ĳ��뺯����Ҳ���漰��һ�����ɴཫ����з�װ�ɶ����ĺ���ģ��
	//CheckCapacity(pList);
	////3.β����������
	//pList->array[pList->size] = x;
	//pList->size++;

	//����ֱ�ӵ���������λ�ò���ĺ���
	SeqListInsert(pList, pList->size, x);
}
//βɾ
void SeqListPopBack(SeqList* pList)
{
	//assert(pList);
	////1.���漰�����ݵ�ɾ��ʱ������Ҫ�жϸÿռ��Ƿ�������
	//if (pList->size == 0)
	//{
	//	printf("No element in SeqList\n");
	//	printf("PopBack failure\n");
	//}
	////2.�������ݵ�ʱ��ɾ������ֻ��Ҫ��pList->size--���Ҳ���Ҫ����λ������Ԫ����Ϊ0��
	////��Ϊ0û���κ����壬��Ϊ����Ҳ��֪�����0�Ǳ��������Ԫ�ػ�����Ϊ��0��
	//else
	//{
	//	pList->size--;
	//	//һ����˵������֮���capacity�����ٱ����û�ȥ��������
	//}

	//����ֱ�ӵ���������λ��ɾ���ĺ���
	SeqListErase(pList, pList->size);
}
//ͷ��
void SeqListPushFront(SeqList* pList, SLDataType x)
{
	//assert(pList);
	//int i = 0;
	////1.�����������ݲ���ʱ�����漰���洢�ռ�������˵��������Ҫ�Ƚ����ж�
	////2.�洢�ռ����ˣ���Ҫ������Ӧ�����ݲ���
	////���ǵ���������д�����Ĳ��뺯����Ҳ���漰��һ�����ɴཫ����з�װ�ɶ����ĺ���ģ��
	//CheckCapacity(pList);
	////(1)�Ƚ�pList->size++
	//pList->size++;
	////(2)���մӺ���ǰ�ķ�ʽ�����ƶ�Ԫ�ص�����λ��
	//for (i = pList->size - 1; i > 0; i--)
	//{
	//	pList->array[i] = pList->array[i - 1];
	//}
	////(3)��x�����׵�ַ��
	//pList->array[0] = x;

	//����ֱ�ӵ���������λ�ò���ĺ���
	SeqListInsert(pList, 0, x);

}
//ͷɾ
void SeqListPopFront(SeqList* pList)
{
	//assert(pList);
	////1.���漰�����ݵ�ɾ��ʱ������Ҫ�жϸÿռ��Ƿ�������
	//if (pList->size == 0)
	//{
	//	printf("No element in SeqList\n");
	//	printf("PopBack failure\n");
	//}
	//else
	//{
	//	//2.�������е�Ԫ�ذ��մ�ǰ�����˳���ƶ�������λ��
	//	int i = 0;
	//	for (i = 0; i < pList->size - 1; i++)
	//	{
	//		pList->array[i] = pList->array[i + 1];
	//	}
	//	//3.��pList->size-- ����Ԫ��-1
	//	pList->size--;
	//}

	//����ֱ�ӵ���������λ��ɾ���ĺ���
	SeqListErase(pList, 0);
}
//����  ���ҵ��˾ͷ����±�ֵ��������Ҳ����ͷ���-1���±겻����Ϊ-1
int SeqListFind(SeqList* pList, SLDataType x)
{
	assert(pList);
	int i = 0;
	//����û��Ԫ�غͲ��Ҳ������Էŵ�ͬһ�����---���Ҳ�����
	for (i = 0; i < pList->size; i++)
	{
		if (pList->array[i] == x)
		{
			return i;
		}
	}
	return -1;//���Ҳ���������-1
}
//������λ�ò���
void SeqListInsert(SeqList* pList, size_t pos, SLDataType x)
{
	assert(pList);
	//1.�����������ݲ���ʱ�����漰���洢�ռ�������˵��������Ҫ�Ƚ����ж�
	//2.�洢�ռ����ˣ���Ҫ������Ӧ�����ݲ���
	//���ǵ���������д�����Ĳ��뺯����Ҳ���漰��һ�����ɴཫ����з�װ�ɶ����ĺ���ģ��
	CheckCapacity(pList);
	if (pos > pList->size)
	{
		printf("The position to insert is wrong!\n");
	}
	else
	{
		//(1)�Ƚ�pList->size++
		pList->size++;
		//(2)��pos�����ұߵ�Ԫ�ذ��մӺ���ǰ��˳���ƶ�������λ��
		int i = 0;
		for (i = pList->size-1; i > pos; i--)
		{
			pList->array[i] = pList->array[i - 1];
		}
		pList->array[pos] = x;
	}
}

//������λ��ɾ��
void SeqListErase(SeqList* pList, size_t pos)
{
	assert(pList);
	//1.���漰�����ݵ�ɾ��ʱ������Ҫ�жϸÿռ��Ƿ�������
	if (pList->size == 0)
	{
		printf("No element in SeqList\n");
		printf("PopBack failure\n");
	}
	if (pos > pList->size)
	{
		printf("The position to Erase element is wrong!\n");
	}
	else
	{
		//(1)���±�Ϊpos�����ұߵ�Ԫ�ذ��մ�ǰ�����˳���ƶ�������λ��
		int i = 0;
		for (i = pos; i < pList->size - 1; i++)
		{
			pList->array[i] = pList->array[i + 1];
		}
		//(2)��size-1
		pList->size--;
	}
}