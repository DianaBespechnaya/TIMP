#include "stdafx.h"
#include "classes.h"
#include <map>
#include <vector>

vector<Base*> copies;

class Functor {
public:
	virtual void operator()(vector<string> args){};
	virtual int getArgNum()=0;
};
class FunctorShow :public Functor {
public:
	FunctorShow(){};
	void operator()(vector<string> args){
		for (int i = 0; i < copies.size(); i ++)
			 copies[i]->show();
		 }
	int getArgNum(){ return 0; };
};
class FunctorCreate :public Functor {
public:
	FunctorCreate(){};
	void operator()(vector<string> args){
		if (args[args.size() - 2] == "A") copies.push_back(new A(args[args.size()-1]));
		if (args[args.size() - 2] == "B") copies.push_back(new B(args[args.size()-1]));
		if (args[args.size() - 2] == "C") copies.push_back(new C(args[args.size()-1]));
	}
	int getArgNum(){ return 2; }
};

map <string, Functor*> mfunc;

int main()
{
	int N;
	cin >> N;
	Functor *f = new FunctorShow;
	Functor *fc = new FunctorCreate;
	mfunc["showall"] = f;
	mfunc["create"] = fc;
	string command;
	vector<string> strvec;
	for (int i = 0; i < N; i++) {
		cin >> command;
		Functor *fctr = mfunc[command];
		if (fctr) {	
			
			int argnum = fctr->getArgNum();
			if (argnum == 2) 
			for (int j = 0; j < argnum; j++) {
				string str;
				cin >> str;
				strvec.push_back(str);
			}
			(*fctr)(strvec);
		}
	}

	return 0;
}
