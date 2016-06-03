// TIMPdll.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
vector<int> tree;

extern "C" {
	__declspec(dllexport) void add(int num) {
		tree.push_back(num);
	}

	__declspec(dllexport) void get() {
		cout << tree[0] << endl;
	}

	__declspec(dllexport) void del(){
		tree.erase(tree.begin());
	}
}