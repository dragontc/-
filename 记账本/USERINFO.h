#pragma once
#ifndef _USERINFO_H
#define _USERINFO_H
#include<iostream>
#include<fstream>
using namespace std;
// �û�
typedef struct User {
	char username[20];
	char password[20];
};
// ����
typedef struct Date {
	int year;
	int month;
	int day;
};
// �û�����
typedef struct Record {
	int index;
	char username[20];
	Date date;
	int money;
	char message[20];
	struct Record* next;
}Record;

#endif // !_USERINFO_H

