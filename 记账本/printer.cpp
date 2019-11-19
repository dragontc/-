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
	printf("            记账本                  \n\n");
	printf("===================================\n\n");
	printf("1.用户登录\n\n");
	printf("2.记账\n\n");
	printf("3.修改\n\n");
	printf("4.统计\n\n");
	printf("5.显示收支\n\n");
	printf("6.成员管理\n\n");
	printf("7.退出\n\n");
	printf("输入选择：");
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
	printf("            成员管理                  \n\n");
	printf("===================================\n\n");
	printf("1.用户注册\n\n");
	printf("2.用户删除\n\n");
	printf("3.用户浏览\n\n");
	printf("输入选择：");
	int res = scanf("%d", &option);
	if (res == 1)
	{
		rewind(stdin);
		return option;
	}
	rewind(stdin);
	return -1;
}