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

class Stack
{
	element *Head;
public:
	Stack() { Head = new element; }
	~Stack();
	void Add(int x);
	void Show();
	void Del();
};

Stack::~Stack()
{
	while (Head != NULL)
	{
		element *temp = Head->Next;
		delete Head;
		Head = temp;
	}
}
/**
		\func void Stack::Add(int x)
*/
void Stack::Add(int x)
{
	element *temp = new element;
	temp->x = x;
	temp->Next = Head;
	Head = temp;
	
}
/**
		\func void Stack::Show()
*/
void Stack::Show()
{
	cout << Head->x << endl;
}
/**
		\func void Stack::Del() 
*/
void Stack::Del() 
{
	element *node = Head;
	Head = Head->Next;
	delete node;	

}
/**
		\func int main()
*/
int main()
{
	int N, dat;
	Stack stack;
	char command[4];

	cin >> N;
	for (int i = 1; i <= N; i++) {
		
		scanf("%s", &command);
		switch (command[0]){
		case 'a':
			scanf("%d", &dat);
			stack.Add(dat);
			break;
		case 'g':			
			stack.Show();
			break;
		case 'd':
			stack.Del();
			break;
		default:
			break;
		}
		
	}

	system("pause");
}