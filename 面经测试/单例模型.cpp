//#include "head.h"
//
////最推荐的写法
//class Singleton
//{
//private://所有构造函数放入私有中，使其无法构造
//	Singleton() { cout << "Singleton Construction" << endl; };
//	~Singleton() { cout << "Singleton Delete" << endl; };
//
//	Singleton(const Singleton &s);
//	Singleton& operator=(const Singleton &s);
//
//public:	
//	static Singleton& GetInstance()//给予接口
//	{ 
//		static Singleton instance;//只能在类外实现
//		return instance;
//	};
//	int val;
//};
//
//int main()
//{
//	Singleton::GetInstance().val = 1;//只能使用这一个对象
//	return 0;
//}
//
////表面可以构造对象的写法
//class Singleton
//{
//private://所有构造函数放入私有中，使其无法构造
//	Singleton() { cout << "Singleton Construction" << endl; };
//	~Singleton() { cout << "Singleton Delete" << endl; };
//
//	Singleton(const Singleton &s);
//	Singleton& operator=(const Singleton &s);
//	static Singleton* instance;//只能类外初始化
//public:
//	static Singleton* GetInstance();//给予接口，类外实现
//	int val;
//};
//Singleton* Singleton::instance = nullptr;//类外初始化
//Singleton* Singleton::GetInstance()
//{
//	if (instance == nullptr)//至一步很重要
//		instance = new Singleton();
//	return instance;
//}
//
//int main()
//{
//	Singleton* p1 = Singleton::GetInstance();//只会构造一次,且不能使用delete
//	Singleton* p2 = Singleton::GetInstance();//p1和p2都指向同一个地址
//	p1->val = 1;
//	p2->val = 2;//p2覆盖p1
//	cout << p1->val << endl;//2
//	cout << p2->val << endl;//2
//	return 0;
//}
