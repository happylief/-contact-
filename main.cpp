#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"



//打印菜单
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
	printf("请选择->");
	scanf("%d", &b);
	switch (b)
	{
	case ADD:
		system("cls");//清屏操作
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
		printf("输入错误，请重新输入\n");
		cue();
		break;

	}
	return b;
}

int main()
{
	int c;
   //创建一个结构体变量
	contact con;
	//先初始化该变量
	init_contact(&con);
	do{
		cue();
		c = function(&con);
	 }while (c);//循环执行，如果输入值为0，则退出循环
	free(con.data);
	con.data = NULL;
	con.max_stor = 0;
	con.sz = 0;
	return 0;
}