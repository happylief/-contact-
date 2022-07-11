#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

//初始化结构数据
void init_contact(contact* arr)
{
	arr->data = (details*)malloc(3 * sizeof(details));//初始空间为3
	arr->sz = 0;                                      //存储数据个数
	arr->max_stor = 3;                                //当前最大存储数据个数
	read_contact(arr);
}

//增加联系人
void ADD_contact(contact *arr)
{
	//对data指针进行扩容
	if (arr->sz == arr->max_stor)
	{
		details* ptr = (details*)realloc(arr->data, (arr->max_stor + 2)*sizeof(details));
		if (ptr != NULL)
		{
			arr->max_stor += 2;
			arr->data = ptr;
			printf("扩容成功。\n");
		}
		else
			perror((char*)ptr);
	}
	printf("请输入联系人姓名：");
	scanf("%s", (arr->data+arr->sz)->name);
	printf("请输入联系人性别：");
	scanf("%s", (arr->data + arr->sz)->sex);
	printf("请输入联系人年龄：");
	scanf("%d", &(arr->data + arr->sz)->age);
	printf("请输入联系人手机：");
	scanf("%s", (arr->data + arr->sz)->phone);
	printf("请输入联系人地址：");
	scanf("%s", (arr->data + arr->sz)->adders);
	printf("请输入联系人职业：");
	scanf("%s", (arr->data + arr->sz)->job);
	printf("添加成功。\n");
	arr->sz++;
	
}


//详细数据显示
void detail_contact(contact *arr)
{
	//打印详细数据标题
	printf("%-20s%-10s%-10s%-15s%-20s%-10s\n", "姓名", "性别", "年龄", "手机", "地址", "职业");
	for (int i = 0; i < arr->sz; i++)
	{
		printf("%-20s%-10s%-10d%-15s%-20s%-10s\n", arr->data[i].name, arr->data[i].sex, arr->data[i].age,
			                                   arr->data[i].phone, arr->data[i].adders, arr->data[i].job);
	}
}

//删除联系人
void delet_contact(contact *arr)
{
	int i;
	char delet[20];
	printf("请输入要删除的联系人：");
	scanf("%s", delet);
	i=search_name(delet, &arr);
	if (i == arr->sz)
	{
		printf("通讯录没有该联系人，无需删除。");
		return;
	}
	for (; i < arr->sz; i++)
	{
		arr->data[i] = arr->data[i + 1];
	}
	printf("删除成功。\n");
	arr->sz--;
}


//查找函数
int search_name(char*nam,contact* *arr)
{
	
	int i = 0;
	for (i = 0;i<(*arr)->sz; i++)
	{
		if (strcmp(nam, ((*arr)->data)[i].name)==0)
		{
			break;
		}
	}
	return i;
}

//查找联系人
void search_contact(contact*arr)
{
	int i=0;
	char search[20];
	printf("请输入要查找的人：");
	scanf("%s", search);
	i=search_name(search, &arr);
	if (i == arr->sz)
	{
		printf("未找到该联系人。\n");
		return;
	}
	printf("%-20s%-10s%-10s%-15s%-20s%-10s\n", "姓名", "性别", "年龄", "手机", "地址", "职业");
	printf("%-20s%-10s%-10d%-15s%-20s%-10s\n", arr->data[i].name, arr->data[i].sex, arr->data[i].age,
		                                        arr->data[i].phone, arr->data[i].adders, arr->data[i].job);
}

//修改联系人信息
void change_contact(contact*arr)
{
	int i;
	char title[20];
	printf("输入要修改的人：");
	scanf("%s", title);
	i=search_name(title, &arr);
	if (i == arr->sz)
	{
		printf("未找到该联系人。\n");
		return;
	}
	printf("请输入联系人姓名：");
	scanf("%s", (arr->data + arr->sz)->name);
	printf("请输入联系人性别：");
	scanf("%s", (arr->data + arr->sz)->sex);
	printf("请输入联系人年龄：");
	scanf("%d", &(arr->data + arr->sz)->age);
	printf("请输入联系人手机：");
	scanf("%s", (arr->data + arr->sz)->phone);
	printf("请输入联系人地址：");
	scanf("%s", (arr->data + arr->sz)->adders);
	printf("请输入联系人职业：");
	scanf("%s", (arr->data + arr->sz)->job);
}



//保存联系人到文件
void exti_save_contact(contact*arr)
{

	int i = 0;
	FILE *pf;
	pf=fopen("contact.doc", "w");//将联系人写入文件
	fprintf(pf, "%d\n", arr->sz);
	for (i = 0; i < arr->sz; i++)
	{
		fprintf(pf, "%-5s%-5s%-3d%-5s%-5s%-5s\n", arr->data[i].name, arr->data[i].sex, arr->data[i].age,
			                     arr->data[i].phone, arr->data[i].adders, arr->data[i].job);
	}
	fclose(pf);
	pf = NULL;
}


//从文件中读取联系人
void read_contact(contact*arr)
{
	int i = 0;

	FILE *pf;
	pf = fopen("contact.doc", "r");//从contact.doc读取数据
	if (pf == NULL)
	{	
		return;
	}
	fscanf(pf, "%d", &arr->sz);
	if (arr->sz > arr->max_stor)
	{
		arr->max_stor = arr->sz;
		details *ptr = (details*)realloc(arr->data, (arr->sz)*sizeof(details));
		if (ptr != NULL)
		{
			arr->data = ptr;
			printf("扩容成功。\n");
		}	
	}
	for (i = 0; i < arr->sz; i++)
	{
		fscanf(pf, "%s%s%d%s%s%s", arr->data[i].name, arr->data[i].sex, &arr->data[i].age,
			arr->data[i].phone, arr->data[i].adders, arr->data[i].job);
	}
	fclose(pf);
	pf = NULL;
}


void clean_contact(contact*arr)
{
	free(arr->data);
	arr->data = NULL;
	arr->data = (details*)malloc(3 * sizeof(details));//重新初始空间为3
	arr->sz = 0;                                      //重置存储数据个数
	arr->max_stor = 3;
	printf("清除成功。\n");

}
