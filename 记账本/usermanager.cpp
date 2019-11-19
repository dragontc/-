#include "userManager.h"
#include <string.h>

User users[20];

void usermanager(int option, User* user)
{
	
	if (option == 1)
	{
		printf("�������û���:");
		cin >> user->username;
		printf("������Ҫ���õ�����:");
		cin >> user->password;
		ofstream file;
		file.open("user.txt", ios::app);
		file << user->username << " " << user->password << endl;
		file.close();
		printf("ע��ɹ��������µ�¼\n\n");

	}
	else if (option == 2)
	{
		char del[20];
		printf("������Ҫɾ�����û�:");
		cin >> del;
		cout << "�û���֤" << endl;
		printf("����������û���:");
		cin >> user->username;
		printf("����������:");
		cin >> user->password;
		ifstream file;
		file.open("user.txt");
		char name[20], password[20];
		bool can = false;
		int count = 0;
		int target = 0;
		while (file >> name >> password)
		{
			strcpy(users[count].username, name);
			strcpy(users[count].password, password);
			count++;
			if (strcmp(name,user->username) == 0 && strcmp(password, user->password) == 0)
			{
				can = true;
			}
			if (strcmp(name, del) == 0)
			{
				target = count - 1;
			}
		}
		file.close();
		ofstream fout("user.txt");
		if (can)
		{
			for (int i = 0; i < count; i++)
			{
				if (i != target)
				{
					fout << users[i].username << " " <<
						users[i].password << endl;
				}
			}
			printf("ɾ���û��ɹ�\n\n");

		}
		else
		{
			cout << "�û���֤ʧ�ܣ�" << endl;
		}
		fout.close();
	}
	else if (option == 3)
	{
		ifstream file;
		file.open("user.txt");
		char name[20], password[20];
		int count = 0;
		cout << "ע���û����£�" << endl;
		while (file >> name >> password)
		{
			count++;
			cout << count << ":   " << name << endl;
		}
		file.close();
	}
}