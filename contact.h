#ifndef _CONTACT_H
#define _CONTACT_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct details
{
	char name[20];
	int age;
	char sex[5];
	char phone[15];
	char adders[30];
	char  job[10];

}details;

typedef struct contact
{
	details *data ;
	int sz;
	int max_stor;
}contact;

enum intput
{
	EXTI,
	ADD,
	DEL,
    CHANGE,
	SEARCH,
	DETAILS,
	CLEAN
};


void init_contact(contact* arr);//初始化函数

void ADD_contact(contact *arr);//添加联系人函数

void detail_contact(contact *arr);//查看联系人详细资料函数

void delet_contact(contact *arr);//删除联系人函数

void search_contact(contact *arr);//查找联系人函数

int search_name(char*nam, contact* *arr);//查找函数

void change_contact(contact*arr);//修改联系人信息函数

void exti_save_contact(contact*arr);//保存联系人到文件函数

void read_contact(contact*arr);//从文件读取联系人函数

void clean_contact(contact*arr);//清空存储数据

#endif