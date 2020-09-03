//#include "head.h"
//
//void autoPtr()
//{
//	auto_ptr<string>p1(new string("i love you."));
//	auto_ptr<string>p2;
//	p2 = p1;//p2获得了p1的所有权
//	cout << *p2 << endl;
//	cout << *p1 << endl;//p1内存失效，无法访问
//}
//
//void  uniquePtr()
//{
//	unique_ptr<string>p1(new string("i love you."));
//	unique_ptr<string>p2;
//	//p2 = p1;//禁止赋值获得所有权
//	p1 = unique_ptr<string>(new string("hello world!"));
//	p2 = move(p1);//正确转移p1的所有权
//	
//	//cout << *p1 << endl;//转移所有权后p1失效
//	cout << *p2 << endl;
//}
//
//class ptrB;
//class ptrA
//{
//public:
//	weak_ptr<ptrB>pb_;
//	~ptrA() 
//	{
//		cout << "A delete\n";
//	}
//};
//class ptrB
//{
//public:
//	shared_ptr<ptrA>pa_;
//	~ptrB()
//	{
//		cout << "B delete\n";
//	}
//};
//void sharePtr()
//{
//	shared_ptr<ptrA>pa(new ptrA());
//	shared_ptr<ptrB>pb(new ptrB());
//	pa->pb_ = pb;
//	pb->pa_ = pa;
//	cout << pa.use_count() << endl;
//	cout << pb.use_count() << endl;	
//	pa->~ptrA();
//	cout << pa.use_count() << endl;
//	cout << pb.use_count() << endl;
//
//}
//
//void mod(int x)
//{
//	int sum = 0;
//	while (x)
//	{
//		if (x % 10)sum++;
//		x /= 10;
//	}
//	cout << sum << endl;
//}
//
//
//int main()
//{
//	mod(1111);
//	mod(-1111);
//	return 0;
//}

