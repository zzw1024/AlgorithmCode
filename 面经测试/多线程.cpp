//////#include "head.h"
//////
//////char c = 'A';
//////
//////void print()
//////{
//////	cout << c << endl;
//////	++c;
//////}
//////
//////int main()
//////{
//////	//vector<thread>th;
//////	for (int i = 0; i < 3; ++i)
//////	{
//////		thread th(print);
//////		th.join();
//////	}
//////	cout << 112 << endl;
//////	return 0;
//////}
//////
//////#include <iostream>
//////using namespace std;
//////class Point {
//////public:
//////	Point(int _x) :x(_x) {}
//////
//////	void testConstFunction(int _x) const {
//////		///������const��Ա�����У������޸��κ����Ա����
//////		x = _x;
//////
//////		///����const��Ա�������ܵ��÷�onst��Ա��������Ϊ��const��Ա�������Ի��޸ĳ�Ա����
//////		modify_x(_x);
//////	}
//////
//////	void modify_x(int _x) {
//////		x = _x;
//////	}
//////
//////	int x;
//////};
//////
////
////
////
////#include "head.h"
////#include <Windows.h>
////#include <process.h>
////
////int main()
////{
////	list<int>L;
////	
////}
//
//
//#include <iostream>
//#include <vector>
//#include <future>
//
//using namespace std;
//
//int print(future<int>& fut)
//{
//	cout << "i am in..." << endl;
//	//int x = fut.get();
//	//cout << x << endl;
//	return 10;
//}
//
//int main()
//{
//	promise<int>prom;
//	future<int>fut = prom.get_future();
//	prom.set_value(555);
//	thread th(print, ref(fut));
//	th.join();
//	cout << fut.get() << endl;
//	return 0;;
//
//}