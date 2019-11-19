#pragma once
#ifndef _USERINFO_H
#define _USERINFO_H
#include<iostream>
#include<fstream>
using namespace std;
// 用户
typedef struct User {
	char username[20];
	char password[20];
};
// 日期
typedef struct Date {
	int year;
	int month;
	int day;
};
// 用户数据
typedef struct Record {
	int index;
	char username[20];
	Date date;
	int money;
	char message[20];
	struct Record* next;
}Record;

#endif // !_USERINFO_H

