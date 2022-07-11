#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

//��ʼ���ṹ����
void init_contact(contact* arr)
{
	arr->data = (details*)malloc(3 * sizeof(details));//��ʼ�ռ�Ϊ3
	arr->sz = 0;                                      //�洢���ݸ���
	arr->max_stor = 3;                                //��ǰ���洢���ݸ���
	read_contact(arr);
}

//������ϵ��
void ADD_contact(contact *arr)
{
	//��dataָ���������
	if (arr->sz == arr->max_stor)
	{
		details* ptr = (details*)realloc(arr->data, (arr->max_stor + 2)*sizeof(details));
		if (ptr != NULL)
		{
			arr->max_stor += 2;
			arr->data = ptr;
			printf("���ݳɹ���\n");
		}
		else
			perror((char*)ptr);
	}
	printf("��������ϵ��������");
	scanf("%s", (arr->data+arr->sz)->name);
	printf("��������ϵ���Ա�");
	scanf("%s", (arr->data + arr->sz)->sex);
	printf("��������ϵ�����䣺");
	scanf("%d", &(arr->data + arr->sz)->age);
	printf("��������ϵ���ֻ���");
	scanf("%s", (arr->data + arr->sz)->phone);
	printf("��������ϵ�˵�ַ��");
	scanf("%s", (arr->data + arr->sz)->adders);
	printf("��������ϵ��ְҵ��");
	scanf("%s", (arr->data + arr->sz)->job);
	printf("��ӳɹ���\n");
	arr->sz++;
	
}


//��ϸ������ʾ
void detail_contact(contact *arr)
{
	//��ӡ��ϸ���ݱ���
	printf("%-20s%-10s%-10s%-15s%-20s%-10s\n", "����", "�Ա�", "����", "�ֻ�", "��ַ", "ְҵ");
	for (int i = 0; i < arr->sz; i++)
	{
		printf("%-20s%-10s%-10d%-15s%-20s%-10s\n", arr->data[i].name, arr->data[i].sex, arr->data[i].age,
			                                   arr->data[i].phone, arr->data[i].adders, arr->data[i].job);
	}
}

//ɾ����ϵ��
void delet_contact(contact *arr)
{
	int i;
	char delet[20];
	printf("������Ҫɾ������ϵ�ˣ�");
	scanf("%s", delet);
	i=search_name(delet, &arr);
	if (i == arr->sz)
	{
		printf("ͨѶ¼û�и���ϵ�ˣ�����ɾ����");
		return;
	}
	for (; i < arr->sz; i++)
	{
		arr->data[i] = arr->data[i + 1];
	}
	printf("ɾ���ɹ���\n");
	arr->sz--;
}


//���Һ���
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

//������ϵ��
void search_contact(contact*arr)
{
	int i=0;
	char search[20];
	printf("������Ҫ���ҵ��ˣ�");
	scanf("%s", search);
	i=search_name(search, &arr);
	if (i == arr->sz)
	{
		printf("δ�ҵ�����ϵ�ˡ�\n");
		return;
	}
	printf("%-20s%-10s%-10s%-15s%-20s%-10s\n", "����", "�Ա�", "����", "�ֻ�", "��ַ", "ְҵ");
	printf("%-20s%-10s%-10d%-15s%-20s%-10s\n", arr->data[i].name, arr->data[i].sex, arr->data[i].age,
		                                        arr->data[i].phone, arr->data[i].adders, arr->data[i].job);
}

//�޸���ϵ����Ϣ
void change_contact(contact*arr)
{
	int i;
	char title[20];
	printf("����Ҫ�޸ĵ��ˣ�");
	scanf("%s", title);
	i=search_name(title, &arr);
	if (i == arr->sz)
	{
		printf("δ�ҵ�����ϵ�ˡ�\n");
		return;
	}
	printf("��������ϵ��������");
	scanf("%s", (arr->data + arr->sz)->name);
	printf("��������ϵ���Ա�");
	scanf("%s", (arr->data + arr->sz)->sex);
	printf("��������ϵ�����䣺");
	scanf("%d", &(arr->data + arr->sz)->age);
	printf("��������ϵ���ֻ���");
	scanf("%s", (arr->data + arr->sz)->phone);
	printf("��������ϵ�˵�ַ��");
	scanf("%s", (arr->data + arr->sz)->adders);
	printf("��������ϵ��ְҵ��");
	scanf("%s", (arr->data + arr->sz)->job);
}



//������ϵ�˵��ļ�
void exti_save_contact(contact*arr)
{

	int i = 0;
	FILE *pf;
	pf=fopen("contact.doc", "w");//����ϵ��д���ļ�
	fprintf(pf, "%d\n", arr->sz);
	for (i = 0; i < arr->sz; i++)
	{
		fprintf(pf, "%-5s%-5s%-3d%-5s%-5s%-5s\n", arr->data[i].name, arr->data[i].sex, arr->data[i].age,
			                     arr->data[i].phone, arr->data[i].adders, arr->data[i].job);
	}
	fclose(pf);
	pf = NULL;
}


//���ļ��ж�ȡ��ϵ��
void read_contact(contact*arr)
{
	int i = 0;

	FILE *pf;
	pf = fopen("contact.doc", "r");//��contact.doc��ȡ����
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
			printf("���ݳɹ���\n");
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
	arr->data = (details*)malloc(3 * sizeof(details));//���³�ʼ�ռ�Ϊ3
	arr->sz = 0;                                      //���ô洢���ݸ���
	arr->max_stor = 3;
	printf("����ɹ���\n");

}
