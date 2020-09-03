#include <iostream>
#include <vector>
using namespace std;

class Base1
{
public:
	virtual void fun1() {}
	virtual void fun2() {}
};

class D :public Base1
{
public:
	void dd();
};

class Base2
{
public:
	virtual void fun3() {}
	virtual void fun4() {}
};

class Drive:public Base1,public Base2
{
public:
	virtual void fun1() {}//Base1
	virtual void fun3() {}//Base2
	virtual void fun5() {}//Dirver
};

enum  MyEnum
{
	south=10, west, east
}sss;

int main()
{
	//sss = west;
	cout << sss << endl;
	Base1 *b = new D;
	
	return  0;


}

