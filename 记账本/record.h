
#pragma once
#ifndef _RECORD_H
#define _RECORD_H
#include "USERINFO.h"
void getRecords();
bool login(User *user);
void printRecords(char username[20]);
bool save(Record* node);
void alter(Record *record, char username[20]);
bool statistics(char username[20]);
void EXIT();
#endif
