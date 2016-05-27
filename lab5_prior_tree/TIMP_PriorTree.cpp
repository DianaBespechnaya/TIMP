// TIMP_PriorTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "vector";

using namespace std;
vector<int> tree;

void add() {
	int i;
	int num;
	scanf("%d", &num);
	if (tree.size() == 0)
		tree.insert(tree.begin(), num);
	else {
		for ( i = 0; i < tree.size(); i++) {
			if (num <= tree[i]) {
				tree.insert(tree.begin() + i, num);
				break;
			}
		}
		if (i == tree.size())
			tree.push_back(num);
	}
}

int main()
{
	int n;
	cin >> n;	
	char operation[4];
	
	for (int j = 0; j <= n; j++) {
		scanf("%s", &operation);
		switch (operation[0]) {
		case 'a':
			add();
			break;
		case 'g':
			cout << tree[0] << endl;
			break;
		case 'd':
			tree.erase(tree.begin());
			break;
		}
	}


    return 0;
}

