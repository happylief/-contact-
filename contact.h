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


void init_contact(contact* arr);//��ʼ������

void ADD_contact(contact *arr);//�����ϵ�˺���

void detail_contact(contact *arr);//�鿴��ϵ����ϸ���Ϻ���

void delet_contact(contact *arr);//ɾ����ϵ�˺���

void search_contact(contact *arr);//������ϵ�˺���

int search_name(char*nam, contact* *arr);//���Һ���

void change_contact(contact*arr);//�޸���ϵ����Ϣ����

void exti_save_contact(contact*arr);//������ϵ�˵��ļ�����

void read_contact(contact*arr);//���ļ���ȡ��ϵ�˺���

void clean_contact(contact*arr);//��մ洢����

#endif