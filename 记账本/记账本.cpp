#include<iostream>
#include<string.h>
#include<stdlib.h>
#include "USERINFO.h"
#include "printer.h"
#include "userManager.h"
#include "record.h"

User* currentuser = NULL;
User user;
User temp;
Record* record;
Record tempRecord;


int main()
{
	int option, optionformanager;
	while (1)
	{
		option = printMainMenu();
		switch (option)
		{
		case 1:
			if (login(&temp))
			{
				currentuser = &temp;
				printf("��¼�ɹ�����\n\n");
			}
			else
				printf("�û���/�������!!\n\n");
			break;
		case 2:
			printf("���ˣ�\n\n");
			if (currentuser == NULL)
			{
				printf("���ȵ�¼\n");
			}
			else
			{
				record = (Record*)malloc(sizeof(Record));
				strcpy(record->username, currentuser->username);
				save(record);
				printf("��¼�ɹ�\n\n");
			}
			break;
		case 3:
			printf("�޸Ĺ��ܣ�\n\n");
			if (currentuser == NULL)
			{
				printf("���ȵ�¼\n");
			}
			else
			{
				alter(&tempRecord, currentuser->username);
				printf("�޸ĳɹ�\n\n");
			}
			

			break;
		case 4:
			printf("ͳ�ƣ�\n\n");
			if (currentuser == NULL)
			{
				printf("���ȵ�¼\n");
			}
			else
			{
				statistics(currentuser->username);
			}
			break;
		case 5:
			printf("��ʾ��֧��\n\n");
			if (currentuser == NULL)
			{
				printf("���ȵ�¼\n");
			}
			else
			{
				printRecords(currentuser->username);
			}
			break;
		case 6:
			//refreshScreen();
			optionformanager = printUserMangerMenu();
			usermanager(optionformanager, &user);
			break;
		case 7:
			EXIT();
			exit(0);
			break;
		default:
			//refreshScreen();
			printf("������������������\n");
			break;
		}
	}

}
