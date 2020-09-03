////#include "head.h"
////
////class Base
////{
////public:
////	virtual int add(int, int) = 0;
////	virtual int mul(int, int) = 0;
////	virtual int mod(int);
////};
////
////class Driver:public Base
////{
////public:
////	int add(int, int);
////	int mul(int, int);
////
////};
////
////int main()
////{
////	Driver d;
////
////}
//
//
//#include  "head.h"
//#include <numeric>
//
//class Base
//{
//public:
//	//void f() { cout << 1 << endl; }
//	void f()const { cout << 2 << endl; }
//	//int a = 10;
//	const int a = 20;
//
//};
//
//int add(int a, int b)
//{
//	return 1;
//}
//
//int main()
//{
//	vector<int>a = { 3,4,8};
//	cout << accumulate(a.begin(), a.end(), 2,add) << endl;
//
//	return 0;
//}