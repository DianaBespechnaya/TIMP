// TIIMP Laba2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char  s[255];
	char str[255];
	char* result;
	
	cin >> s;
	ifstream fin(s);	
	while (!fin.eof()) {
		fin.getline(s, 255);	//��������� �� ����� ������ � s	
		if ((strstr(s, "/**")) != NULL) {  //�������� �� ������� � s "/** "
			if ((strstr(s, "\\func")) == NULL)
				fin.getline(s, 255);
			result = strstr(s, "\\func"); //result ��������� �� �� ����� � s, ��� ����� \func
			result += 6;//result ������ ��������� �� 6 ���� ������ (������������ "\func ")
			strcpy(str, result); //�������� result  � str 
			if ((strstr(s, "*/")) != NULL){
				str[strlen(result) - 2] = '\0';// "��������" */
				cout << str << endl;
			}
			else {
				fin.getline(s, 255);
				if ((strstr(s, "*/")) != NULL)
					cout << str << endl;
			}
		}

	}
	system("pause");
	return 0;
}

