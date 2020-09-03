//#include "head.h"
//class Base
//{
//public:
//int num;
//char *p;
//static int s;
//Base(int n = 0):num(n),p(new char) {}
//};
//
//int Base::s = 0;
//int main()
//{
//Base a(10);
//a.s = 88;
//*(a.p) = 'a';
//Base b = a;
//Base c = a;
//cout << b.s << endl;
//cout << *(b.p) << endl;
//a.num = 9;
//a.s = 77;
//*(a.p) = 'p';
//cout << b.s << endl;
//cout << *(b.p) << endl;
//return  0;
//
//}
//
//class Object
//{
//public:
//	Object()
//	{
//		cout << "构造函数" << endl;
//	}
//
//	~Object()
//	{
//		cout << "析构函数" << endl;
//	}
//
//	void fun(string info)
//	{
//		cout << info << endl;
//	}
//
//};
//
//int main()
//{
//
//	Object obj;
//	string str = "我是一个类的成员函数！";
//	thread t1(&Object::fun, &obj, str);
//	t1.join();
//
//	getchar();
//	return 1;
//}
//
//
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//struct Node
//{
//	int val;
//	Node *L, *R;
//	Node(int a = 0) :val(a), L(nullptr), R(nullptr) {}
//};
//
//int getHigh(Node *root)
//{
//	if (root == nullptr)
//		return 0;
//	int LHigh = getHigh(root->L);
//	int RHigh = getHigh(root->R);
//	return max(LHigh, RHigh) + 1;
//}
//
//int main()
//{
//	Node *root = new Node(1);
//	root->L = new Node(2);
//	root->R = new Node(3);
//	root->L->L = new Node(4);
//	root->R->R = new Node(5);
//	root->R->R->L = new Node(6);
//	cout << getHigh(root) << endl;
//	return 0;
//}
//
//
