#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"



//��ӡ�˵�
void cue()
{
	printf("***************************************\n");
	printf("*******  1 ADD        2 DEL   *********\n");
	printf("*******  3 CHANGE     4 SEARCH*********\n");
	printf("*******  5 DETAILS    0 EXTI  *********\n");
	printf("*******  6 CLEAN              *********\n");
	printf("***************************************\n");
}
int function(contact*con)
{
	int b = 0;
	printf("��ѡ��->");
	scanf("%d", &b);
	switch (b)
	{
	case ADD:
		system("cls");//��������
		ADD_contact(con);
		break;
	case DEL:
		system("cls");
		delet_contact(con);
		break;
	case DETAILS:
		system("cls");
		detail_contact(con);
		break;
	case CHANGE:
		system("cls");
		change_contact(con);
		break;
	case SEARCH:
		system("cls");
		search_contact(con);
		break;
	case EXTI:
		exti_save_contact(con);
		break;
	case CLEAN:
		clean_contact(con);
		break;
	default:
		printf("�����������������\n");
		cue();
		break;

	}
	return b;
}

int main()
{
	int c;
   //����һ���ṹ�����
	contact con;
	//�ȳ�ʼ���ñ���
	init_contact(&con);
	do{
		cue();
		c = function(&con);
	 }while (c);//ѭ��ִ�У��������ֵΪ0�����˳�ѭ��
	free(con.data);
	con.data = NULL;
	con.max_stor = 0;
	con.sz = 0;
	return 0;
}