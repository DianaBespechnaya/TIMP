// TIIMP Laba2.cpp: определяет точку входа для консольного приложения.
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
		fin.getline(s, 255);	//считываем из файла строку в s	
		if ((strstr(s, "\\func")) != NULL) { //проверка на наличие в s "\func"
			result = strstr(s, "\\func"); //result указывает на то место в s, где стоит \func
			result+=6;//result теперь указывает на 6 байт правее (перепрыгнули "\func ")
			if (strstr(result, "*/") != NULL) //проверяем, заканчивается ли данная строка  на "*/"
			{
				strcpy(str, result); //копируем result  в str 
				str[strlen(result) - 2] = '\0';// "затираем" */
				cout << str << endl;
			}
			else
			cout << result << endl;
		}
	}

	return 0;
}

