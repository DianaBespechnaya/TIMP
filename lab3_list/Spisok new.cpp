// Spisok new.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct element 
{
	int x; 
	element *Next = NULL; 
};

class List 
{
	element *Head; 
public:
	List() { Head = new element; } 
	~List(); 
	void Add(int x, int ind);
	void Show(int); 
	void Del(int);
};

List::~List() 
{
	while (Head != NULL)  
	{
		element *temp = Head->Next; 
		delete Head; 
		Head = temp; 
	}
}
/**
		\func void List::Add(int x, int ind)
*/
void List::Add(int x, int ind) 
{
	element *temp = new element; 
	temp->x = x; 
	if (ind == 0) {
		temp->Next = Head;
		Head = temp;
	}
	else{
		element *node = Head;
		if (ind > 1) {	
			for (int i = 0; i < ind-1; i++) {
				if (node->Next != NULL)
					node = node->Next;
				else {
					element *empty = new element;
					node->Next = empty;
					node = node->Next;
				}
			}
		}

		element *tempElem = node->Next;
		node->Next = temp;
		temp->Next = tempElem;
	}

}
/**
		\func void List::Show(int ind)
*/
void List::Show(int ind)
{
	element *temp = Head; 
	if (ind != 0) {
		for (int i = 0; i < ind; i++) 
		{
			temp = temp->Next; 
		}
	}
	cout << temp->x << endl; 
}
/**
		\func void List::Del(int ind)
*/
void List::Del(int ind) {
	if (ind == 0) Head = Head->Next;
	else{
		element *temp = Head; 
		if (ind > 1) {
			for (int i = 0; i < ind - 1; i++) 
			{
				temp = temp->Next; 
			}
		}
		element *node = temp->Next;
		temp->Next = node->Next;
		delete node;
	}	
}
/**
		\func int main()
*/
int main()
{
	int N, ind, dat; 
	List lst; 
	char command[4];
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%s", &command);
		switch (command[0]){
		case 'a':
			scanf("%d %d", &ind, &dat);
			lst.Add(dat, ind);
			break;
		case 'g':
			scanf("%d", &ind);
			lst.Show(ind);
			break;
		case 'd':
			scanf("%d", &ind);
			lst.Del(ind);
			break;
		default:
			break;
		}
	}
	
	return 0;
}