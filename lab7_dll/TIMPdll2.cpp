// TIMPdll2.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;
vector<int> tree;

extern "C" {
	__declspec(dllexport) void add(int num) {
		int i;
		if (tree.size() == 0)
			tree.insert(tree.begin(), num);
		else {
			for (i = 0; i < tree.size(); i++) {
				if (num <= tree[i]) {
					tree.insert(tree.begin() + i, num);
					break;
				}
			}
			if (i == tree.size())
				tree.push_back(num);
		}
	}


	__declspec(dllexport) void get() {
		cout << tree[0]<< endl;
	}

	__declspec(dllexport) void del(){
		tree.erase(tree.begin());
	}
}


