#include "printer.h"
#include <stdio.h>

void refreshScreen()
{
	for (int i = 0; i < 50; i++)
		printf("\n");
}

int printMainMenu()
{
	int option;
	printf("===================================\n\n");
	printf("            ���˱�                  \n\n");
	printf("===================================\n\n");
	printf("1.�û���¼\n\n");
	printf("2.����\n\n");
	printf("3.�޸�\n\n");
	printf("4.ͳ��\n\n");
	printf("5.��ʾ��֧\n\n");
	printf("6.��Ա����\n\n");
	printf("7.�˳�\n\n");
	printf("����ѡ��");
	int res = scanf("%d", &option);
	if (res == 1)
	{
		rewind(stdin);
		return option;
	}
	rewind(stdin);
	return -1;
}

int printUserMangerMenu()
{
	int option;
	printf("===================================\n\n");
	printf("            ��Ա����                  \n\n");
	printf("===================================\n\n");
	printf("1.�û�ע��\n\n");
	printf("2.�û�ɾ��\n\n");
	printf("3.�û����\n\n");
	printf("����ѡ��");
	int res = scanf("%d", &option);
	if (res == 1)
	{
		rewind(stdin);
		return option;
	}
	rewind(stdin);
	return -1;
}