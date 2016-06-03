#include <iostream>
#include <string>

using namespace std;

class Base {
public:
	virtual void show() = 0;
	Base(string v) { value = v; }
protected:
	string value;
};
class A : public Base{
public:
	A(string v) : Base(v) {};
	void show(){ cout << "class A: " << value << endl; }
};
class B : public Base{
public:
	B(string v) : Base(v) {};
	void show(){ cout << "class B: " << value << endl; }
};
class C : public Base{
public:
	C(string v) : Base(v) {};
	void show(){ cout << "class C: " << value << endl; }
};