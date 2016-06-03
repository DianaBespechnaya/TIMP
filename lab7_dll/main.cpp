
#include <stdio.h>
#include <string>
#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
	string lib;
	cin >> lib;
	
	HINSTANCE h;

	void(*add) (int);
	void(*get) ();
	void(*del) ();

	if (lib == "Queue.dll") h = LoadLibrary(TEXT("TIMPdll.dll"));
	if (lib == "PriorQueue.dll")h = LoadLibrary(TEXT("TIMPdll2.dll"));
	if (!h)
	{
		printf("cannot find this lib\n");
		system("pause");
		return 0;
	}
	else {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			string command;
			cin >> command;
			if (command == "add") {
				int n;
				cin >> n;
				add = (void(*) (int))GetProcAddress(h, "add");
				add(n);
			}
			if (command == "get") {
				get = (void(*) ())GetProcAddress(h, "get");
				get();
			}
			if (command == "del"){
				del = (void(*) ())GetProcAddress(h, "del");
				del();
			}
		}
	}
	
	FreeLibrary(h);
	
	return 0;
}