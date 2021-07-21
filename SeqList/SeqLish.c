#define _CRT_SECURE_NO_WARNINGS 1 
#include"SeqList.h"

//����---��ʼ��
void SeqListInit(SL* seq)
{
	seq->capacity = Init_SIZE;
	seq->size = 0;
	seq->arr = (SLDatatype*)malloc(seq->capacity * sizeof(SLDatatype));
}

//����
void SeqListDestory(SL* seq)
{
	free(seq->arr);
	seq->arr = NULL;
	seq->size = 0;
	seq->capacity = 0;
}

//��ӡ
void SeqListPrint(SL* seq)
{
	int i = 0;
	for (i = 0; i < seq->size; i++)
	{
		printf("%d  ", seq->arr[i]);
	}
	printf("\n-------------------------\n");
}

//���ݼ��
void CheckCapacity(SL* seq)
{
	//�ж��Ƿ���Ҫ����
	if (seq->size == seq->capacity)
	{
		//�������ݲ���
		seq->capacity = 2 * seq->capacity;
		SLDatatype* ptr = (SLDatatype*)realloc(seq->arr, seq->capacity * sizeof(SLDatatype));
		if (ptr != NULL)
		{
			seq->arr = ptr;
			printf("Increase Capacity Success!\n");
		}
		else
		{
			perror("Increase Capacity Failed!\n");
		}
	}
}


//β��
void SeqListPushBack(SL* seq, SLDatatype x)
{
	//1.��������ʱ������Ҫ�ж��Ƿ��пռ乩����ʹ��
	//������Ƿ����ݷ�װ��һ������
	CheckCapacity(seq);
	//2.���ݽ����󣬽������ݵĲ���
	seq->arr[seq->size] = x;
	//3.seq->size+1
	seq->size++;
}

//ͷ��
void SeqListPushFront(SL* seq, SLDatatype x)
{
	int i = 0;
	CheckCapacity(seq);
	//1.�Ƚ�����Ԫ�ذ��մӺ���ǰ��˳���ƶ�
	for (i = seq->size; i > 0; i--)
	{
		seq->arr[i] = seq->arr[i-1];
	}
	//2.��ͷ����������
	seq->arr[i] = x;//Ҳ����д��seq->arr[0] = x;
	//3.seq->size+1
	seq->size++;
}

//βɾ
void SeqListPopBack(SL* seq)
{
	//ɾ������ʱ����Ҫ�ж��Ƿ�������
	if (seq->size == 0)
	{
		printf("The SeqList is empty!\n");
		return;
	}
	seq->size--;
}
//ͷɾ
void SeqListPopFront(SL* seq)
{
	//ɾ������ʱ����Ҫ�ж��Ƿ�������
	if (seq->size == 0)
	{
		printf("The SeqList is empty!\n");
		return;
	}
	//����Ԫ�صĸ�����ʵ������ɾ��
	//���ڶ���Ԫ�ؼ���֮���Ԫ�ذ��մ�ǰ����˳�������Ƶ�ǰһλ
	int i = 0;
	for (i = 0; i < seq->size - 1; i++)
	{
		seq->arr[i] = seq->arr[i + 1];
	}
	seq->size--;
}