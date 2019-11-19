#include "USERINFO.h"
#include "record.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//���˱����� 
Record* RecordPTR;
Record* END;
int MaxIndex;

int days[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
// ��ȡ�ļ����� 
void getRecords() {
	ifstream fcin("records.txt");
	Record* node;
	RecordPTR = (Record*)malloc(sizeof(Record));
	END = RecordPTR;
	int index, year, month, day, money;
	char username[20], message[20];
	while (fcin >> index) {
		node = (Record*)malloc(sizeof(Record));
		node->index = MaxIndex = index;
		fcin >> node->username >> (node->date).year >> (node->date).month >> (node->date).day >> node->money >> node->message;
		END->next = node;
		END = node;
	}
	END->next = NULL;
	fcin.close();
}

// ��½ģ�� 
bool login(User* user) {
	ifstream fcin("user.txt");
	char name[20], passwd[20];
	printf("�����û���:");
	cin >> user->username;
	printf("��������:");
	cin >> user->password;
	while (fcin >> name >> passwd) {
		if (!strcmp(user->username, name) && !strcmp(user->password, passwd)) {
			getRecords();
			fcin.close();
			return true;
		}
	}
	fcin.close();
	return false;
}

// ��ʾ��֧ģ�� 
void printRecords(char username[20]) {
	Record* node = RecordPTR->next;
	while (node != NULL) {
		if (!strcmp(node->username, username)) {
			cout << "���:" << node->index << " ����:" << node->date.year << "-" << node->date.month << "-" << node->date.day << " ���:" << node->money << " ��ע:" << node->message << endl;
		}
		node = node->next;
	}
}

// ����ģ�� 
bool save(Record *node) {
	printf("����������: ��� �·� ���� ��� ��ע��\n");
	cin >> node->date.year >> node->date.month >> node->date.day >> node->money >> node->message;
	node->index = ++MaxIndex;
	node->next = NULL;
	END = RecordPTR;
	while (END->next != NULL) {
		END = END->next;
	}
	END->next = node;
	END = END->next;

	// ��ӡ���ӽ��
	printRecords(node->username);
	return true;
}


//�޸�ģ��
void alter(Record *record, char username[20]) {
	cout << "��ݣ��·ݣ����ڣ�����עΪ0��ʾ���޸�\n" << endl;
	cout << "��ݣ��·ݣ����ڣ����Ϊ0�ұ�עΪ��delete����ɾ���ļ�¼\n" << endl;
	cout << "��ű�������\n" << endl;
	cout << "����������: ��� ��� �·� ���� ��� ��ע\n" << endl;
	cin >> record->index >> record->date.year >> record->date.month
		>> record->date.day >> record->money >> record->message;
	// ȫ��Ϊ�գ�ɾ�� 
	if (record->index <= MaxIndex && record->date.year == 0 && record->date.month == 0 && record->date.day == 0 && record->money == 0 && (strcmp(record->message, "delete") == 0)) {
		Record* head = RecordPTR;
		while (head != NULL && head->next != NULL) {
			if (head->next->index == record->index && !strcmp(username, head->next->username)) {
				head->next = head->next->next;
			}
			head = head->next;
		}
	}
	else {
		Record* node = RecordPTR->next;
		while (node != NULL) {
			if (node->index == record->index && !strcmp(username, node->username)) {
				if (record->date.year != 0)  (node->date).year = record->date.year;
				if (record->date.month != 0) (node->date).month = record->date.month;
				if (record->date.day != 0)   (node->date).day = record->date.day;
				if (record->money != 0)  node->money = record->money;
				if (strcmp(record->message, "delete") == 1 && strcmp(record->message, "0") != 0) strcpy(node->message, record->message);
				break;
			}
			node = node->next;
		}
	}

	// �޸���ɣ���ӡ��� 
	printRecords(username);
}


// ͳ��ģ��
bool statistics(char username[20]) {
	Record* node = RecordPTR->next;
	int in = 0, out = 0, all = 0;
	while (node != NULL) {
		if (!strcmp(node->username, username)) {
			if (node->money < 0)  out += node->money;
			else in += node->money;
			all += node->money;
		}
		node = node->next;
	}
	cout << "����֧���" << all << endl;
	cout << "������:" << in << endl;
	cout << "��֧��:" << out << endl;
	return true;
}

void EXIT()
{
	ofstream fcout("records.txt");
	Record* node = RecordPTR->next;
	int cnt = 1;
	while (node != NULL) {
		fcout << cnt++ << " " << node->username << " " << (node->date).year << " " << (node->date).month << " " << (node->date).day << " " << node->money << " " << node->message << endl;
		node = node->next;
	}
}
