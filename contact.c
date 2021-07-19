#define _CRT_SECURE_NO_WARNINGS 1 
#include"contact.h"
//初始化的实现---静态版本
//void InitContact(Contact* pc)
//{
//	pc->size = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//初始化---动态版本
void InitContact(Contact* pc)
{
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->size = 0;
	pc->capacity = DEFAULT_SZ;
}

//增加联系人---静态版本
//void AddContact(Contact* pc)
//{
//	//判断通讯录数组空间利用情况
//	if (pc->size == MAX_PEO)
//	{
//		printf("The Contact is full! Add information failed!\n");
//		return;
//	}
//	//增加一个人的信息
//	printf("Please input name:>>");
//	scanf("%s", pc->data[pc->size].name);
//	printf("Please input age:>>");
//    scanf("%d", &pc->data[pc->size].age);
//	printf("Please input sex:>>");
//	scanf("%s", pc->data[pc->size].sex);
//	printf("Please input telephone numbers:>>");
//	scanf("%s", pc->data[pc->size].tele);
//	printf("Please input address:>>");
//	scanf("%s", pc->data[pc->size].addr);
//	printf("AddContact Suceess!\n");
//	pc->size++;
//}

//增加联系人---动态版本
void AddContact(Contact* pc)
{
	//考虑动态增容
	if (pc->size == pc->capacity)
	{
		PeoInfo* ptr =(PeoInfo*) realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity = pc->capacity + INC_SZ;
			printf("Increase Capacity Success!\n");
		}
		else
		{
			perror("AddContact");
			printf("Add new contact failed!\n");
			return;
		}
	}
	
	//增加一个人的信息
	printf("Please input name:>>");
	scanf("%s", pc->data[pc->size].name);
	printf("Please input age:>>");
	scanf("%d", &pc->data[pc->size].age);
	printf("Please input sex:>>");
	scanf("%s", pc->data[pc->size].sex);
	printf("Please input telephone numbers:>>");
	scanf("%s", pc->data[pc->size].tele);
	printf("Please input address:>>");
	scanf("%s", pc->data[pc->size].addr);

	pc->size++;
	printf("Add Contact Suceess!\n");
}

//销毁
void DestoryContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->size = 0;
	pc->capacity = 0;
}


//打印
void PrintContact(const Contact* pc)
{
	int i = 0;
	//打印标题
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "Name", "Age", "Sex", "Tele", "Address");
	//打印数据
	for (i = 0; i < pc->size; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->data[i].name,
			pc->data[i].age, pc->data[i].sex, 
			pc->data[i].tele, pc->data[i].addr);
	}
	return;
}

static int FindByName(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//删除一个人的信息
void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	//判断通讯录是否有信息
	if (pc->size == 0)
	{
		printf("The Contact is empty!\n");
		return;
	}
	printf("Please input the name to delete:>>");
	scanf("%s", name);

	//1.查找删除的人
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("The people that you want to delete is not exit!\n");
		return;
	}
	else
	{
		int i = 0;
		for (i = pos; i < pc->size - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->size--;

		printf("Delete Success!\n");
	}
}
//查找
void SearchContact(const Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	//判断通讯录是否有信息
	if (pc->size == 0)
	{
		printf("The Contact is empty!\n");
		return;
	}
	printf("Please input the name to search:>>");
	scanf("%s", name);

	//1.查找人
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("The people that you want to search is not exit!\n");
		return;
	}
	else
	{
		//打印
		//打印标题
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "Name", "Age", "Aex", "Tele", "Tddress");
		//打印数据
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->data[pos].name,
			pc->data[pos].age, pc->data[pos].sex,
			pc->data[pos].tele, pc->data[pos].addr);

		printf("Search Suceess!\n");
	}
}
//修改
void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	//判断通讯录是否有信息
	if (pc->size == 0)
	{
		printf("The Contact is empty!\n");
		return;
	}
	printf("Please input the name to modify:>>");
	scanf("%s", name);

	//1.查找修改的人
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("The people that you want to modify is not exit!\n");
		return;
	}
	else
	{
		printf("Please input name:>>");
		scanf("%s", pc->data[pos].name);
		printf("Please input age:>>");
		scanf("%d", &pc->data[pos].age);
		printf("Please input sex:>>");
		scanf("%s", pc->data[pos].sex);
		printf("Please input telephone numbers:>>");
		scanf("%s", pc->data[pos].tele);
		printf("Please input address:>>");
		scanf("%s", pc->data[pos].addr);

		printf("Modify Suceess!\n");
	}
}
