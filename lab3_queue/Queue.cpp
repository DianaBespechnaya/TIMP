// Queue.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct element
{
	int x;
	element *Next = NULL;
};

class Queue
{
	element *Head;
public:
	Queue() { Head = new element; }
	~Queue();
	void Add(int x);
	void Show();
	void Del();
};

Queue::~Queue()
{
	while (Head != NULL)
	{
		element *temp = Head->Next;
		delete Head;
		Head = temp;
	}
}
/**
		\func void Queue::Add(int x)
*/
void Queue::Add(int x)
{
	element *temp = new element;
	temp->x = x;
	element *node = Head;
	while (node->Next != NULL)
		node = node->Next;
	node->Next = temp;
}
/**
		\func void Queue::Show()
*/
void Queue::Show()
{
	cout << Head->x << endl;
}
/**
		\func void Queue::Del()
*/
void Queue::Del()
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
	Queue queue;
	char command[4];

	cin >> N;
	for (int i = 1; i <= N; i++) {

		scanf("%s", &command);
		switch (command[0]){
		case 'a':
			scanf("%d", &dat);
			queue.Add(dat);
			break;
		case 'g':
			queue.Show();
			break;
		case 'd':
			queue.Del();
			break;
		default:
			break;
		}

	}

	system("pause");
}